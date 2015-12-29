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

#include "hdr_call_id.h"
#include "definitions.h"
#include "parse_ctrl.h"

t_hdr_call_id::t_hdr_call_id() : t_header() {};

void t_hdr_call_id::set_call_id(string id) {
	populated = true;
	call_id = id;
}

string t_hdr_call_id::encode(void) const {
	string s;

	if (!populated) return s;

	if (t_parser::compact_headers) {
		s = "i: ";
	} else {
		s = "Call-ID: ";
	}

	s += call_id + CRLF;

	return s;
}
