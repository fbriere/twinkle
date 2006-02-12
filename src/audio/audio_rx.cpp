/*
    Copyright (C) 2005-2006  Michel de Boer <michelboer@xs4all.nl>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <sys/time.h>
#include "audio_rx.h"
#include "log.h"
#include "rtp_telephone_event.h"
#include "userintf.h"
#include "line.h"
#include "sys_settings.h"
#include <ctime>
#include <cstdlib>
#include "audits/memman.h"

#define SAMPLE_BUF_SIZE (ptime * AUDIO_SAMPLE_RATE/1000 * AUDIO_SAMPLE_SIZE/8)

// Debug macro to print timestamp
#define DEBUG_TS(s)	{ gettimeofday(&debug_timer, NULL);\
			  cout << "DEBUG: ";\
			  cout << debug_timer.tv_sec * 1000 +\
			          debug_timer.tv_usec / 1000;\
			  cout << " " << (s) << endl;\
			}

//////////
// PRIVATE
//////////

unsigned char t_audio_rx::encode(short pcm_sample) {
	switch(codec) {
	case CODEC_G711_ALAW:
		return linear2alaw(pcm_sample);
	case CODEC_G711_ULAW:
		return linear2ulaw(pcm_sample);
	default:
		assert(false);
	}
}

bool t_audio_rx::get_sound_samples(void) {
	int status;
	struct timespec sleeptimer;
	struct timeval debug_timer;

	mtx_3way.lock();

	if (is_3way && !is_main_rx_3way) {
		// We are not the main receiver in a 3-way call, so
		// get the sound samples from the local media buffer.
		// This buffer will be filled by the main receiver.
		if (!media_3way_peer_rx->get(sample_buf, SAMPLE_BUF_SIZE)) {
			// The mutex is unlocked before going to sleep.
			// First I had the mutex unlock after the sleep.
			// That worked fine with LinuxThreading, but it does
			// not work with NPTL. It causes a deadlock when
			// the main receiver calls post_media_peer_rx_3way
			// as NPTL does not fair scheduling. This thread
			// simly gets the lock again and the main receiver
			// dies from starvation.
			mtx_3way.unlock();

			// There is not enough data yet. Sleep for 1 ms.
			sleeptimer.tv_sec = 0;
			sleeptimer.tv_nsec = 1000000;
			nanosleep(&sleeptimer, NULL);
			// Do not use the nobreak_count here. It might be that
			// the other receiver uses a different payload size.
			// Then it might take a little longer before the 1st
			// data is available. In case of a tight loop, it will
			// be broken by the main receiver.
			return false;
		}
	} else {
		// Get the sound samples from the DSP
		status = input_device->read(sample_buf, SAMPLE_BUF_SIZE);
		if (status != SAMPLE_BUF_SIZE) {
			if (!logged_capture_failure) {
				// Log this failure only once
				log_file->write_header("t_audio_rx::get_sound_samples",
					LOG_NORMAL, LOG_WARNING);
				log_file->write_raw("Audio rx line ");
				log_file->write_raw(get_line()->get_line_number()+1);
				log_file->write_raw(": sound capture failed.\n");
				log_file->write_footer();
				logged_capture_failure = true;
			}
			stop_running = true;
			mtx_3way.unlock();
			return false;
		}

		// If line is muted, then fill sample buffer with silence.
		// Note that we keep reading the dsp, to prevent the DSP buffers
		// from filling up.
		if (get_line()->get_is_muted()) {
			bzero(sample_buf, SAMPLE_BUF_SIZE);
		}
	}

	// Convert buffer to a buffer of shorts as the samples are 16 bits
	short *sb = (short *)sample_buf;
	
	// Reduce noise
	if (sys_config->au_reduce_noise_mic) {
		pcm_reduce_noise(sb, SAMPLE_BUF_SIZE / 2);
	}

	if (is_3way) {
		// Send the sound samples to the other receiver if we
		// are the main receiver.
		// There may be no other receiver when one of the far-ends
		// has put the call on-hold.
		if (is_main_rx_3way && peer_rx_3way) {
			peer_rx_3way->post_media_peer_rx_3way(sample_buf, SAMPLE_BUF_SIZE);
		}

		// Mix the sound samples with the 3rd party
		if (media_3way_peer_tx->get(mix_buf_3way, SAMPLE_BUF_SIZE)) {
			short *mix_sb = (short *)mix_buf_3way;
			for (int i = 0; i < SAMPLE_BUF_SIZE / 2; i++) {
				sb[i] = mix_linear_pcm(sb[i], mix_sb[i]);
			}
		}
	}

	mtx_3way.unlock();

	// Encode sound samples
	switch (codec) {
	case CODEC_G711_ALAW:
	case CODEC_G711_ULAW:
		for (int i = 0; i < payload_size; i++) {
			payload[i] = encode(sb[i]);
		}
		break;
	case CODEC_GSM:
		gsm_encode(gsm_encoder, (short *)sb, payload);
		break;
	default:
		assert(false);
	}

	return true;
}

void t_audio_rx::get_dtmf_payload(void) {
	struct timespec sleeptimer;
	
	t_rtp_telephone_event *dtmf_payload = (t_rtp_telephone_event *)payload;

	// RFC 2833 3.5, 3.6
	dtmf_payload->set_event(dtmf_current);
	dtmf_payload->set_reserved(false);
	dtmf_payload->set_volume(user_config->dtmf_volume);

	if (dtmf_pause) {
		// Trailing pause phase of a DTMF tone
		// Repeat the last packet
		dtmf_payload->set_end(true);

		int pause_duration = timestamp - dtmf_timestamp - dtmf_duration +
				     nsamples;
		if (pause_duration / payload_size * ptime >=
					user_config->dtmf_pause)
		{
			// This is the last packet to be sent for the
			// current DTMF tone.
			dtmf_stop = true;
			log_file->write_header("t_audio_rx::get_dtmf_payload", LOG_NORMAL);
			log_file->write_raw("Audio rx line ");
			log_file->write_raw(get_line()->get_line_number()+1);
			log_file->write_raw(": finish DTMF event - ");
			log_file->write_raw(dtmf_current);
			log_file->write_endl();
			log_file->write_footer();
		}
	} else {
		// Play phase of a DTMF tone
		// The duration counts from the start of the tone.
		dtmf_duration = timestamp - dtmf_timestamp + nsamples;

		// Check if the tone must end
		if (dtmf_duration / nsamples * ptime >=
						user_config->dtmf_duration)
		{
			dtmf_payload->set_end(true);
			dtmf_pause = true;
		} else {
			dtmf_payload->set_end(false);
		}
	}

	dtmf_payload->set_duration(dtmf_duration);
	
	// Sleep ptime ms
	// The reason for sleeping is that the DTMF event indicates that
	// the DTMF tone lasts for ptime ms. So this time really has to pass.
	sleeptimer.tv_sec = 0;

	if (ptime >= 20) {
		sleeptimer.tv_nsec =
			ptime * 1000000 - 5000000;
	} else {
		// With a thread schedule of 10ms
		// granularity, this will schedule the
		// thread every 10ms.
		sleeptimer.tv_nsec = 5000000;
	}
	nanosleep(&sleeptimer, NULL);

	// Empty sound card buffer.
	// During the DTMF tone, no sound from the sound card is played out.
	input_device->flush(false, true);
}

bool t_audio_rx::get_dtmf_event(void) {
	// DTMF events are not supported in a 3-way conference
	if (is_3way) return false;

	if (!sema_dtmf_q.try_down()) {
		// No DTMF event available
		return false;
	}
	
	// Get next DTMF event
	mtx_dtmf_q.lock();
	dtmf_current = dtmf_queue.front();
	dtmf_queue.pop();
	mtx_dtmf_q.unlock();

	// Initialize DTMF settings
	dtmf_playing = true;
	dtmf_pause = false;
	dtmf_stop = false;
	dtmf_timestamp = timestamp;
	dtmf_duration = nsamples;

	// Log DTMF event
	log_file->write_header("t_audio_rx::get_dtmf_event", LOG_NORMAL);
	log_file->write_raw("Audio rx line ");
	log_file->write_raw(get_line()->get_line_number()+1);
	log_file->write_raw(": start DTMF event - ");
	log_file->write_raw(dtmf_current);
	log_file->write_endl();
	log_file->write_raw("Payload type: ");
	log_file->write_raw(pt_telephone_event);
	log_file->write_endl();

	log_file->write_footer();

	// Set RTP payload format
	rtp_session->setPayloadFormat(
		DynamicPayloadFormat(pt_telephone_event, AUDIO_SAMPLE_RATE));

	// As all RTP event contain the same timestamp, the ccRTP stack will
	// discard packets when the timestamp gets to old.
	// Increase the expire timeout value to prevent this.
	rtp_session->setExpireTimeout((JITTER_BUF_MS +
		user_config->dtmf_duration + user_config->dtmf_pause) * 1000);

	return true;
}

void t_audio_rx::set_sound_payload_format(void) {
	switch(codec) {
	case CODEC_G711_ALAW:
		rtp_session->setPayloadFormat(StaticPayloadFormat(sptPCMA));
		break;
	case CODEC_G711_ULAW:
		rtp_session->setPayloadFormat(StaticPayloadFormat(sptPCMU));
		break;
	case CODEC_GSM:
		rtp_session->setPayloadFormat(StaticPayloadFormat(sptGSM));
		break;
	default:
		assert(false);
	}
}

//////////
// PUBLIC
//////////

t_audio_rx::t_audio_rx(t_audio_session *_audio_session,
		   t_audio_io *_input_device, t_twinkle_rtp_session *_rtp_session,
	           t_audio_codec _codec, unsigned short _ptime) : sema_dtmf_q(0)
{
	audio_session = _audio_session;
	
	user_config = audio_session->get_line()->get_user();
	assert(user_config);
	
	input_device = _input_device;
	rtp_session = _rtp_session;
	codec = _codec;
	dtmf_playing = false;
	dtmf_pause = false;
	dtmf_stop = false;
	is_running = false;
	stop_running = false;
	logged_capture_failure = false;

	pt_telephone_event = -1;

	// Set ptime
	if (codec == CODEC_GSM) {
		// GSM has fixed ptime
		ptime = PTIME_GSM;
	} else if (_ptime == 0) {
		switch(codec) {
		case CODEC_G711_ALAW:
			ptime = PTIME_G711_ALAW;
			break;
		case CODEC_G711_ULAW:
			ptime = PTIME_G711_ULAW;
			break;
		default:
			assert(false);
		}
	} else {
		ptime = _ptime;
	}

	sample_buf = new unsigned char[SAMPLE_BUF_SIZE];
	MEMMAN_NEW_ARRAY(sample_buf);

	// Determine payload size
	if (codec == CODEC_GSM) {
		gsm_encoder = gsm_create();
		payload_size = 33;
	} else {
		payload_size = AUDIO_SAMPLE_RATE/1000 * ptime;
	}

	payload = new unsigned char[payload_size];
	MEMMAN_NEW_ARRAY(payload);
	nsamples = AUDIO_SAMPLE_RATE/1000 * ptime;

	// Initialize 3-way settings to 'null'
	media_3way_peer_tx = NULL;
	media_3way_peer_rx = NULL;
	peer_rx_3way = NULL;
	mix_buf_3way = NULL;
	is_3way = false;
	is_main_rx_3way = false;
}

t_audio_rx::~t_audio_rx() {
	struct timespec sleeptimer;

	if (is_running) {
		stop_running = true;
		do {
			sleeptimer.tv_sec = 0;
			sleeptimer.tv_nsec = 10000000;
			nanosleep(&sleeptimer, NULL);
		} while (is_running);
	}

	MEMMAN_DELETE_ARRAY(sample_buf);
	delete [] sample_buf;
	MEMMAN_DELETE_ARRAY(payload);
	delete [] payload;

	// Clean up resources for the GSM codec.
	if (codec == CODEC_GSM) gsm_destroy(gsm_encoder);

	// Clean up resources for 3-way conference calls
	if (media_3way_peer_tx) {
		MEMMAN_DELETE(media_3way_peer_tx);
		delete media_3way_peer_tx;
	}
	if (media_3way_peer_rx) {
		MEMMAN_DELETE(media_3way_peer_rx);
		delete media_3way_peer_rx;
	}
	if (mix_buf_3way) {
		MEMMAN_DELETE_ARRAY(mix_buf_3way);
		delete [] mix_buf_3way;
	}
}

void t_audio_rx::set_running(bool running) {
	is_running = running;
}

void t_audio_rx::run(void) {
	int status;
	struct timespec sleeptimer;
	struct timeval debug_timer;

	// The running flag is set already in t_audio_session::run to prevent
	// a crash when the thread gets destroyed before it starts running.
	// is_running = true;

	// For a 3-way conference only the main receiver has access
	// to the dsp.
	if (!is_3way || is_main_rx_3way) {
		// Enable recording
		if (sys_config->equal_audio_dev(sys_config->dev_speaker, sys_config->dev_mic)) {
			input_device->enable(true, true);
		} else {
			input_device->enable(false, true);
		}

		// If the stream is stopped for call-hold, then the buffer might
		// be filled with old sound samples.
		input_device->flush(false, true);
	}

	// Synchronize the timestamp driven by the sampling rate
	// of the recording with the timestamp of the RTP session.
	// As the RTP session is already created in advance, the
	// RTP clock is a bit ahead already.
	timestamp = rtp_session->getCurrentTimestamp() + nsamples;

	// The nobreak_count will count how many times the loop below cycles
	// without taking a real time break.
	// TODO: this is not used anymore. Can be removed in the future if note needed.
	nobreak_count = 0;

	while (true) {
		if (stop_running) break;

		// If we are in a tight loop for more than ptime msecs then
		// something must be wrong. For some reason no data is coming
		// from the soundcard anymore.
		if (nobreak_count > ptime) {
			log_file->write_header("t_audio_rx::run");
			log_file->write_raw("Audio rx line ");
			log_file->write_raw(get_line()->get_line_number()+1);
			log_file->write_raw(": tight loop detected.\n");
			log_file->write_footer();
			break;
		}

		if (dtmf_playing) {
			rtp_session->setMark(false);
			get_dtmf_payload();
		} else if (get_dtmf_event()) {
			// RFC 2833
			// Set marker in first RTP packet of a DTMF event
			rtp_session->setMark(true);
			get_dtmf_payload();
		} else if (get_sound_samples()) {
			rtp_session->setMark(false);
		} else {
			continue;
		}

		// If timestamp is more than 1 payload size ahead of the clock of
		// the ccRTP stack, then drop the current payload and do not advance
		// the timestamp. This will happen if the DSP delivers more
		// sound samples than the set sample rate. To compensate for this
		// samples must be dropped.
		if (timestamp <= rtp_session->getCurrentTimestamp() + nsamples) {
			if (dtmf_playing) {
				// Send DTMF payload
				rtp_session->putData(dtmf_timestamp, payload,
							sizeof(t_rtp_telephone_event));

				// If DTMF has ended then set payload back to sound
				if (dtmf_stop) {
					set_sound_payload_format();
					dtmf_playing = false;
					dtmf_stop = false;
				}
			} else {
				// Send sound samples
				// Set the expire timeout to the jitter buffer size.
				// This allows for old packets still to be sent out.
				rtp_session->setExpireTimeout(MAX_OUT_AUDIO_DELAY_MS * 1000);
				rtp_session->putData(timestamp, payload, payload_size);
			}

			timestamp += nsamples;
		} else {
			log_file->write_header("t_audio_rx::run", LOG_NORMAL, LOG_DEBUG);
			log_file->write_raw("Audio rx line ");
			log_file->write_raw(get_line()->get_line_number()+1);
			log_file->write_raw(": discarded surplus of sound samples.\n");
			log_file->write_footer();
		}

		// If there is enough data in the DSP buffers to fill another
		// RTP packet then do not sleep, but immediately go to the
		// next cycle to play out the data. Probably this thread did
		// not get enough time, so the buffer filled up. The far end
		// jitter buffer has to cope with the jitter caused by this.
		if (is_3way && !is_main_rx_3way) {
			if (media_3way_peer_rx->size_content() >= SAMPLE_BUF_SIZE) {
				continue;
			}
		} else {
			if (input_device->get_buffer_space(true) >= SAMPLE_BUF_SIZE) continue;
		}

		// There is no data left in the DSP buffers to play out anymore.
		// So the timestamp must be in sync with the clock of the ccRTP
		// stack. It might get behind if the sound cards samples a bit
		// slower than the set sample rate. Advance the timestamp to get
		// in sync again.
		if (timestamp <= rtp_session->getCurrentTimestamp() - 
			(JITTER_BUF_MS / ptime) * nsamples)
		{
			timestamp += nsamples * (JITTER_BUF_MS / ptime);
			log_file->write_header("t_audio_rx::run", LOG_NORMAL, LOG_DEBUG);
			log_file->write_raw("Audio rx line ");
			log_file->write_raw(get_line()->get_line_number()+1);
			log_file->write_raw(": timestamp forwarded by ");
			log_file->write_raw(nsamples * (JITTER_BUF_MS / ptime));
			log_file->write_endl();
			log_file->write_footer();
		}			
	}

	is_running = false;
}

void t_audio_rx::set_pt_telephone_event(int pt) {
	pt_telephone_event = pt;
}

void t_audio_rx::push_dtmf(char digit) {
	// Ignore invalid DTMF digits
	if (!VALID_DTMF_SYM(digit)) return;

	// Ignore if DTMF tones are not supported for this session
	if (pt_telephone_event < 0) {
		ui->cb_dtmf_not_supported(get_line()->get_line_number());
		return;
	}

	// Ignore DTMF tones in a 3-way conference
	if (is_3way) return;

	char dtmf_ev = char2dtmf_ev(digit);

	mtx_dtmf_q.lock();
	dtmf_queue.push(dtmf_ev);
	mtx_dtmf_q.unlock();
	sema_dtmf_q.up();
}

t_line *t_audio_rx::get_line(void) const {
	return audio_session->get_line();
}

void t_audio_rx::join_3way(bool main_rx, t_audio_rx *peer_rx) {
	mtx_3way.lock();

	if (is_3way) {
		log_file->write_header("t_audio_rx::join_3way", LOG_NORMAL);
		log_file->write_raw("ERROR: audio rx line ");
		log_file->write_raw(get_line()->get_line_number()+1);
		log_file->write_raw(" - 3way is already active.\n");
		log_file->write_footer();
		mtx_3way.unlock();
		return;
	}

	// Logging
	log_file->write_header("t_audio_rx::join_3way");
	log_file->write_raw("Audio rx line ");
	log_file->write_raw(get_line()->get_line_number()+1);
	log_file->write_raw(": join 3-way.\n");
	if (main_rx) {
		log_file->write_raw("Role is: mixer.\n");
	} else {
		log_file->write_raw("Role is: non-mixing.\n");
	}
	if (peer_rx) {
		log_file->write_raw("A peer receiver already exists.\n");
	} else {
		log_file->write_raw("A peer receiver does not exist.\n");
	}
	log_file->write_footer();

	// Create media buffers for the 2 far-ends of a 3-way call.
	// The size of the media buffer is the size of the jitter buffer.
	// This allows for jitter in the RTP streams and also for
	// incompatible payload sizes. Eg. 1 far-end may send 20ms paylaods,
	// while the other sends 30ms payloads. The outgoing RTP stream might
	// even have another payload size.
	// When the data has been captured from the soundcard, it will be
	// checked if there is enough data available in the media buffers, i.e.
	// the same amount of data as captured from the soundcard for mixing.
	// If there is it will be retrieved and mixed.
	// If there isn't the captured sound will simply be sent on its own
	// to the far-end. Meanwhile the buffer will fill up with data such
	// that from the next captured sample there will be sufficient data
	// for mixing.
	media_3way_peer_tx = new t_media_buffer(JITTER_BUF_SIZE);
	MEMMAN_NEW(media_3way_peer_tx);
	media_3way_peer_rx = new t_media_buffer(JITTER_BUF_SIZE);
	MEMMAN_NEW(media_3way_peer_rx);

	// Create a mix buffer for one sample frame.
	mix_buf_3way = new unsigned char[SAMPLE_BUF_SIZE];
	MEMMAN_NEW_ARRAY(mix_buf_3way);

	peer_rx_3way = peer_rx;

	is_3way = true;
	is_main_rx_3way = main_rx;

	// Stop DTMF tones as these are not supported in a 3way
	dtmf_playing = false;

	mtx_3way.unlock();
}

void t_audio_rx::set_peer_rx_3way(t_audio_rx *peer_rx) {
	mtx_3way.lock();

	if (!is_3way) {
		mtx_3way.unlock();
		return;
	}

	// Logging
	log_file->write_header("t_audio_rx::set_peer_rx_3way");
	log_file->write_raw("Audio rx line ");
	log_file->write_raw(get_line()->get_line_number()+1);
	if (peer_rx) {
		log_file->write_raw(": set peer receiver.\n");
	} else {
		log_file->write_raw(": erase peer receiver.\n");
	}
	if (is_main_rx_3way) {
		log_file->write_raw("Role is: mixer.\n");
	} else {
		log_file->write_raw("Role is: non-mixing.\n");
	}
	log_file->write_footer();

	peer_rx_3way = peer_rx;

	mtx_3way.unlock();
}

void t_audio_rx::set_main_rx_3way(bool main_rx) {
	mtx_3way.lock();

	if (!is_3way) {
		mtx_3way.unlock();
		return;
	}

	// Logging
	log_file->write_header("t_audio_rx::set_main_rx_3way");
	log_file->write_raw("Audio rx line ");
	log_file->write_raw(get_line()->get_line_number()+1);
	if (main_rx) {
		log_file->write_raw(": change role to: mixer.\n");
	} else {
		log_file->write_raw(": change role to: non-mixing.\n");
	}
	log_file->write_footer();


	// Initialize the DSP if we become the mixer and we were not before
	if (main_rx && !is_main_rx_3way) {		
		// Enable recording
		int arg;
		if (sys_config->equal_audio_dev(sys_config->dev_speaker, sys_config->dev_mic)) {
			input_device->enable(true, true);
		} else {
			input_device->enable(false, true);
		}

		// If the stream is stopped for call-hold, then the buffer might
		// be filled with old sound samples.
		input_device->flush(false, true);
	}

	is_main_rx_3way = main_rx;

	mtx_3way.unlock();
}

void t_audio_rx::stop_3way(void) {
	mtx_3way.lock();

	if (!is_3way) {
		log_file->write_header("t_audio_rx::stop_3way");
		log_file->write_raw("ERROR: audio rx line ");
		log_file->write_raw(get_line()->get_line_number()+1);
		log_file->write_raw(" - 3way is not active.\n");
		log_file->write_footer();
		mtx_3way.unlock();
		return;
	}

	// Logging
	log_file->write_header("t_audio_rx::stop_3way");
	log_file->write_raw("Audio rx line ");
	log_file->write_raw(get_line()->get_line_number()+1);
	log_file->write_raw(": stop 3-way.");
	log_file->write_footer();

	is_3way = false;
	is_main_rx_3way = false;

	peer_rx_3way = NULL;

	MEMMAN_DELETE(media_3way_peer_tx);
	delete media_3way_peer_tx;
	media_3way_peer_tx = NULL;
	MEMMAN_DELETE(media_3way_peer_rx);
	delete media_3way_peer_rx;
	media_3way_peer_rx = NULL;
	MEMMAN_DELETE_ARRAY(mix_buf_3way);
	delete [] mix_buf_3way;
	mix_buf_3way = NULL;

	mtx_3way.unlock();
}

void t_audio_rx::post_media_peer_tx_3way(unsigned char *media, int len) {
	mtx_3way.lock();

	if (!is_3way) {
		// This is not a 3-way call. This is not necessarily an
		// error condition. The 3rd party may be in the process of
		// leaving the conference.
		// Simply discard the posted media
		mtx_3way.unlock();
		return;
	}

	media_3way_peer_tx->add(media, len);

	mtx_3way.unlock();
}

void t_audio_rx::post_media_peer_rx_3way(unsigned char *media, int len) {
	mtx_3way.lock();

	if (!is_3way) {
		// This is not a 3-way call. This is not necessarily an
		// error condition. The 3rd party may be in the process of
		// leaving the conference.
		// Simply discard the posted media
		mtx_3way.unlock();
		return;
	}

	media_3way_peer_rx->add(media, len);

	mtx_3way.unlock();
}

bool t_audio_rx::get_is_main_rx_3way(void) const {
	return is_main_rx_3way;
}
