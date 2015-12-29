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

#include "request.h"
#include "util.h"
#include "parse_ctrl.h"
#include "protocol.h"
#include "audits/memman.h"
#include <sstream>
#include <cc++/digest.h>

using namespace ost;

bool t_request::authorize(const t_challenge &chlg,
	const string &username, const string &passwd, unsigned long nc,
	const string &cnonce, t_credentials &cr, string &fail_reason) const
{
	string A1, A2;
	string qop = "";

	// Only Digest authentication is supported
	if (chlg.auth_scheme != AUTH_DIGEST) {
		fail_reason = "Authentication scheme " + chlg.auth_scheme;
		fail_reason += " not supported.";
		return false;
	}

	const t_digest_challenge &dchlg = chlg.digest_challenge;

	// Only MD5 algorithm is supported
	if (dchlg.algorithm != ALG_MD5) {
		fail_reason = "Authentication algorithm " + dchlg.algorithm;
		fail_reason += " not supported.";
		return false;
	}

	// Determine QOP
	if (!dchlg.qop_options.empty()) {
		const list<string>::const_iterator i = find(
			dchlg.qop_options.begin(), dchlg.qop_options.end(),
			QOP_AUTH_INT);
		const list<string>::const_iterator j = find(
			dchlg.qop_options.begin(), dchlg.qop_options.end(),
			QOP_AUTH);
		if (i != dchlg.qop_options.end())
			qop = QOP_AUTH_INT;
		else {
			if (j != dchlg.qop_options.end())
				qop = QOP_AUTH;
			else {
				fail_reason = "Non of the qop values are supported.";
				return false;
			}
		}
	}

	// RFC 2617 3.2.2.2
	A1 = username + ":" + dchlg.realm + ":" + passwd;

	// RFC 2617 3.2.2.3
	if (qop == QOP_AUTH || qop == "") {
		A2 = method2str(method, unknown_method) + ":" + uri.encode();
	} else {
		A2 = method2str(method, unknown_method) + ":" + uri.encode();
		A2 += ":";
		if (body) {
			MD5Digest MD5body;
			MD5body << body->encode();
			ostringstream os;
			os << MD5body;
			A2 += os.str();
		} else {
			MD5Digest MD5body;
			MD5body << "";
			ostringstream os;
			os << MD5body;
			A2 += os.str();
		}
	}

	// RFC 2716 3.2.2.1
	// Caculate digest
	MD5Digest MD5A1;
	MD5Digest MD5A2;
	ostringstream HA1;
	ostringstream HA2;

	MD5A1 << A1;
	MD5A2 << A2;
	HA1 << MD5A1;
	HA2 << MD5A2;

	string x;

	if (qop == QOP_AUTH || qop == QOP_AUTH_INT) {
		x = HA1.str() + ":";
		x += dchlg.nonce + ":";
		x += int2str(nc, "%08x") + ":";
		x += cnonce + ":";
		x += qop + ":";
		x += HA2.str();
	} else {
		x = HA1.str() + ":";
		x += dchlg.nonce + ":";
		x += HA2.str();
	}

	// Create credentials
	cr.auth_scheme = AUTH_DIGEST;
	t_digest_response &dr = cr.digest_response;

	MD5Digest digest;
	digest << x;
	ostringstream dresp;
	dresp << digest;

	dr.dresponse = dresp.str();
	dr.username = username;
	dr.realm = dchlg.realm;
	dr.nonce = dchlg.nonce;
	dr.digest_uri = uri;
	dr.algorithm = ALG_MD5;
	dr.opaque = dchlg.opaque;

	// RFC 2617 3.2.2
	if (qop != "") {
		dr.message_qop = qop;
		dr.cnonce = cnonce;
		dr.nonce_count = nc;
	}

	return true;
}

t_request::t_request() : t_sip_message() {
	method = METHOD_UNKNOWN;
}

t_request::t_request(const t_request &r) : t_sip_message(r),
		uri(r.uri),
		method(r.method)
{
}

t_request::t_request(const t_method m) : t_sip_message() {
	method = m;
}

void t_request::set_method(const string &s) {
	method = str2method(s);
	if (method == METHOD_UNKNOWN) {
		unknown_method = s;
	}
}

string t_request::encode(void) {
	string s;

	s = method2str(method, unknown_method) + ' ' + uri.encode();
	s += " SIP/";
	s += version;
	s += CRLF;
	s += t_sip_message::encode();
	return s;
}

t_sip_message *t_request::copy(void) const {
	t_sip_message *m =  new t_request(*this);
	MEMMAN_NEW(m);
	return m;
}

t_response *t_request::create_response(int code, string reason) const
{
	t_response *r;

	r = new t_response(code, reason);
	MEMMAN_NEW(r);
	r->hdr_from = hdr_from;
	r->hdr_call_id = hdr_call_id;
	r->hdr_cseq = hdr_cseq;
	r->hdr_via = hdr_via;
	r->hdr_to = hdr_to;

	// Create a to-tag if none was present in the request
	if (hdr_to.tag.size() == 0) {
		r->hdr_to.set_tag(NEW_TAG);
	}

	// Server
	SET_HDR_SERVER(r->hdr_server);

	return r;
}

bool t_request::is_valid(bool &fatal, string &reason) const {
	if (!t_sip_message::is_valid(fatal, reason)) return false;

	fatal = false;

	if (t_parser::check_max_forwards && !hdr_max_forwards.is_populated()) {
		reason = "Max-Forwards header missing";
		return false;
	}

	switch(method) {
	case INVITE:
		if (!hdr_contact.is_populated()) {
			reason = "Contact header missing";
			return false;
		}
		break;
	case PRACK:
		// RFC 3262 7.1
		if (!hdr_rack.is_populated()) {
			reason = "RAck header missing";
			return false;
		}
		break;
	}

	return true;
}

void t_request::get_destination(unsigned long &ipaddr, unsigned short &port,
			const t_user &user_profile)
{
	// Send a REGISTER to the registrar if provisioned.
	if (method == REGISTER && user_profile.use_registrar) {
		ipaddr = user_profile.registrar.get_h_ip();
		port = user_profile.registrar.get_hport();
		return;
	}

	// A mid dialog request will go to the host in the contact
	// header (put in the request-URI in this request) or route list
	// specified in the final response of the invite (the Route-header in
	// this request).
	// Note that an ACK for a failed INVITE (3XX-6XX) will be
	// sent by the transaction layer to the ipaddr/port of the
	// INVITE.
	if (hdr_route.is_populated() && hdr_route.route_to_first_route) {
		// Take URI from first route-header
		t_url &u = hdr_route.route_list.front().uri;
		ipaddr = u.get_h_ip();
		port = u.get_hport();
	} else {
		// Take Request-URI
		ipaddr = uri.get_h_ip();
		port = uri.get_hport();
	}

	// Verify if the destination is overriden by outbound proxy settings
	if (user_profile.use_outbound_proxy) {
		if (user_profile.non_resolvable_to_proxy &&
		    ipaddr != 0 && port != 0)
		{
			// The destination has been resolved, so do not
			// use the outbound proxy in this case.
			return;
		}

		if (user_profile.all_requests_to_proxy) {
			// All requests should go to the proxy.
			// Override destination by the outbound proxy address.
			ipaddr = user_profile.outbound_proxy.get_h_ip();
			port = user_profile.outbound_proxy.get_hport();
			return;
		} else if (hdr_to.tag == "") {
			// Only out-of-dialog requests (including
			// initial INVITE) should go to the outbound
			// proxy.
			// Override destination by the outbound proxy address.
			ipaddr = user_profile.outbound_proxy.get_h_ip();
			port = user_profile.outbound_proxy.get_hport();
			return;
		}
	}
}

bool t_request::www_authorize(const t_challenge &chlg, const string &username,
	       const string &passwd, unsigned long nc,
	       const string &cnonce, t_credentials &cr, string &fail_reason)
{
	if (!authorize(chlg, username, passwd, nc, cnonce, cr, fail_reason)) {
		return false;
	}

	hdr_authorization.add_credentials(cr);

	return true;
}

bool t_request::proxy_authorize(const t_challenge &chlg, const string &username,
	       const string &passwd, unsigned long nc,
	       const string &cnonce, t_credentials &cr, string &fail_reason)
{
	if (!authorize(chlg, username, passwd, nc, cnonce, cr, fail_reason)) {
		return false;
	}

	hdr_proxy_authorization.add_credentials(cr);

	return true;
}
