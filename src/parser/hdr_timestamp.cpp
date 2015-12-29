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

#include "definitions.h"
#include "hdr_timestamp.h"
#include "util.h"

t_hdr_timestamp::t_hdr_timestamp() : t_header() {
	timestamp = 0;
	delay = 0;
}

void t_hdr_timestamp::set_timestamp(float t) {
	populated = true;
	timestamp = t;
}

void t_hdr_timestamp::set_delay(float d) {
	populated = true;
	delay = d;
}

string t_hdr_timestamp::encode(void) const {
	string s;

	if (!populated) return s;

	s = "Timestamp: ";
	s += float2str(timestamp, "%.3f");

	if (delay != 0) s += float2str(delay, " %.3f");

	s += CRLF;
	return s;
}
