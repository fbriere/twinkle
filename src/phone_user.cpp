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

#include "phone_user.h"
#include "log.h"
#include "userintf.h"
#include "util.h"
#include "audits/memman.h"

extern t_phone 		*phone;
extern t_event_queue	*evq_sender_udp;
extern string		user_host;

t_phone_user::t_phone_user(const t_user &profile) {
	user_config = profile.copy();
	service = new t_service(user_config);
	MEMMAN_NEW(service);
	
	active = true;

	r_options = NULL;
	r_register = NULL;
	r_deregister = NULL;
	r_query_register = NULL;
	r_stun = NULL;
	
	// Initialize registration data
	// Call-ID cannot be set here as user_host is not determined yet.
	register_seqnr = NEW_SEQNR;
	is_registered = false;
	register_ipaddr = 0L;
	register_port = 0;
	last_reg_failed = false;
	
	// Initialize STUN data
	stun_public_ip_sip = 0L;
	stun_public_port_sip = 0;
	use_stun = false;
	use_nat_keepalive = false;
	
	// Timers
	id_registration = 0;
	id_nat_keepalive = 0;
}

t_phone_user::~t_phone_user() {
	// Stop timers
	if (id_registration) phone->stop_timer(PTMR_REGISTRATION, this);
	if (id_nat_keepalive) phone->stop_timer(PTMR_NAT_KEEPALIVE, this);

	// Delete pointers
	if (r_options) {
		MEMMAN_DELETE(r_options);
		delete r_options;
	}
	if (r_register) {
		MEMMAN_DELETE(r_register);
		delete r_register;
	}
	if (r_deregister) {
		MEMMAN_DELETE(r_deregister);
		delete r_deregister;
	}
	if (r_query_register) {
		MEMMAN_DELETE(r_query_register);
		delete r_query_register;
	}
	if (r_stun) {
		MEMMAN_DELETE(r_stun);
		delete r_stun;
	}
	
	MEMMAN_DELETE(service);
	delete service;
	MEMMAN_DELETE(user_config);
	delete user_config;
}

t_user *t_phone_user::get_user_profile(void) {
	return user_config;
}

void t_phone_user::registration(t_register_type register_type, bool re_register,
		unsigned long expires)
{
	// If STUN is enabled, then do a STUN query before registering if not
	// done so already.
	if (register_type == REG_REGISTER && use_stun &&
	    stun_public_ip_sip == 0)
	{
		if (r_stun) return;
	
		StunMessage req;
		StunAtrString username;
		username.sizeValue = 0;
		stunBuildReqSimple(&req, username, false, false);
		r_stun = new t_client_request(user_config, &req, 0);
		MEMMAN_NEW(r_stun);
		phone->send_request(user_config, &req, r_stun->get_tuid());
		registration_time = expires;
		return;
	}

	// Stop registration timer for non-query request
	if (register_type != REG_QUERY) {
		phone->stop_timer(PTMR_REGISTRATION, this);
	}

	// Create call-id if no call-id is created yet
	if (register_call_id == "") {
		register_call_id = NEW_CALL_ID(user_config);
	}

	// RFC 3261 10.2
	// Construct REGISTER request

	t_request *req = create_request(REGISTER, 
			t_url(string(USER_SCHEME) + ":" + user_config->get_domain()));

	// To
	req->hdr_to.set_uri(user_config->create_user_uri());
	req->hdr_to.set_display(user_config->get_display());

	//Call-ID
	req->hdr_call_id.set_call_id(register_call_id);

	// CSeq
	req->hdr_cseq.set_method(REGISTER);
	req->hdr_cseq.set_seqnr(++register_seqnr);

	// Contact
        t_contact_param contact;

        switch (register_type) {
        case REG_REGISTER:
                contact.uri.set_url(user_config->create_user_contact());
                if (expires > 0) {
			if (user_config->get_registration_time_in_contact()) {
				contact.set_expires(expires);
			} else {
				req->hdr_expires.set_time(expires);
			}
		}
                req->hdr_contact.add_contact(contact);
                break;
        case REG_DEREGISTER:
                contact.uri.set_url(user_config->create_user_contact());
 		if (user_config->get_registration_time_in_contact()) {
			contact.set_expires(0);
		} else {
			req->hdr_expires.set_time(0);
		}
                req->hdr_contact.add_contact(contact);
                break;
        case REG_DEREGISTER_ALL:
                req->hdr_contact.set_any();
                req->hdr_expires.set_time(0);
                break;
        default:
                break;
        }

	// Allow
	SET_HDR_ALLOW(req->hdr_allow, user_config);

	// Store request in the proper place
	t_tuid tuid;

        switch(register_type) {
        case REG_REGISTER:
		// Delete a possible pending registration request
		if (r_register) {
			MEMMAN_DELETE(r_register);
			delete r_register;
		}
                r_register = new t_client_request(user_config, req, 0);
		MEMMAN_NEW(r_register);
                tuid = r_register->get_tuid();

                // Store expiration time for re-registration.
                registration_time = expires;
                break;
        case REG_QUERY:
		// Delete a possible pending query registration request
		if (r_query_register) {
			MEMMAN_DELETE(r_query_register);
			delete r_query_register;
		}
                r_query_register = new t_client_request(user_config, req, 0);
		MEMMAN_NEW(r_query_register);
                tuid = r_query_register->get_tuid();
                break;
        case REG_DEREGISTER:
        case REG_DEREGISTER_ALL:
		// Delete a possible pending de-registration request
		if (r_deregister) {
			MEMMAN_DELETE(r_deregister);
			delete r_deregister;
		}
                r_deregister = new t_client_request(user_config, req, 0);
		MEMMAN_NEW(r_deregister);
                tuid = r_deregister->get_tuid();
                break;
        default:
                assert(false);
        }

        // Send REGISTER
        authorizor.set_re_register(re_register);
	ui->cb_register_inprog(user_config, register_type);
        phone->send_request(user_config, req, tuid);
	MEMMAN_DELETE(req);
        delete req;
}

void t_phone_user::options(const t_url &to_uri, const string &to_display) {
	// RFC 3261 11.1
	// Construct OPTIONS request

	t_request *req = create_request(OPTIONS, to_uri);

	// To
	req->hdr_to.set_uri(to_uri);
	req->hdr_to.set_display(to_display);

	// Call-ID
	req->hdr_call_id.set_call_id(NEW_CALL_ID(user_config));

	// CSeq
	req->hdr_cseq.set_method(OPTIONS);
	req->hdr_cseq.set_seqnr(NEW_SEQNR);

	// Accept
	req->hdr_accept.add_media(t_media("application","sdp"));

	// Store and send request
	// Delete a possible pending options request
	if (r_options) {
		MEMMAN_DELETE(r_options);
		delete r_options;
	}
	r_options = new t_client_request(user_config, req, 0);
	MEMMAN_NEW(r_options);
	phone->send_request(user_config, req, r_options->get_tuid());
	MEMMAN_DELETE(req);
	delete req;
}

void t_phone_user::handle_response_out_of_dialog(t_response *r, t_tuid tuid) {
	t_client_request **current_cr;
	t_request *req;
	bool is_register = false;

	if (r_register && r_register->get_tuid() == tuid) {
		current_cr = &r_register;
		is_register = true;
	} else if (r_deregister && r_deregister->get_tuid() == tuid) {
		current_cr = &r_deregister;
		is_register = true;
	} else if (r_query_register && r_query_register->get_tuid() == tuid) {
		current_cr = &r_query_register;
		is_register = true;
	} else if (r_options && r_options->get_tuid() == tuid) {
		current_cr = &r_options;
	} else {
		// Response does not match any pending request.
		return;
	}

	req = (*current_cr)->get_request();

	// Authentication
	if (r->must_authenticate()) {
		if (authorize(req, r)) {
			resend_request(req, is_register, *current_cr);
			return;
		}

		// Authentication failed
		// Handle the 401/407 as a normal failure response
	}
	
	// RFC 3263 4.3
	// Failover
	if (r->code == R_503_SERVICE_UNAVAILABLE) {
		if (req->next_destination()) {
			log_file->write_report("Failover to next destination.",
				"t_phone_user::handle_response_out_of_dialog");
			resend_request(req, is_register, *current_cr);
			return;
		}			
	}

	// Redirect request if there is another destination
	if (user_config->get_allow_redirection()) {
		// If the response is a 3XX response then add redirection
		// contacts
		if (r->get_class() == R_3XX  &&
		    r->hdr_contact.is_populated())
		{
			(*current_cr)->redirector.add_contacts(
					r->hdr_contact.contact_list);
		}

		// Get next destination
		t_contact_param contact;
		if ((*current_cr)->redirector.get_next_contact(contact)) {
			// Ask user for permission to redirect if indicated
			// by user config
			bool permission = true;
			if (user_config->get_ask_user_to_redirect()) {
				permission = ui->cb_ask_user_to_redirect_request(
							user_config,
							contact.uri, contact.display,
							r->hdr_cseq.method);
			}

			if (permission) {
				req->uri = contact.uri;
				req->calc_destinations(*user_config);
				ui->cb_redirecting_request(user_config, contact);
				resend_request(req, is_register, *current_cr);
				return;
			}
		}
	}

	// REGISTER (register)
	if (r_register && r_register->get_tuid() == tuid) {
		bool re_register;
		handle_response_register(r, re_register);
		MEMMAN_DELETE(r_register);
		delete r_register;
		r_register = NULL;
		if (re_register) registration(REG_REGISTER, authorizor.get_re_register(), 
				registration_time);
		return;
	}

	// REGISTER (de-register)
	if (r_deregister && r_deregister->get_tuid() == tuid) {
		handle_response_deregister(r);
		MEMMAN_DELETE(r_deregister);
		delete r_deregister;
		r_deregister = NULL;
		return;
	}

	// REGISTER (query)
	if (r_query_register && r_query_register->get_tuid() == tuid) {
		handle_response_query_register(r);
		MEMMAN_DELETE(r_query_register);
		delete r_query_register;
		r_query_register = NULL;
		return;
	}


	// OPTIONS
	if (r_options && r_options->get_tuid() == tuid) {
		handle_response_options(r);
		MEMMAN_DELETE(r_options);
		delete r_options;
		r_options = NULL;
		return;
	}

	// Response does not match any pending request. Do nothing.
}

void t_phone_user::resend_request(t_request *req, bool is_register, t_client_request *cr) {
	// A new sequence number must be assigned
	if (is_register) {
		req->hdr_cseq.set_seqnr(++register_seqnr);
	} else {
		req->hdr_cseq.seqnr++;
	}

	// Create a new via-header. Otherwise the
	// request will be seen as a retransmission
	req->hdr_via.via_list.clear();
	t_via via(USER_HOST(user_config), sys_config->get_sip_udp_port());
	req->hdr_via.add_via(via);

	cr->renew(0);
	phone->send_request(user_config, req, cr->get_tuid());
}

void t_phone_user::handle_response_out_of_dialog(StunMessage *r, t_tuid tuid) {
	if (!r_stun || r_stun->get_tuid() != tuid) {
		// Response does not match pending STUN request
		return;
	}
	
	if (r->msgHdr.msgType == BindResponseMsg && r->hasMappedAddress) {
		// The STUN response contains the public IP.
		stun_public_ip_sip = r->mappedAddress.ipv4.addr;
		stun_public_port_sip = r->mappedAddress.ipv4.port;
                MEMMAN_DELETE(r_stun);
                delete r_stun;
                r_stun = NULL;
                registration(REG_REGISTER, false, registration_time);
                return;
	}
	
	if (r->msgHdr.msgType == BindErrorResponseMsg && r->hasErrorCode) {
		// STUN request failed.
                ui->cb_stun_failed(r->errorCode.errorClass * 100 +
                	r->errorCode.number, r->errorCode.reason);
	} else {	
		// No satisfying STUN response was received.
 	       ui->cb_stun_failed();
	}
	
        MEMMAN_DELETE(r_stun);
        delete r_stun;
        r_stun = NULL;
	
        // Try registration later.
	bool first_failure = !last_reg_failed;
        last_reg_failed = true;
        is_registered = false;
	ui->cb_register_stun_failed(user_config, first_failure);
        phone->start_set_timer(PTMR_REGISTRATION, DUR_REG_FAILURE * 1000, this);
}

void t_phone_user::handle_response_register(t_response *r, bool &re_register) {
	t_contact_param *c;
	unsigned long expires;
	unsigned long e;
	bool first_failure, first_success;

	re_register = false;
	
	// Store the destination IP address/port of the REGISTER message.
	// To this destination the NAT keep alive packets will be sent.
	t_request *req = r_register->get_request();
	req->get_destination(register_ipaddr, register_port, *user_config);

        switch(r->get_class()) {
        case R_2XX:
                last_reg_failed = false;

                // Stop registration timer if one was running
                phone->stop_timer(PTMR_REGISTRATION, this);

                c = r->hdr_contact.find_contact(user_config->create_user_contact());
                if (!c) {               	
	               	if (!user_config->get_allow_missing_contact_reg()) {
				is_registered = false;

	              		log_file->write_report(
        	       			"Contact header is missing.",
               				"t_phone_user::handle_response_register",
               				LOG_NORMAL, LOG_WARNING);
				
				ui->cb_invalid_reg_resp(user_config,
					r, "Contact header missing.");
				return;
                        }
                }

                if (c && c->is_expires_present() && c->get_expires() != 0) {
                        expires = c->get_expires();
                }
                else if (r->hdr_expires.is_populated() &&
                         r->hdr_expires.time != 0)
                {
                        expires = r->hdr_expires.time;
                }
                else {	
               		if (!user_config->get_allow_missing_contact_reg()) {
				is_registered = false;
				
               			log_file->write_report(
               				"Expires parameter/header mising.",
               				"t_phone_user::handle_response_register",
               				LOG_NORMAL, LOG_WARNING);
				
				ui->cb_invalid_reg_resp(user_config,
					r, "Expires parameter/header mising.");
				return;
                        }
                        
                        expires = user_config->get_registration_time();
                        
                        // Assume a default expiration of 3600 sec if no expiry
                        // time was returned.
                        if (expires == 0) expires = 3600;
                }

                // Start new registration timer
                // The maximum value of the timer can be 2^32-1 s
                // The maximum timer that we can handle however is 2^31-1 ms
                e = (expires > 2147483 ? 2147483 : expires);
                phone->start_set_timer(PTMR_REGISTRATION, e * 1000, this);
		first_success = !is_registered;
                is_registered = true;
		ui->cb_register_success(user_config, r, expires, first_success);
		
		// Start sending NAT keepalive packets when STUN is used
		// (or in case of symmetric firewall)
		if (use_nat_keepalive && id_nat_keepalive == 0) {
			// Just start the NAT keepalive timer. The REGISTER
			// message itself created the NAT binding. So there is
			// no need to send a NAT keep alive packet now.
			phone->start_timer(PTMR_NAT_KEEPALIVE, this);
		}

                break;
        case R_4XX:
                is_registered = false;

                // RFC 3261 10.3
                if (r->code == R_423_INTERVAL_TOO_BRIEF) {
                        if (!r->hdr_min_expires.is_populated()) {
                                // Violation of RFC 3261 10.3 item 7
                                ui->cb_invalid_reg_resp(user_config, r,
                                        "Min-Expires header missing.");
                                return;
                        }

                        if (r->hdr_min_expires.time <= registration_time) {
                                // Wrong Min-Expires time
                                string s = "Min-Expires (";
                                s += ulong2str(r->hdr_min_expires.time);
                                s += ") is smaller than the requested ";
                                s += "time (";
                                s += ulong2str(registration_time);
                                s += ")";
                                ui->cb_invalid_reg_resp(user_config, r, s);
                                return;
                        }

                        // Automatic re-register with Min-Expires time
                        registration_time = r->hdr_min_expires.time;
                        re_register = true;
                        return;
                }

		// If authorization failed, then do not start the continuous
		// re-attempts. When authorization fails the user is asked
		// for credentials (in GUI). So the user cancelled these
		// questions and should not be bothered with the same question
		// again every 30 seconds. The user does not have the
		// credentials.
		if (r->code == R_401_UNAUTHORIZED ||
		    r->code == R_407_PROXY_AUTH_REQUIRED)
		{
			last_reg_failed = true;
			ui->cb_register_failed(user_config, r, true);			
	
			return;
		}

                // fall thru
        default:
		first_failure = !last_reg_failed;
                last_reg_failed = true;
                is_registered = false;
                authorizor.remove_from_cache(""); // Clear credentials cache
		ui->cb_register_failed(user_config, r, first_failure);
                phone->start_set_timer(PTMR_REGISTRATION, DUR_REG_FAILURE * 1000, this);
                
		// Clear STUN information
		if (use_stun) {
			stun_public_ip_sip = 0L;
			stun_public_port_sip = 0;
		}
		
		if (use_nat_keepalive) {
			phone->stop_timer(PTMR_NAT_KEEPALIVE, this);
		}
        }
}

void t_phone_user::handle_response_deregister(t_response *r) {
	is_registered = false;
	last_reg_failed = false;

	if (r->is_success()) {
		ui->cb_deregister_success(user_config, r);
	} else {
		ui->cb_deregister_failed(user_config, r);
	}
	
	// Clear STUN information
	if (use_stun) {
		stun_public_ip_sip = 0L;
		stun_public_port_sip = 0;
	}
	
	if (use_nat_keepalive) {
		phone->stop_timer(PTMR_NAT_KEEPALIVE, this);
	}
}

void t_phone_user::handle_response_query_register(t_response *r) {
	if (r->is_success()) {
		ui->cb_fetch_reg_result(user_config, r);
	} else {
		ui->cb_fetch_reg_failed(user_config, r);
	}
}

void t_phone_user::handle_response_options(t_response *r) {
	ui->cb_options_response(r);
}

void t_phone_user::send_nat_keepalive(void) {
	if (register_ipaddr == 0 || register_port == 0) {
		log_file->write_report(
			"Cannot resolve destination for NAT keepalive packet.",
			"t_phone_user::send_nat_keepalive", LOG_NORMAL, LOG_CRITICAL);
		return;
	}
		
	evq_sender_udp->push_nat_keepalive(register_ipaddr, register_port);
}

void t_phone_user::timeout(t_phone_timer timer) {
	switch (timer) {
	case PTMR_REGISTRATION:
		id_registration = 0;
		
		// Registration expired. Re-register.
		if (is_registered || last_reg_failed) {
			// Re-register if no register is pending
			if (!r_register) {
				registration(REG_REGISTER, true, registration_time);
			}
		}
		break;
	case PTMR_NAT_KEEPALIVE:
		id_nat_keepalive = 0;
		
		// Send a new NAT keepalive packet
		if (use_nat_keepalive) {
			send_nat_keepalive();
			phone->start_timer(PTMR_NAT_KEEPALIVE, this);
		}
		break;
	default:
		assert(false);
	}
}

t_request *t_phone_user::create_request(t_method m, const t_url &request_uri) const {
	t_request *req = new t_request(m);
	MEMMAN_NEW(req);

	// Via
	t_via via(USER_HOST(user_config), sys_config->get_sip_udp_port());
	req->hdr_via.add_via(via);

	// From
	req->hdr_from.set_uri(user_config->create_user_uri());
	req->hdr_from.set_display(user_config->get_display());
	req->hdr_from.set_tag(NEW_TAG);

	// Max-Forwards header (mandatory)
	req->hdr_max_forwards.set_max_forwards(MAX_FORWARDS);

	// User-Agent
	SET_HDR_USER_AGENT(req->hdr_user_agent);
	
	// Set request URI and calculate destinations. By calculating
	// destinations now, the request can be resend to a next destination
	// if failover is needed.
	req->uri = request_uri;
	req->calc_destinations(*user_config);

	return req;
}

t_response *t_phone_user::create_options_response(t_request *r,
		bool in_dialog) const
{
	t_response *resp;

	// RFC 3261 11.2
	switch(phone->get_state()) {
	case PS_IDLE:
		if (!in_dialog && service->is_dnd_active()) {
			resp = r->create_response(R_480_TEMP_NOT_AVAILABLE);
		} else {
			resp = r->create_response(R_200_OK);
		}
		break;
	case PS_BUSY:
		if (in_dialog) {
			resp = r->create_response(R_200_OK);
		} else {
			resp = r->create_response(R_486_BUSY_HERE);
		}
		break;
	default:
		assert(false);
	}

	SET_HDR_ALLOW(resp->hdr_allow, user_config);
	SET_HDR_ACCEPT(resp->hdr_accept);
	SET_HDR_ACCEPT_ENCODING(resp->hdr_accept_encoding);
	SET_HDR_ACCEPT_LANGUAGE(resp->hdr_accept_language);
	SET_HDR_SUPPORTED(resp->hdr_supported);

	if (user_config->get_ext_100rel() != EXT_DISABLED) {
		resp->hdr_supported.add_feature(EXT_100REL);
	}

	// TODO: include SDP body if requested (optional)

	return resp;
}

bool t_phone_user::get_is_registered(void) const {
	return is_registered;
}

bool t_phone_user::get_last_reg_failed(void) const {
	return last_reg_failed;
}

string t_phone_user::get_ip_sip(void) const {
	if (stun_public_ip_sip) return h_ip2str(stun_public_ip_sip);
	if (user_config->get_use_nat_public_ip()) return user_config->get_nat_public_ip();
	return LOCAL_IP;
}

unsigned short t_phone_user::get_public_port_sip(void) const {
	if (stun_public_port_sip) return stun_public_port_sip;
	return sys_config->get_sip_udp_port();
}

bool t_phone_user::match(t_response *r, t_tuid tuid) const {
	if (r_register && r_register->get_tuid() == tuid) {
		return true;
	} else if (r_deregister && r_deregister->get_tuid() == tuid) {
		return true;
	} else if (r_query_register && r_query_register->get_tuid() == tuid) {
		return true;
	} else if (r_options && r_options->get_tuid() == tuid) {
		return true;
	} else {
		// Response does not match any pending request.
		return false;
	}
}

bool t_phone_user::match(t_request *r) const {
	if (r->uri.get_user() == user_config->get_contact_name()) {
		return true;
	}
	
	if (r->uri.get_user() == user_config->get_name() &&
	    r->uri.get_host() == user_config->get_domain())
	{
		return true;
	}
	
	return false;
}

bool t_phone_user::match(StunMessage *r, t_tuid tuid) const {
	if (r_stun && r_stun->get_tuid() == tuid) return true;
	return false;
}

bool t_phone_user::authorize(t_request *r, t_response *resp) {
	if (authorizor.authorize(user_config, r, resp)) {
		return true;
	}
	return false;
}

void t_phone_user::remove_cached_credentials(const string &realm) {
	authorizor.remove_from_cache(realm);
}

bool t_phone_user::is_active(void) const {
	return active;
}

void t_phone_user::activate(const t_user &user) {
	// Replace old user config with the new passed user config, because
	// the user config might have been edited while this phone user was
	// inactive.
	delete user_config;
	MEMMAN_DELETE(user_config);
	user_config = user.copy();
	
	// Initialize registration data
	register_seqnr = NEW_SEQNR;
	is_registered = false;
	register_ipaddr = 0L;
	register_port = 0;
	last_reg_failed = false;
	
	// Initialize STUN data
	stun_public_ip_sip = 0L;
	stun_public_port_sip = 0;
	use_stun = false;
	use_nat_keepalive = false;
	
	active = true;
}

void t_phone_user::deactivate(void) {
	// Stop timers
	if (id_registration) phone->stop_timer(PTMR_REGISTRATION, this);
	if (id_nat_keepalive) phone->stop_timer(PTMR_NAT_KEEPALIVE, this);

	active = false;
}
