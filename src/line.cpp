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
#include "exceptions.h"
#include "line.h"
#include "log.h"
#include "sdp/sdp.h"
#include "util.h"
#include "user.h"
#include "userintf.h"
#include "audits/memman.h"

extern t_event_queue	*evq_timekeeper;

///////////////
// t_call_info
///////////////

t_call_info::t_call_info() {
	clear();
}

void t_call_info::clear(void) {
	from_uri.set_url("");
	from_display.clear();
	from_organization.clear();
	to_uri.set_url("");
	to_display.clear();
	to_organization.clear();
	subject.clear();
	dtmf_supported = false;
	hdr_referred_by = t_hdr_referred_by();
	last_provisional_reason.clear();
	send_codec = CODEC_NULL;
	recv_codec = CODEC_NULL;
	refer_supported = false;
}


///////////
// t_line
///////////

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

t_dialog *t_line::match_response(StunMessage *r, t_tuid tuid,
		const list<t_dialog *> &l) const
{
	list<t_dialog *>::const_iterator i;
	for (i = l.begin(); i != l.end(); i++) {
		if ((*i)->match_response(r, tuid)) return *i;
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

	if (active_dialog && active_dialog->get_state() == DS_CONFIRMED_SUB) {
		// The calls has been released but a subscription is
		// still active.
		// TODO: a line with this state should go to the background?
		substate = LSSUB_RELEASING;
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
		auto_answer = false;
		call_info.clear();
		call_history->add_call_record(call_hist_record);
		call_hist_record.renew();
		phone->line_cleared(line_number);
		user_config = NULL;
		user_defined_ringtone.clear();
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
		auto_answer = false;
		state = LS_IDLE;
		substate = LSSUB_IDLE;
		call_info.clear();
		call_history->add_call_record(call_hist_record);
		call_hist_record.renew();
		phone->line_cleared(line_number);
		user_config = NULL;
		user_defined_ringtone.clear();
		ui->cb_line_state_changed();
	}
}

///////////
// Public
///////////

t_line::t_line(t_phone *_phone, unsigned short _line_number) {
	assert(_line_number < NUM_LINES);

	// NOTE: The rtp_port attribute can only be initialized when
	//       a user profile has been selected.

	phone = _phone;
	state = LS_IDLE;
	substate = LSSUB_IDLE;
	open_dialog = NULL;
	active_dialog = NULL;
	is_on_hold = false;
	is_muted = false;
	auto_answer = false;
	line_number = _line_number;
	id_invite_comp = 0;
	id_no_answer = 0;
	user_config = NULL;
	user_defined_ringtone.clear();
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

t_refer_state t_line::get_refer_state(void) const {
	if (active_dialog) return active_dialog->refer_state;
	return REFST_NULL;
}

void t_line::start_timer(t_line_timer timer, t_dialog_id did) {
	t_tmr_line	*t;
	t_dialog	*dialog = get_dialog(did);
	unsigned long	dur;

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
		t = new t_tmr_line(DUR_NO_ANSWER(user_config), timer, this, did);
		MEMMAN_NEW(t);
		id_no_answer = t->get_id();
		break;
	case LTMR_RE_INVITE_GUARD:
		assert(dialog);
		t = new t_tmr_line(DUR_RE_INVITE_GUARD, timer, this, did);
		MEMMAN_NEW(t);
		dialog->id_re_invite_guard = t->get_id();
		break;
	case LTMR_GLARE_RETRY:
		assert(dialog);
		if (dialog->is_call_id_owner()) {
			dur = DUR_GLARE_RETRY_OWN;
		} else {
			dur = DUR_GLARE_RETRY_NOT_OWN;
		}
		t = new t_tmr_line(dur, timer, this, did);
		MEMMAN_NEW(t);
		dialog->id_glare_retry = t->get_id();
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
	case LTMR_CANCEL_GUARD:
		assert(dialog);
		t = new t_tmr_line(DUR_CANCEL_GUARD, timer, this, did);
		MEMMAN_NEW(t);
		dialog->id_cancel_guard = t->get_id();
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
	case LTMR_GLARE_RETRY:
		assert(dialog);
		id = &dialog->id_glare_retry;
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
	case LTMR_CANCEL_GUARD:
		assert(dialog);
		id = &dialog->id_cancel_guard;
		
		// KLUDGE
		if (*id == 0) {
			// Cancel is always sent on the open dialog.
			// The timer is probably stopped from a pending dialog,
			// therefore the timer is stopped on the wrong dialog.
			// Check if the open dialog has a CANCEL guard timer.
			if (open_dialog) id = &open_dialog->id_cancel_guard;
		}
		break;
	default:
		assert(false);
	}

	if (*id != 0) evq_timekeeper->push_stop_timer(*id);
	*id = 0;
}

void t_line::invite(t_user *user, const t_url &to_uri, const string &to_display,
		const string &subject)
{
	invite(user, to_uri, to_display, subject, t_hdr_referred_by());
}

void t_line::invite(t_user *user, const t_url &to_uri, const string &to_display,
		const string &subject, const t_hdr_referred_by &hdr_referred_by)
{
	assert(user);
	
	// Ignore if line is not idle
	if (state != LS_IDLE) {
		return;
	}

	assert(!open_dialog);
	
	user_config = user;

	call_info.from_uri = create_user_uri();
	call_info.from_display = user_config->display;
	call_info.from_organization = user_config->organization;
	call_info.to_uri = to_uri;
	call_info.to_display = to_display;
	call_info.to_organization.clear();
	call_info.subject = subject;
	call_info.hdr_referred_by = hdr_referred_by;

	state = LS_BUSY;
	substate = LSSUB_OUTGOING_PROGRESS;
	ui->cb_line_state_changed();

	open_dialog = new t_dialog(this);
	MEMMAN_NEW(open_dialog);
	open_dialog->send_invite(to_uri, to_display, subject, hdr_referred_by);

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

void t_line::redirect(const list<t_display_url> &destinations, int code, string reason)
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
		ui->cb_stop_call_notification(line_number);
		active_dialog->send_bye();
		cleanup();
		return;
	}

	// Always send the CANCEL on the open dialog.
	// The pending dialogs will be cleared when the INVITE gets
	// terminated.
	// CANCEL is send on the open dialog as the CANCEL must have
	// the same tags as the INVITE.
	if (open_dialog) {
		substate = LSSUB_RELEASING;
		ui->cb_line_state_changed();
		ui->cb_stop_call_notification(line_number);
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

void t_line::send_dtmf(char digit, bool inband) {
	if (active_dialog && active_dialog->get_state() == DS_CONFIRMED) {
		active_dialog->send_dtmf(digit, inband);
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

bool t_line::hold(bool rtponly) {
	if (is_on_hold) return true;

	if (active_dialog && active_dialog->get_state() == DS_CONFIRMED) {
		active_dialog->hold(rtponly);
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

void t_line::refer(const t_url &uri, const string &display) {
	if (active_dialog && active_dialog->get_state() == DS_CONFIRMED) {
		active_dialog->send_refer(uri, display);
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
	
	assert(user_config);

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
	
	assert(user_config);

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
	t_dialog *d;

	assert(user_config);
	
	if (active_dialog) {
		// If an active dialog exists then non-2XX should
		// only be for this dialog.
		if (active_dialog->match_response(r, 0)) {
			bool response_processed = false;

			if (r->code == R_503_SERVICE_UNAVAILABLE) {
				// RFC 3263 4.3
				// Failover to next destination
				if (active_dialog->failover_request(r))
				{
					// Failover successul.
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

				if (r->code == R_503_SERVICE_UNAVAILABLE) {
					// INVITE failover
					if (open_dialog->failover_invite())
					{
						// Failover successul.
						// The response does not need to
						// be processed any further
						response_processed = true;
					}
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
		// If the response is a 503 then do not send the
		// response to the dialog as the request must be resent.
		// For an INVITE request, the transaction layer has already
		// sent ACK for a failure response.
		if (r->code != R_503_SERVICE_UNAVAILABLE && r->hdr_cseq.method != INVITE) {
			open_dialog->recvd_response(r, tuid, tid);
		}

		if (r->hdr_cseq.method == INVITE) {
			bool response_processed = false;

			if (r->code == R_503_SERVICE_UNAVAILABLE) {
				// INVITE failover
				if (open_dialog->failover_invite())
				{
					// Failover successul.
					// The response does not need to
					// be processed any further
					response_processed = true;
				}
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

void t_line::recvd_global_error(t_response *r, t_tuid tuid, t_tid tid) {
	recvd_redirect(r, tuid, tid);
}

void t_line::recvd_invite(t_user *user, t_request *r, t_tid tid, const string &ringtone) {
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
		
		assert(user);
		user_config = user;
		user_defined_ringtone = ringtone;
		
		call_info.from_uri = r->hdr_from.uri;
		call_info.from_display = r->hdr_from.display;
		if (r->hdr_organization.is_populated()) {
			call_info.from_organization = r->hdr_organization.name;
		} else {
			call_info.from_organization.clear();
		}
		call_info.to_uri = r->hdr_to.uri;
		call_info.to_display = r->hdr_to.display;
		call_info.to_organization.clear();
		call_info.subject = r->hdr_subject.subject;

		// Check for REFER support
		// If the Allow header is not present then assume REFER
		// is supported.
		if (!r->hdr_allow.is_populated() ||
		    r->hdr_allow.contains_method(REFER))
		{
			call_info.refer_supported = true;
		}

		active_dialog = new t_dialog(this);
		MEMMAN_NEW(active_dialog);
		active_dialog->recvd_request(r, 0, tid);
		state = LS_BUSY;
		substate = LSSUB_INCOMING_PROGRESS;
		ui->cb_line_state_changed();
		start_timer(LTMR_NO_ANSWER);
		cleanup();
		
		// Answer if auto answer mode is activated
		if (auto_answer) answer();
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

void t_line::recvd_subscribe(t_request *r, t_tid tid) {
	if (active_dialog && active_dialog->match_request(r)) {
		active_dialog->recvd_request(r, 0, tid);
	} else {
		// Should not get here as phone already checked that
		// the request matched with this line
		assert(false);
	}
	cleanup();
}

void t_line::recvd_notify(t_request *r, t_tid tid) {
	if (active_dialog && active_dialog->match_request(r)) {
		active_dialog->recvd_request(r, 0, tid);
	} else {
		// Should not get here as phone already checked that
		// the request matched with this line
		assert(false);
	}
	cleanup();
}

bool t_line::recvd_refer(t_request *r, t_tid tid) {
	bool retval = false;

	if (active_dialog && active_dialog->match_request(r)) {
		active_dialog->recvd_request(r, 0, tid);
		retval = active_dialog->refer_accepted;
	} else {
		// Should not get here as phone already checked that
		// the request matched with this line
		assert(false);
	}
	cleanup();
	return retval;
}

void t_line::recvd_stun_resp(StunMessage *r, t_tuid tuid, t_tid tid) {
	t_dialog *d;

	if (active_dialog && active_dialog->match_response(r, tuid)) {
		active_dialog->recvd_stun_resp(r, tuid, tid);
		cleanup();
		return;
	}
	
	if (open_dialog && open_dialog->match_response(r, tuid)) {
		open_dialog->recvd_stun_resp(r, tuid, tid);
		cleanup();
		return;
	}
	
	d = match_response(r, tuid, pending_dialogs);
	if (d) {
		d->recvd_stun_resp(r, tuid, tid);
		cleanup();
		return;
	}
	
	d = match_response(r, tuid, dying_dialogs);
	if (d) {
		d->recvd_stun_resp(r, tuid, tid);
		cleanup();
		return;
	}
}

void t_line::failure(t_failure failure, t_tid tid) {
	// TODO
}

void t_line::timeout(t_line_timer timer, t_dialog_id did) {
	// This method is called by the timekeeper thread, so lock
	// the phone (transaction layer) to prevent race conditions.

	phone->lock();

	t_dialog *dialog = get_dialog(did);
	list<t_display_url> cf_dest; // call forwarding destinations

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
		log_file->write_report("No answer timeout",
					"t_line::timeout");
		
		if (active_dialog) {
			assert(user_config);
			t_service srv = phone->get_service(user_config);
			if (srv.get_cf_active(CF_NOANSWER, cf_dest)) {
				log_file->write_report("Call redirection no answer",
					"t_line::timeout");
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
	case LTMR_GLARE_RETRY:
		// If there is no dialog then ignore the timeout
		if (dialog) {
			dialog->id_glare_retry = 0;
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
	case LTMR_CANCEL_GUARD:
		// If there is no dialog then ignore the timeout
		if (dialog) {
			dialog->id_cancel_guard = 0;
			dialog->timeout(timer);
		}
		break;
	default:
		assert(false);
	}

	cleanup();

	phone->unlock();
}

void t_line::timeout_sub(t_subscribe_timer timer, t_dialog_id did,
		const string &event_type, const string &event_id)
{
	// This method is called by the timekeeper thread, so lock
	// the phone (transaction layer) to prevent race conditions.

	phone->lock();

	t_dialog *dialog = get_dialog(did);
	if (dialog) dialog->timeout_sub(timer, event_type, event_id);
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

bool t_line::match(StunMessage *r, t_tuid tuid) {
	if (open_dialog && open_dialog->match_response(r, tuid)) {
		return true;
	}

	if (active_dialog && active_dialog->match_response(r, tuid)) {
		return true;
	}

	if (match_response(r, tuid, pending_dialogs)) {
		return true;
	}

	if (match_response(r, tuid, dying_dialogs)) {
		return true;
	}

	return false;
}

bool t_line::is_invite_retrans(t_request *r) {
	assert(r->method == INVITE);
	return (active_dialog && active_dialog->is_invite_retrans(r));
}

void t_line::process_invite_retrans(void) {
	if (active_dialog) active_dialog->process_invite_retrans();
}

string t_line::create_user_contact(void) const {
	assert(user_config);
	return user_config->create_user_contact();
}

string t_line::create_user_uri(void) const {
	assert(user_config);
	return user_config->create_user_uri();
}

t_response *t_line::create_options_response(t_request *r, bool in_dialog) const
{
	assert(user_config);
	return phone->create_options_response(user_config, r, in_dialog);
}

void t_line::send_response(t_response *r, t_tuid tuid, t_tid tid) {
	phone->send_response(r, tuid, tid);
}

void t_line::send_request(t_request *r, t_tuid tuid) {
	assert(user_config);
	phone->send_request(user_config, r, tuid);
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

bool t_line::get_auto_answer(void) const {
	return auto_answer;
}

void t_line::set_auto_answer(bool enable) {
	auto_answer = enable;
}

bool t_line::is_refer_succeeded(void) const {
	if (active_dialog) return active_dialog->refer_succeeded;
	return false;
}

bool t_line::seize(void) {
	// Only an idle line can be seized.
	if (substate != LSSUB_IDLE) return false;

	substate = LSSUB_SEIZED;
	ui->cb_line_state_changed();
	
	return true;
}

void t_line::unseize(void) {
	// Only a seized line can be unseized.
	if (substate != LSSUB_SEIZED) return;

	substate = LSSUB_IDLE;
	ui->cb_line_state_changed();
}

t_session *t_line::get_session(void) const {
	if (!active_dialog) return NULL;

	return active_dialog->get_session();
}

t_audio_session *t_line::get_audio_session(void) const {
	if (!active_dialog) return NULL;

	return active_dialog->get_audio_session();
}

void t_line::notify_refer_progress(t_response *r) {
	if (active_dialog) active_dialog->notify_refer_progress(r);
}

void t_line::failed_retrieve(void) {
	// Call retrieve failed, so line is still on-hold
	is_on_hold = true;
	ui->cb_line_state_changed();
}

void t_line::failed_hold(void) {
	// Call hold failed, so line is not on-hold
	is_on_hold = false;
	ui->cb_line_state_changed();
}

void t_line::retry_retrieve_succeeded(void) {
	// Retry of retrieve succeeded, so line is not on-hold anymore
	is_on_hold = false;
	ui->cb_line_state_changed();
}

t_call_info t_line::get_call_info(void) const {
	return call_info;
}

void t_line::ci_set_dtmf_supported(bool supported, bool inband) {
	call_info.dtmf_supported = supported;
	call_info.dtmf_inband = inband;
}

void t_line::ci_set_last_provisional_reason(const string &reason) {
	call_info.last_provisional_reason = reason;
}

void t_line::ci_set_send_codec(t_audio_codec codec) {
	call_info.send_codec = codec;
}

void t_line::ci_set_recv_codec(t_audio_codec codec) {
	call_info.recv_codec = codec;
}

void t_line::ci_set_refer_supported(bool supported) {
	call_info.refer_supported = supported;
}

void t_line::init_rtp_port(void) {
	rtp_port = sys_config->rtp_port + line_number * 2;
}

unsigned short t_line::get_rtp_port(void) const {
	return rtp_port;
}

t_user *t_line::get_user(void) const {
	return user_config;
}

string t_line::get_ringtone(void) const {
	if (!user_defined_ringtone.empty()) {
		// Ring tone returned by incoming call script
		return user_defined_ringtone;
	} else if (!user_config->ringtone_file.empty()) {
		// Ring tone from user profile
		return user_config->ringtone_file;
	} else if (!sys_config->ringtone_file.empty()) {
		// Ring tone from system settings
		return sys_config->ringtone_file;
	} else {
		// Twinkle default
		return FILE_RINGTONE;
	}	
}
