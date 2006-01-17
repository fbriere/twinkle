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

#include "header.h"
#include "protocol.h"
#include "util.h"

t_header::t_header() {
	populated = false;
}

bool t_header::is_populated() const {
	return populated;
}

string t_header::get_value(void) const {
	string s;
	int i;

	if (!populated) return s;

	s = encode();
	i = s.find(':');

	// The colon cannot be the first or last character
	if (i == string::npos || i == s.size()-1) return "";

	s = s.substr(i+1);
	i = s.find(CRLF);
	s = s.substr(0, i);

	return (trim(s));
}
