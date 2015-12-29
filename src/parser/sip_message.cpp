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

#include "sip_message.h"
#include "util.h"
#include "parse_ctrl.h"
#include "sdp/sdp.h"
#include "audits/memman.h"

////////////////////////////////////
// class t_sip_message
////////////////////////////////////

t_sip_message::t_sip_message() {
	version = SIP_VERSION;
	body = NULL;
}

t_sip_message::t_sip_message(const t_sip_message& m) :
		version(m.version),
		hdr_accept(m.hdr_accept),
		hdr_accept_encoding(m.hdr_accept_encoding),
		hdr_accept_language(m.hdr_accept_language),
		hdr_alert_info(m.hdr_alert_info),
		hdr_allow(m.hdr_allow),
		hdr_auth_info(m.hdr_auth_info),
		hdr_authorization(m.hdr_authorization),
		hdr_call_id(m.hdr_call_id),
		hdr_call_info(m.hdr_call_info),
		hdr_contact(m.hdr_contact),
		hdr_content_disp(m.hdr_content_disp),
		hdr_content_encoding(m.hdr_content_encoding),
		hdr_content_language(m.hdr_content_language),
		hdr_content_length(m.hdr_content_length),
		hdr_content_type(m.hdr_content_type),
		hdr_cseq(m.hdr_cseq),
		hdr_date(m.hdr_date),
		hdr_error_info(m.hdr_error_info),
		hdr_expires(m.hdr_expires),
		hdr_from(m.hdr_from),
		hdr_in_reply_to(m.hdr_in_reply_to),
		hdr_max_forwards(m.hdr_max_forwards),
		hdr_min_expires(m.hdr_min_expires),
		hdr_mime_version(m.hdr_mime_version),
		hdr_organization(m.hdr_organization),
		hdr_priority(m.hdr_priority),
		hdr_proxy_authenticate(m.hdr_proxy_authenticate),
		hdr_proxy_authorization(m.hdr_proxy_authorization),
		hdr_proxy_require(m.hdr_proxy_require),
		hdr_rack(m.hdr_rack),
		hdr_record_route(m.hdr_record_route),
		hdr_reply_to(m.hdr_reply_to),
		hdr_require(m.hdr_require),
		hdr_retry_after(m.hdr_retry_after),
		hdr_route(m.hdr_route),
		hdr_rseq(m.hdr_rseq),
		hdr_server(m.hdr_server),
		hdr_subject(m.hdr_subject),
		hdr_supported(m.hdr_supported),
		hdr_timestamp(m.hdr_timestamp),
		hdr_to(m.hdr_to),
		hdr_unsupported(m.hdr_unsupported),
		hdr_user_agent(m.hdr_user_agent),
		hdr_via(m.hdr_via),
		hdr_warning(m.hdr_warning),
		hdr_www_authenticate(m.hdr_www_authenticate),
		unknown_headers(m.unknown_headers)
{
	if (m.body) {
		body = m.body->copy();
	} else {
		body = NULL;
	}
}

t_sip_message::~t_sip_message() {
	if (body) {
		MEMMAN_DELETE(body);
		delete body;
	}
}

void t_sip_message::add_unknown_header(const string &name,
				       const string &value) {
	t_parameter h(name, value);
	unknown_headers.push_back(h);
}

bool t_sip_message::is_valid(bool &fatal, string &reason) const {

	// RFC 3261 8.1.1
	// Mandatory headers
	if (!hdr_to.is_populated()) {
		fatal = true;
		reason = "To-header missing";
		return false;
	}

	if (!hdr_from.is_populated()) {
		fatal = true;
		reason = "From header missing";
		return false;
	}

	if (!hdr_cseq.is_populated()) {
		fatal = true;
		reason = "CSeq header missing";
		return false;
	}

	if (!hdr_call_id.is_populated()) {
		fatal = true;
		reason = "Call-ID header missing";
		return false;
	}

	if (!hdr_via.is_populated()) {
		fatal = true;
		reason = "Via header missing";
		return false;
	}

	// RFC 3261 20.15
	// Content-Type MUST be present if body is not empty
	if (body && !hdr_content_type.is_populated()) {
		fatal = false;
		reason = "Content-Type header missing";
		return false;
	}

	return true;
}

string t_sip_message::encode(void) {
	string s;
	string encoded_body;

	// RFC 3261 7.3.1
	// Headers needed by a proxy should be on top
	s += hdr_via.encode();
	s += hdr_route.encode();
	s += hdr_record_route.encode();
	s += hdr_proxy_require.encode();
	s += hdr_max_forwards.encode();
	s += hdr_proxy_authenticate.encode();
	s += hdr_proxy_authorization.encode();

	// Order as in many examples
	s += hdr_to.encode();
	s += hdr_from.encode();
	s += hdr_call_id.encode();
	s += hdr_cseq.encode();
	s += hdr_contact.encode();
	s += hdr_content_type.encode();

	// Authentication headers
	s += hdr_auth_info.encode();
	s += hdr_authorization.encode();
	s += hdr_www_authenticate.encode();

	// Remaining headers in alphabetical order
	s += hdr_accept.encode();
	s += hdr_accept_encoding.encode();
	s += hdr_accept_language.encode();
	s += hdr_alert_info.encode();
	s += hdr_allow.encode();
	s += hdr_call_info.encode();
	s += hdr_content_disp.encode();
	s += hdr_content_encoding.encode();
	s += hdr_content_language.encode();
	s += hdr_date.encode();
	s += hdr_error_info.encode();
	s += hdr_expires.encode();
	s += hdr_in_reply_to.encode();
	s += hdr_min_expires.encode();
	s += hdr_mime_version.encode();
	s += hdr_organization.encode();
	s += hdr_priority.encode();
	s += hdr_rack.encode();
	s += hdr_reply_to.encode();
	s += hdr_require.encode();
	s += hdr_retry_after.encode();
	s += hdr_rseq.encode();
	s += hdr_server.encode();
	s += hdr_subject.encode();
	s += hdr_supported.encode();
	s += hdr_timestamp.encode();
	s += hdr_unsupported.encode();
	s += hdr_user_agent.encode();
	s += hdr_warning.encode();

	// Unknown headers
	for (list<t_parameter>::const_iterator i = unknown_headers.begin();
	     i != unknown_headers.end(); i++)
	{
		s += i->name;
		s += ": ";
		s += i->value;
		s += CRLF;
	}

	// Encode body if present. Set the content length.
	if (body) {
		encoded_body = body->encode();
		hdr_content_length.set_length(encoded_body.size());
	} else {
		// RFC 3261 20.14
		// If no body is present then Content-Length MUST be 0
		hdr_content_length.set_length(0);
	}

	// Content-Length appears last in examples
	s += hdr_content_length.encode();

	// Blank line between headers and body
	s += CRLF;

	// Add body
	if (body) s += encoded_body;

	return s;
}
