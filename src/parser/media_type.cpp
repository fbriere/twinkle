/*
    Copyright (C) 2005-2008  Michel de Boer <michel@twinklephone.com>

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

#include <cstdlib>

#include "media_type.h"
#include "util.h"

using namespace std;

t_media::t_media() {
	q = 1.0;
}

t_media::t_media(const string &t, const string &s) {
	q = 1.0;
	type = t;
	subtype = s;
}

void t_media::add_params(const list<t_parameter> &l) {
	list<t_parameter>::const_iterator i = l.begin();

	media_param_list.clear();
	accept_extension_list.clear();

	// Add media parameters
	while (i != l.end() && i->name != "q") {
		if (i->name == "charset") {
			charset = i->value;
		} else {
			media_param_list.push_back(*i);
		}
		++i;
	}

	// Set the quality factor
	if (i != l.end()) {
		q = atof(i->value.c_str());
		i++;
	}

	// Add accept extension parameters
	while (i != l.end()) {
		accept_extension_list.push_back(*i);
		i++;
	}
}


string t_media::encode(void) const {
	string s;

	s = type + '/' + subtype;
	if (!charset.empty()) {
		s += ";charset=";
		s += charset;
	}
	s += param_list2str(media_param_list);
	
	if (q != 1) {
		s += ";q=";
		s += float2str(q, 1);
	}
	
	s += param_list2str(accept_extension_list);

	return s;
}
