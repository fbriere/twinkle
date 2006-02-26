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

#include <assert.h>
#include <iostream>
#include <signal.h>
#include "call_history.h"
#include "call_script.h"
#include "exceptions.h"
#include "phone.h"
#include "line.h"
#include "log.h"
#include "sdp/sdp.h"
#include "util.h"
#include "user.h"
#include "userintf.h"
#include "audits/memman.h"
#include "sockets/socket.h"
#include "stun/stun_transaction.h"

extern t_phone 		*phone;
extern t_event_queue	*evq_timekeeper;
extern t_event_queue	*evq_sender_udp;
extern string		user_host;

///////////
// Private
///////////

void t_phone::invite(t_phone_user *pu, const t_url &to_uri, const string &to_display,
		const string &subject)
{
	// Ignore if active line is not idle
	if (lines[active_line]->get_state() != LS_IDLE) {
		return;
	}

	lines[active_line]->invite(pu->get_user_profile(), to_uri, to_display, subject);
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

void t_phone::redirect(const list<t_display_url> &destinations, int code, string reason)
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
		if (sys_config->hangup_both_3way) {
			line1_3way->end_call();
			line2_3way->end_call();
		} else {
			// Hangup the active line, and make the next
			// line active.
			int l = active_line;
			activate_line((l+1) % NUM_USER_LINES);
			lines[l]->end_call();
		}
		
		return;
	}

	// Ignore if active line is idle
	if (lines[active_line]->get_state() == LS_IDLE) return;

	lines[active_line]->end_call();
}

void t_phone::registration(t_phone_user *pu, t_register_type register_type, 
		unsigned long expires)
{
	pu->registration(register_type, expires);
}

void t_phone::options(t_phone_user *pu, const t_url &to_uri, const string &to_display) {
	pu->options(to_uri, to_display);
}

void t_phone::options(void) {
	lines[active_line]->options();
}

bool t_phone::hold(bool rtponly) {
	// A line in a 3-way call cannot be held
	if (is_3way && (
	    active_line == line1_3way->get_line_number() ||
	    active_line == line2_3way->get_line_number()))
	{
		return false;
	}

	return lines[active_line]->hold(rtponly);
}

void t_phone::retrieve(void) {
	lines[active_line]->retrieve();
}

void t_phone::refer(const t_url &uri, const string &display) {
	lines[active_line]->refer(uri, display);
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

	// Retrieve the call on the new active line unless that line
	// is transferring a call and the user profile indicates that
	// the referrer holds the call during call transfer.
	t_user *user_config = lines[l]->get_user();
	if (get_line_refer_state(l) == REFST_NULL || 
	    (user_config && !user_config->referrer_hold))
	{
		retrieve();
	}

	// Play ring tone, if the new active line has an incoming call
	// in progress.
	if (get_line(l)->get_substate() == LSSUB_INCOMING_PROGRESS) {
		ui->cb_play_ringtone(l);
	}

	ui->cb_line_state_changed();
}

void t_phone::send_dtmf(char digit) {
	lines[active_line]->send_dtmf(digit);
}

void t_phone::start_timer(t_phone_timer timer, t_phone_user *pu) {
	t_tmr_phone	*t;
	t_user		*user_config = pu->get_user_profile();

	switch(timer) {
	case PTMR_NAT_KEEPALIVE:
		t = new t_tmr_phone(user_config->timer_nat_keepalive * 1000, timer, this);
		MEMMAN_NEW(t);
		pu->id_nat_keepalive = t->get_id();
		break;
	default:
		assert(false);
	}

	evq_timekeeper->push_start_timer(t);
	MEMMAN_DELETE(t);
	delete t;
}

void t_phone::stop_timer(t_phone_timer timer, t_phone_user *pu) {
	unsigned short	*id;

	switch(timer) {
	case PTMR_REGISTRATION:
		id = &pu->id_registration;
		break;
	case PTMR_NAT_KEEPALIVE:
		id = &pu->id_nat_keepalive;
		break;
	default:
		assert(false);
	}

	if (*id != 0) evq_timekeeper->push_stop_timer(*id);
	*id = 0;
}

void t_phone::start_set_timer(t_phone_timer timer, long time, t_phone_user *pu) {
	t_tmr_phone	*t;


	switch(timer) {
	case PTMR_REGISTRATION:
		long new_time;

		// Re-register before registration expires
		if (pu->get_last_reg_failed() || time <= RE_REGISTER_DELTA * 1000) {
			new_time = time;
		} else {
			new_time = time - (RE_REGISTER_DELTA * 1000);
		}
		t = new t_tmr_phone(new_time, timer, this);
		MEMMAN_NEW(t);
		pu->id_registration = t->get_id();
		break;
	default:
		assert(false);
	}

	evq_timekeeper->push_start_timer(t);
	MEMMAN_DELETE(t);
	delete t;
}

void t_phone::handle_response_out_of_dialog(t_response *r, t_tuid tuid) {
	t_phone_user *pu = match_phone_user(r, tuid);
	if (!pu) {
		// Response does not match any pending request.
		return;
	}
	
	pu->handle_response_out_of_dialog(r, tuid);
}

void t_phone::handle_response_out_of_dialog(StunMessage *r, t_tuid tuid) {
	t_phone_user *pu = match_phone_user(r, tuid);
	if (!pu) {
		// Response does not match any pending request.
		return;
	}
	
	pu->handle_response_out_of_dialog(r, tuid);
}

t_phone_user *t_phone::find_phone_user(const string &profile_name) {
	for (list<t_phone_user *>::iterator i = phone_users.begin();
	     i != phone_users.end(); i++)
	{
		if (!(*i)->is_active()) continue;
		
		t_user *user_config = (*i)->get_user_profile();
		if (user_config->get_profile_name() == profile_name) {
			return *i;
		}
	}
	
	return NULL;
}

t_phone_user *t_phone::match_phone_user(t_response *r, t_tuid tuid) {
	for (list<t_phone_user *>::iterator i = phone_users.begin();
	     i != phone_users.end(); i++)
	{
		if ((*i)->match(r, tuid)) return *i;
	}
	
	return NULL;
}

t_phone_user *t_phone::match_phone_user(t_request *r) {
	for (list<t_phone_user *>::iterator i = phone_users.begin();
	     i != phone_users.end(); i++)
	{
		if ((*i)->match(r)) return *i;
	}
	
	return NULL;
}

t_phone_user *t_phone::match_phone_user(StunMessage *r, t_tuid tuid) {
	for (list<t_phone_user *>::iterator i = phone_users.begin();
	     i != phone_users.end(); i++)
	{
		if ((*i)->match(r, tuid)) return *i;
	}
	
	return NULL;
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
	t_call_record call_record;

	// Check if this INVITE is a retransmission.
	// Once the TU sent a 2XX repsonse on an INVITE it has to deal
	// with retransmissions.
	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->is_invite_retrans(r)) {
			lines[i]->process_invite_retrans();
			return;
		}
	}
	
	// Find out for which user this INVITE is.
	t_phone_user *pu = match_phone_user(r);
	if (!pu) {
		resp = r->create_response(R_404_NOT_FOUND);
		send_response(resp, 0, tid);
		
		// Do not create a call history record as this is a misrouted
		// call.
		
		MEMMAN_DELETE(resp);
		delete resp;
		return;
	}
	
	// Reject call if phone is not active
	if (!is_active) {
		resp = r->create_response(R_480_TEMP_NOT_AVAILABLE);
		send_response(resp, 0, tid);
		MEMMAN_DELETE(resp);
		delete resp;
		return;
	}
	
	t_user *user_config = pu->get_user_profile();

	// Check if the far end requires any unsupported extensions
	if (!user_config->check_required_ext(r, unsupported))
	{
		// Not all required extensions are supported
		resp = r->create_response(R_420_BAD_EXTENSION);
		resp->hdr_unsupported.set_features(unsupported);
		send_response(resp, 0, tid);
		
		// Do not create a call history record here. The far-end
		// should retry the call without the extension, so this
		// is not a missed call from the user point of view.
		// Not that this INVITE can also be a re-INVITE.
				
		MEMMAN_DELETE(resp);
		delete resp;
		return;
	}

	// RFC 3261 12.2.2
	// An INVITE with a To-header without a tag is an initial
	// INVITE
	if (r->hdr_to.tag == "") {
		t_display_url display_url;
		list<t_display_url> cf_dest; // call forwarding destinations
		
		// Call user defineable incoming call script to determine how
		// to handle this call
		t_script_result script_result;
		
		if (!user_config->script_incoming_call.empty()) {
			// Send 100 Trying as the script might take a while
			resp = r->create_response(R_100_TRYING);
			send_response(resp, 0, tid);
			MEMMAN_DELETE(resp);
			delete resp;
			
			t_call_script script(user_config->script_incoming_call);
			script.exec(script_result, user_config, r);
		}
		
		// Perform the action in the script_result.
		// NOTE: the default action is "continue"
		switch (script_result.action) {
		case t_script_result::ACTION_CONTINUE:
			// Continue with call
			break;
		case t_script_result::ACTION_AUTOANSWER:
			log_file->write_report("Incoming call script action: autoanswer",
				"t_phone::recvd_invite");
			break;
		case t_script_result::ACTION_REJECT:
			log_file->write_report("Incoming call script action: reject",
				"t_phone::recvd_invite");
			resp = r->create_response(R_603_DECLINE, script_result.reason);
			send_response(resp, 0, tid);
			
			// Create a call history record
			call_record.start_call(r, t_call_record::DIR_IN, 
				user_config->get_profile_name());
			call_record.fail_call(resp);
			call_history->add_call_record(call_record);
			
			MEMMAN_DELETE(resp);
			delete resp;
			return;
			break;
		case t_script_result::ACTION_DND:
			log_file->write_report("Incoming call script action: dnd",
				"t_phone::recvd_invite");
			resp = r->create_response(R_480_TEMP_NOT_AVAILABLE, 
					script_result.reason);
			send_response(resp, 0, tid);
			
			// Create a call history record
			call_record.start_call(r, t_call_record::DIR_IN, 
				user_config->get_profile_name());
			call_record.fail_call(resp);
			call_history->add_call_record(call_record);
			
			MEMMAN_DELETE(resp);
			delete resp;
			return;
			break;
		case  t_script_result::ACTION_REDIRECT:
			log_file->write_report("Incoming call script action: redirect",
				"t_phone::recvd_invite");
			ui->expand_destination(user_config, 
				script_result.contact, display_url);
			if (display_url.is_valid()) {
				cf_dest.clear();
				cf_dest.push_back(display_url);
				resp = r->create_response(R_302_MOVED_TEMPORARILY);
				resp->hdr_contact.set_contacts(cf_dest);
			} else {
				log_file->write_report("Invalid redirect contact",
					"t_phone::recvd_invite",
					LOG_NORMAL, LOG_WARNING);
				resp = r->create_response(R_500_INTERNAL_SERVER_ERROR); 
			}
			send_response(resp, 0, tid);
			
			// Create a call history record
			call_record.start_call(r, t_call_record::DIR_IN, 
				user_config->get_profile_name());
			call_record.fail_call(resp);
			call_history->add_call_record(call_record);
			
			MEMMAN_DELETE(resp);
			delete resp;
			return;
			break;
		default:
			log_file->write_report("Error in incoming call script",
				"t_phone::recvd_invite", LOG_NORMAL, LOG_WARNING);
			resp = r->create_response(R_500_INTERNAL_SERVER_ERROR); 
			send_response(resp, 0, tid);
			
			// Create a call history record
			call_record.start_call(r, t_call_record::DIR_IN, 
				user_config->get_profile_name());
			call_record.fail_call(resp);
			call_history->add_call_record(call_record);
			
			MEMMAN_DELETE(resp);
			delete resp;
			return;
			break;
		}		

		// Call forwarding always
		// NOTE: if a call script returned the autoanswer action, then
		//       call forwarding should be bypassed
		if (pu->service.get_cf_active(CF_ALWAYS, cf_dest) &&
		    script_result.action == t_script_result::ACTION_CONTINUE) 
		{
			log_file->write_report("Call redirection unconditional",
				"t_phone::recvd_invite");
			resp = r->create_response(R_302_MOVED_TEMPORARILY);
			resp->hdr_contact.set_contacts(cf_dest);
			send_response(resp, 0, tid);
			
			// Create a call history record
			call_record.start_call(r, t_call_record::DIR_IN, 
				user_config->get_profile_name());
			call_record.fail_call(resp);
			call_history->add_call_record(call_record);
		
			MEMMAN_DELETE(resp);
			delete resp;
			return;
		}

		// Do not disturb
		// RFC 3261 21.4.18
		// NOTE: if a call script returned the autoanswer action, then
		//       do not disturb should be bypassed
		if (pu->service.is_dnd_active() &&
		    script_result.action == t_script_result::ACTION_CONTINUE) 
		{
			log_file->write_report("Do not disturb",
				"t_phone::recvd_invite");
			resp = r->create_response(R_480_TEMP_NOT_AVAILABLE);
			send_response(resp, 0, tid);

			// Create a call history record
			call_record.start_call(r, t_call_record::DIR_IN, 
				user_config->get_profile_name());
			call_record.fail_call(resp);
			call_history->add_call_record(call_record);
			
			MEMMAN_DELETE(resp);
			delete resp;
			return;
		}

		// Send the INVITE to the active line if it is idle
		if (lines[active_line]->get_substate() == LSSUB_IDLE) {
			// Auto answer
			if (pu->service.is_auto_answer_active() ||
			    script_result.action == t_script_result::ACTION_AUTOANSWER) 
			{
				log_file->write_report("Auto answer",
					"t_phone::recvd_invite");
				lines[active_line]->set_auto_answer(true);
			}		
		
			lines[active_line]->recvd_invite(user_config, r, tid,
				script_result.ringtone);
			
			return;
		}

		if (sys_config->call_waiting || all_lines_idle()) {
			// Send the INVITE to the first idle unseized line
			for (unsigned short i = 0; i < NUM_USER_LINES; i++) {
				if (lines[i]->get_substate() == LSSUB_IDLE) {
					lines[i]->recvd_invite(user_config, r, tid,
						script_result.ringtone);
					return;
				}
			}
		}

		// The phone is busy
		// Call forwarding busy
		if (pu->service.get_cf_active(CF_BUSY, cf_dest)) {
			log_file->write_report("Call redirection busy",
				"t_phone::recvd_invite");
			resp = r->create_response(R_302_MOVED_TEMPORARILY);
			resp->hdr_contact.set_contacts(cf_dest);
			send_response(resp, 0, tid);
			
			// Create a call history record
			call_record.start_call(r, t_call_record::DIR_IN, 
				user_config->get_profile_name());
			call_record.fail_call(resp);
			call_history->add_call_record(call_record);
			
			MEMMAN_DELETE(resp);
			delete resp;
		}

		// Send busy response
		resp = r->create_response(R_486_BUSY_HERE);
		send_response(resp, 0, tid);
		
		// Create a call history record
		call_record.start_call(r, t_call_record::DIR_IN, 
			user_config->get_profile_name());
		call_record.fail_call(resp);
		call_history->add_call_record(call_record);
			
		MEMMAN_DELETE(resp);
		delete resp;
		return;
	}

	// RFC 3261 12.2.2
	// A To-header with a tag is a mid-dialog request.
	// Find a line that matches the request
	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match(r)) {
			lines[i]->recvd_invite(user_config, r, tid, "");
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

	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match(r)) {
			t_user *user_config = lines[i]->get_user();
			assert(user_config);

			if (!user_config->check_required_ext(r, unsupported))
			{
				// Not all required extensions are supported
				resp = r->create_response(R_420_BAD_EXTENSION);
				resp->hdr_unsupported.set_features(unsupported);
				send_response(resp, 0, tid);
				MEMMAN_DELETE(resp);
				delete resp;
				return;
			}			
		
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
	
	// Find out for which user this OPTIONS is.
	t_phone_user *pu = match_phone_user(r);
	if (!pu) {
		resp = r->create_response(R_404_NOT_FOUND);
		send_response(resp, 0, tid);
		MEMMAN_DELETE(resp);
		delete resp;
		return;
	}

	// Check if the far end requires any unsupported extensions
	if (!pu->get_user_profile()->check_required_ext(r, unsupported))
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
		resp = pu->create_options_response(r);
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

void t_phone::recvd_subscribe(t_request *r, t_tid tid) {
	t_response *resp;

	if (r->hdr_event.event_type != SIP_EVENT_REFER) {
		// Non-supported event type
		resp = r->create_response(R_489_BAD_EVENT);
		resp->hdr_allow_events.add_event_type(SIP_EVENT_REFER);
		send_response(resp, 0 ,tid);
		MEMMAN_DELETE(resp);
		delete resp;
		return;
	}

	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match(r)) {
			lines[i]->recvd_subscribe(r, tid);
			return;
		}
	}

	if (r->hdr_to.tag == "") {
		// A REFER outside a dialog is not allowed by Twinkle
		if (r->hdr_event.event_type == SIP_EVENT_REFER) {
			// RFC 3515 2.4.4
			resp = r->create_response(R_403_FORBIDDEN);
		}

		send_response(resp, 0 ,tid);
		MEMMAN_DELETE(resp);
		delete resp;
		return;
	}

	resp = r->create_response(R_481_TRANSACTION_NOT_EXIST);
	send_response(resp, 0, tid);
	MEMMAN_DELETE(resp);
	delete resp;
}

void t_phone::recvd_notify(t_request *r, t_tid tid) {
	t_response *resp;

	if (r->hdr_event.event_type != SIP_EVENT_REFER) {
		// Non-supported event type
		resp = r->create_response(R_489_BAD_EVENT);
		resp->hdr_allow_events.add_event_type(SIP_EVENT_REFER);
		send_response(resp, 0 ,tid);
		MEMMAN_DELETE(resp);
		delete resp;
		return;
	}

	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match(r)) {
			lines[i]->recvd_notify(r, tid);
			if (lines[i]->get_refer_state() == REFST_NULL) {
				// Refer subscription has finished.
				log_file->write_report("Refer subscription terminated.",
					"t_phone::recvd_notify");

				if (lines[i]->is_refer_succeeded()) {
					log_file->write_report(
						"Refer succeeded. End call with referee,",
						"t_phone::recvd_notify");
					lines[i]->end_call();
				} else {
					log_file->write_report("Refer failed.",
						"t_phone::recvd_notify");

					t_user *user_config = lines[i]->get_user();
					assert(user_config);
					if (user_config->referrer_hold &&
					    lines[i]->get_is_on_hold())
					{
						// Retrieve the call if the line is active.
						if (i == active_line) {
							log_file->write_report(
								"Retrieve call with referee.",
								"t_phone::recvd_notify");
							lines[i]->retrieve();
						}
					}
				}
			}
			return;
		}
	}

	if (r->hdr_to.tag == "") {
		// NOTIFY outside a dialog is not allowed.
		resp = r->create_response(R_403_FORBIDDEN);
		send_response(resp, 0 ,tid);
		MEMMAN_DELETE(resp);
		delete resp;
		return;
	}

	resp = r->create_response(R_481_TRANSACTION_NOT_EXIST);
	send_response(resp, 0, tid);
	MEMMAN_DELETE(resp);
	delete resp;
}

void t_phone::recvd_refer(t_request *r, t_tid tid) {
	t_response *resp;

	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match(r)) {
			// Reject if a 3-way call is established.
			if (is_3way) {
				log_file->write_report("3-way call active. Reject REFER.",
					"t_phone::recvd_refer");
				resp = r->create_response(R_603_DECLINE);
				send_response(resp, 0, tid);
				MEMMAN_DELETE(resp);
				delete resp;
				return;
			}
			
			// Reject if the line is on-hold.
			if (is_3way || lines[i]->get_is_on_hold()) {
				log_file->write_report("Line is on-hold. Reject REFER.",
					"t_phone::recvd_refer");
				resp = r->create_response(R_603_DECLINE);
				send_response(resp, 0, tid);
				MEMMAN_DELETE(resp);
				delete resp;
				return;
			}

			// Check if a refer is alread in progress
			if (i == LINENO_REFERRER ||
			    lines[LINENO_REFERRER]->get_state() != LS_IDLE)
			{
				log_file->write_report(
					"A REFER is still in progress. Reject REFER.",
					"t_phone::recvd_refer");
				resp = r->create_response(R_603_DECLINE);
				send_response(resp, 0, tid);
				MEMMAN_DELETE(resp);
				delete resp;
				return;
			}

			if (!lines[i]->recvd_refer(r, tid)) {
				// Refer has been rejected.
				return;
			}
			
			t_user *user_config = lines[i]->get_user();
			assert(user_config);

			ui->cb_call_referred(user_config, i, r);

			// Put line on-hold and place it in the referrer line
			log_file->write_report(
				"Hold call before calling the refer-target.",
				"t_phone::recvd_refer");

			if (user_config->referee_hold) {
				lines[i]->hold();
			} else {
				// The user profile indicates that the line should
				// not be put on-hold, i.e. do not send re-INVITE.
				// So only stop RTP.
				lines[i]->hold(true);
			}

			t_line *l = lines[i];
			lines[i] = lines[LINENO_REFERRER];
			lines[i]->line_number = i;
			lines[LINENO_REFERRER] = l;
			lines[LINENO_REFERRER]->line_number = LINENO_REFERRER;

			ui->cb_line_state_changed();

			// Setup call to the Refer-To destination
			log_file->write_report("Call refer-target.",
				"t_phone::recvd_refer");
			lines[i]->invite(user_config, r->hdr_refer_to.uri,
				r->hdr_refer_to.display, "", r->hdr_referred_by);
			lines[i]->open_dialog->is_referred_call = true;

			return;
		}
	}

	if (r->hdr_to.tag == "") {
		// Twinkle does not allow a REFER outside a dialog.
		resp = r->create_response(R_403_FORBIDDEN);
		send_response(resp, 0 ,tid);
		MEMMAN_DELETE(resp);
		delete resp;
		return;
	}

	resp = r->create_response(R_481_TRANSACTION_NOT_EXIST);
	send_response(resp, 0, tid);
	MEMMAN_DELETE(resp);
	delete resp;
}

void t_phone::failure(t_failure failure, t_tid tid) {
	// TODO
}

void t_phone::recvd_stun_resp(StunMessage *r, t_tuid tuid, t_tid tid) {
	for (unsigned short i = 0; i < NUM_LINES; i++) {
		if (lines[i]->match(r, tuid)) {
			lines[i]->recvd_stun_resp(r, tuid, tid);
			return;
		}
	}

	// out-of-dialog STUN responses
	handle_response_out_of_dialog(r, tuid);
}


///////////
// Public
///////////

t_phone::t_phone() : t_transaction_layer() {
	is_active = true;
	active_line = 0;

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
	// Delete phone lines
	for (unsigned short i = 0; i < NUM_LINES; i++) {
		MEMMAN_DELETE(lines[i]);
		delete lines[i];
	}
	
	// Delete all phone users
	for (list<t_phone_user *>::iterator i = phone_users.begin();
	     i != phone_users.end(); i++)
	{
		MEMMAN_DELETE(*i);
		delete *i;
	}
}

void t_phone::pub_invite(t_user *user, 
		const t_url &to_uri, const string &to_display,
		const string &subject)
{
	lock();
	
	t_phone_user *pu = find_phone_user(user->get_profile_name());
	if (pu) {
		invite(pu, to_uri, to_display, subject);
	} else {
		log_file->write_header("t_phone::pub_invite", LOG_NORMAL, LOG_WARNING);
		log_file->write_raw("User profile not active: ");
		log_file->write_raw(user->get_profile_name());
		log_file->write_footer();
	}
	
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

void t_phone::pub_redirect(const list<t_display_url> &destinations, int code, string reason)
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

void t_phone::pub_registration(t_user *user,
		t_register_type register_type,
		unsigned long expires)
{
	lock();
	
	t_phone_user *pu = find_phone_user(user->get_profile_name());
	if (pu) {
		registration(pu, register_type, expires);
	} else {
		log_file->write_header("t_phone::pub_registration", LOG_NORMAL, LOG_WARNING);
		log_file->write_raw("User profile not active: ");
		log_file->write_raw(user->get_profile_name());
		log_file->write_footer();
	}
	
	unlock();
}

void t_phone::pub_options(t_user *user,
		const t_url &to_uri, const string &to_display) 
{
	lock();
	
	t_phone_user *pu = find_phone_user(user->get_profile_name());
	if (pu) {
		options(pu, to_uri, to_display);
	} else {
		log_file->write_header("t_phone::pub_options", LOG_NORMAL, LOG_WARNING);
		log_file->write_raw("User profile not active: ");
		log_file->write_raw(user->get_profile_name());
		log_file->write_footer();
	}
	
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

void t_phone::pub_refer(const t_url &uri, const string &display) {
	lock();
	refer(uri, display);
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

bool t_phone::pub_seize(void) {
	bool retval;
	
	lock();
	retval = lines[active_line]->seize();
	unlock();
	
	return retval;
}

void t_phone::pub_unseize(void) {
	lock();
	lines[active_line]->unseize();
	unlock();
}

t_phone_state t_phone::get_state(void) const {
	t_phone *self = const_cast<t_phone *>(this);

	self->lock();
	for (unsigned short i = 0; i < NUM_USER_LINES; i++) {
		if (lines[i]->get_state() == LS_IDLE) {
			self->unlock();
			return PS_IDLE;
		}
	}

	// All lines are busy, so the phone is busy.
	self->unlock();
	return PS_BUSY;
}

bool t_phone::all_lines_idle(void) const {
	t_phone *self = const_cast<t_phone *>(this);

	self->lock();
	for (unsigned short i = 0; i < NUM_USER_LINES; i++) {
		if (lines[i]->get_substate() != LSSUB_IDLE) {
			self->unlock();
			return false;
		}
	}
	
	// All lines are idle
	self->unlock();
	return true;
}

void t_phone::timeout(t_phone_timer timer, unsigned short id_timer) {
	lock();

	switch (timer) {
	case PTMR_REGISTRATION:
		for (list<t_phone_user *>::iterator i = phone_users.begin();
		     i != phone_users.end(); i++)
		{
			if ((*i)->id_registration == id_timer) {
				(*i)->timeout(timer);
			}
		}
		break;
	case PTMR_NAT_KEEPALIVE:
		for (list<t_phone_user *>::iterator i = phone_users.begin();
		     i != phone_users.end(); i++)
		{
			if ((*i)->id_nat_keepalive == id_timer) {
				(*i)->timeout(timer);
			}
		}
		break;
	default:
		assert(false);
	}

	unlock();
}

void t_phone::set_active_line(unsigned short l) {
	lock();
	assert (l < NUM_USER_LINES);
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

bool t_phone::authorize(t_user *user, t_request *r, t_response *resp) 
{
	bool result = false;
	
	lock();
	t_phone_user *pu = find_phone_user(user->get_profile_name());
	if (pu) result = pu->authorize(r, resp);
	unlock();
	
	return result;
}

void t_phone::remove_cached_credentials(t_user *user, const string &realm) {
	lock();
	t_phone_user *pu = find_phone_user(user->get_profile_name());
	if (pu) pu->remove_cached_credentials(realm);
	unlock();
}

bool t_phone::get_is_registered(t_user *user) {
	bool result = false;
	
	lock();
	t_phone_user *pu = find_phone_user(user->get_profile_name());
	if (pu) result = pu->get_is_registered();
	unlock();
	
	return result;
}

bool t_phone::get_last_reg_failed(t_user *user) {
	bool result = false;
	
	lock();
	t_phone_user *pu = find_phone_user(user->get_profile_name());
	if (pu) result = pu->get_last_reg_failed();
	unlock();
	
	return result;
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

bool t_phone::is_line_auto_answered(unsigned short lineno) const {
	assert(lineno < NUM_LINES);
	t_phone *self = const_cast<t_phone *>(this);

	self->lock();
	bool b = get_line(lineno)->get_auto_answer();
	self->unlock();
	return b;
}

t_refer_state t_phone::get_line_refer_state(unsigned short lineno) const {
	assert(lineno < NUM_LINES);
	t_phone *self = const_cast<t_phone *>(this);

	self->lock();
	t_refer_state s = get_line(lineno)->get_refer_state();
	self->unlock();
	return s;
}

t_user *t_phone::get_line_user(unsigned short lineno) {
	assert(lineno < NUM_LINES);
	lock();
	t_user *user = get_line(lineno)->get_user();
	unlock();
	return user;
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
	assert(lineno1 < NUM_USER_LINES);
	assert(lineno2 < NUM_USER_LINES);

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

void t_phone::notify_refer_progress(t_response *r, unsigned short referee_lineno) {
	if (lines[LINENO_REFERRER]->get_state() != LS_IDLE) {
		lines[LINENO_REFERRER]->notify_refer_progress(r);

		if (!lines[LINENO_REFERRER]->active_dialog ||
		    lines[LINENO_REFERRER]->active_dialog->get_state() != DS_CONFIRMED)
		{
			// The call to the referrer has already been
			// terminated.
			return;
		}

		if (r->is_final()) {
			if (r->is_success()) {
				// Reference was successful, end the call with
				// with the referrer.
				log_file->write_header(
					"t_phone::notify_refer_progress");
				log_file->write_raw(
					"Call to refer-target succeeded.\n");
				log_file->write_raw(
					"End call with referrer.\n");
				log_file->write_footer();
				
				lines[LINENO_REFERRER]->end_call();
			} else {
				// Reference failed, retrieve the call with the
				// referrer.
				log_file->write_header(
					"t_phone::notify_refer_progress");
				log_file->write_raw(
					"Call to refer-target failed.\n");
				log_file->write_raw(
					"Restore call with referrer.\n");
				log_file->write_footer();

				// Retrieve the parked line
				t_line *l = lines[referee_lineno];
				lines[referee_lineno] = lines[LINENO_REFERRER];
				lines[referee_lineno]->line_number = referee_lineno;
				lines[LINENO_REFERRER] = l;
				lines[LINENO_REFERRER]->line_number = LINENO_REFERRER;
				
				// Retrieve the call if the line is active
				if (referee_lineno == active_line) {
					log_file->write_report(
						"Retrieve call with referrer.",
						"t_phone::notify_refer_progress");
					lines[referee_lineno]->retrieve();
				}
				
				t_user *user_config = lines[referee_lineno]->get_user();
				assert(user_config);
				
				ui->cb_retrieve_referrer(user_config, referee_lineno);
			}
		}
	}
}

t_call_info t_phone::get_call_info(unsigned short lineno) const {
	assert(lineno < NUM_LINES);
	t_phone *self = const_cast<t_phone *>(this);

	self->lock();
	t_call_info call_info = get_line(lineno)->get_call_info();
	self->unlock();
	return call_info;
}

t_call_record t_phone::get_call_hist(unsigned short lineno) const {
	assert(lineno < NUM_LINES);
	t_phone *self = const_cast<t_phone *>(this);

	self->lock();
	t_call_record call_hist = get_line(lineno)->call_hist_record;
	self->unlock();
	return call_hist;
}

string t_phone::get_ringtone(unsigned short lineno) const {
	assert(lineno < NUM_LINES);
	t_phone *self = const_cast<t_phone *>(this);

	self->lock();
	string ringtone = get_line(lineno)->get_ringtone();
	self->unlock();
	return ringtone;
}

void t_phone::init_rtp_ports(void) {
	for (int i = 0; i < NUM_LINES; i++) {
		lines[i]->init_rtp_port();
	}
}

bool t_phone::add_phone_user(const t_user &user_config, t_user **dup_user) {
	lock();
	for (list<t_phone_user *>::iterator i = phone_users.begin();
	     i != phone_users.end(); i++)
	{
		t_user *user = (*i)->get_user_profile();
		
		// If the profile is already added, then just activate it.
		if (user->get_profile_name() == user_config.get_profile_name())
		{	
			if (!(*i)->is_active()) (*i)->activate(user_config);
			unlock();
			return true;
		}
		
		// Check if there is already another profile for the same
		// user.
		if (user->name == user_config.name &&
		    user->domain == user_config.domain &&
		    (*i)->is_active())
		{
			*dup_user = user;
			unlock();
			return false;
		}
	}
	
	// Add the user
	t_phone_user *pu = new t_phone_user(user_config);
	MEMMAN_NEW(pu);
	phone_users.push_back(pu);
	unlock();
	
	return true;
}

void t_phone::remove_phone_user(const t_user &user_config) {
	lock();
	t_phone_user *pu = find_phone_user(user_config.get_profile_name());
	if (pu) pu->deactivate();
	unlock();
}

list<t_user *> t_phone::ref_users(void) {
	list<t_user *> l;
	
	lock();
	for (list<t_phone_user *>::iterator i = phone_users.begin();
	     i != phone_users.end(); i++)
	{
		if (!(*i)->is_active()) continue;
		l.push_back((*i)->get_user_profile());
	}
	unlock();
	
	return l;
}

t_user *t_phone::ref_user_display_uri(const string &display_uri) {
	t_user *u = NULL;
	
	lock();
	for (list<t_phone_user *>::iterator i = phone_users.begin();
	     i != phone_users.end(); i++)
	{
		if (!(*i)->is_active()) continue;
		if ((*i)->get_user_profile()->get_display_uri() == display_uri) {
			u = (*i)->get_user_profile();
			break;
		}
	}
	unlock();
	
	return u;
}

t_user *t_phone::ref_user_profile(const string &profile_name) {
	t_user *u = NULL;
	
	lock();
	t_phone_user *pu = find_phone_user(profile_name);
	if (pu) u = pu->get_user_profile();
	unlock();
	
	return u;
}

t_service t_phone::get_service(t_user *user) {
	t_service srv;
	
	lock();
	t_phone_user *pu = find_phone_user(user->get_profile_name());
	if (pu) srv = pu->service;
	unlock();
	
	return srv;
}

t_service *t_phone::ref_service(t_user *user) {
	t_service *srv;
	
	lock();
	t_phone_user *pu = find_phone_user(user->get_profile_name());
	if (pu) srv = &(pu->service);
	unlock();
	
	return srv;
}

string t_phone::get_ip_sip(t_user *user) {
	string result;

	lock();
	t_phone_user *pu = find_phone_user(user->get_profile_name());
	if (pu) {
		result = pu->get_ip_sip();
	} else {
		result = LOCAL_IP;
	}
	unlock();
	
	return result;
}

unsigned short t_phone::get_public_port_sip(t_user *user) {
	unsigned short result;
	
	lock();
	t_phone_user *pu = find_phone_user(user->get_profile_name());
	if (pu) {
		result = pu->get_public_port_sip();
	} else {
		result = get_default_port(USER_SCHEME);
	}
	unlock();
	
	return result;
}

bool t_phone::use_stun(t_user *user) {
	bool result;

	lock();
	t_phone_user *pu = find_phone_user(user->get_profile_name());
	if (pu) {
		result = pu->use_stun;
	} else {
		result = false;
	}
	unlock();
	
	return result;
}

void t_phone::disable_stun(t_user *user) {
	lock();
	t_phone_user *pu = find_phone_user(user->get_profile_name());
	if (pu) pu->use_stun = false;
	unlock();
}

bool t_phone::stun_discover_nat(list<string> &msg_list) {
	bool retval = true;
	
	lock();
	for (list<t_phone_user *>::iterator i = phone_users.begin();
	     i != phone_users.end(); i++)
	{
		if (!(*i)->is_active()) continue;
		t_user *user_config = (*i)->get_user_profile();
		if (user_config->use_stun) {
			string msg;
			if (!::stun_discover_nat(*i, msg)) {
				string s("User profile: ");
				s + user_config->get_profile_name();
				s += "\n\n";
				s += msg;
				msg_list.push_back(s);
				retval = false;
			}
		}
	}
	unlock();
	
	return retval;
}

bool t_phone::stun_discover_nat(t_user *user, string &msg) {
	bool retval = true;
	
	lock();
	if (user->use_stun) {
		t_phone_user *pu = find_phone_user(user->get_profile_name());
		if (pu) {
			retval = ::stun_discover_nat(pu, msg);
		}
	}
	unlock();
	
	return retval;
}

t_response *t_phone::create_options_response(t_user *user, t_request *r,
					bool in_dialog)
{
	t_response *resp;
	
	lock();
	t_phone_user *pu = find_phone_user(user->get_profile_name());
	if (pu) {
		resp = pu->create_options_response(r, in_dialog);
	} else {
		resp = r->create_response(R_500_INTERNAL_SERVER_ERROR);
	}
	unlock();
	
	return resp;
}

void t_phone::init(void) {
	lock();
	
	list<t_user *> user_list = ref_users();
	
	// Automatic registration at startup if requested
	for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++)
	{
		if ((*i)->register_at_startup) {
			pub_registration(*i, REG_REGISTER, DUR_REGISTRATION(*i));
		}
	}
	
	unlock();
}

void t_phone::terminate(void) {
	lock();
	
	// Clear all lines
	for (int i = 0; i < NUM_LINES; i++) {
		switch (lines[i]->get_substate()) {
		case LSSUB_IDLE:
			break;
		case LSSUB_SEIZED:
			lines[i]->unseize();
			break;
		case LSSUB_INCOMING_PROGRESS:
			ui->cb_stop_tone(i);
			lines[i]->reject();
			break;
		case LSSUB_OUTGOING_PROGRESS:
			ui->cb_stop_tone(i);
			// Fall thru
		case LSSUB_ANSWERING:
		case LSSUB_ESTABLISHED:
			lines[i]->end_call();
			break;
		}
	}
	
	// Deactivate phone
	is_active = false;
	
	unlock();
	
	// De-register all registered users.
	list<t_user *> user_list = ref_users();
	ui->cb_display_msg("Deregistering phone...");
	for (list<t_user *>::iterator i = user_list.begin();
	     i != user_list.end(); i++)
	{
		if (get_is_registered(*i)) {
			pub_registration(*i, REG_DEREGISTER);
		}
	}
	
	// Wait till phone is deregistered.
	for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++)
	{
		while (get_is_registered(*i)) {
			sleep(1);
		}
	}
	
	// Wait till all lines are idle
	int dur = 0;
	while (dur < QUIT_IDLE_WAIT) {
		if (all_lines_idle()) break;
		sleep(1);
		dur++;
	}
}

void *phone_uas_main(void *arg) {
	phone->run();
}

void *phone_sigwait(void *arg) {
	sigset_t	sigset;
	int		sig;

	sigemptyset(&sigset);
	sigaddset(&sigset, SIGINT);
	sigaddset(&sigset, SIGTERM);

	sigwait(&sigset, &sig);
	ui->cmd_quit();
}
