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

// SIP bodies
#ifndef _H_SIP_BODY
#define _H_SIP_BODY

#include <string>

using namespace std;

enum t_body_type {
	BODY_OPAQUE,
	BODY_SDP
};

// Base class for SIP bodies
class t_sip_body {
public:
	// Indicates if the body content is invalid.
	// This will be set by the body parser
	bool 	invalid;

	t_sip_body();
	virtual ~t_sip_body() {}

	// Return text encoded body
	virtual string encode(void) const = 0;

	// Create a copy of the body
	virtual t_sip_body *copy(void) const = 0;

	// Get type of body
	virtual t_body_type get_type(void) const = 0;
};


// Opaque bodies
class t_sip_body_opaque : public t_sip_body {
public:
	string	opaque;

	t_sip_body_opaque(string s);
	string encode(void) const;
	t_sip_body *copy(void) const;
	t_body_type get_type(void) const;
};

#endif
