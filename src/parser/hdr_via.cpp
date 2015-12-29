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

#include <iostream>
#include "definitions.h"
#include "hdr_via.h"
#include "util.h"
#include "parse_ctrl.h"
#include "protocol.h"
#include "sockets/url.h"

t_via::t_via() {
	port = 0;
	ttl = 0;
	rport_present = false;
	rport = 0;
}

t_via::t_via(const string &_host, const int _port, bool add_rport) {
	protocol_name = "SIP";
	protocol_version = SIP_VERSION;
	transport = "UDP";
	host = _host;
	branch = RFC3261_COOKIE + random_token(8);

	if (_port != get_default_port("sip")) {
		port = _port;
	} else {
		port = 0;
	}

	ttl = 0;
	rport_present = add_rport;
	rport = 0;
}

void t_via::add_extension(const t_parameter &p) {
	extensions.push_back(p);
}

string t_via::encode(void) const {
	string s;

	s = protocol_name + '/' + protocol_version + '/' + transport;
	s += ' ';
	s += host;

	if (port > 0) {
		s += ':';
		s += int2str(port);
	}

	if (ttl > 0) s += int2str(ttl, ";ttl=%d");

	if (maddr.size() > 0) {
		s += ";maddr=";
		s += maddr;
	}

	if (received.size() > 0) {
		s += ";received=";
		s += received;
	}

	if (rport_present) {
		s += ";rport";
		if (rport > 0) {
			s += "=";
			s += int2str(rport);
		}
	}

	if (branch.size() > 0) {
		s += ";branch=";
		s += branch;
	}

	s += param_list2str(extensions);
	return s;
}

void t_via::get_response_dst(unsigned long &ipaddr, unsigned short &prt)
{
	struct hostent *h;
	
	string url_str("sip:");

	// RFC 3261 18.2.2
	// Determine the address to send a repsonse to
	if (maddr.size() > 0) {
		url_str += maddr;
	} else if (received.size() > 0) {
		// NOTE: the received-parameter will be added by the
		// UDP listener if needed.
		url_str += received;
	} else {
		url_str += host;
	}

	// RFC 3581 4
	if (rport_present && rport > 0) {
		// NOTE: the rport value will be added by the UDP listener
		// if the rport parameter without value was present.
		url_str += ':';
		url_str += int2str(rport);
	} else if (port != 0) {
		url_str += ':';
		url_str += int2str(port);
	}
	
	// If there was no maddr parameter, then the URL will always point to
	// an IP address; either the host was an IP address or a received parameter
	// containing an IP address was added (see RFC 3261 18.2.1)
	// If there was an maddr, then the URL can be a domain that could have
	// multiple SRV records. RFC 3263 section 5 does not specify what to do in
	// this case. So just send the response to the first destination.
	t_url u(url_str);
	list<t_ip_port> ip_list = u.get_h_ip_srv("udp");
	ipaddr = ip_list.front().ipaddr;
	prt = ip_list.front().port;
}

bool t_via::rfc3261_compliant(void) const {
	return (branch.find(RFC3261_COOKIE) == 0);
}


t_hdr_via::t_hdr_via() : t_header() {}

void t_hdr_via::add_via(const t_via &v) {
	populated = true;
	via_list.push_back(v);
}

string t_hdr_via::encode(void) const {
	return (t_parser::multi_values_as_list ? encode_list() : encode_multi_header());
}

string t_hdr_via::encode_list(void) const {
	string s;

	if (!populated) return s;

	if (t_parser::compact_headers) {
		s = "v: ";
	} else {
		s = "Via: ";
	}

	s += encode_value();
	s += CRLF;
	
	return s;
}

string t_hdr_via::encode_multi_header(void) const {
	string s;

	if (!populated) return s;

	for (list<t_via>::const_iterator i = via_list.begin();
	     i != via_list.end(); i++)
	{
		if (t_parser::compact_headers) {
			s += "v: ";
		} else {
			s += "Via: ";
		}
	
		s += i->encode();
		s += CRLF;
	}

	return s;
}

string t_hdr_via::encode_value(void) const {
	string s;

	if (!populated) return s;

	for (list<t_via>::const_iterator i = via_list.begin();
	     i != via_list.end(); i++)
	{
		if (i != via_list.begin()) s += ", ";
		s += i->encode();
	}

	return s;
}

string t_hdr_via::encode_env(void) const {
	string s;
	
	s = "SIP_VIA=";
	s += encode_value();
	
	return s;
}

void t_hdr_via::get_response_dst(unsigned long &ipaddr,
		unsigned short &prt)
{
	if (!populated) {
		ipaddr = 0;
		prt = 0;
		return;
	}

	via_list.front().get_response_dst(ipaddr, prt);
}
