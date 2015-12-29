/*
    Copyright (C) 2005  Michel de Boer <michelboer@xs4all.nl>

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

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <cstdlib>
#include <cstdio>
#include <linux/soundcard.h>
#include "audio_session.h"
#include "line.h"
#include "log.h"
#include "userintf.h"
#include "util.h"
#include "audits/memman.h"

static t_audio_session *_audio_session;

///////////
// PRIVATE
///////////

bool t_audio_session::is_3way(void) const {
	t_line *l = get_line();
	t_phone *p = l->get_phone();

	return p->part_of_3way(l->get_line_number());
}

t_audio_session *t_audio_session::get_peer_3way(void) const {
	t_line *l = get_line();
	t_phone *p = l->get_phone();

	t_line *peer_line = p->get_3way_peer_line(l->get_line_number());

	return peer_line->get_audio_session();
}

bool t_audio_session::open_dsp(void) {
	int arg;	// arg for ioctl()
	int status;	// return from ioctl()

	// On some systems opening the audio devices blocks if another
	// process or thread has opened it already. To prevent a deadlock
	// first try to open the device in non-blocking mode.
	// If the device is still open by another twinkle thread then that
	// is a bug, but this way at least non deadlock is caused.
	fd = open(AUDIO_DEVICE, O_RDWR | O_NONBLOCK);
	if (fd < 0) {
		string msg("Failed to open sound card (non-blocking): ");
		msg += strerror(errno);
		log_file->write_report(msg, "t_audio_session::t_audio_session",
			LOG_NORMAL, LOG_CRITICAL);
		ui->cb_display_msg(msg, MSG_CRITICAL);
		return false;
	}

	// Now close the device again as we do not want to have subsequent
	// operations on the device in non-blocking mode.
	close(fd);

	// Open audio device
	fd = open(AUDIO_DEVICE, O_RDWR);
	if (fd < 0) {
		string msg("Failed to open sound card: ");
		msg += strerror(errno);
		log_file->write_report(msg, "t_audio_session::t_audio_session",
			LOG_NORMAL, LOG_CRITICAL);
		ui->cb_display_msg(msg, MSG_CRITICAL);
		return false;
	}

	// Disable recording
	// If recording is not disabled, then the capture buffers will
	// already fill with data. Then when the audio_rx thread starts
	// to read blocks of 160 samples, it gets all these initial blocks
	// very quickly 1 per 12 ms I have seen. And hence the timestamps
	// for these blocks get out of sync with the RTP stack.
	// Also a large delay is introduced by this. So recording should
	// be enabled just before the data is read from the device.
	arg = ~PCM_ENABLE_INPUT;
	status = ioctl(fd, SNDCTL_DSP_SETTRIGGER, &arg);
	if (status == -1) {
		string msg("SNDCTL_DSP_SETTRIGGER ioctl failed: ");
		msg += strerror(errno);
		log_file->write_report(msg, "t_audio_session::t_audio_session",
			LOG_NORMAL, LOG_CRITICAL);
		ui->cb_display_msg("Cannot disable recording on sound card.",
			MSG_CRITICAL);
		return false;
	}

	// Full duplex
	status = ioctl(fd, SNDCTL_DSP_SETDUPLEX, 0);
	if (status == -1) {
		string msg("SNDCTL_DSP_SETDUPLEX ioctl failed: ");
		msg += strerror(errno);
		log_file->write_report(msg, "t_audio_session::t_audio_session",
			LOG_NORMAL, LOG_CRITICAL);
		ui->cb_display_msg("Sound card cannot be set to full duplex.",
			MSG_CRITICAL);
		return false;
	}

	// Set fragment size
	arg = 0x00ff0007; // 255 buffers of 2^7 bytes each
	status = ioctl(fd, SNDCTL_DSP_SETFRAGMENT, &arg);
	if (status == -1) {
		string msg("SNDCTL_DSP_FRAGMENT ioctl failed: ");
		msg += strerror(errno);
		log_file->write_report(msg, "t_audio_session::t_audio_session",
			LOG_NORMAL, LOG_CRITICAL);
		ui->cb_display_msg("Cannot set buffer size on sound card.",
			MSG_CRITICAL);
		return false;
	}

	// Mono
	arg = 1;
	status = ioctl(fd, SNDCTL_DSP_CHANNELS, &arg);
	if (status == -1) {
		string msg("SNDCTL_DSP_CHANNELS ioctl failed: ");
		msg += strerror(errno);
		log_file->write_report(msg, "t_audio_session::t_audio_session",
			LOG_NORMAL, LOG_CRITICAL);
		ui->cb_display_msg("Sound card cannot be set to mono.", MSG_CRITICAL);
		return false;
	}
	if (arg != 1) {
		log_file->write_report("Unable to set mono mode",
			"t_audio_session::t_audio_session",
			LOG_NORMAL, LOG_CRITICAL);
		ui->cb_display_msg("Sound card cannot be set to mono.", MSG_CRITICAL);
		return false;
	}

	// Sample format
	arg = AFMT_S16_LE; // signed 16 bits little endian
	status = ioctl(fd, SNDCTL_DSP_SETFMT, &arg);
	if (status == -1) {
		string msg("SNDCTL_DSP_SETFMT ioctl failed: ");
		msg += strerror(errno);
		log_file->write_report(msg, "t_audio_session::t_audio_session",
			LOG_NORMAL, LOG_CRITICAL);
		ui->cb_display_msg("Cannot set sound card to 16 bits recording.",
			MSG_CRITICAL);
		return false;
	}

	arg = 16;	   /* sample size in bits */
  	status = ioctl(fd, SOUND_PCM_WRITE_BITS, &arg);
	if (status == -1) {
		string msg("SOUND_PCM_WRITE_BITS ioctl failed: ");
		msg += strerror(errno);
		log_file->write_report(msg, "t_audio_session::t_audio_session",
			LOG_NORMAL, LOG_CRITICAL);
		ui->cb_display_msg("Cannot set sound card to 16 bits playing.",
			MSG_CRITICAL);
		return false;
	}

	// Sample rate
	arg = AUDIO_SAMPLE_RATE;
	status = ioctl(fd, SNDCTL_DSP_SPEED, &arg);
	if (status == -1) {
		string msg("SNDCTL_DSP_SPEED ioctl failed: ");
		msg += strerror(errno);
		log_file->write_report(msg, "t_audio_session::t_audio_session",
			LOG_NORMAL, LOG_CRITICAL);
		msg = "Cannot set sound card sample rate to ";
		msg += int2str(AUDIO_SAMPLE_RATE);
		ui->cb_display_msg(msg, MSG_CRITICAL);
		return false;
	}

	return true;
}

///////////
// PUBLIC
///////////

t_audio_session::t_audio_session(t_session *_session,
		const string &_recv_host, unsigned short _recv_port,
	        const string &_dst_host, unsigned short _dst_port,
		t_audio_codec _codec, unsigned short _ptime)
{
	valid = false;

	session = _session;
	audio_rx = NULL;
	audio_tx = NULL;
	thr_audio_rx = NULL;
	thr_audio_tx = NULL;

	codec = _codec;
	ptime = _ptime;

	log_file->write_header("t_audio_session::t_audio_session");
	log_file->write_raw("Receive RTP from: ");
	log_file->write_raw(_recv_host);
	log_file->write_raw(":");
	log_file->write_raw(_recv_port);
	log_file->write_endl();
	log_file->write_raw("Send RTP to: ");
	log_file->write_raw(_dst_host);
	log_file->write_raw(":");
	log_file->write_raw(_dst_port);
	log_file->write_endl();
	log_file->write_footer();

	// Create RTP session
	try {
		if (_recv_host.empty() || _recv_port == 0) {
			rtp_session = new SymmetricRTPSession(
				InetHostAddress("0.0.0.0"));
			MEMMAN_NEW(rtp_session);
		} else {
			rtp_session = new SymmetricRTPSession(
				InetHostAddress(_recv_host.c_str()), _recv_port);
			MEMMAN_NEW(rtp_session);
		}
	} catch(...) {
		// If the RTPSession constructor throws an exception, no
		// object is created, so clear the pointer.
		rtp_session = NULL;
		string msg("Failed to create a UDP socket (RTP) on port ");
		msg += int2str(_recv_port);
		log_file->write_report(msg, "t_audio_session::t_audio_session",
			LOG_NORMAL, LOG_CRITICAL);
		ui->cb_show_msg(msg, MSG_CRITICAL);
		return;
	}

	if (!_dst_host.empty() && _dst_port != 0) {
		rtp_session->addDestination(
			InetHostAddress(_dst_host.c_str()), _dst_port);
	}

	// Set payload format for outgoing RTP packets
	switch(codec) {
	case CODEC_G711_ALAW:
		rtp_session->
			setPayloadFormat(StaticPayloadFormat(sptPCMA));
		break;
	case CODEC_G711_ULAW:
		rtp_session->
			setPayloadFormat(StaticPayloadFormat(sptPCMU));
		break;
	case CODEC_GSM:
		rtp_session->
			setPayloadFormat(StaticPayloadFormat(sptGSM));
		break;
	default:
		assert(false);
	}

	// Open and initialize sound card
	t_audio_session *as_peer;
	if (is_3way() && (as_peer = get_peer_3way())) {
		fd = as_peer->get_fd_dsp();
		if (fd < 0) return;
	} else {
		if (!open_dsp()) return;
	}

	// Create recorder
	if (!_recv_host.empty() && _recv_port != 0) {
		audio_rx = new t_audio_rx(this, fd, rtp_session, codec, ptime);
		MEMMAN_NEW(audio_rx);

		// Setup 3-way configuration if this audio session is part of
		// a 3-way.
		if (is_3way()) {
			t_audio_session *peer = get_peer_3way();
			if (!peer || !peer->audio_rx) {
				// There is no peer rx yet, so become the main rx
				audio_rx->join_3way(true, NULL);

				if (peer && peer->audio_tx) {
					peer->audio_tx->set_peer_rx_3way(audio_rx);
				}
			} else {
				// There is a peer rx already so that must be the
				// main rx.
				audio_rx->join_3way(false, peer->audio_rx);
				peer->audio_rx->set_peer_rx_3way(audio_rx);

				if (peer->audio_tx) {
					peer->audio_tx->set_peer_rx_3way(audio_rx);
				}
			}
		}
	}

	// Create player
	if (!_dst_host.empty() && _dst_port != 0) {
		audio_tx = new t_audio_tx(this, fd, rtp_session, codec, ptime);
		MEMMAN_NEW(audio_tx);

		// Setup 3-way configuration if this audio session is part of
		// a 3-way.
		if (is_3way()) {
			t_audio_session *peer = get_peer_3way();
			if (!peer) {
				// There is no peer tx yet, so become the mixer tx
				audio_tx->join_3way(true, NULL, NULL);
			} else if (!peer->audio_tx) {
				// There is a peer audio session, but no peer tx,
				// so become the mixer tx
				audio_tx->join_3way(true, NULL, peer->audio_rx);
			} else {
				// There is a peer tx already. That must be the
				// mixer.
				audio_tx->join_3way(
					false, peer->audio_tx, peer->audio_rx);
			}
		}
	}

	valid = true;
}

t_audio_session::~t_audio_session() {
	// Delete of the audio_rx and audio_tx objects will terminate
	// thread execution.
	if (audio_rx) {
		// Reconfigure 3-way configuration if this audio session is
		// part of a 3-way.
		if (is_3way()) {
			t_audio_session *peer = get_peer_3way();
			if (peer) {
				// Make the peer audio rx the main rx and remove
				// reference to this audio rx
				if (peer->audio_rx) {
					peer->audio_rx->set_peer_rx_3way(NULL);
					peer->audio_rx->set_main_rx_3way(true);
				}

				// Remove reference to this audio rx
				if (peer->audio_tx) {
					peer->audio_tx->set_peer_rx_3way(NULL);
				}
			}
		}
		MEMMAN_DELETE(audio_rx);
		delete audio_rx;
	}

	if (audio_tx) {
		// Reconfigure 3-way configuration if this audio session is
		// part of a 3-way.
		if (is_3way()) {
			t_audio_session *peer = get_peer_3way();
			if (peer) {
				// Make the peer audio tx the mixer and remove
				// reference to this audio tx
				if (peer->audio_tx) {
					peer->audio_tx->set_peer_tx_3way(NULL);
					peer->audio_tx->set_mixer_3way(true);
				}
			}
		}
		MEMMAN_DELETE(audio_tx);
		delete audio_tx;
	}

	if (thr_audio_rx) {
		MEMMAN_DELETE(thr_audio_rx);
		delete thr_audio_rx;
	}
	if (thr_audio_tx) {
		MEMMAN_DELETE(thr_audio_tx);
		delete thr_audio_tx;
	}

	if (rtp_session) {
		log_file->write_header("t_audio_session::~t_audio_session");
		log_file->write_raw("Line ");
		log_file->write_raw(get_line()->get_line_number()+1);
		log_file->write_raw(": stopping RTP session.\n");
		log_file->write_footer();

		MEMMAN_DELETE(rtp_session);
		delete rtp_session;

		log_file->write_header("t_audio_session::~t_audio_session");
		log_file->write_raw("Line ");
		log_file->write_raw(get_line()->get_line_number()+1);
		log_file->write_raw(": RTP session stopped.\n");
		log_file->write_footer();
	}

	if (fd >= 0 && (!is_3way() || !get_peer_3way())) {
		close(fd);
	}
}

void t_audio_session::run(void) {
	_audio_session = this;

	log_file->write_header("t_audio_session::run");
	log_file->write_raw("Line ");
	log_file->write_raw(get_line()->get_line_number()+1);
	log_file->write_raw(": starting RTP session.\n");
	log_file->write_footer();

	rtp_session->startRunning();

	log_file->write_header("t_audio_session::run");
	log_file->write_raw("Line ");
	log_file->write_raw(get_line()->get_line_number()+1);
	log_file->write_raw(": RTP session started.\n");
	log_file->write_footer();

	if (audio_rx) {
		try {
			thr_audio_rx = new t_thread(main_audio_rx, NULL);
			MEMMAN_NEW(thr_audio_rx);
			// thr_audio_rx->set_sched_fifo(90);
			thr_audio_rx->detach();
		} catch (int) {
			string msg("Failed to create audio_rx thread.");
			log_file->write_report(msg, "t_audio_session::run",
				LOG_NORMAL, LOG_CRITICAL);
			ui->cb_show_msg(msg, MSG_CRITICAL);
			exit(1);
		}
	}


	if (audio_tx) {
		try {
			thr_audio_tx = new t_thread(main_audio_tx, NULL);
			MEMMAN_NEW(thr_audio_tx);
			// thr_audio_tx->set_sched_fifo(90);
			thr_audio_tx->detach();
		} catch (int) {
			string msg("Failed to create audio_tx thread.");
			log_file->write_report(msg, "t_audio_session::run",
				LOG_NORMAL, LOG_CRITICAL);
			ui->cb_show_msg(msg, MSG_CRITICAL);
			exit(1);
		}
	}
}

void t_audio_session::set_pt_out_dtmf(unsigned short pt) {
	if (audio_rx) audio_rx->set_pt_telephone_event(pt);
}

void t_audio_session::set_pt_in_dtmf(unsigned short pt, unsigned short pt_alt) {
	if (audio_tx) audio_tx->set_pt_telephone_event(pt, pt_alt);
}

void t_audio_session::send_dtmf(char digit) {
	if (audio_rx) audio_rx->push_dtmf(digit);
}

t_line *t_audio_session::get_line(void) const {
	return session->get_line();
}

void t_audio_session::start_3way(void) {
	if (audio_rx) {
		audio_rx->join_3way(true, NULL);
	}

	if (audio_tx) {
		audio_tx->join_3way(true, NULL, NULL);
	}
}

void t_audio_session::stop_3way(void) {
	if (audio_rx) {
		t_audio_session *peer = get_peer_3way();
		if (peer) {
			if (peer->audio_rx) {
				peer->audio_rx->set_peer_rx_3way(NULL);
			}

			if (peer->audio_tx) {
				peer->audio_tx->set_peer_rx_3way(NULL);
			}
		}
		audio_rx->stop_3way();
	}

	if (audio_tx) {
		t_audio_session *peer = get_peer_3way();
		if (peer) {
			if (peer->audio_tx) {
				peer->audio_tx->set_peer_tx_3way(NULL);
			}
		}
		audio_tx->stop_3way();
	}
}

bool t_audio_session::is_valid(void) const {
	return valid;
}

int t_audio_session::get_fd_dsp(void) const {
	return fd;
}

void *main_audio_rx(void *arg) {
	_audio_session->audio_rx->run();
}

void *main_audio_tx(void *arg) {
	_audio_session->audio_tx->run();
}
