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

// State of active phone user

#ifndef _PHONE_USER_H
#define _PHONE_USER_H

#include <string>
#include <list>
#include "auth.h"
#include "protocol.h"
#include "service.h"
#include "transaction_layer.h"
#include "user.h"
#include "parser/request.h"
#include "parser/response.h"
#include "stun/stun.h"

using namespace std;

// Forward declarations
class t_client_request;

class t_phone_user {
private:
	t_user			*user_config;

	// State
	// Indicates that this user is active. A non-active user
	// is not removed from the user list as some transactions may
	// still need the user info after the user got de-activated.
	bool			active;

	// Requests outside a dialog
	t_client_request	*r_options;
	t_client_request	*r_register;
	t_client_request	*r_deregister;
	t_client_request	*r_query_register;
	
	// STUN request
	t_client_request	*r_stun;

	// Registration data
	string			register_call_id;
	unsigned long		register_seqnr; // last seqnr to issued
	bool			is_registered;
	unsigned long		registration_time; // expiration in seconds
	bool			last_reg_failed; // last registration failed
	unsigned long		register_ipaddr; // Dest IP addr of last REGISTER
	unsigned short		register_port; // Dest port of last REGISTER
	
	// STUN data
	unsigned long		stun_public_ip_sip; // Public IP for SIP
	unsigned short		stun_public_port_sip; // Public port for SIP
	
	// Authorizor
	t_auth			authorizor;
	
	// Resend the request: a new sequence number will be assigned and a new via
	// header created (new transaction).
	// is_register indicates is this request is a register
	// cr is the current client request for this request.
	void resend_request(t_request *req, bool is_register, t_client_request *cr);

	// Handle REGISTER repsonses. On return the re-register indicates
	// if an automatic re-registration needs to be done.
	void handle_response_register(t_response *r, bool &re_register);
	void handle_response_deregister(t_response *r);
	void handle_response_query_register(t_response *r);

	void handle_response_options(t_response *r);
	
	// Send a NAT keep alive packet
	void send_nat_keepalive(void);
	
public:
	// Timers
	unsigned short		id_registration;
	unsigned short		id_nat_keepalive;
	
	// Supplementary services
	t_service	service;
	
	// STUN
	bool		use_stun; // Indicates if STUN must be used
	bool		use_nat_keepalive; // Send NAT keepalive ?
	
	// The constructor will create a copy of profile.
	t_phone_user(const t_user &profile);
	~t_phone_user();
	
	t_user *get_user_profile(void);
	
	// Handle responses for out-of-dialog requests
	void handle_response_out_of_dialog(t_response *r, t_tuid tuid);
	void handle_response_out_of_dialog(StunMessage *r, t_tuid tuid);
	
	void registration(t_register_type register_type, bool re_register,
					unsigned long expires = 0);
					
	// OPTIONS outside dialog
	void options(const t_url &to_uri, const string &to_display = "");
	
	void timeout(t_phone_timer timer);
	
	// Create request. Headers that are the same for each request
	// are already populated.
	t_request *create_request(t_method m, const t_url &request_uri) const;
	
	// Create a response to an OPTIONS request
	// Argument 'in-dialog' indicates if the OPTIONS response is
	// sent within a dialog.
	t_response *create_options_response(t_request *r,
					bool in_dialog = false) const;
	
	// Get registration status
	bool get_is_registered(void) const;
	bool get_last_reg_failed(void) const;
	
	// Get IP address and port for SIP
	string get_ip_sip(void) const;
	unsigned short get_public_port_sip(void) const;
	
	// Try to match message with phone user
	bool match(t_response *r, t_tuid tuid) const;
	bool match(t_request *r) const;
	bool match(StunMessage *r, t_tuid tuid) const;
	
	// Authorize the request based on the challenge in the response
	// Returns false if authorization fails.
	bool authorize(t_request *r, t_response *resp);
	
	// Remove cached credentials for a particular realm
	void remove_cached_credentials(const string &realm);
	
	bool is_active(void) const;
	void activate(const t_user &user);
	void deactivate(void);
};

#endif
