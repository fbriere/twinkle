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
#include <sys/time.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <linux/soundcard.h>
#include <iostream>
#include "tone_gen.h"
#include "log.h"
#include "sys_settings.h"
#include "user.h"
#include "userintf.h"
#include "util.h"
#include "audits/memman.h"

#define	TONE_DEVICE	DEV_DSP

// Number of samples read at once from the wav file
#define NUM_SAMPLES_PER_TURN	1024

// Duration of one turn in ms
#define DURATION_TURN	(NUM_SAMPLES_PER_TURN * 1000 / wav_format.samples_per_sec)


// Main function for play thread
void *tone_gen_play(void *arg) {
	t_tone_gen *tg = (t_tone_gen *)arg;
	tg->play();
}

t_tone_gen::t_tone_gen(const string &filename) {
	string f;

	wav_file = NULL;
	fd_dsp = 0;
	valid = false;
	data_buf = NULL;
	thr_play = NULL;
	loop = false;
	pause = 0;

	if (filename.size() == 0) return;

	// Add share directory to filename
	if (filename[0] != '/') {
		f = sys_config->get_dir_share();
		f += "/";
		f += filename;
	} else {
		f = filename;
	}

	wav_filename = f;

	wav_file = new ifstream(f.c_str());
	MEMMAN_NEW(wav_file);
	if (!*wav_file) {
		string msg("Cannot open ");
		msg += f;
		log_file->write_report(msg, "t_tone_gen::t_tone_gen",
			LOG_NORMAL, LOG_WARNING);
		ui->cb_display_msg(msg, MSG_WARNING);
		return;
	}

	log_file->write_header("t_tone_gen::t_tone_gen");
	log_file->write_raw("Opened ");
	log_file->write_raw(f);
	log_file->write_endl();
	log_file->write_footer();

	t_iff_header iff_hdr;
	wav_file->read((char *)&iff_hdr, sizeof(iff_hdr));

	if (strncmp(iff_hdr.id, IFF_ID_RIFF, 4) != 0) {
		log_file->write_report("This is not a RIFF file.",
			"t_tone_gen::t_tone_gen", LOG_NORMAL, LOG_WARNING);
		string msg(f);
		msg += " is not a valid wav-file.";
		ui->cb_display_msg(msg, MSG_WARNING);
		return;
	}

	if (strncmp(iff_hdr.type, RIFF_TYPE_WAV, 4) != 0) {
		log_file->write_report("This is not a WAVE file.",
			"t_tone_gen::t_tone_gen", LOG_NORMAL, LOG_WARNING);
		string msg(f);
		msg += " is not a valid wav-file.";
		ui->cb_display_msg(msg, MSG_WARNING);
		return;
	}

	// Find format chunk
	bool found_fmt_hdr = false;
	while (!found_fmt_hdr && !wav_file->eof()) {
		t_chunk_header chunk_hdr;

		wav_file->read((char *)&chunk_hdr, sizeof(chunk_hdr));
		if (strncmp(chunk_hdr.id, CHK_ID_FMT, 4) != 0) continue;
		if (chunk_hdr.size != sizeof(wav_format)) {
			log_file->write_report("Unsupported fmt chunk length.",
				"t_tone_gen::t_tone_gen",
				LOG_NORMAL, LOG_WARNING);
			string msg(f);
			msg += " has an unsupported wav-format.";
			ui->cb_display_msg(msg, MSG_WARNING);
			return;
		}

		wav_file->read((char *)&wav_format, sizeof(wav_format));
		if (wav_format.format_tag != FMT_UNCOMPRESSED) {
			log_file->write_report("Unsupported wav format.",
				"t_tone_gen::t_tone_gen",
				LOG_NORMAL, LOG_WARNING);
			string msg(f);
			msg += " has an unsupported wav-format.";
			ui->cb_display_msg(msg, MSG_WARNING);
			return;
		}

		found_fmt_hdr = true;
	}

	if (!found_fmt_hdr) {
		log_file->write_report("Format chunk missing.",
			"t_tone_gen::t_tone_gen", LOG_NORMAL, LOG_WARNING);
		string msg(f);
		msg += " has an unsupported wav-format.";
		ui->cb_display_msg(msg, MSG_WARNING);
		return;
	}

	// Find data chunk
	bool found_data_hdr = false;
	while (!found_data_hdr && !wav_file->eof()) {
		t_chunk_header chunk_hdr;

		wav_file->read((char *)&chunk_hdr, sizeof(chunk_hdr));
		if (strncmp(chunk_hdr.id, CHK_ID_DATA, 4) != 0) continue;

		found_data_hdr = true;
	}

	if (!found_data_hdr) {
		log_file->write_report("Data chunk missing.",
			"t_tone_gen::t_tone_gen", LOG_NORMAL, LOG_WARNING);
		string msg(f);
		msg += " has an unsupported wav-format.";
		ui->cb_display_msg(msg, MSG_WARNING);
		return;
	}

	valid = true;
	stop_playing = false;
}

t_tone_gen::~t_tone_gen() {
	if (wav_file) {
		MEMMAN_DELETE(wav_file);
		delete wav_file;
	}
	if (fd_dsp > 0) close(fd_dsp);
	if (data_buf) {
		MEMMAN_DELETE_ARRAY(data_buf);
		delete [] data_buf;
	}
	if (thr_play) {
		MEMMAN_DELETE(thr_play);
		delete thr_play;
	}
}

bool t_tone_gen::is_valid(void) const {
	return valid;
}

void t_tone_gen::play(void) {
	int arg, arg2;	// arg for ioctl()
	int status;	// return from ioctl()
	struct timespec sleeptimer;

	if (!valid) return;

	fd_dsp = open(TONE_DEVICE, O_WRONLY);
	if (fd_dsp < 0) {
		string msg("Failed to open sound card: ");
		msg += strerror(errno);
		log_file->write_report(msg, "t_tone_gen::t_tone_gen",
			LOG_NORMAL, LOG_WARNING);
		ui->cb_display_msg(msg, MSG_WARNING);
		return;
	}

	// Set fragment size
	arg = 0x00ff000a; // 255 buffers of 2^10 bytes each
	status = ioctl(fd_dsp, SNDCTL_DSP_SETFRAGMENT, &arg);
	if (status == -1) {
		string msg("SNDCTL_DSP_FRAGMENT ioctl failed: ");
		msg += strerror(errno);
		log_file->write_report(msg, "t_tone_gen::t_tone_gen",
			LOG_NORMAL, LOG_WARNING);
		ui->cb_display_msg("Cannot set buffer size on sound card.",
			MSG_WARNING);
		return;
	}

	// Set audio format
	if (wav_format.bits_per_sample == 8) {
		arg = AFMT_U8;
		arg2 = 8;
	} else if (wav_format.bits_per_sample == 16) {
		arg = AFMT_S16_LE;
		arg2 = 16;
	} else {
		log_file->write_report("Unsupported sample size.",
			"t_tone_gen::t_tone_gen");
		return;
	}
	status = ioctl(fd_dsp, SNDCTL_DSP_SETFMT, &arg);
	if (status == -1) {
		string msg("SNDCTL_DSP_SETFMT ioctl failed: ");
		msg += strerror(errno);
		log_file->write_report(msg, "t_tone_gen::t_tone_gen",
			LOG_NORMAL, LOG_WARNING);
		ui->cb_display_msg("Cannot set sound card to 16 bits recording.",
			MSG_WARNING);
		return;
	}

	status = ioctl(fd_dsp, SOUND_PCM_WRITE_BITS, &arg2);
	if (status == -1) {
		string msg("SOUND_PCM_WRITE_BITS ioctl failed: ");
		msg += strerror(errno);
		log_file->write_report(msg, "t_tone_gen::t_tone_gen",
			LOG_NORMAL, LOG_WARNING);
		ui->cb_display_msg("Cannot set sound card to 16 bits playing.",
			MSG_WARNING);
		return;
	}

	// Channels
	arg = wav_format.channels;
	status = ioctl(fd_dsp, SNDCTL_DSP_CHANNELS, &arg);
	if (status == -1) {
		string msg("SNDCTL_DSP_CHANNELS ioctl failed: ");
		msg += strerror(errno);
		log_file->write_report(msg, "t_tone_gen::t_tone_gen",
			LOG_NORMAL, LOG_WARNING);
		msg = "Sound card cannot be set to ";
		msg += int2str(wav_format.channels);
		msg += " channel(s).";
		ui->cb_display_msg(msg, MSG_WARNING);
		return;
	}

	// Sample rate
	arg = wav_format.samples_per_sec;
	status = ioctl(fd_dsp, SNDCTL_DSP_SPEED, &arg);
	if (status == -1) {
		string msg("SNDCTL_DSP_SPEED ioctl failed: ");
		msg += strerror(errno);
		log_file->write_report(msg, "t_audio_session::t_audio_session",
			LOG_NORMAL, LOG_WARNING);
		msg = "Cannot set sound card sample rate to ";
		msg += int2str(wav_format.samples_per_sec);
		ui->cb_display_msg(msg, MSG_WARNING);
		return;
	}

	mtx_play.lock();

	do {
		int nbytes = NUM_SAMPLES_PER_TURN * wav_format.block_align;
		data_buf = new char[nbytes];
		MEMMAN_NEW_ARRAY(data_buf);
		unsigned long start_pos = wav_file->tellg();

		bool first_playout = true;
		while (!wav_file->eof()) {
			if (stop_playing) break;

			// Play sample
			wav_file->read(data_buf, nbytes);
			write(fd_dsp, data_buf, wav_file->gcount());
		}

		MEMMAN_DELETE_ARRAY(data_buf);
		delete [] data_buf;
		data_buf = NULL;

		if (stop_playing) break;

		// Pause between repetitions
		if (loop) {
			// Play silence
			if (pause > 0) {
				int silence;

				if (wav_format.bits_per_sample == 8) {
					silence = 128;
				} else {
					silence = 0;
				}

				data_buf = new char[nbytes];
				MEMMAN_NEW_ARRAY(data_buf);
				memset(data_buf, silence, nbytes);

				for (int i = 0; i < pause; i += DURATION_TURN) {
					write(fd_dsp, data_buf, nbytes);
					if (stop_playing) break;
				}

				MEMMAN_DELETE_ARRAY(data_buf);
				delete [] data_buf;
				data_buf = NULL;
			}

			if (stop_playing) break;

			// Set file pointer back to start of data
			MEMMAN_DELETE(wav_file);
			delete wav_file;
			wav_file = new ifstream(wav_filename.c_str());
			MEMMAN_NEW(wav_file);
			wav_file->seekg(start_pos);
		}
	} while (loop);

	mtx_play.unlock();
}

void t_tone_gen::start_play_thread(bool _loop, int _pause) {
	loop = _loop;
	pause = _pause;
	thr_play = new t_thread(tone_gen_play, this);
	MEMMAN_NEW(thr_play);
	thr_play->detach();
}

void t_tone_gen::stop(void) {
	if (stop_playing) return;

	stop_playing = true;

	// The lock will return as soon as the playing has finished.
	mtx_play.lock();
	mtx_play.unlock();

	// Stop audio play out
	int arg = 0;
	ioctl(fd_dsp, SNDCTL_DSP_RESET, &arg);
	close(fd_dsp);
	fd_dsp = 0;
}


