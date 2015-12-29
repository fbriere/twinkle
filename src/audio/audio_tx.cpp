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

#include <assert.h>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <sys/types.h>
#include <sys/time.h>
#include "audio_tx.h"
#include "log.h"
#include "phone.h"
#include "userintf.h"
#include "line.h"
#include "audits/memman.h"

extern t_phone *phone;

#define SAMPLE_BUF_SIZE (MAX_PTIME * sc_sample_rate/1000 * AUDIO_SAMPLE_SIZE/8)

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

short t_audio_tx::decode(unsigned char sample) {
	switch(codec) {
	case CODEC_G711_ALAW:
		return (short)alaw2linear(sample);
	case CODEC_G711_ULAW:
		return (short)ulaw2linear(sample);
	default:
		assert(false);
	}
}

//////////
// PUBLIC
//////////

t_audio_tx::t_audio_tx(t_audio_session *_audio_session,
		   t_audio_io *_playback_device, t_twinkle_rtp_session *_rtp_session,
	           t_audio_codec _codec, 
	           const map<unsigned short, t_audio_codec> &_payload2codec,
	           unsigned short _ptime)
{
	audio_session = _audio_session;
	
	user_config = audio_session->get_line()->get_user();
	assert(user_config);
	
	playback_device = _playback_device;
	rtp_session = _rtp_session;
	codec = _codec;
	sc_sample_rate = audio_sample_rate(_codec);
	payload2codec = _payload2codec;
	is_running = false;
	stop_running = false;
	
	// Create GSM decoder
	gsm_decoder = gsm_create();
	
#ifdef HAVE_SPEEX
	// Create speex decoder
	speex_bits_init(&speex_nb_bits);
	speex_bits_init(&speex_wb_bits);
	speex_bits_init(&speex_uwb_bits);
	speex_nb_dec_state = speex_decoder_init(&speex_nb_mode);
	speex_wb_dec_state = speex_decoder_init(&speex_wb_mode);
	speex_uwb_dec_state = speex_decoder_init(&speex_uwb_mode);
	
	// Initialize decoder with user settings
	int arg = (user_config->speex_penh ? 1 : 0);
	speex_decoder_ctl(speex_nb_dec_state, SPEEX_SET_ENH, &arg);
	speex_decoder_ctl(speex_wb_dec_state, SPEEX_SET_ENH, &arg);
	speex_decoder_ctl(speex_uwb_dec_state, SPEEX_SET_ENH, &arg);
#endif

	// Determine the expected ptime. The ptime of received packets
	// might differ.
#ifdef HAVE_SPEEX
	int speex_frame_size;
#endif
	
	switch(codec) {
	case CODEC_G711_ALAW:
		if (_ptime == 0) {
			ptime = PTIME_G711_ALAW;
		} else {
			ptime = _ptime;
		}
		break;
	case CODEC_G711_ULAW:
		if (_ptime == 0) {
			ptime = PTIME_G711_ULAW;
		} else {
			ptime = _ptime;
		}
		break;	
	case CODEC_GSM:
		// GSM has fixed ptime
		ptime = PTIME_GSM;
		break;
#ifdef HAVE_SPEEX
	case CODEC_SPEEX_NB:
		speex_decoder_ctl(speex_nb_dec_state, SPEEX_GET_FRAME_SIZE, 
				&speex_frame_size);
		ptime = speex_frame_size / (audio_sample_rate(codec) / 1000);
		break;
	case CODEC_SPEEX_WB:
		speex_decoder_ctl(speex_wb_dec_state, SPEEX_GET_FRAME_SIZE, 
				&speex_frame_size);
		ptime = speex_frame_size / (audio_sample_rate(codec) / 1000);
		break;
	case CODEC_SPEEX_UWB:
		speex_decoder_ctl(speex_uwb_dec_state, SPEEX_GET_FRAME_SIZE, 
				&speex_frame_size);
		ptime = speex_frame_size / (audio_sample_rate(codec) / 1000);
		break;
#endif
	default:
		assert(false);
	}

	sample_buf = new unsigned char[SAMPLE_BUF_SIZE];
	MEMMAN_NEW_ARRAY(sample_buf);

	// Create concealment buffers
	for (int i = 0; i < MAX_CONCEALMENT; i++) {
		conceal_buf[i] = new unsigned char[SAMPLE_BUF_SIZE];
		MEMMAN_NEW_ARRAY(conceal_buf[i]);
		conceal_buflen[i] = 0;
	}
	conceal_num = 0;
	conceal_pos = 0;

	// Initialize jitter buffer
	jitter_buf = new unsigned char[JITTER_BUF_SIZE(sc_sample_rate)];
	MEMMAN_NEW_ARRAY(jitter_buf);
	jitter_buf_len = 0;
	load_jitter_buf = true;
	soundcard_buf_size = playback_device->get_buffer_size(false);

	// Initialize 3-way settings
	is_3way = false;
	is_3way_mixer = false;
	media_3way_peer_tx = NULL;
	peer_tx_3way = NULL;
	peer_rx_3way = NULL;
	mix_buf_3way = NULL;
	
	// Initialize telephone event settings
	pt_telephone_event = -1;
	pt_telephone_event_alt = 1;
}

t_audio_tx::~t_audio_tx() {
	struct timespec sleeptimer;
	
	if (is_running) {
		stop_running = true;
		do {
			sleeptimer.tv_sec = 0;
			sleeptimer.tv_nsec = 10000000;
			nanosleep(&sleeptimer, NULL);
			continue;
		} while (is_running);
	}

	MEMMAN_DELETE_ARRAY(sample_buf);
	delete [] sample_buf;
	MEMMAN_DELETE_ARRAY(jitter_buf);
	delete [] jitter_buf;

	for (int i = 0; i < MAX_CONCEALMENT; i++) {
		MEMMAN_DELETE_ARRAY(conceal_buf[i]);
		delete [] conceal_buf[i];
	}

	// Destroy GSM decoder
	gsm_destroy(gsm_decoder);
	
#ifdef HAVE_SPEEX
	// Destroy speex decoder
	speex_bits_destroy(&speex_nb_bits);
	speex_bits_destroy(&speex_wb_bits);
	speex_bits_destroy(&speex_uwb_bits);
	speex_decoder_destroy(speex_nb_dec_state);
	speex_decoder_destroy(speex_wb_dec_state);
	speex_decoder_destroy(speex_uwb_dec_state);
#endif

	// Cleanup 3-way resources
	if (media_3way_peer_tx) {
		MEMMAN_DELETE(media_3way_peer_tx);
		delete media_3way_peer_tx;
	}
	if (mix_buf_3way) {
		MEMMAN_DELETE_ARRAY(mix_buf_3way);
		delete [] mix_buf_3way;
	}
}

void t_audio_tx::retain_for_concealment(unsigned char *buf, unsigned short len) {
	if (conceal_num == 0) {
		memcpy(conceal_buf[0], buf, len);
		conceal_buflen[0] = len;
		conceal_num = 1;
		conceal_pos = 0;
		return;
	}

	if (conceal_num < MAX_CONCEALMENT) {
		memcpy(conceal_buf[conceal_num], buf, len);
		conceal_buflen[conceal_num] = len;
		conceal_num++;
		return;
	}

	memcpy(conceal_buf[conceal_pos], buf, len);
	conceal_buflen[conceal_pos] = len;
	conceal_pos = (conceal_pos + 1) % MAX_CONCEALMENT;
}

void t_audio_tx::conceal(short num) {
#ifdef HAVE_SPEEX
	// The speex codec has a PLC algorithm itself
	// Only use this PLC is the sound card sample rate equals the codec
	// sample rate. If they differ, then we should resample the speex
	// samples. As this should be a rare case, we are lazy here. In
	// this rare case, use Twinkle's low-tech PLC.
	if (is_speex_codec(codec) && audio_sample_rate(codec) == sc_sample_rate) {
		short *sb = (short *)sample_buf;
		for (int i = 0; i < num; i++) {
			int speex_frame_size;
			int retval;
			
			switch(codec) {
			case CODEC_SPEEX_NB:
				retval = speex_decode_int(speex_nb_dec_state, NULL, sb);
				if (retval < 0) {
					LOG_SPEEX_ERROR("t_audio_tx::conceal", 
						"speex_decode_int", retval);
				}
				speex_decoder_ctl(speex_nb_dec_state, SPEEX_GET_FRAME_SIZE, 
					&speex_frame_size);
				break;
			case CODEC_SPEEX_WB:
				retval = speex_decode_int(speex_wb_dec_state, NULL, sb);
				if (retval < 0) {
					LOG_SPEEX_ERROR("t_audio_tx::conceal", 
						"speex_decode_int", retval);
				}
				speex_decoder_ctl(speex_wb_dec_state, SPEEX_GET_FRAME_SIZE, 
					&speex_frame_size);
				break;
			case CODEC_SPEEX_UWB:
				retval = speex_decode_int(speex_uwb_dec_state, NULL, sb);
				if (retval < 0) {
					LOG_SPEEX_ERROR("t_audio_tx::conceal", 
						"speex_decode_int", retval);
				}
				speex_decoder_ctl(speex_uwb_dec_state, SPEEX_GET_FRAME_SIZE, 
					&speex_frame_size);
				break;
			default:
				assert(false);
			}

			play_pcm(sample_buf, speex_frame_size * 2);
		}
		
		return;
	}
#endif

	// Replay previous packets for other codecs
	short i = (conceal_pos + (MAX_CONCEALMENT - num)) % MAX_CONCEALMENT;

	if (i >= conceal_pos) {
		for (int j = i; j < MAX_CONCEALMENT; j++) {
			play_pcm(conceal_buf[j], conceal_buflen[j]);
		}

		for (int j = 0; j < conceal_pos; j++) {
			play_pcm(conceal_buf[j], conceal_buflen[j]);
		}
	} else {
		for (int j = i; j < conceal_pos; j++) {
			play_pcm(conceal_buf[j], conceal_buflen[j]);
		}
	}
}

void t_audio_tx::clear_conceal_buf(void) {
	conceal_pos = 0;
	conceal_num = 0;
}

void t_audio_tx::play_pcm(unsigned char *buf, unsigned short len, bool only_3rd_party) {
	int status;
	struct timeval debug_timer;

	unsigned char *playbuf = buf;

	// If there is only sound from the 3rd party in a 3-way, then check
	// if there is still enough sound in the buffer of the DSP to be
	// played. If not, then play out the sound from the 3rd party only.
	if (only_3rd_party) {
		if (playback_device->get_buffer_space(false) < soundcard_buf_size - len) {
			// There is still sound in the DSP buffers to be
			// played, so let's wait. Maybe in the next cycle
			// an RTP packet from the far-end will be received.
			return;
		}
	}

	// If we are in a 3-way then send the samples to the peer audio
	// receiver for mixing
	if (!only_3rd_party && is_3way && peer_rx_3way) {
		peer_rx_3way->post_media_peer_tx_3way(buf, len, sc_sample_rate);
	}

	// If we are in a 3-way conference and we are not the mixer then
	// send the sound samples to the mixer
	if (is_3way && !is_3way_mixer) {
		if (peer_tx_3way) {
			peer_tx_3way->post_media_peer_tx_3way(buf, len, sc_sample_rate);
			return;
		} else {
			// There is no peer.
			return;
		}
	}

	// Mix audio for 3-way conference
	if (is_3way && is_3way_mixer) {
		if (media_3way_peer_tx->get(mix_buf_3way, len)) {
			short *mix_sb = (short *)mix_buf_3way;
			short *sb = (short *)buf;
			for (int i = 0; i < len / 2; i++) {
				mix_sb[i] = mix_linear_pcm(sb[i], mix_sb[i]);
			}

			playbuf = mix_buf_3way;
		}
	}

	// Fill jitter buffer before playing
	if (load_jitter_buf) {
		if (jitter_buf_len + len < JITTER_BUF_SIZE(sc_sample_rate)) {
			memcpy(jitter_buf + jitter_buf_len, playbuf, len);
			jitter_buf_len += len;
		} else {
			// Write the contents of the jitter buffer to the DSP.
			// The buffers in the DSP will now function as jitter
			// buffer.
			status = playback_device->write(jitter_buf, jitter_buf_len);
			if (status != jitter_buf_len) {
				string msg("Writing to dsp failed: ");
				msg += strerror(errno);
				log_file->write_report(msg, "t_audio_tx::play_pcm",
					LOG_NORMAL, LOG_CRITICAL);
			}

			// Write passed sound samples to DSP.
			status = playback_device->write(playbuf, len);
			if (status != len) {
				string msg("Writing to dsp failed: ");
				msg += strerror(errno);
				log_file->write_report(msg, "t_audio_tx::play_pcm",
					LOG_NORMAL, LOG_CRITICAL);
			}

			load_jitter_buf = false;
		}

		return;
	}

	// If buffer on soundcard is empty, then the jitter buffer needs
	// to be refilled. This should only occur when no RTP packets
	// have been received for a while (silence suppression or packet loss)
	int bufferspace = playback_device->get_buffer_space(false);
	if (bufferspace == soundcard_buf_size && len <= JITTER_BUF_SIZE(sc_sample_rate)) {
		memcpy(jitter_buf, playbuf, len);
		jitter_buf_len = len;
		load_jitter_buf = true;
		log_file->write_header("t_audio_tx::play_pcm", LOG_NORMAL, LOG_DEBUG);
		log_file->write_raw("Audio tx line ");
		log_file->write_raw(get_line()->get_line_number()+1);
		log_file->write_raw(": jitter buffer empy.\n");
		log_file->write_footer();
		return;
	}

	// If the play-out buffer contains the maximum number of
	// packets then start skipping packets to prevent
	// unacceptable delay.
	// This can only happen if the thread did not get
	// processing time for a while and RTP packets start to
	// pile up.
	// Or if a soundcard plays out the samples at just less then
	// the requested sample rate.
	/* Not needed anymore, the ::run loop already discards incoming RTP packets
	   with a late timestamp. This seems to solve the slow soundcard problem
	   better. The solution below caused annoying ticks in the playout.
	   
	if (soundcard_buf_size - bufferspace > JITTER_BUF_SIZE + len) {
		log_file->write_header("t_audio_tx::play_pcm", LOG_NORMAL, LOG_DEBUG);
		log_file->write_raw("Audio tx line ");
		log_file->write_raw(get_line()->get_line_number()+1);
		log_file->write_raw(": jitter buffer overflow: ");
		log_file->write_raw(bufferspace);
		log_file->write_raw(" bytes.\n");
		log_file->write_footer();
		return;
	}
	*/

	// Write passed sound samples to DSP.
	status = playback_device->write(playbuf, len);
	if (status != len) {
		string msg("Writing to dsp failed: ");
		msg += strerror(errno);
		log_file->write_report(msg, "t_audio_tx::play_pcm",
			LOG_NORMAL, LOG_CRITICAL);
	}
}

void t_audio_tx::set_running(bool running) {
	is_running = running;
}

void t_audio_tx::run(void) {
	const AppDataUnit* adu;
	struct timespec sleeptimer;
	struct timeval debug_timer;
	int last_seqnum = -1; // seqnum of last received RTP packet
	bool recvd_dtmf = false; // indicates if last RTP packets is a DTMF event

	// The running flag is set already in t_audio_session::run to prevent
	// a crash when the thread gets destroyed before it starts running.
	// is_running = true;

	unsigned long rtp_timestamp;
	
	// This thread may not take the lock on the transaction layer to
	// prevent dead locks
	phone->add_prohibited_thread();
	ui->add_prohibited_thread();
	
	while (true) {
		do {
			adu = NULL;
			if (stop_running) break;
			rtp_timestamp = rtp_session->getFirstTimestamp();
			adu = rtp_session->getData(
					rtp_session->getFirstTimestamp());
			if (adu == NULL || adu->getSize() <= 0) {
				// There is no packet available. This may have
				// several reasons:
				// - the thread scheduling granularity does
				//   not match ptime
				// - packet lost
				// - packet delayed
				// Wait another cycle for a packet. The
				// jitter buffer will cope with this variation.
				if (adu) {
					delete adu;
					adu = NULL;
				}

				// If we are the mixer in a 3-way call and there
				// is enough media from the other far-end then
				// this must be sent to the dsp.
				if (is_3way && is_3way_mixer &&
				    media_3way_peer_tx->size_content() >=
				    	ptime * (audio_sample_rate(codec) / 1000) * 2)
				{
					// Fill the sample buffer with silence
					int len = ptime * (audio_sample_rate(codec) / 1000);
					memset(sample_buf, 0, len);
					play_pcm(sample_buf, len, true);
				}

				// Sleep ptime ms
				sleeptimer.tv_sec = 0;

				if (ptime >= 20) {
					sleeptimer.tv_nsec =
						ptime * 1000000 - 10000000;
				} else {
					// With a thread schedule of 10ms
					// granularity, this will schedule the
					// thread every 10ms.
					sleeptimer.tv_nsec = 5000000;
				}
				nanosleep(&sleeptimer, NULL);
			}
		} while (adu == NULL || (adu->getSize() <= 0));
		
		if (stop_running) {
			if (adu) delete adu;
			break;
		}

		if (adu) {
			// adu is created by ccRTP, but we have to delete it,
			// so report it to MEMMAN
			MEMMAN_NEW(const_cast<ost::AppDataUnit*>(adu));
		}

		// Check for a codec change
		map<unsigned short, t_audio_codec>::const_iterator it_codec;
		it_codec = payload2codec.find(adu->getType());
		t_audio_codec recvd_codec = CODEC_NULL;
		if (it_codec != payload2codec.end()) {
			recvd_codec = it_codec->second;
		}

		switch(recvd_codec) {
		case CODEC_G711_ULAW:
		case CODEC_G711_ALAW:
		case CODEC_GSM:
		case CODEC_SPEEX_NB:
		case CODEC_SPEEX_WB:
		case CODEC_SPEEX_UWB:
			if (codec != recvd_codec) {
				codec = recvd_codec;
				get_line()->ci_set_recv_codec(codec);
				ui->cb_async_recv_codec_changed(get_line()->get_line_number(),
					codec);

				log_file->write_header("t_audio_tx::run", 
					LOG_NORMAL, LOG_DEBUG);
				log_file->write_raw("Audio tx line ");
				log_file->write_raw(get_line()->get_line_number()+1);
				log_file->write_raw(": codec change to ");
				log_file->write_raw(ui->format_codec(codec));
				log_file->write_endl();
				log_file->write_footer();
			}
			break;
		default:
			if (adu->getType() == pt_telephone_event ||
			    adu->getType() == pt_telephone_event_alt) 
			{
				recvd_dtmf = true;
				break;
			}

			if (codec != CODEC_UNSUPPORTED) {
				codec = CODEC_UNSUPPORTED;
				get_line()->ci_set_recv_codec(codec);
				ui->cb_async_recv_codec_changed(get_line()->get_line_number(),
					codec);

				log_file->write_header("t_audio_tx::run", 
					LOG_NORMAL, LOG_DEBUG);
				log_file->write_raw("Audio tx line ");
				log_file->write_raw(get_line()->get_line_number()+1);
				log_file->write_raw(": payload type ");
				log_file->write_raw(adu->getType());
				log_file->write_raw(" not supported\n");
				log_file->write_footer();
			}

			last_seqnum = adu->getSeqNum();
			MEMMAN_DELETE(const_cast<ost::AppDataUnit*>(adu));
			delete adu;
			continue;
			break;
		}

		// DTMF event
		if (recvd_dtmf) {
			// NOTE: the DTMF tone will be detected here
			// while there might still be data in the jitter
			// buffer. If the jitter buffer was already sent
			// to the DSP, then the DSP will continue to play
			// out the buffer sound samples.

			if (dtmf_previous_timestamp != rtp_timestamp) {
				// A new DTMF tone has been received.
				dtmf_previous_timestamp = rtp_timestamp;
				t_rtp_telephone_event *e =
					(t_rtp_telephone_event *)adu->getData();
				ui->cb_async_dtmf_detected(get_line()->get_line_number(),
					e->get_event());

				// Log DTMF event
				log_file->write_header("t_audio_tx::run");
				log_file->write_raw("Audio tx line ");
				log_file->write_raw(get_line()->get_line_number()+1);
				log_file->write_raw(": detected DTMF event - ");
				log_file->write_raw(e->get_event());
				log_file->write_endl();
				log_file->write_footer();
			}

			recvd_dtmf = false;
			last_seqnum = adu->getSeqNum();
			MEMMAN_DELETE(const_cast<ost::AppDataUnit*>(adu));
			delete adu;
			continue;
		}

		// Skip packet if the payload size is too big
		if ((codec == CODEC_G711_ALAW || codec == CODEC_G711_ULAW) &&
		    adu->getSize() > SAMPLE_BUF_SIZE / 2) 
		{
			log_file->write_header("t_audio_tx::run", LOG_NORMAL, LOG_DEBUG);
			log_file->write_raw("Audio tx line ");
			log_file->write_raw(get_line()->get_line_number()+1);
			log_file->write_raw(": RTP payload size (");
			log_file->write_raw((unsigned long)(adu->getSize()));
			log_file->write_raw(" bytes) exceeds maximum\n");
			log_file->write_footer();
			last_seqnum = adu->getSeqNum();
			MEMMAN_DELETE(const_cast<ost::AppDataUnit*>(adu));
			delete adu;
			continue;
		}
		
#ifdef HAVE_SPEEX
		int speex_frame_size;
#endif

		// Determine received ptime
		unsigned short recvd_ptime;
		switch(codec) {
		case CODEC_GSM:
			recvd_ptime = PTIME_GSM;
			break;
		case CODEC_G711_ULAW:
		case CODEC_G711_ALAW:
			recvd_ptime = adu->getSize() / (audio_sample_rate(codec) / 1000);
			break;
#ifdef HAVE_SPEEX
		case CODEC_SPEEX_NB:
			speex_decoder_ctl(speex_nb_dec_state, SPEEX_GET_FRAME_SIZE, 
					&speex_frame_size);
			recvd_ptime = speex_frame_size / (audio_sample_rate(codec) / 1000);
			break;
		case CODEC_SPEEX_WB:
			speex_decoder_ctl(speex_wb_dec_state, SPEEX_GET_FRAME_SIZE, 
					&speex_frame_size);
			recvd_ptime = speex_frame_size / (audio_sample_rate(codec) / 1000);
			break;
		case CODEC_SPEEX_UWB:
			speex_decoder_ctl(speex_uwb_dec_state, SPEEX_GET_FRAME_SIZE, 
					&speex_frame_size);
			recvd_ptime = speex_frame_size / (audio_sample_rate(codec) / 1000);
			break;
#endif	
		default:
			assert(false);
		}

		// Log a change of ptime
		if (ptime != recvd_ptime) {
			log_file->write_header("t_audio_tx::run", LOG_NORMAL, LOG_DEBUG);
			log_file->write_raw("Audio tx line ");
			log_file->write_raw(get_line()->get_line_number()+1);
			log_file->write_raw(": ptime changed from ");
			log_file->write_raw(ptime);
			log_file->write_raw(" ms to ");
			log_file->write_raw(recvd_ptime);
			log_file->write_raw(" ms\n");
			log_file->write_footer();
			ptime = recvd_ptime;
		}

		// Discard invalid GSM payload sizes
		if (codec == CODEC_GSM && adu->getSize() != 33) {
			log_file->write_header("t_audio_tx::run", LOG_NORMAL, LOG_DEBUG);
			log_file->write_raw("Audio tx line ");
			log_file->write_raw(get_line()->get_line_number()+1);
			log_file->write_raw(": invalid GSM payload size: ");
			log_file->write_raw((unsigned long)(adu->getSize()));
			log_file->write_endl();
			log_file->write_footer();
			last_seqnum = adu->getSeqNum();
			MEMMAN_DELETE(const_cast<ost::AppDataUnit*>(adu));
			delete adu;
			continue;
		}
		
		// Check for lost packets
		// This must be done before decoding the received samples as the
		// speex decoder has its own PLC algorithm for which it needs the decoding
		// state before decoding the new samples.
		if (adu->getSeqNum() != (last_seqnum + 1) % 65536 && last_seqnum != -1) {
			// Packets have been lost
			int num_lost = adu->getSeqNum() - last_seqnum - 1;
			if (num_lost < 0) num_lost += 65536; // seqnum wrapped around

			log_file->write_header("t_audio_tx::run", LOG_NORMAL, LOG_DEBUG);
			log_file->write_raw("Audio tx line ");
			log_file->write_raw(get_line()->get_line_number()+1);
			log_file->write_raw(": ");
			log_file->write_raw(num_lost);
			log_file->write_raw(" RTP packets lost.\n");
			log_file->write_footer();

			if (num_lost <= conceal_num) {
				// Conceal packet loss
				conceal(num_lost);
			}
			clear_conceal_buf();
		}
		
		// Determine if resampling is needed due to dynamic change to
		// codec with other sample rate.
		short downsample_factor = 1;
		short upsample_factor = 1;
		if (audio_sample_rate(codec) > sc_sample_rate) {
			downsample_factor = audio_sample_rate(codec) / sc_sample_rate;
		} else if (audio_sample_rate(codec) < sc_sample_rate) {
			upsample_factor = sc_sample_rate / audio_sample_rate(codec);
		}
		
		// Create sample buffer. If no resampling is needed, the sample
		// buffer from the audio_tx object can be used directly.
		// Otherwise a temporary sample buffers is created that will
		// be resampled to the object's sample buffer later.
		short *sb;
		if (downsample_factor > 1) {
			sb = new short[SAMPLE_BUF_SIZE / 2 * downsample_factor];
			MEMMAN_NEW_ARRAY(sb);
		} else if (upsample_factor > 1) {
			sb = new short[SAMPLE_BUF_SIZE / 2];
			MEMMAN_NEW_ARRAY(sb);
		} else {
			sb = (short *)sample_buf;
		}
				
		// Decode the audio
		unsigned char *payload = const_cast<uint8 *>(adu->getData());
		short sample_size;
		int retval;
		bool decode_failed = false;
		switch (codec) {
		case CODEC_G711_ALAW:
		case CODEC_G711_ULAW:
			for (int i = 0; i < adu->getSize(); i++) {
				sb[i] = decode(payload[i]);
			}
			sample_size = adu->getSize() * 2;
			break;
		case CODEC_GSM:
			gsm_decode(gsm_decoder, payload, sb);
			sample_size = 320; // 160 2-byte samples
			break;
#ifdef HAVE_SPEEX
		case CODEC_SPEEX_NB:
			speex_bits_read_from(&speex_nb_bits, (char *)payload, adu->getSize());
			retval = speex_decode_int(speex_nb_dec_state, &speex_nb_bits, sb);
			if (retval < 0) {
				LOG_SPEEX_ERROR("t_audio_tx::run",  
					"speex_decode_int", retval);
				decode_failed = true;
			}
			sample_size = speex_frame_size * 2;
			break;
		case CODEC_SPEEX_WB:
			speex_bits_read_from(&speex_wb_bits, (char *)payload, adu->getSize());
			retval = speex_decode_int(speex_wb_dec_state, &speex_wb_bits, sb);
			if (retval < 0) {
				LOG_SPEEX_ERROR("t_audio_tx::run", 
					"speex_decode_int", retval);
				decode_failed = true;
			}
			sample_size = speex_frame_size * 2;
			break;
		case CODEC_SPEEX_UWB:
			speex_bits_read_from(&speex_uwb_bits, (char *)payload, adu->getSize());
			retval = speex_decode_int(speex_uwb_dec_state, &speex_uwb_bits, sb);
			if (retval < 0) {
				LOG_SPEEX_ERROR("t_audio_tx::run", 
					"speex_decode_int", retval);
				decode_failed = true;
			}
			sample_size = speex_frame_size * 2;
			break;
#endif
		default:
			assert(false);
		}
		
		if (decode_failed) {
			last_seqnum = adu->getSeqNum();
			MEMMAN_DELETE(const_cast<ost::AppDataUnit*>(adu));
			delete adu;
			continue;
		}
		
		// Resample if needed
		if (downsample_factor > 1) {
			short *p = sb;
			sb = (short *)sample_buf;
			for (int i = 0; i < sample_size / 2; i += downsample_factor) {
				sb[i / downsample_factor] = p[i];
			}
			MEMMAN_DELETE_ARRAY(p);
			delete [] p;
			sample_size /= downsample_factor;
		} else if (upsample_factor > 1) {
			short *p = sb;
			sb = (short *)sample_buf;
			for (int i = 0; i < sample_size / 2; i++) {
				for (int j = 0; j < upsample_factor; j++) {
					sb[i * upsample_factor + j] = p[i];
				}
			}
			MEMMAN_DELETE_ARRAY(p);
			delete [] p;
			sample_size *= upsample_factor;
		}
		
		// Discard packet if we are lacking behind. This happens if the
		// soundcard plays at a rate less than the requested sample rate.
		if (rtp_session->isWaiting()) {
			uint32 last_ts = rtp_session->getLastTimestamp();
			uint32 diff;
			
			if (last_ts >= rtp_timestamp) {
				diff = last_ts - rtp_timestamp;
			} else {
				// Timestamp wrapped around
				diff = last_ts - rtp_timestamp + 2^64;
			}
			
			if (diff > (JITTER_BUF_SIZE(sc_sample_rate) / AUDIO_SAMPLE_SIZE) * 8)
			{
				log_file->write_header("t_audio_tx::run", LOG_NORMAL, LOG_DEBUG);
				log_file->write_raw("Audio tx line ");
				log_file->write_raw(get_line()->get_line_number()+1);
				log_file->write_raw(": discard delayed packet.\n");
				log_file->write_raw("Timestamp: ");
				log_file->write_raw(rtp_timestamp);
				log_file->write_raw(", Last timestamp: ");
				log_file->write_raw((long unsigned int)last_ts);
				log_file->write_endl();
				log_file->write_footer();
					
				last_seqnum = adu->getSeqNum();
				MEMMAN_DELETE(const_cast<ost::AppDataUnit*>(adu));
				delete adu;
				continue;
			}
		}

		play_pcm(sample_buf, sample_size);
		retain_for_concealment(sample_buf, sample_size);
		last_seqnum = adu->getSeqNum();
		MEMMAN_DELETE(const_cast<ost::AppDataUnit*>(adu));
		delete adu;

		// No sleep is done here but in the loop waiting
		// for a new packet. If a packet is already available
		// it can be send to the sound card immediately so
		// the play-out buffer keeps filled.
		// If the play-out buffer gets empty you hear a
		// crack in the sound.
	}

	phone->remove_prohibited_thread();
	ui->remove_prohibited_thread();
	is_running = false;
}

void t_audio_tx::set_pt_telephone_event(int pt, int pt_alt) {
	pt_telephone_event = pt;
	pt_telephone_event_alt = pt_alt;
}

t_line *t_audio_tx::get_line(void) const {
	return audio_session->get_line();
}

void t_audio_tx::join_3way(bool mixer, t_audio_tx *peer_tx, t_audio_rx *peer_rx) {
	mtx_3way.lock();

	if (is_3way) {
		log_file->write_header("t_audio_tx::join_3way");
		log_file->write_raw("ERROR: audio tx line ");
		log_file->write_raw(get_line()->get_line_number()+1);
		log_file->write_raw(" - 3way is already active.\n");
		log_file->write_footer();
		mtx_3way.unlock();
		return;
	}

	// Logging
	log_file->write_header("t_audio_tx::join_3way");
	log_file->write_raw("Audio tx line ");
	log_file->write_raw(get_line()->get_line_number()+1);
	log_file->write_raw(": join 3-way.\n");
	if (mixer) {
		log_file->write_raw("Role is: mixer.\n");
	} else {
		log_file->write_raw("Role is: non-mixing.\n");
	}
	if (peer_tx) {
		log_file->write_raw("A peer transmitter already exists.\n");
	} else {
		log_file->write_raw("A peer transmitter does not exist.\n");
	}
	if (peer_rx) {
		log_file->write_raw("A peer receiver already exists.\n");
	} else {
		log_file->write_raw("A peer receiver does not exist.\n");
	}
	log_file->write_footer();

	peer_tx_3way = peer_tx;
	peer_rx_3way = peer_rx;
	is_3way_mixer = mixer;
	is_3way = true;

	// Create buffers for mixing
	mix_buf_3way = new unsigned char[SAMPLE_BUF_SIZE];
	MEMMAN_NEW_ARRAY(mix_buf_3way);

	// See comments in audio_rx.cpp for the size of this buffer.
	media_3way_peer_tx = new t_media_buffer(JITTER_BUF_SIZE(sc_sample_rate));
	MEMMAN_NEW(media_3way_peer_tx);

	mtx_3way.unlock();
}

void t_audio_tx::set_peer_tx_3way(t_audio_tx *peer_tx) {
	mtx_3way.lock();

	if (!is_3way) {
		mtx_3way.unlock();
		return;
	}

	// Logging
	log_file->write_header("t_audio_tx::set_peer_tx_3way");
	log_file->write_raw("Audio tx line ");
	log_file->write_raw(get_line()->get_line_number()+1);
	if (peer_tx) {
		log_file->write_raw(": set peer transmitter.\n");
	} else {
		log_file->write_raw(": erase peer transmitter.\n");
	}
	if (is_3way_mixer) {
		log_file->write_raw("Role is: mixer.\n");
	} else {
		log_file->write_raw("Role is: non-mixing.\n");
	}
	log_file->write_footer();


	peer_tx_3way = peer_tx;

	mtx_3way.unlock();
}

void t_audio_tx::set_peer_rx_3way(t_audio_rx *peer_rx) {
	mtx_3way.lock();

	if (!is_3way) {
		mtx_3way.unlock();
		return;
	}

	// Logging
	log_file->write_header("t_audio_tx::set_peer_rx_3way");
	log_file->write_raw("Audio tx line ");
	log_file->write_raw(get_line()->get_line_number()+1);
	if (peer_rx) {
		log_file->write_raw(": set peer receiver.\n");
	} else {
		log_file->write_raw(": erase peer receiver.\n");
	}
	if (is_3way_mixer) {
		log_file->write_raw("Role is: mixer.\n");
	} else {
		log_file->write_raw("Role is: non-mixing.\n");
	}
	log_file->write_footer();

	peer_rx_3way = peer_rx;

	mtx_3way.unlock();
}

void t_audio_tx::set_mixer_3way(bool mixer) {
	mtx_3way.lock();

	if (!is_3way) {
		mtx_3way.unlock();
		return;
	}

	// Logging
	log_file->write_header("t_audio_tx::set_mixer_3way");
	log_file->write_raw("Audio tx line ");
	log_file->write_raw(get_line()->get_line_number()+1);
	if (mixer) {
		log_file->write_raw(": change role to: mixer.\n");
	} else {
		log_file->write_raw(": change role to: non-mixing.\n");
	}
	log_file->write_footer();

	is_3way_mixer = mixer;
	
	mtx_3way.unlock();
}

void t_audio_tx::stop_3way(void) {
	mtx_3way.lock();

	if (!is_3way) {
		log_file->write_header("t_audio_tx::stop_3way");
		log_file->write_raw("ERROR: audio tx line ");
		log_file->write_raw(get_line()->get_line_number()+1);
		log_file->write_raw(" - 3way is not active.\n");
		log_file->write_footer();
		mtx_3way.unlock();
		return;
	}

	// Logging
	log_file->write_header("t_audio_tx::stop_3way");
	log_file->write_raw("Audio tx line ");
	log_file->write_raw(get_line()->get_line_number()+1);
	log_file->write_raw(": stop 3-way.\n");
	log_file->write_footer();

	is_3way = false;
	is_3way_mixer = false;

	if (media_3way_peer_tx) {
		MEMMAN_DELETE(media_3way_peer_tx);
		delete media_3way_peer_tx;
		media_3way_peer_tx = NULL;
	}

	if (mix_buf_3way) {
		MEMMAN_DELETE_ARRAY(mix_buf_3way);
		delete [] mix_buf_3way;
		mix_buf_3way = NULL;
	}

	mtx_3way.unlock();
}

void t_audio_tx::post_media_peer_tx_3way(unsigned char *media, int len,
		unsigned short peer_sample_rate) 
{
	mtx_3way.lock();

	if (!is_3way || !is_3way_mixer) {
		mtx_3way.unlock();
		return;
	}
	
	if (peer_sample_rate != sc_sample_rate) {
		// Resample media from peer to sample rate of this transmitter
		int output_len = (len / 2) * sc_sample_rate / peer_sample_rate;
		short *output_buf = new short[output_len];
		MEMMAN_NEW_ARRAY(output_buf);
		int resample_len = resample((short *)media, len / 2, peer_sample_rate,
					output_buf, output_len, sc_sample_rate);
		media_3way_peer_tx->add((unsigned char *)output_buf, resample_len * 2);
		MEMMAN_DELETE_ARRAY(output_buf);
		delete [] output_buf;
	} else {
		media_3way_peer_tx->add(media, len);
	}

	mtx_3way.unlock();
}

bool t_audio_tx::get_is_3way_mixer(void) const {
	return is_3way_mixer;
}
