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

#include "hdr_content_encoding.h"
#include "definitions.h"
#include "parse_ctrl.h"

t_hdr_content_encoding::t_hdr_content_encoding() : t_header() {};

void t_hdr_content_encoding::add_coding(const t_coding &coding) {
	populated = true;
	coding_list.push_back(coding);
}

string t_hdr_content_encoding::encode(void) const {
	string s;

	if (!populated) return s;

	if (t_parser::compact_headers) {
		s = "e: ";
	} else {
		s = "Content-Encoding: ";
	}

	s += encode_value();
	s += CRLF;

	return s;
}

string t_hdr_content_encoding::encode_value(void) const {
	string s;

	if (!populated) return s;

	for (list<t_coding>::const_iterator i = coding_list.begin();
	     i != coding_list.end(); i++)
	{
		if (i != coding_list.begin()) s += ", ";
		s += i->encode();
	}

	return s;
}

string t_hdr_content_encoding::encode_env(void) const {
	string s;
	
	s = "SIP_CONTENT_ENCODING=";
	s += encode_value();
	
	return s;
}
