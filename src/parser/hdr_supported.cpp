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
#include "hdr_supported.h"
#include "parse_ctrl.h"

t_hdr_supported::t_hdr_supported() : t_header() {};

void t_hdr_supported::add_feature(const string &f) {
	populated = true;
	features.push_back(f);
}

void t_hdr_supported::set_empty(void) {
	populated = true;
	features.clear();
}

bool t_hdr_supported::contains(const string &f) const {
	if (!populated) return false;

	for (list<string>::const_iterator i = features.begin();
	     i != features.end(); i++)
	{
		if (*i == f) return true;
	}

	return false;
}

string t_hdr_supported::encode(void) const {
	string s;

	if (!populated) return s;

	if (t_parser::compact_headers) {
		s = "k: ";
	} else {
		s = "Supported: ";
	}

	s += encode_value();
	s += CRLF;
	
	return s;
}

string t_hdr_supported::encode_value(void) const {
	string s;

	if (!populated) return s;

	for (list<string>::const_iterator i = features.begin();
	     i != features.end(); i++)
	{
		if (i != features.begin()) s += ", ";
		s += *i;
	}

	return s;
}

string t_hdr_supported::encode_env(void) const {
	string s;
	
	s = "SIP_SUPPORTED=";
	s += encode_value();
	
	return s;
}
