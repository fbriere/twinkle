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

#include "audio_codecs.h"

short mix_linear_pcm(short pcm1, short pcm2) {
	long mixed_sample = long(pcm1) + long(pcm2);

	// Compress a 17 bit PCM value into a 16-bit value.
	// The easy way is to divide the value by 2, but this lowers
	// the volume.
	// Only lower the volume for the loud values. As for a normal
	// voice call the values are not that loud, this gives better
	// quality.
	if (mixed_sample > 16384) {
		mixed_sample = 16384 + (mixed_sample - 16384) / 3;
	} else if (mixed_sample < -16384) {
		mixed_sample = -16384 - (-16384 - mixed_sample) / 3;
	}

	return short(mixed_sample);
}
