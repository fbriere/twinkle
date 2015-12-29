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
#include "line.h"
#include "sdp/sdp.h"
#include "util.h"
#include "user.h"
#include "userintf.h"
#include "audits/memman.h"

extern t_event_queue	*evq_timekeeper;

///////////
// Private
///////////
t_dialog *t_line::match_response(t_response *r,
		const list<t_dialog *> &l) const
{
	list<t_dialog *>::const_iterator i;
	for (i = l.begin(); i != l.end(); i++) {
		if ((*i)->match_response(r, 0)) return *i;
	}

	return NULL;
}

t_dialog *t_line::get_dialog(t_dialog_id did) const {
	list<t_dialog *>::const_iterator i;

	if (did == 0) return NULL;

	if (open_dialog && open_dialog->get_id() == did) {
		return open_dialog;
	}

	if (active_dialog && active_dialog->get_id() == did) {
		return active_dialog;
	}

	for (i = pending_dialogs.begin(); i != pending_dialogs.end(); i++) {
		if ((*i)->get_id() == did) return *i;
	}

	for (i = dying_dialogs.begin(); i != dying_dialogs.end(); i++) {
		if ((*i)->get_id() == did) return *i;
	}

	return NULL;
}

void t_line::cleanup(void) {
	list<t_dialog *>::iterator i;

	if (open_dialog && open_dialog->get_state() == DS_TERMINATED) {
		MEMMAN_DELETE(open_dialog);
		delete open_dialog;
		open_dialog = NULL;
	}

	if (active_dialog && active_dialog->get_state() == DS_TERMINATED) {
		MEMMAN_DELETE(active_dialog);
		delete active_dialog;
		active_dialog = NULL;

		stop_timer(LTMR_INVITE_COMP);
		stop_timer(LTMR_NO_ANSWER);

		// If the call has been ended within 64*T1 seconds
		// after the reception of the first 2XX response, there
		// might still be open and pending dialogs. To be nice these
		// dialogs should be kept till the 64*T1 timer expires.
		// This complicates the setup of new call however. For
		// now the dialogs will be killed. If a slow UAS
		// still responds, it has bad luck and will time out.
		//
		// TODO:
		// A nice solution would be to move the pending and open
		// dialog to the dying dialog and start a new time 64*T1
		// timer to keep the dying dialogs alive. A sequence of
		// a few short calls would add to the dying dialogs and
		// keep some dialogs alive longer than necessary. This
		// only has an impact on resources, not on signalling.
		// Note that the open dialog must be appended after the
		// pending dialogs, otherwise all received responses for
		// a pending dialog will match the open dialog if that
		// match is tried first by match_response()
		for (i = pending_dialogs.begin(); i != pending_dialogs.end();
			i++)
		{
			MEMMAN_DELETE(*i);
			delete *i;
		}
		pending_dialogs.clear();

		if (open_dialog) {
			MEMMAN_DELETE(open_dialog);
			delete open_dialog;
		}
		open_dialog = NULL;
	}

	for (i = pending_dialogs.begin(); i != pending_dialogs.end(); i++) {
		if ((*i)->get_state() == DS_TERMINATED) {
			MEMMAN_DELETE(*i);
			delete *i;
			*i = NULL;
		}
	}
	pending_dialogs.remove(NULL);

	for (i = dying_dialogs.begin(); i != dying_dialogs.end(); i++) {
		if ((*i)->get_state() == DS_TERMINATED) {
			MEMMAN_DELETE(*i);
			delete *i;
			*i = NULL;
		}
	}
	dying_dialogs.remove(NULL);

	if (!open_dialog && !active_dialog && pending_dialogs.size() == 0) {
		state = LS_IDLE;
		substate = LSSUB_IDLE;
		is_on_hold = false;
		is_muted = false;
		phone->line_cleared(line_number);
		ui->cb_line_state_changed();
	}
}

void t_line::cleanup_open_pending(void) {
	if (open_dialog) {
		MEMMAN_DELETE(open_dialog);
		delete open_dialog;
		open_dialog = NULL;
	}

	list<t_dialog *>::iterator i;
	for (i = pending_dialogs.begin(); i != pending_dialogs.end(); i++) {
		MEMMAN_DELETE(*i);
		delete *i;
	}
	pending_dialogs.clear();

	if (!active_dialog) {
		is_on_hold = false;
		is_muted = false;
		state = LS_IDLE;
		substate = LSSUB_IDLE;
		phone->line_cleared(line_number);
		ui->cb_line_state_changed();
	}
}

///////////
// Public
///////////

t_line::t_line(t_phone *_phone, unsigned short _line_number) {
	assert(_line_number < NUM_LINES);

	phone = _phone;
	state = LS_IDLE;
	substate = LSSUB_IDLE;
	open_dialog = NULL;
	active_dialog = NULL;
	is_on_hold = false;
	is_muted = false;
	line_number = _line_number;
	id_invite_comp = 0;
	id_no_answer = 0;
}

t_line::~t_line() {
	list<t_dialog *>::iterator i;

	// Stop timers
	if (id_invite_comp) stop_timer(LTMR_INVITE_COMP);
	if (id_no_answer) stop_timer(LTMR_NO_ANSWER);

	// Delete pointers
	if (open_dialog) {
		MEMMAN_DELETE(open_dialog);
		delete open_dialog;
	}
	if (active_dialog) {
		MEMMAN_DELETE(active_dialog);
		delete active_dialog;
	}

	// Delete dialogs
	for (i = pending_dialogs.begin(); i != pending_dialogs.end(); i++) {
		MEMMAN_DELETE(*i);
		delete *i;
	}

	for (i = dying_dialogs.begin(); i != dying_dialogs.end(); i++) {
		MEMMAN_DELETE(*i);
		delete *i;
	}
}

t_line_state t_line::get_state(void) const {
	return state;
}

t_line_substate t_line::get_substate(void) const {
	return substate;
}

void t_line::start_timer(t_line_timer timer, t_dialog_id did) {
	t_tmr_line	*t;
	t_dialog	*dialog = get_dialog(did);

	switch(timer) {
	case LTMR_ACK_TIMEOUT:
		assert(dialog);
		// RFC 3261 13.3.1.4
		if (dialog->dur_ack_timeout == 0) {
			dialog->dur_ack_timeout = DURATION_T1;
		} else {
			dialog->dur_ack_timeout *= 2;
			if (dialog->dur_ack_timeout > DURATION_T2 ) {
				dialog->dur_ack_timeout = DURATION_T2;
			}
		}
		t = new t_tmr_line(dialog->dur_ack_timeout , timer, this,
					did);
		MEMMAN_NEW(t);
		dialog->id_ack_timeout = t->get_id();
		break;
	case LTMR_ACK_GUARD:
		assert(dialog);
		// RFC 3261 13.3.1.4
		t = new t_tmr_line(64 * DURATION_T1, timer, this, did);
		MEMMAN_NEW(t);
		dialog->id_ack_guard = t->get_id();
		break;
	case LTMR_INVITE_COMP:
		// RFC 3261 13.2.2.4
		t = new t_tmr_line(64 * DURATION_T1, timer, this, did);
		MEMMAN_NEW(t);
		id_invite_comp = t->get_id();
		break;
	case LTMR_NO_ANSWER:
		t = new t_tmr_line(DUR_NO_ANSWER, timer, this, did);
		MEMMAN_NEW(t);
		id_no_answer = t->get_id();
		break;
	case LTMR_RE_INVITE_GUARD:
		assert(dialog);
		t = new t_tmr_line(DUR_RE_INVITE_GUARD, timer, this, did);
		MEMMAN_NEW(t);
		dialog->id_re_invite_guard = t->get_id();
		break;
	case LTMR_100REL_TIMEOUT:
		assert(dialog);
		// RFC 3262 3
		if (dialog->dur_100rel_timeout == 0) {
			dialog->dur_100rel_timeout = DUR_100REL_TIMEOUT;
		} else {
			dialog->dur_100rel_timeout *= 2;
		}
		t = new t_tmr_line(dialog->dur_100rel_timeout , timer, this,
					did);
		MEMMAN_NEW(t);
		dialog->id_100rel_timeout = t->get_id();
		break;
	case LTMR_100REL_GUARD:
		assert(dialog);
		// RFC 3262 3
		t = new t_tmr_line(DUR_100REL_GUARD, timer, this, did);
		MEMMAN_NEW(t);
		dialog->id_100rel_guard = t->get_id();
		break;
	default:
		assert(false);
	}

	evq_timekeeper->push_start_timer(t);
	MEMMAN_DELETE(t);
	delete t;
}

void t_line::stop_timer(t_line_timer timer, t_dialog_id did) {
	unsigned short	*id;
	t_dialog	*dialog = get_dialog(did);

	switch(timer) {
	case LTMR_ACK_TIMEOUT:
		assert(dialog);
		dialog->dur_ack_timeout = 0;
		id = &dialog->id_ack_timeout;
		break;
	case LTMR_ACK_GUARD:
		assert(dialog);
		id = &dialog->id_ack_guard;
		break;
	case LTMR_INVITE_COMP:
		id = &id_invite_comp;
		break;
	case LTMR_NO_ANSWER:
		id = &id_no_answer;
		break;
	case LTMR_RE_INVITE_GUARD:
		assert(dialog);
		id = &dialog->id_re_invite_guard;
		break;
	case LTMR_100REL_TIMEOUT:
		assert(dialog);
		dialog->dur_100rel_timeout = 0;
		id = &dialog->id_100rel_timeout;
		break;
	case LTMR_100REL_GUARD:
		assert(dialog);
		id = &dialog->id_100rel_guard;
		break;
	default:
		assert(false);
	}

	if (*id != 0) evq_timekeeper->push_stop_timer(*id);
	*id = 0;
}

void t_line::invite(const t_url &to_uri, const string &to_display,
		const string &subject)
{
	// Ignore if line is not idle
	if (state != LS_IDLE) {
		return;
	}

	assert(!open_dialog);

	state = LS_BUSY;
	substate = LSSUB_OUTGOING_PROGRESS;
	ui->cb_line_state_changed();

	open_dialog = new t_dialog(this);
	MEMMAN_NEW(open_dialog);
	open_dialog->send_invite(to_uri, to_display, subject);

	cleanup();
}

void t_line::answer(void) {
	// Ignore if line is idle
	if (state == LS_IDLE) return;
	assert(active_dialog);

	stop_timer(LTMR_NO_ANSWER);

	try {
		substate = LSSUB_ANSWERING;
		ui->cb_line_state_changed();
		active_dialog->answer();
	}
	catch (t_exception x) {
		// TODO: there is no call to answer
	}

	cleanup();
}

void t_line::reject(void) {
	// Ignore if line is idle
	if (state == LS_IDLE) return;
	assert(active_dialog);

	stop_timer(LTMR_NO_ANSWER);

	try {
		active_dialog->reject(R_603_DECLINE);
	}
	catch (t_exception x) {
		// TODO: there is no call to reject
	}

	cleanup();
}

void t_line::redirect(const list<t_url> &destinations, int code, string reason)
{
	// Ignore if line is idle
	if (state == LS_IDLE) return;
	assert(active_dialog);

	stop_timer(LTMR_NO_ANSWER);

	try {
		active_dialog->redirect(destinations, code, reason);
	}
	catch (t_exception x) {
		// TODO: there is no call to redirect
	}

	cleanup();
}

void t_line::end_call(void) {
	// Ignore if phone is idle
	if (state == LS_IDLE) return;

	if (active_dialog) {
		substate = LSSUB_RELEASING;
		ui->cb_line_state_changed();
		ui->cb_stop_tone(line_number);
		active_dialog->send_bye();
		cleanup();
		return;
	}

	// Always send the CANCEL on the open dialog.
	if (open_dialog) {
		substate = LSSUB_RELEASING;
		ui->cb_line_state_changed();
		ui->cb_stop_tone(line_number);
		open_dialog->send_cancel(!pending_dialogs.empty());
		cleanup();
		return;
	}

	// TODO:
	// The call is only ended for real when the dialog reaches
	// the DS_TERMINATED state, i.e. a 200 OK on BYE is received
	// or a 487 TERMINATED on INVITE is received.
	// If the CANCEL glares with a 200 OK on INVITE the call will
	// not be ended at all.
	// The dialog should get some stale state such that a new
	// call can be setup while the old call is terminated in a
	// proper way. Maybe add to dying_dialogs.
}

void t_line::send_dtmf(char digit) {
	if (active_dialog && active_dialog->get_state() == DS_CONFIRMED) {
		active_dialog->send_dtmf(digit);
		cleanup();
		return;
	}
}

void t_line::options(void) {
	if (active_dialog && active_dialog->get_state() == DS_CONFIRMED) {
		active_dialog->send_options();
		cleanup();
		return;
	}
}

bool t_line::hold(void) {
	if (is_on_hold) return true;

	if (active_dialog && active_dialog->get_state() == DS_CONFIRMED) {
		active_dialog->hold();
		is_on_hold = true;
		ui->cb_line_state_changed();
		cleanup();
		return true;
	}

	return false;
}

void t_line::retrieve(void) {
	if (!is_on_hold) return;

	if (active_dialog && active_dialog->get_state() == DS_CONFIRMED) {
		active_dialog->retrieve();
		is_on_hold = false;
		ui->cb_line_state_changed();
		cleanup();
		return;
	}
}

void t_line::mute(bool enable) {
	is_muted = enable;
}

void t_line::recvd_provisional(t_response *r, t_tuid tuid, t_tid tid) {
	t_dialog *d;

	if (active_dialog && active_dialog->match_response(r, 0)) {
		active_dialog->recvd_response(r, tuid, tid);
		cleanup();
		return;
	}

	d = match_response(r, pending_dialogs);
	if (d) {
		d->recvd_response(r, tuid, tid);
		cleanup();
		return;
	}

	d = match_response(r, dying_dialogs);
	if (d) {
		d->recvd_response(r, tuid, tid);
		cleanup();
		return;
	}

	if (open_dialog && open_dialog->match_response(r, tuid)) {
		if (r->hdr_cseq.method == INVITE) {
			if (r->hdr_to.tag.size() > 0) {
				// Create a new pending dialog
				d = open_dialog->copy();
				pending_dialogs.push_back(d);
				d->recvd_response(r, tuid, tid);
			} else {
				open_dialog->recvd_response(r, tuid, tid);
			}
		} else {
			open_dialog->recvd_response(r, tuid, tid);
		}

		cleanup();
		return;
	}

	// out-of-dialog response
	// Provisional responses should only be given for INVITE.
	// A response for an INVITE is always in a dialog.
	// Ignore provisional responses for other requests.
}

void t_line::recvd_success(t_response *r, t_tuid tuid, t_tid tid) {
	t_dialog *d;

	if (active_dialog && active_dialog->match_response(r, 0)) {
		active_dialog->recvd_response(r, tuid, tid);
		cleanup();
		return;
	}

	d = match_response(r, pending_dialogs);
	if (d) {
		d->recvd_response(r, tuid, tid);
		if (r->hdr_cseq.method == INVITE) {
			if (!active_dialog) {
				// Make the dialog the active dialog
				active_dialog = d;
				pending_dialogs.remove(d);
				start_timer(LTMR_INVITE_COMP);
				substate = LSSUB_ESTABLISHED;
				ui->cb_line_state_changed();
			} else {
				// An active dialog already exists.
				// Terminate this dialog by sending BYE
				d->send_bye();
			}
		}

		cleanup();
		return;
	}

	d = match_response(r, dying_dialogs);
	if (d) {
		d->recvd_response(r, tuid, tid);
		if (r->hdr_cseq.method == INVITE) {
			d->send_bye();
		}
		cleanup();
		return;
	}

	if (open_dialog && open_dialog->match_response(r, tuid)) {
		if (r->hdr_cseq.method == INVITE) {
			// Create a new dialog
			d = open_dialog->copy();

			if (!active_dialog) {
				active_dialog = d;
				active_dialog->recvd_response(r, tuid, tid);
				start_timer(LTMR_INVITE_COMP);
				substate = LSSUB_ESTABLISHED;
				ui->cb_line_state_changed();
			} else {
				pending_dialogs.push_back(d);
				d->recvd_response(r, tuid, tid);

				// An active dialog already exists.
				// Terminate this dialog by sending BYE
				d->send_bye();
			}
		} else {
			open_dialog->recvd_response(r, tuid, tid);
		}

		cleanup();
		return;
	}

	// Response does not match with any pending request. Discard.
}

void t_line::recvd_redirect(t_response *r, t_tuid tuid, t_tid tid) {
	t_dialog *d;

	if (active_dialog) {
		// If an active dialog exists then non-2XX should
		// only be for this dialog.
		if (active_dialog->match_response(r, 0)) {
			// Redirection of mid-dialog request
			if (!user_config->allow_redirection ||
			    !active_dialog->redirect_request(r))
			{
				// Redirection not allowed/failed
				active_dialog->recvd_response(r, tuid, tid);
			}
		}

		cleanup();
		return;
	}

	d = match_response(r, pending_dialogs);
	if (d) {
		d->recvd_response(r, tuid, tid);
		if (r->hdr_cseq.method == INVITE) {
			pending_dialogs.remove(d);
			MEMMAN_DELETE(d);
			delete d;

			// RFC 3261 13.2.2.3
			// All early dialogs are considered terminated
			// upon reception of the non-2xx final response.
			list<t_dialog *>::iterator i;
			for (i = pending_dialogs.begin();
			     i != pending_dialogs.end(); i++)
			{
				MEMMAN_DELETE(*i);
				delete *i;
			}
			pending_dialogs.clear();

			if (open_dialog) {
				if (!user_config->allow_redirection ||
				    !open_dialog->redirect_invite(r))
				{
					MEMMAN_DELETE(open_dialog);
					delete open_dialog;
					open_dialog = NULL;
				}
			}
		}

		cleanup();
		return;
	}

	d = match_response(r, dying_dialogs);
	if (d) {
		d->recvd_response(r, tuid, tid);
		cleanup();
		return;
	}

	if (open_dialog && open_dialog->match_response(r, tuid)) {
		if (r->hdr_cseq.method != INVITE) {
			// TODO: can there be a non-INVITE response for an
			//       open dialog??
			open_dialog->recvd_response(r, tuid, tid);
		}

		if (r->hdr_cseq.method == INVITE) {
			if (!user_config->allow_redirection ||
			    !open_dialog->redirect_invite(r))
			{
				// Redirection failed/not allowed
				open_dialog->recvd_response(r, tuid, tid);
				MEMMAN_DELETE(open_dialog);
				delete open_dialog;
				open_dialog = NULL;
			}

			// RFC 3261 13.2.2.3
			// All early dialogs are considered terminated
			// upon reception of the non-2xx final response.
			list<t_dialog *>::iterator i;
			for (i = pending_dialogs.begin();
			     i != pending_dialogs.end(); i++)
			{
				MEMMAN_DELETE(*i);
				delete *i;
			}
			pending_dialogs.clear();
		}

		cleanup();
		return;
	}

	// out-of-dialog responses should be handled by the phone
}

void t_line::recvd_client_error(t_response *r, t_tuid tuid, t_tid tid) {
	t_dialog *d;

	if (active_dialog) {
		// If an active dialog exists then non-2XX should
		// only be for this dialog.
		if (active_dialog->match_response(r, 0)) {
			bool response_processed = false;

			if (r->must_authenticate()) {
				// Authentication for mid-dialog request
				if (active_dialog->resend_request_auth(r))
				{
					// Authorization successul.
					// The response does not need to be
					// processed any further
					response_processed = true;
				}
			}

			if (!response_processed) {
				// The request failed, redirect it if there
				// are other destinations available.
				if (!user_config->allow_redirection ||
				    !active_dialog->redirect_request(r))
				{
					// Request failed
					active_dialog->
						recvd_response(r, tuid, tid);
				}
			}
		}

		cleanup();
		return;
	}

	d = match_response(r, pending_dialogs);
	if (d) {
		d->recvd_response(r, tuid, tid);
		if (r->hdr_cseq.method == INVITE) {
			pending_dialogs.remove(d);
			MEMMAN_DELETE(d);
			delete d;

			// RFC 3261 13.2.2.3
			// All early dialogs are considered terminated
			// upon reception of the non-2xx final response.
			list<t_dialog *>::iterator i;
			for (i = pending_dialogs.begin();
			     i != pending_dialogs.end(); i++)
			{
				MEMMAN_DELETE(*i);
				delete *i;
			}
			pending_dialogs.clear();

			if (open_dialog) {
				bool response_processed = false;

				if (r->must_authenticate()) {
					// INVITE authentication
					if (open_dialog->resend_invite_auth(r))
					{
						// Authorization successul.
						// The response does not need to
						// be processed any further
						response_processed = true;
					}
				}

				// Resend INVITE if the response indicated that
				// required extensions are not supported.
				if (!response_processed &&
				    open_dialog->resend_invite_unsupported(r))
				{
					response_processed = true;
				}

				if (!response_processed) {
					// The request failed, redirect it if there
					// are other destinations available.
					if (!user_config->allow_redirection ||
					    !open_dialog->redirect_invite(r))
					{
						// Request failed
						MEMMAN_DELETE(open_dialog);
						delete open_dialog;
						open_dialog = NULL;
					}
				}
			}
		}

		cleanup();
		return;
	}

	d = match_response(r, dying_dialogs);
	if (d) {
		d->recvd_response(r, tuid, tid);
		cleanup();
		return;
	}

	if (open_dialog && open_dialog->match_response(r, tuid)) {
		// If the response is a 401/407 then do not send the
		// response to the dialog as the request must be resent.
		// For an INVITE request, the transaction layer has already
		// sent ACK for a failure response.
		if (!r->must_authenticate() && r->hdr_cseq.method != INVITE) {
			open_dialog->recvd_response(r, tuid, tid);
		}

		if (r->hdr_cseq.method == INVITE) {
			bool response_processed = false;

			if (r->must_authenticate()) {
				// INVITE authentication
				if (open_dialog->resend_invite_auth(r))
				{
					// Authorization successul.
					// The response does not need to
					// be processed any further
					response_processed = true;
				}
			}

			// Resend INVITE if the response indicated that
			// required extensions are not supported.
			if (!response_processed &&
			    open_dialog->resend_invite_unsupported(r))
			{
				response_processed = true;
			}

			if (!response_processed) {
				// The request failed, redirect it if there
				// are other destinations available.
				if (!user_config->allow_redirection ||
				    !open_dialog->redirect_invite(r))
				{
					// Request failed
					open_dialog->recvd_response(r, tuid, tid);
					MEMMAN_DELETE(open_dialog);
					delete open_dialog;
					open_dialog = NULL;
				}
			}

			// RFC 3261 13.2.2.3
			// All early dialogs are considered terminated
			// upon reception of the non-2xx final response.
			list<t_dialog *>::iterator i;
			for (i = pending_dialogs.begin();
			     i != pending_dialogs.end(); i++)
			{
				MEMMAN_DELETE(*i);
				delete *i;
			}
			pending_dialogs.clear();
		}

		cleanup();
		return;
	}

	// out-of-dialog responses should be handled by the phone
}

void t_line::recvd_server_error(t_response *r, t_tuid tuid, t_tid tid) {
	recvd_redirect(r, tuid, tid);
}

void t_line::recvd_global_error(t_response *r, t_tuid tuid, t_tid tid) {
	recvd_redirect(r, tuid, tid);
}

void t_line::recvd_invite(t_request *r, t_tid tid) {
	t_response *resp;

	switch (state) {
	case LS_IDLE:
		assert(!active_dialog);
		assert(r->hdr_to.tag == "");

		/*
		// TEST ONLY
		// Test code to test INVITE authentication
		if (!r->hdr_authorization.is_populated()) {
			resp = r->create_response(R_401_UNAUTHORIZED);
			t_challenge c;
			c.auth_scheme = AUTH_DIGEST;
			c.digest_challenge.realm = "mtel.nl";
			c.digest_challenge.nonce = "0123456789abcdef";
			c.digest_challenge.opaque = "secret";
			c.digest_challenge.algorithm = ALG_MD5;
			c.digest_challenge.qop_options.push_back(QOP_AUTH);
			c.digest_challenge.qop_options.push_back(QOP_AUTH_INT);
			resp->hdr_www_authenticate.set_challenge(c);
			send_response(resp, 0, tid);
			return;
		}
		*/

		// Check user in the request-URI
		if (r->uri.get_user() != user_config->name) {
			resp = r->create_response(R_404_NOT_FOUND);
			send_response(resp, 0, tid);
			MEMMAN_DELETE(resp);
			delete resp;
			return;
		}

		active_dialog = new t_dialog(this);
		MEMMAN_NEW(active_dialog);
		active_dialog->recvd_request(r, 0, tid);
		state = LS_BUSY;
		substate = LSSUB_INCOMING_PROGRESS;
		ui->cb_line_state_changed();
		start_timer(LTMR_NO_ANSWER);
		cleanup();
		break;
	case LS_BUSY:
		// Only re-INVITEs can be sent to a busy line
		assert(r->hdr_to.tag != "");

		/*
		// TEST ONLY
		// Test code to test re-INVITE authentication
		if (!r->hdr_authorization.is_populated()) {
			resp = r->create_response(R_401_UNAUTHORIZED);
			t_challenge c;
			c.auth_scheme = AUTH_DIGEST;
			c.digest_challenge.realm = "mtel.nl";
			c.digest_challenge.nonce = "0123456789abcdef";
			c.digest_challenge.opaque = "secret";
			c.digest_challenge.algorithm = ALG_MD5;
			c.digest_challenge.qop_options.push_back(QOP_AUTH);
			c.digest_challenge.qop_options.push_back(QOP_AUTH_INT);
			resp->hdr_www_authenticate.set_challenge(c);
			send_response(resp, 0, tid);
			return;
		}
		*/

		if (active_dialog && active_dialog->match_request(r)) {
			// re-INVITE
			active_dialog->recvd_request(r, 0, tid);
			cleanup();
			return;
		}

		// Should not get here as phone already checked that
		// the request matched with this line
		assert(false);
		break;
	default:
		assert(false);
	}
}

void t_line::recvd_ack(t_request *r, t_tid tid) {
	if (active_dialog && active_dialog->match_request(r)) {
		active_dialog->recvd_request(r, 0, tid);
		substate = LSSUB_ESTABLISHED;
		ui->cb_line_state_changed();
	} else {
		// Should not get here as phone already checked that
		// the request matched with this line
		assert(false);
	}
	cleanup();
}

void t_line::recvd_cancel(t_request *r, t_tid cancel_tid,
		t_tid target_tid)
{
	// A CANCEL matches a dialog if the target tid equals the tid
	// of the INVITE request. This will be checked by
	// dialog::recvd_cancel() itself.
	if (active_dialog) {
		active_dialog->recvd_cancel(r, cancel_tid, target_tid);
	} else {
		// Should not get here as phone already checked that
		// the request matched with this line
		assert(false);
	}
	cleanup();
}

void t_line::recvd_bye(t_request *r, t_tid tid) {
	if (active_dialog && active_dialog->match_request(r)) {
		/*
		// TEST ONLY
		// Test code to test INVITE authentication
		if (!r->hdr_authorization.is_populated()) {
			t_response *resp =
				r->create_response(R_401_UNAUTHORIZED);
			t_challenge c;
			c.auth_scheme = AUTH_DIGEST;
			c.digest_challenge.realm = "mtel.nl";
			c.digest_challenge.nonce = "0123456789abcdef";
			c.digest_challenge.opaque = "secret";
			c.digest_challenge.algorithm = ALG_MD5;
			c.digest_challenge.qop_options.push_back(QOP_AUTH);
			c.digest_challenge.qop_options.push_back(QOP_AUTH_INT);
			resp->hdr_www_authenticate.set_challenge(c);
			send_response(resp, 0, tid);
			return;
		}
		*/

		active_dialog->recvd_request(r, 0, tid);
	} else {
		// Should not get here as phone already checked that
		// the request matched with this line
		assert(false);
	}
	cleanup();
}

void t_line::recvd_options(t_request *r, t_tid tid) {
	t_response *resp;

	if (active_dialog && active_dialog->match_request(r)) {
		active_dialog->recvd_request(r, 0, tid);
	} else {
		// Should not get here as phone already checked that
		// the request matched with this line
		assert(false);
	}
	cleanup();
}

void t_line::recvd_prack(t_request *r, t_tid tid) {
	if (active_dialog && active_dialog->match_request(r)) {
		active_dialog->recvd_request(r, 0, tid);
	} else {
		// Should not get here as phone already checked that
		// the request matched with this line
		assert(false);
	}
	cleanup();
}

void t_line::failure(t_failure failure, t_tid tid) {
	// TODO
}

void t_line::timeout(t_line_timer timer, t_dialog_id did) {
	// This method is called by the timekeeper thread, so lock
	// the phone (transaction layer) to prevent race conditions.

	phone->lock();

	t_dialog *dialog = get_dialog(did);
	list<t_url> cf_dest; // call forwarding destinations

	switch (timer) {
	case LTMR_ACK_TIMEOUT:
		// If there is no dialog then ignore the timeout
		if (dialog) {
			dialog->id_ack_timeout = 0;
			dialog->timeout(timer);
		}
		break;
	case LTMR_ACK_GUARD:
		// If there is no dialog then ignore the timeout
		if (dialog) {
			dialog->id_ack_guard = 0;
			dialog->dur_ack_timeout = 0;
			dialog->timeout(timer);
		}
		break;
	case LTMR_INVITE_COMP:
		id_invite_comp = 0;
		// RFC 3261 13.2.2.4
		// The UAC core considers the INVITE transaction completed
		// 64*T1 seconds after the reception of the first 2XX
		// response.
		// Cleanup all open and pending dialogs
		cleanup_open_pending();
		break;
	case LTMR_NO_ANSWER:
		// User did not answer the call.
		// Reject call or redirect it if CF_NOANSWER is active.
		// If there is no active dialog then ignore the timeout.
		// The timer should have been stopped already.
		if (active_dialog) {
			if (phone->service.get_cf_active(CF_NOANSWER, cf_dest)) {
				active_dialog->redirect(cf_dest,
					R_302_MOVED_TEMPORARILY);
			} else {
				active_dialog->reject(R_480_TEMP_NOT_AVAILABLE,
					REASON_480_NO_ANSWER);
			}
			
			ui->cb_answer_timeout(get_line_number());
		}
		break;
	case LTMR_RE_INVITE_GUARD:
		// If there is no dialog then ignore the timeout
		if (dialog) {
			dialog->id_re_invite_guard = 0;
			dialog->timeout(timer);
		}
		break;
	case LTMR_100REL_TIMEOUT:
		// If there is no dialog then ignore the timeout
		if (dialog) {
			dialog->id_100rel_timeout = 0;
			dialog->timeout(timer);
		}
		break;
	case LTMR_100REL_GUARD:
		// If there is no dialog then ignore the timeout
		if (dialog) {
			dialog->id_100rel_guard = 0;
			dialog->dur_100rel_timeout = 0;
			dialog->timeout(timer);
		}
		break;
	default:
		assert(false);
	}

	cleanup();

	phone->unlock();
}

bool t_line::match(t_response *r, t_tuid tuid) {
	if (open_dialog && open_dialog->match_response(r, tuid)) {
		return true;
	}

	if (active_dialog && active_dialog->match_response(r, 0)) {
		return true;
	}

	if (match_response(r, pending_dialogs)) {
		return true;
	}

	if (match_response(r, dying_dialogs)) {
		return true;
	}

	return false;
}

bool t_line::match(t_request *r) {
	assert(r->method != CANCEL);
	return (active_dialog && active_dialog->match_request(r));
}

bool t_line::match_cancel(t_request *r, t_tid target_tid) {
	assert(r->method == CANCEL);

	// A CANCEL matches a dialog if the target tid equals the tid
	// of the INVITE request.
	return (active_dialog && active_dialog->match_cancel(r, target_tid));
}

string t_line::create_user_contact(void) const {
	return phone->create_user_contact();
}

string t_line::create_user_uri(void) const {
	return phone->create_user_uri();
}

t_response *t_line::create_options_response(t_request *r, bool in_dialog) const
{
	return phone->create_options_response(r, in_dialog);
}

void t_line::send_response(t_response *r, t_tuid tuid, t_tid tid) {
	phone->send_response(r, tuid, tid);
}

void t_line::send_request(t_request *r, t_tuid tuid) {
	phone->send_request(r, tuid);
}

t_phone *t_line::get_phone(void) const {
	return phone;
}

unsigned short t_line::get_line_number(void) const {
	return line_number;
}

bool t_line::get_is_on_hold(void) const {
	return is_on_hold;
}

bool t_line::get_is_muted(void) const {
	return is_muted;
}

void t_line::seize(void) {
	// Only an idle line can be seized.
	if (substate != LSSUB_IDLE) return;

	substate = LSSUB_SEIZED;
	ui->cb_line_state_changed();
}

void t_line::unseize(void) {
	// Only a seized line can be unseized.
	if (substate != LSSUB_SEIZED) return;

	substate = LSSUB_IDLE;
	ui->cb_line_state_changed();
}

t_audio_session *t_line::get_audio_session(void) const {
	if (!active_dialog) return NULL;

	return active_dialog->get_audio_session();
}
