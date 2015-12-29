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
#include "hdr_contact.h"
#include "parse_ctrl.h"
#include "util.h"

t_contact_param::t_contact_param() {
	q = 1.0;
	expires = 0;
	expires_present = false;
}

void t_contact_param::add_extension(const t_parameter &p) {
	extensions.push_back(p);
}

string t_contact_param::encode(void) const {
	string s;

	if (display.size() > 0) {
		s += '"';
		s += display;
		s += '"';
		s += ' ';
	}

	s += '<';
	s += uri.encode();
	s += '>';
	if (q != 1) s += float2str(q, ";q=%.1f");
	if (expires_present) s += ulong2str(expires, ";expires=%u");
	s += param_list2str(extensions);

	return s;
}

bool t_contact_param::operator<(const t_contact_param &c) const {
	return (q > c.q);
}


t_hdr_contact::t_hdr_contact() : t_header() {
	any_flag = false;
}

void t_hdr_contact::add_contact(const t_contact_param &contact) {
	populated = true;
	contact_list.push_back(contact);
}

void t_hdr_contact::add_contacts(const list<t_contact_param> &l) {
	populated = true;

	for (list<t_contact_param>::const_iterator i = l.begin(); i != l.end();
	     i++)
	{
		contact_list.push_back(*i);
	}
}

void t_hdr_contact::set_contacts(const list<t_contact_param> &l) {
	populated = true;
	contact_list = l;
}

void t_hdr_contact::set_contacts(const list<t_url> &l) {
	t_contact_param c;

	populated = true;

	contact_list.clear();
	for (list<t_url>::const_iterator i = l.begin(); i != l.end(); i++) {
		c.uri = *i;
		contact_list.push_back(c);
	}
}

void t_hdr_contact::set_contacts(const list<t_display_url> &l) {
	t_contact_param c;

	populated = true;

	contact_list.clear();
	for (list<t_display_url>::const_iterator i = l.begin(); i != l.end(); i++) {
		c.uri = i->url;
		c.display = i->display;
		contact_list.push_back(c);
	}
}

void t_hdr_contact::set_any(void) {
	populated = true;
	any_flag = true;
	contact_list.clear();
}

t_contact_param *t_hdr_contact::find_contact(const t_url &u) {
	for (list<t_contact_param>::iterator i = contact_list.begin();
	     i != contact_list.end(); i++)
	{
		if (u.sip_match(i->uri)) return &(*i);
	}

	return NULL;
}

bool t_contact_param::is_expires_present(void) const {
	return expires_present;
}

unsigned long t_contact_param::get_expires(void) const {
	return expires;
}

void t_contact_param::set_expires(unsigned long e) {
	expires_present = true;
	expires = e;
}

string t_hdr_contact::encode(void) const {
	string s;

	if (!populated) return s;

	if (t_parser::compact_headers) {
		s = "m: ";
	} else {
		s = "Contact: ";
	}

	if (any_flag) {
		s += '*';
		s += CRLF;
		return s;
	}

	for (list<t_contact_param>::const_iterator i = contact_list.begin();
	     i != contact_list.end(); i++)
	{
		if (i != contact_list.begin()) s += ", ";
		s += i->encode();
	}

	s += CRLF;
	return s;
}
