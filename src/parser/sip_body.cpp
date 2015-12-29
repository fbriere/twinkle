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

#include "sip_body.h"
#include "sip_message.h"
#include "audits/memman.h"

////////////////////////////////////
// class t_sip_body
////////////////////////////////////

t_sip_body::t_sip_body() {
	invalid = false;
}

////////////////////////////////////
// class t_sip_body_opaque
////////////////////////////////////

t_sip_body_opaque::t_sip_body_opaque(string s) : t_sip_body() {
	opaque = s;
}

string t_sip_body_opaque::encode(void) const {
	return opaque;
}

t_sip_body *t_sip_body_opaque::copy(void) const {
	t_sip_body_opaque *sb =  new t_sip_body_opaque(*this);
	MEMMAN_NEW(sb);
	return sb;
}

t_body_type t_sip_body_opaque::get_type(void) const {
	return BODY_OPAQUE;
}

////////////////////////////////////
// class t_sip_body_sipfrag
////////////////////////////////////

t_sip_body_sipfrag::t_sip_body_sipfrag(t_sip_message *m) {
	sipfrag = m->copy();
}

t_sip_body_sipfrag::~t_sip_body_sipfrag() {
	MEMMAN_DELETE(sipfrag);
	delete sipfrag;
}

string t_sip_body_sipfrag::encode(void) const {
	return sipfrag->encode(false);
}

t_sip_body *t_sip_body_sipfrag::copy(void) const {
	t_sip_body_sipfrag *sb = new t_sip_body_sipfrag(sipfrag);
	MEMMAN_NEW(sb);
	return sb;
}

t_body_type t_sip_body_sipfrag::get_type(void) const {
	return BODY_SIPFRAG;
}

