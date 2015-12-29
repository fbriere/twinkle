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

#include "definitions.h"
#include "hdr_proxy_require.h"

t_hdr_proxy_require::t_hdr_proxy_require() : t_header() {};

void t_hdr_proxy_require::add_feature(const string &f) {
	populated = true;
	features.push_back(f);
}

string t_hdr_proxy_require::encode(void) const {
	string s;

	if (!populated) return s;

	s = "Proxy-Require: ";

	for (list<string>::const_iterator i = features.begin();
	     i != features.end(); i++)
	{
		if (i != features.begin()) s += ", ";
		s += *i;
	}

	s += CRLF;
	return s;
}
