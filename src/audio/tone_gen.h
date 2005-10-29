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

#ifndef _TONE_GEN_H
#define _TONE_GEN_H

#include <string>
#include <fstream>
#include <cc++/config.h>
#include "threads/mutex.h"
#include "threads/thread.h"
#include "threads/sema.h"

#ifndef _SYS_SETTINGS_H
class t_audio_device;
#endif
#ifndef _AUDIO_DEVICE_H
class t_audio_io;
#endif

using namespace std;

#define IFF_ID_RIFF	"RIFF"
#define RIFF_TYPE_WAV	"WAVE"

struct t_iff_header {
	char		id[4];
	uint32		size;
	char		type[4];
};

#define CHK_ID_FMT	"fmt "
#define CHK_ID_DATA	"data"

struct t_chunk_header {
	char		id[4];
	uint32		size;
};

#define FMT_UNCOMPRESSED	1

struct t_chunk_fmt {
	short		format_tag;
	unsigned short	channels;
	uint32		samples_per_sec;
	uint32		avg_bytes_per_sec;
	unsigned short	block_align;
	unsigned short	bits_per_sample;
};

class t_tone_gen {
private:
	string		wav_filename;	// name of wav file
	ifstream	*wav_file;	// input file stream for wav file
	const t_audio_device*		dev_tone;	// device to play tone
	t_audio_io*		aio;		// soundcard
	t_chunk_fmt	wav_format;	// format chunk from wav file
	bool		valid;		// wav file is in a valid format
	bool		stop_playing;	// indicates if playing should stop
	t_thread	*thr_play;	// playing thread
	bool		loop;		// repeat playing
	int		pause;		// pause (ms) between repetitions
	char		*data_buf;	// buffer for reading sound samples
	t_semaphore	sema_finished;	// indicates if playing finished

public:
	t_tone_gen(const string &filename, const t_audio_device &_dev_tone);
	~t_tone_gen();

	bool is_valid(void) const;

	// Play the wav file
	// loop = true -> repeat playing
	// pause is pause in ms between repetitions
	void start_play_thread(bool _loop, int _pause);
	void play(void);

	// Stop playing
	void stop(void);
};

#endif
