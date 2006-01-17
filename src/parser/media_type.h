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

// Media mime type definition

#ifndef _MEDIA_TYPE_H
#define _MEDIA_TYPE_H

#include <list>
#include <string>
#include "parameter.h"

using namespace std;

class t_media {
public:
	string	type;		// main type
	string	subtype;	// subtype
	float	q;		// quality factor
	list<t_parameter> media_param_list; 	 // media paramters
	list<t_parameter> accept_extension_list; // accept parameters

	t_media();

	// Construct object with type = t, subtype = s;
	t_media(const string &t, const string &s);

	// Method for parser to add the parsed parameter list l.
	// l should start with optional media parameters followed
	// by the q-paramter followed by accept parameters.
	void add_params(const list<t_parameter> &l);

	string encode(void) const;
};

#endif
