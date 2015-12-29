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

// Request

#ifndef _REQUEST_H
#define _REQUEST_H

#include <string>
#include "response.h"
#include "sip_message.h"
#include "sockets/url.h"
#include "user.h"

using namespace std;

class t_request : public t_sip_message {
private:
	// Calculate credentials based on the challenge
	// Returns false if challenge is not supported; in this case
	// fail_reason contains the reason for failure.
	bool authorize(const t_challenge &chlg, const string &username,
		       const string &passwd, unsigned long nc,
		       const string &cnonce, t_credentials &cr,
		       string &fail_reason) const;

public:
	t_url		uri;
	t_method	method;
	string		unknown_method; // set if method is UNKNOWN

	t_request();
	t_request(const t_request &r);
	t_request(const t_method m);

	t_msg_type get_type(void) const { return MSG_REQUEST; }
	void set_method(const string &s);
	string encode(void);
	t_sip_message *copy(void) const;

	// Create a response with response code based on the
	// request. The response is created following the general
	// rules in RFC 3261 8.2.6.2.
	// The to-hdr is simply copied from the request to the
	// response.
	// If the to-tag is missing, then
	// a to-tag will be generated and added to the to-header
	// of the response.
	// A specific reason may be added to the status code.
	t_response *create_response(int code, string reason = "") const;

	bool is_valid(bool &fatal, string &reason) const;

	void get_destination(unsigned long &ipaddr, unsigned short &port,
		const t_user &user_profile);

	// Create authorization credentials based on the challenge
	// Returns false if challenge is not supported and fail_reason
	// contains the reason for failure.
	// Returns true if authorization succeeded and cr will contain
	// the credentials.
	bool www_authorize(const t_challenge &chlg, const string &username,
	       const string &passwd, unsigned long nc,
	       const string &cnonce, t_credentials &cr, string &fail_reason);

	bool proxy_authorize(const t_challenge &chlg, const string &username,
	       const string &passwd, unsigned long nc,
	       const string &cnonce, t_credentials &cr, string &fail_reason);
};

#endif
