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

#ifndef _AUDIO_CODECS_H
#define _AUDIO_CODECS_H

#include "g711.h"
#include "g72x.h"

// Audio codecs
enum t_audio_codec {
	CODEC_NULL,
	CODEC_UNSUPPORTED,
	CODEC_G711_ALAW,
	CODEC_G711_ULAW,
	CODEC_GSM
};

// Default ptime values (ms) for audio codecs
#define PTIME_G711_ALAW		20
#define PTIME_G711_ULAW		20
#define PTIME_GSM		20
#define MIN_PTIME		10
#define MAX_PTIME		80

// Audio sample settings
#define AUDIO_SAMPLE_RATE	8000
#define AUDIO_SAMPLE_SIZE	16


// Maximum length (in packets) for concealment of lost packets
#define MAX_CONCEALMENT		2

// Size of jitter buffer in ms
// The jitter buffer is used to smooth playing out incoming RTP packets.
// The size of the buffer is also used as the expiry time in the ccRTP
// stack. Packets that have timestamp that is older than then size of
// the jitter buffer will not be sent out anymore.
#define JITTER_BUF_MS		80

// Buffer sizes
#define JITTER_BUF_SIZE (JITTER_BUF_MS * AUDIO_SAMPLE_RATE/1000 * AUDIO_SAMPLE_SIZE/8)

// Mix 2 16 bits signed linear PCM values
short mix_linear_pcm(short pcm1, short pcm2);

#endif
