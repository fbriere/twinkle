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

#include <assert.h>
#include <iostream>
#include <signal.h>
#include "exceptions.h"
#include "phone.h"
#include "line.h"
#include "log.h"
#include "sdp/sdp.h"
#include "util.h"
#include "user.h"
#include "userintf.h"
#include "audits/memman.h"

extern t_phone 		*phone;
extern t_event_queue	*evq_timekeeper;
extern string		user_host;

///////////
// Private
///////////

void t_phone::invite(const t_url &to_uri, const string &to_display,
		const string &subject)
{
	// Ignore if active line is not idle
	if (lines[active_line]->get_state() != LS_IDLE) {
		return;
	}

	lines[active_line]->invite(to_uri, to_display, subject);
}

void t_phone::answer(void) {
	// Ignore if active line is idle
	if (lines[active_line]->get_state() == LS_IDLE) return;

	lines[active_line]->answer();
}

void t_phone::reject(void) {
	// Ignore if active line is idle
	if (lines[active_line]->get_state() == LS_IDLE) return;

	lines[active_line]->reject();
}

void t_phone::redirect(const list<t_url> &destinations, int code, string reason)
{
	// Ignore if active line is idle
	if (lines[active_line]->get_state() == LS_IDLE) return;

	lines[active_line]->redirect(destinations, code, reason);
}

void t_phone::end_call(void) {
	// If 3-way is active then end call on both lines
	if (is_3way && (
	    active_line == line1_3way->get_line_number() ||
	    active_line == line2_3way->get_line_number()))
	{
		line1_3way->end_call();
		line2_3way->end_call();
		return;
	}

	// Ignore if active line is idle
	if (lines[active_line]->get_state() == LS_IDLE) return;

	lines[active_line]->end_call();
}

void t_phone::registration(t_register_type register_type, unsigned long expires)
{
	// Stop registration timer for non-query request
	if (register_type != REG_QUERY) {
		stop_timer(PTMR_REGISTRATION);
	}

	// Create call-id if no call-id is created yet
	if (register_call_id == "") {
		register_call_id = NEW_CALL_ID;
	}

	// RFC 3261 10.2
	// Construct REGISTER request

	t_request *req = create_request(REGISTER);

	// Request-URI
	req->uri = string(USER_SCHEME) + ":" + user_config->domain;

	// To
	req->hdr_to.set_uri(create_user_uri());
	req->hdr_to.set_display(user_config->display);

	//Call-ID
	req->hdr_call_id.set_call_id(register_call_id);

	// CSeq
	req->hdr_cseq.set_method(REGISTER);
	req->hdr_cseq.set_seqnr(++register_seqnr);

	// Contact
        t_contact_param contact;

        switch (register_type) {
        case REG_REGISTER:
                contact.uri.set_url(create_user_contact());
                if (expires > 0) {
			if (user_config->registration_time_in_contact) {
				contact.set_expires(expires);
			} else {
				req->hdr_expires.set_time(expires);
			}
		}
                req->hdr_contact.add_contact(contact);
                break;
        case REG_DEREGISTER:
                contact.uri.set_url(create_user_contact());
 		if (user_config->registration_time_in_contact) {
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
	SET_HDR_ALLOW(req->hdr_allow);

	// Store request in the proper place
	t_tuid tuid;

        switch(register_type) {
        case REG_REGISTER:
		// Delete a possible pending registration request
		if (r_register) {
			MEMMAN_DELETE(r_register);
			delete r_register;
		}
                r_register = new t_client_request(req, 0);
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
                r_query_register = new t_client_request(req, 0);
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
                r_deregister = new t_client_request(req, 0);
		MEMMAN_NEW(r_deregister);
                tuid = r_deregister->get_tuid();
                break;
        default:
                assert(false);
        }

        // Send REGISTER
	ui->cb_register_inprog(register_type);
        send_request(req, tuid);
	MEMMAN_DELETE(req);
        delete req;
}

void t_phone::options(const t_url &to_uri, const string &to_display) {
	// RFC 3261 11.1
	// Construct OPTIONS request

	t_request *req = create_request(OPTIONS);

	// Request-URI
	req->uri = to_uri;

	// To
	req->hdr_to.set_uri(to_uri);
	req->hdr_to.set_display(to_display);

	// Call-ID
	req->hdr_call_id.set_call_id(NEW_CALL_ID);

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
	r_options = new t_client_request(req, 0);
	MEMMAN_NEW(r_options);
	send_request(req, r_options->get_tuid());
	MEMMAN_DELETE(req);
	delete req;
}

void t_phone::options(void) {
	lines[active_line]->options();
}

bool t_phone::hold(void) {
	// A line in a 3-way call cannot be held
	if (is_3way && (
	    active_line == line1_3way->get_line_number() ||
	    active_line == line2_3way->get_line_number()))
	{
		return false;
	}

	return lines[active_line]->hold();
}

void t_phone::retrieve(void) {
	lines[active_line]->retrieve();
}

void t_phone::activate_line(unsigned short l) {
	unsigned short a = get_active_line();
	if (a == l) return;

	// Just switch the active line if there is a conference.
	if (is_3way) {
		set_active_line(l);
		ui->cb_line_state_changed();
		return;
	}


	// Put the current active line on hold if it has a call.
	// Only established calls can be put on-hold. Transient calls
	// should be torn down or just kept in the same transient state
	// when switching to the other line.
	if (get_line(a)->get_state() == LS_BUSY && !hold()) {
		// The line is busy but could not be put on-hold. Determine
		// what to do based on the line sub state.
		switch(get_line(a)->get_substate()) {
		case LSSUB_OUTGOING_PROGRESS:
			// User has outgoing call in progress on the active
			// line, but decided to switch line, so tear down
			// the call.
			end_call();
			ui->cb_stop_tone(a);
			break;
		case LSSUB_INCOMING_PROGRESS:
			// The incoming call on the current active will stay,
			// just stop the ring tone.
			ui->cb_stop_tone(a);
			break;
		case LSSUB_ANSWERING:
			// Answering is in progress, so call cannot be put
			// on-hold. Tear down the call.
			end_call();
			break;
		case LSSUB_RELEASING:
			// The releasing call on the current line will get
			// released. No need to take any action here.
			break;
		default:
			// This should not happen.
			log_file->write_report("ERROR: Call cannot be put on hold.",
				"t_phone::activate_line");
		}
	}

	set_active_line(l);
	retrieve();

	// Play ring tone, if the new acitve line has an incoming call
	// in progress.
	if (get_line(l)->get_substate() == LSSUB_INCOMING_PROGRESS) {
		ui->cb_play_ringtone();
	}

	ui->cb_line_state_changed();
}

void t_phone::send_dtmf(char digit) {
	lines[active_line]->send_dtmf(digit);
}

bool t_phone::check_required_ext(t_request *r, list<string> &unsupported) const {
	bool all_supported = true;

	unsupported.clear();
	if (!r->hdr_require.is_populated()) return true;

	for (list<string>::iterator i = r->hdr_require.features.begin();
	     i != r->hdr_require.features.end(); i++)
	{
		if (*i == EXT_100REL) {
			if (user_config->ext_100rel != EXT_DISABLED) continue;
		}

		// Extension is not supported
		unsupported.push_back(*i);
		all_supported = false;
	}

	return all_supported;
}

void t_phone::start_timer(t_phone_timer timer) {
	t_tmr_phone	*t;

	switch(timer) {
	default:
		assert(false);
	}

	evq_timekeeper->push_start_timer(t);
	MEMMAN_DELETE(t);
	delete t;
}

void t_phone::stop_timer(t_phone_timer timer) {
	unsigned short	*id;

	switch(timer) {
	case PTMR_REGISTRATION:
		id = &id_registration;
		break;
	default:
		assert(false);
	}

	if (*id != 0) evq_timekeeper->push_stop_timer(*id);
	*id = 0;
}

void t_phone::start_set_timer(t_phone_timer timer, long time) {
	t_tmr_phone	*t;


	switch(timer) {
	case PTMR_REGISTRATION:
		long new_time;

		// Re-register before registration expires
		if (last_reg_failed || time <= RE_REGISTER_DELTA * 1000) {
			new_time = time;
		} else {
			new_time = time - (RE_REGISTER_DELTA * 1000);
		}
		t = new t_tmr_phone(new_time, timer, this);
		MEMMAN_NEW(t);
		id_registration = t->get_id();
		break;
	default:
		assert(false);
	}

	evq_timekeeper->push_start_timer(t);
	MEMMAN_DELETE(t);
	delete t;
}

void t_phone::handle_response_out_of_dialog(t_response *r, t_tuid tuid) {
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
		if (authorizor.authorize(req, r)) {
			// A new sequence number must be assigned
			if (is_register) {
				req->hdr_cseq.set_seqnr(++register_seqnr);
			} else {
				req->hdr_cseq.seqnr++;
			}

			// Create a new via-header. Otherwise the
			// request will be seen as a retransmission
			req->hdr_via.via_list.clear();
			t_via via(USER_HOST, user_config->sip_udp_port);
			req->hdr_via.add_via(via);

			(*current_cr)->renew(0);
			send_request(req, (*current_cr)->get_tuid());
			return;
		}

		// Authentication failed
		// Handle the 401/407 as a normal failure response
	}

	// Redirect request if there is another destination
	if (user_config->allow_redirection) {
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
			if (user_config->ask_user_to_redirect) {
				permission = ui->cb_ask_user_to_redirect_request(
							contact.uri, contact.display,
							r->hdr_cseq.method);
			}

			if (permission) {
				req->uri = contact.uri;

				// CSeq must be incremented
				if (is_register) {
					req->hdr_cseq.set_seqnr(++register_seqnr);
				} else {
					req->hdr_cseq.seqnr++;
				}

				// Create a new via-header. Otherwise the
				// request will be seen as a retransmission
				req->hdr_via.via_list.clear();
				t_via via(USER_HOST, user_config->sip_udp_port);
				req->hdr_via.add_via(via);

				ui->cb_redirecting_request(contact);

				(*current_cr)->renew(0);
				send_request(req, (*current_cr)->get_tuid());

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
		if (re_register) registration(REG_REGISTER, registration_time);
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

void t_phone::handle_response_register(t_response *r, bool &re_register) {
	t_contact_param *c;
	unsigned long expires;
	unsigned long e;
	bool first_failure, first_success;

	re_register = false;

        switch(r->get_class()) {
        case R_2XX:
                last_reg_failed = false;

                // Stop registration timer is one was running
                stop_timer(PTMR_REGISTRATION);

                c = r->hdr_contact.find_contact(create_user_contact());
                if (!c) {
			is_registered = false;
                        ui->cb_invalid_reg_resp(r, "Contact header missing.");
                        return;
                }

                if (c->is_expires_present() && c->get_expires() != 0) {
                        expires = c->get_expires();
                }
                else if (r->hdr_expires.is_populated() &&
                         r->hdr_expires.time != 0)
                {
                        expires = r->hdr_expires.time;
                }
                else {
			is_registered = false;
                        ui->cb_invalid_reg_resp(r, "Expires parameter/header mising.");
                        return;
                }

                // Start new registration timer
                // The maximum value of the timer can be 2^32-1 s
                // The maximum timer that we can handle however is 2^31-1 ms
                e = (expires > 2147483 ? 2147483 : expires);
                start_set_timer(PTMR_REGISTRATION, e * 1000);
		first_success = !is_registered;
                is_registered = true;
		ui->cb_register_success(r, expires, first_success);

                break;
        case R_4XX:
                is_registered = false;

                // RFC 3261 10.3
                if (r->code == R_423_INTERVAL_TOO_BRIEF) {
                        if (!r->hdr_min_expires.is_populated()) {
                                // Violation of RFC 3261 10.3 item 7
                                ui->cb_invalid_reg_resp(r,
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
                                ui->cb_invalid_reg_resp(r, s);
                                return;
                        }

                        // Automatic re-register with Min-Expires time
                        registration_time = r->hdr_min_expires.time;
                        re_register = true;
                        return;
                }

		// If authorization failed, the do not start the continuous
		// re-attempts. When authorization fails the user is asked
		// for credentials (in GUI). So the user cancelled this
		// questions and should not be bothered with the same question
		// again every 30 seconds. The user does not have the
		// credentials.
		if (r->code == R_401_UNAUTHORIZED ||
		    r->code == R_407_PROXY_AUTH_REQUIRED)
		{
			last_reg_failed = true;
			ui->cb_register_failed(r, true);
			return;
		}

                // fall thru
        default:
		first_failure = !last_reg_failed;
                last_reg_failed = true;
                is_registered = false;
		ui->cb_register_failed(r, first_failure);
                start_set_timer(PTMR_REGISTRATION, DUR_REG_FAILURE * 1000);
        }
}

void t_phone::handle_response_deregister(t_response *r) {
	is_registered = false;
	last_reg_failed = false;

	if (r->is_success()) {
		ui->cb_deregister_success(r);
	} else {
		ui->cb_deregister_failed(r);
	}
}

void t_phone::handle_response_query_register(t_response *r) {
	if (r->is_success()) {
		ui->cb_fetch_reg_result(r);
	} else {
		ui->cb_fetch_reg_failed(r);
	}
}

void t_phone::handle_response_options(t_response *r) {
	ui->cb_options_response(r);
}

//////////////
// Protected
//////////////

void t_phone::recvd_provisional(t_response *r, t_tuid tuid, t_tid tid) {
	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match(r, tuid)) {
			lines[i]->recvd_provisional(r, tuid, tid);
			return;
		}
	}

	// out-of-dialog response
	// Provisional responses should only be given for INVITE.
	// A response for an INVITE is always in a dialog.
	// Ignore provisional responses for other requests.
}

void t_phone::recvd_success(t_response *r, t_tuid tuid, t_tid tid) {
	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match(r, tuid)) {
			lines[i]->recvd_success(r, tuid, tid);
			return;
		}
	}

	// out-of-dialog responses
	handle_response_out_of_dialog(r, tuid);
}

void t_phone::recvd_redirect(t_response *r, t_tuid tuid, t_tid tid) {
	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match(r, tuid)) {
			lines[i]->recvd_redirect(r, tuid, tid);
			return;
		}
	}

	// out-of-dialog responses
	handle_response_out_of_dialog(r, tuid);
}

void t_phone::recvd_client_error(t_response *r, t_tuid tuid, t_tid tid) {
	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match(r, tuid)) {
			lines[i]->recvd_client_error(r, tuid, tid);
			return;
		}
	}

	// out-of-dialog responses
	handle_response_out_of_dialog(r, tuid);
}

void t_phone::recvd_server_error(t_response *r, t_tuid tuid, t_tid tid) {
	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match(r, tuid)) {
			lines[i]->recvd_server_error(r, tuid, tid);
			return;
		}
	}

	// out-of-dialog responses
	handle_response_out_of_dialog(r, tuid);
}

void t_phone::recvd_global_error(t_response *r, t_tuid tuid, t_tid tid) {
	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match(r, tuid)) {
			lines[i]->recvd_global_error(r, tuid, tid);
			return;
		}
	}

	// out-of-dialog responses
	handle_response_out_of_dialog(r, tuid);
}

void t_phone::recvd_invite(t_request *r, t_tid tid) {
	t_response *resp;
	list <string> unsupported;

	// Check if the far end requires any unsupported extensions
	if (!check_required_ext(r, unsupported))
	{
		// Not all required extensions are supported
		resp = r->create_response(R_420_BAD_EXTENSION);
		resp->hdr_unsupported.set_features(unsupported);
		send_response(resp, 0, tid);
		MEMMAN_DELETE(resp);
		delete resp;
		return;
	}

	// RFC 3261 12.2.2
	// An INVITE with a To-header without a tag is an inital
	// INVITE
	if (r->hdr_to.tag == "") {
		list<t_url> cf_dest; // call forwarding destinations

		// Call forwarding always
		if (service.get_cf_active(CF_ALWAYS, cf_dest)) {
			resp = r->create_response(R_302_MOVED_TEMPORARILY);
			resp->hdr_contact.set_contacts(cf_dest);
			send_response(resp, 0, tid);
			MEMMAN_DELETE(resp);
			delete resp;
			return;
		}

		// Do not disturb
		// RFC 3261 21.4.18
		if (service.is_dnd_active()) {
			resp = r->create_response(R_480_TEMP_NOT_AVAILABLE);
			send_response(resp, 0, tid);
			MEMMAN_DELETE(resp);
			delete resp;
			return;
		}

		// Send the INVITE to the active line if it is idle
		if (lines[active_line]->get_substate() == LSSUB_IDLE) {
			lines[active_line]->recvd_invite(r, tid);
			return;
		}

		// Send the INVITE to the first idle unseized line
		for (unsigned short i = 0; i < NUM_LINES; i++) {
			if (lines[i]->get_substate() == LSSUB_IDLE) {
				lines[i]->recvd_invite(r, tid);
				return;
			}
		}

		// All lines are busy
		// Call forwarding busy
		if (service.get_cf_active(CF_BUSY, cf_dest)) {
			resp = r->create_response(R_302_MOVED_TEMPORARILY);
			resp->hdr_contact.set_contacts(cf_dest);
			send_response(resp, 0, tid);
			MEMMAN_DELETE(resp);
			delete resp;
		}

		// Send busy response
		resp = r->create_response(R_486_BUSY_HERE);
		send_response(resp, 0, tid);
		MEMMAN_DELETE(resp);
		delete resp;
		return;
	}

	// RFC 3261 12.2.2
	// A To-header with a tag is a mid-dialog request.
	// Find a line that matches the request
	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match(r)) {
			lines[i]->recvd_invite(r, tid);
			return;
		}
	}

	// No dialog matches with the request.
	resp = r->create_response(R_481_TRANSACTION_NOT_EXIST);
	send_response(resp, 0, tid);
	MEMMAN_DELETE(resp);
	delete resp;
}

void t_phone::recvd_ack(t_request *r, t_tid tid) {
	t_response *resp;

	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match(r)) {
			lines[i]->recvd_ack(r, tid);
			return;
		}
	}

	resp = r->create_response(R_481_TRANSACTION_NOT_EXIST);
	send_response(resp, 0, tid);
	MEMMAN_DELETE(resp);
	delete resp;
}

void t_phone::recvd_cancel(t_request *r, t_tid cancel_tid,
		t_tid target_tid)
{
	t_response *resp;

	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match_cancel(r, target_tid)) {
			lines[i]->recvd_cancel(r, cancel_tid, target_tid);
			return;
		}
	}

	resp = r->create_response(R_481_TRANSACTION_NOT_EXIST);
	send_response(resp, 0, cancel_tid);
	MEMMAN_DELETE(resp);
	delete resp;
}

void t_phone::recvd_bye(t_request *r, t_tid tid) {
	t_response *resp;
	list <string> unsupported;

	// Check if the far end requires any unsupported extensions
	if (!check_required_ext(r, unsupported))
	{
		// Not all required extensions are supported
		resp = r->create_response(R_420_BAD_EXTENSION);
		resp->hdr_unsupported.set_features(unsupported);
		send_response(resp, 0, tid);
		MEMMAN_DELETE(resp);
		delete resp;
		return;
	}

	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match(r)) {
			lines[i]->recvd_bye(r, tid);
			return;
		}
	}

	resp = r->create_response(R_481_TRANSACTION_NOT_EXIST);
	send_response(resp, 0, tid);
	MEMMAN_DELETE(resp);
	delete resp;
}

void t_phone::recvd_options(t_request *r, t_tid tid) {
	t_response *resp;
	list <string> unsupported;

	// Check if the far end requires any unsupported extensions
	if (!check_required_ext(r, unsupported))
	{
		// Not all required extensions are supported
		resp = r->create_response(R_420_BAD_EXTENSION);
		resp->hdr_unsupported.set_features(unsupported);
		send_response(resp, 0, tid);
		MEMMAN_DELETE(resp);
		delete resp;
		return;
	}

	// Check if this is a mid-dialog request.
	if (r->hdr_to.tag !="") {
		// RFC 3261 12.2.2
		// A To-header with a tag is a mid-dialog request.
		// No dialog matches with the request.
		for (unsigned short i = 0; i < NUM_LINES; i++) {
			if (lines[i]->match(r)) {
				lines[i]->recvd_options(r, tid);
				return;
			}
		}

		resp = r->create_response(R_481_TRANSACTION_NOT_EXIST);
		send_response(resp, 0, tid);
		MEMMAN_DELETE(resp);
		delete resp;
	 } else {
		// Request outside dialog

		// Check user in the request-URI
		if (r->uri.get_user() != user_config->name) {
			resp = r->create_response(R_404_NOT_FOUND);
			send_response(resp, 0, tid);
			MEMMAN_DELETE(resp);
			delete resp;
			return;
		}

		resp = create_options_response(r);
		send_response(resp, 0, tid);
		MEMMAN_DELETE(resp);
		delete resp;
	}
}

void t_phone::recvd_register(t_request *r, t_tid tid) {
	// The softphone is not a registrar.
	t_response *resp = r->create_response(R_403_FORBIDDEN);
	send_response(resp, 0, tid);
	MEMMAN_DELETE(resp);
	delete resp;

	// TEST ONLY: code for testing a 423 Interval Too Brief
	/*
	if (r->hdr_contact.contact_list.front().get_expires() < 30) {
		t_response *resp = r->create_response(
					R_423_INTERVAL_TOO_BRIEF);
		resp->hdr_min_expires.set_time(30);
		send_response(resp, 0, tid);
		delete resp;
		return;
	}

	// Code for testing a 200 OK response (register)
	t_response *resp = r->create_response(R_200_OK);
	resp->hdr_contact.set_contacts(r->hdr_contact.contact_list);
	resp->hdr_contact.contact_list.front().set_expires(30);
	resp->hdr_date.set_now();
	send_response(resp, 0, tid);
	delete resp;

	// Code for testing 200 OK response (de-register)
	t_response *resp = r->create_response(R_200_OK);
	send_response(resp, 0, tid);
	delete resp;

	// Code for testing 200 OK response (query)
	t_response *resp = r->create_response(R_200_OK);
	t_contact_param contact;
	contact.uri.set_url("sip:aap@xs4all.nl");
	resp->hdr_contact.add_contact(contact);
	contact.uri.set_url("sip:noot@xs4all.nl");
	resp->hdr_contact.add_contact(contact);
	send_response(resp, 0, tid);
	delete resp;

	// Code for testing a 401 response (register)
	if (r->hdr_authorization.is_populated() &&
	    r->hdr_authorization.credentials_list.front().digest_response.
	    	nonce == "0123456789abcdef")
	{
		t_response *resp = r->create_response(R_200_OK);
		resp->hdr_contact.set_contacts(r->hdr_contact.contact_list);
		resp->hdr_contact.contact_list.front().set_expires(30);
		resp->hdr_date.set_now();
		send_response(resp, 0, tid);
		delete resp;
	} else {
		t_response *resp = r->create_response(R_401_UNAUTHORIZED);
		t_challenge c;
		c.auth_scheme = AUTH_DIGEST;
		c.digest_challenge.realm = "mtel.nl";
		if (r->hdr_authorization.is_populated()) {
			c.digest_challenge.nonce = "0123456789abcdef";
			c.digest_challenge.stale = true;
		} else {
			c.digest_challenge.nonce = "aaaaaa0123456789";
		}
		c.digest_challenge.opaque = "secret";
		c.digest_challenge.algorithm = ALG_MD5;
		// c.digest_challenge.qop_options.push_back(QOP_AUTH);
		// c.digest_challenge.qop_options.push_back(QOP_AUTH_INT);
		resp->hdr_www_authenticate.set_challenge(c);
		send_response(resp, 0, tid);
	}
	*/
}

void t_phone::recvd_prack(t_request *r, t_tid tid) {
	t_response *resp;

	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match(r)) {
			lines[i]->recvd_prack(r, tid);
			return;
		}
	}

	resp = r->create_response(R_481_TRANSACTION_NOT_EXIST);
	send_response(resp, 0, tid);
	MEMMAN_DELETE(resp);
	delete resp;
}

void t_phone::failure(t_failure failure, t_tid tid) {
	// TODO
}


///////////
// Public
///////////

t_phone::t_phone() : t_transaction_layer() {
	active_line = 0;

	r_options = NULL;
	r_register = NULL;
	r_deregister = NULL;
	r_query_register = NULL;

	// Initialize registration data
	// Call-ID cannot be set here as user_host is not determined yet.
	register_seqnr = NEW_SEQNR;
	is_registered = false;

	// Create phone lines
	for (unsigned short i = 0; i < NUM_LINES; i++) {
		lines[i] = new t_line(this, i);
		MEMMAN_NEW(lines[i]);
	}

	// Initialize 3-way conference data
	is_3way = false;
	line1_3way = NULL;
	line2_3way = NULL;
}

t_phone::~t_phone() {
	// Stop timers
	if (id_registration) stop_timer(PTMR_REGISTRATION);

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

	// Delete phone lines
	for (unsigned short i = 0; i < NUM_LINES; i++) {
		MEMMAN_DELETE(lines[i]);
		delete lines[i];
	}
}

void t_phone::pub_invite(const t_url &to_uri, const string &to_display,
		const string &subject)
{
	lock();
	invite(to_uri, to_display, subject);
	unlock();
}

void t_phone::pub_answer(void) {
	lock();
	answer();
	unlock();
}

void t_phone::pub_reject(void) {
	lock();
	reject();
	unlock();
}

void t_phone::pub_redirect(const list<t_url> &destinations, int code, string reason)
{
	lock();
	redirect(destinations, code, reason);
	unlock();
}

void t_phone::pub_end_call(void) {
	lock();
	end_call();
	unlock();
}

void t_phone::pub_registration(t_register_type register_type,
		unsigned long expires)
{
	lock();
	registration(register_type, expires);
	unlock();
}

void t_phone::pub_options(const t_url &to_uri, const string &to_display) {
	lock();
	options(to_uri, to_display);
	unlock();
}

void t_phone::pub_options(void) {
	lock();
	options();
	unlock();
}

bool t_phone::pub_hold(void) {
	lock();
	bool retval = hold();
	unlock();
	return retval;
}

void t_phone::pub_retrieve(void) {
	lock();
	retrieve();
	unlock();
}

void t_phone::mute(bool enable) {
	lock();

	// In a 3-way call, both lines must be muted
	if (is_3way && (
	    active_line == line1_3way->get_line_number() ||
	    active_line == line2_3way->get_line_number()))
	{
		line1_3way->mute(enable);
		line2_3way->mute(enable);
	}
	else
	{
		lines[active_line]->mute(enable);
	}

	unlock();
}

void t_phone::pub_activate_line(unsigned short l) {
	lock();
	activate_line(l);
	unlock();
}

void t_phone::pub_send_dtmf(char digit) {
	lock();
	send_dtmf(digit);
	unlock();
}

void t_phone::pub_seize(void) {
	lock();
	lines[active_line]->seize();
	unlock();
}

void t_phone::pub_unseize(void) {
	lock();
	lines[active_line]->unseize();
	unlock();
}

void *phone_uas_main(void *arg) {
	phone->run();
}


t_phone_state t_phone::get_state(void) const {
	t_phone *self = const_cast<t_phone *>(this);

	self->lock();
	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->get_state() == LS_IDLE) {
			self->unlock();
			return PS_IDLE;
		}
	}

	// All lines are busy, so the phone is busy.
	self->unlock();
	return PS_BUSY;
}

void t_phone::timeout(t_phone_timer timer) {
	lock();

	switch (timer) {
	case PTMR_REGISTRATION:
		// Registration expired. Re-register.
		if (is_registered || last_reg_failed) {
			// Re-register if no register is pending
			if (!r_register) {
				registration(REG_REGISTER, registration_time);
			}
		}
		break;
	default:
		assert(false);
	}

	unlock();
}

string t_phone::create_user_contact(void) const {
	string s;

	s = USER_SCHEME;
	s += ':';
	s += user_config->name;
	s += '@';
	s += USER_HOST;

	if (user_config->sip_udp_port != get_default_port(USER_SCHEME)) {
		s += ':';
		s += int2str(user_config->sip_udp_port);
	}

	if (user_config->numerical_user_is_phone &&
	    t_url::looks_like_phone(user_config->name))
	{
		// RFC 3261 19.1.1
		// If the URI contains a telephone number it SHOULD contain
		// the user=phone parameter.
		s += ";user=phone";
	}

	return s;
}

string t_phone::create_user_uri(void) const {
	string s;

	s = USER_SCHEME;
	s += ':';
	s += user_config->name;
	s += '@';
	s += user_config->domain;

	if (user_config->numerical_user_is_phone &&
	    t_url::looks_like_phone(user_config->name))
	{
		// RFC 3261 19.1.1
		// If the URI contains a telephone number it SHOULD contain
		// the user=phone parameter.
		s += ";user=phone";
	}

	return s;
}

t_request *t_phone::create_request(t_method m) const {
	t_request *req = new t_request(m);
	MEMMAN_NEW(req);

	// Via
	t_via via(USER_HOST, user_config->sip_udp_port);
	req->hdr_via.add_via(via);

	// From
	req->hdr_from.set_uri(create_user_uri());
	req->hdr_from.set_display(user_config->display);
	req->hdr_from.set_tag(NEW_TAG);

	// Max-Forwards header (mandatory)
	req->hdr_max_forwards.set_max_forwards(MAX_FORWARDS);

	// User-Agent
	SET_HDR_USER_AGENT(req->hdr_user_agent);

	return req;
}

t_response *t_phone::create_options_response(t_request *r,
		bool in_dialog) const
{
	t_response *resp;

	// RFC 3261 11.2
	switch(get_state()) {
	case PS_IDLE:
		if (!in_dialog && service.is_dnd_active()) {
			resp = r->create_response(R_486_BUSY_HERE);
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

	SET_HDR_ALLOW(resp->hdr_allow);
	SET_HDR_ACCEPT(resp->hdr_accept);
	SET_HDR_ACCEPT_ENCODING(resp->hdr_accept_encoding);
	SET_HDR_ACCEPT_LANGUAGE(resp->hdr_accept_language);
	SET_HDR_SUPPORTED(resp->hdr_supported);

	if (user_config->ext_100rel != EXT_DISABLED) {
		resp->hdr_supported.add_feature(EXT_100REL);
	}

	// TODO: include SDP body if requested (optional)

	return resp;
}

void t_phone::set_active_line(unsigned short l) {
	lock();
	assert (l < NUM_LINES);
	active_line = l;
	unlock();
}

unsigned short t_phone::get_active_line(void) const {
	return active_line;
}

t_line *t_phone::get_line(unsigned short lineno) const {
	assert(lineno < NUM_LINES);
	return lines[lineno];
}

bool t_phone::authorize(t_request *r, t_response *resp) {
	lock();
	if (authorizor.authorize(r, resp)) {
		// A new sequence number must be assigned
		r->hdr_cseq.seqnr++;

		// Create a new via-header. Otherwise the
		// request will be seen as a retransmission
		r->hdr_via.via_list.clear();
		t_via via(USER_HOST, user_config->sip_udp_port);
		r->hdr_via.add_via(via);

		unlock();
		return true;
	}

	unlock();
	return false;
}

bool t_phone::get_is_registered(void) const {
	return is_registered;
}

bool t_phone::get_last_reg_failed(void) const {
	return last_reg_failed;
}

t_line_state t_phone::get_line_state(unsigned short lineno) const {
	assert(lineno < NUM_LINES);
	t_phone *self = const_cast<t_phone *>(this);

	self->lock();
	t_line_state s = get_line(lineno)->get_state();
	self->unlock();
	return s;
}

t_line_substate t_phone::get_line_substate(unsigned short lineno) const {
	assert(lineno < NUM_LINES);
	t_phone *self = const_cast<t_phone *>(this);

	self->lock();
	t_line_substate s = get_line(lineno)->get_substate();
	self->unlock();
	return s;
}

bool t_phone::is_line_on_hold(unsigned short lineno) const {
	assert(lineno < NUM_LINES);
	t_phone *self = const_cast<t_phone *>(this);

	self->lock();
	bool b = get_line(lineno)->get_is_on_hold();
	self->unlock();
	return b;
}

bool t_phone::is_line_muted(unsigned short lineno) const {
	assert(lineno < NUM_LINES);
	t_phone *self = const_cast<t_phone *>(this);

	self->lock();
	bool b = get_line(lineno)->get_is_muted();
	self->unlock();
	return b;
}

bool t_phone::part_of_3way(unsigned short lineno) {
	lock();

	if (!is_3way) {
		unlock();
		return false;
	}

	if (line1_3way->get_line_number() == lineno) {
		unlock();
		return true;
	}

	if (line2_3way->get_line_number() == lineno) {
		unlock();
		return true;
	}

	unlock();
	return false;
}

t_line *t_phone::get_3way_peer_line(unsigned short lineno) {
	lock();

	if (!is_3way) {
		unlock();
		return NULL;
	}

	if (line1_3way->get_line_number() == lineno) {
		unlock();
		return line2_3way;
	}

	unlock();
	return line1_3way;
}

bool t_phone::join_3way(unsigned short lineno1, unsigned short lineno2) {
	assert(lineno1 < NUM_LINES);
	assert(lineno2 < NUM_LINES);

	lock();

	// Check if there isn't a 3-way already
	if (is_3way) {
		unlock();
		return false;
	}

	// Both lines must have a call.
	if (lines[lineno1]->get_substate() != LSSUB_ESTABLISHED ||
	    lines[lineno2]->get_substate() != LSSUB_ESTABLISHED)
	{
		unlock();
		return false;
	}

	// One of the lines must be on-hold
	t_line *held_line, *talking_line;
	if (lines[lineno1]->get_is_on_hold()) {
		held_line = lines[lineno1];
		talking_line = lines[lineno2];
	} else if (lines[lineno2]->get_is_on_hold()) {
		held_line = lines[lineno2];
		talking_line = lines[lineno1];
	} else {
		unlock();
		return false;
	}

	// Set 3-way data
	is_3way = true;
	line1_3way = talking_line;
	line2_3way = held_line;

	// The user may have put both lines on-hold. In this case the
	// talking line is on-hold too!
	if (talking_line->get_is_on_hold()) {
		// Retrieve the held call
		talking_line->retrieve();
	} else {
		// Start the 3-way on the talking line
		t_audio_session *as_talking = talking_line->get_audio_session();
		if (as_talking) as_talking->start_3way();
	}

	// Retrieve the held call
	held_line->retrieve();

	unlock();
	return true;
}

void t_phone::line_cleared(unsigned short lineno) {
	assert(lineno < NUM_LINES);

	lock();

	// Clean up 3-way data if the line was involved in a 3-way
	if (is_3way)
	{
		bool line_in_3way = false;
		t_audio_session *as_peer;
		t_line *line_peer;

		if (lineno == line1_3way->get_line_number()) {
			line_in_3way = true;
			line_peer = line2_3way;
		} else if (lineno == line2_3way->get_line_number()) {
			line_in_3way = true;
			line_peer = line1_3way;
		}

		if (line_in_3way) {
			// Stop the 3-way mixing on the peer line
			as_peer = line_peer->get_audio_session();
			if (as_peer) as_peer->stop_3way();

			// Make the peer line the active line
			set_active_line(line_peer->get_line_number());

			is_3way = false;
			line1_3way = NULL;
			line2_3way = NULL;
		}
	}

	unlock();
}
