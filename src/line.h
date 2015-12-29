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

#ifndef _LINE_H
#define _LINE_H

#include <list>
#include <string>
#include "dialog.h"
#include "phone.h"
#include "sockets/url.h"
#include "parser/request.h"
#include "parser/response.h"

using namespace std;

// Forward declarations
class t_dialog;
class t_phone;

class t_line {
	friend class t_phone;
	
private:
	t_line_state		state;
	t_line_substate		substate;
	bool			is_on_hold;
	bool			is_muted;

	// Line number (starting from 0)
	unsigned short		line_number;

	// The phone that owns this line
	t_phone			*phone;

	// Dialog for which no response with a to-tag has been received.
	// Formally this is not a dialog yet.
	t_dialog		*open_dialog;

	// Dialogs for which a response (1XX/2XX) with a to-tag has
	// been received.
	list<t_dialog *>	pending_dialogs;

	// Outgoing call: The first dialog for which a 2XX has been received.
	// Incoming call: Dialog created by an incoming INVITE
	t_dialog		*active_dialog;

	// Currently not used.
	list<t_dialog *>	dying_dialogs;

	// Timers
	unsigned short		id_invite_comp;
	unsigned short		id_no_answer;

	// Find a dialog from the list that matches the response.
	t_dialog *match_response(t_response *r,
				const list<t_dialog *> &l) const;

	// Get the dialog with id == did. If dialog does not exist
	// then NULL is returned.
	t_dialog *get_dialog(t_dialog_id did) const;

	// Clean up terminated dialogs
	void cleanup(void);

	// Cleanup all open and pending dialogs
	void cleanup_open_pending(void);

public:
	t_line(t_phone *_phone, unsigned short _line_number);
	~t_line();

	t_line_state get_state(void) const;
	t_line_substate get_substate(void) const;

	// Timer operations
	void start_timer(t_line_timer timer, t_dialog_id did = 0);
	void stop_timer(t_line_timer timer, t_dialog_id did = 0);

	// Actions
	void invite(const t_url &to_uri, const string &to_display,
		const string &subject);
	void answer(void);
	void reject(void);
	void redirect(const list<t_url> &destinations, int code, string reason = "");
	void end_call(void);
	void send_dtmf(char digit);

	// OPTIONS inside dialog
	void options(void);

	bool hold(void); // returns false if call cannot be put on hold
	void retrieve(void);

	// Mute/unmute a call
	// - enable = true -> mute
	// - enable = false -> unmute
	void mute(bool enable);

	// Events
	void recvd_provisional(t_response *r, t_tuid tuid, t_tid tid);
	void recvd_success(t_response *r, t_tuid tuid, t_tid tid);
	void recvd_redirect(t_response *r, t_tuid tuid, t_tid tid);
	void recvd_client_error(t_response *r, t_tuid tuid, t_tid tid);
	void recvd_server_error(t_response *r, t_tuid tuid, t_tid tid);
	void recvd_global_error(t_response *r, t_tuid tuid, t_tid tid);

	void recvd_invite(t_request *r, t_tid tid);
	void recvd_ack(t_request *r, t_tid tid);
	void recvd_cancel(t_request *r, t_tid cancel_tid, t_tid target_tid);
	void recvd_bye(t_request *r, t_tid tid);
	void recvd_options(t_request *r, t_tid tid);
	void recvd_register(t_request *r, t_tid tid);
	void recvd_prack(t_request *r, t_tid tid);

	void failure(t_failure failure, t_tid tid);

	void timeout(t_line_timer timer, t_dialog_id did);

	// Return true if the reponse or request matches a dialog that
	// is owned by this line
	bool match(t_response *r, t_tuid tuid);
	bool match(t_request *r);
	bool match_cancel(t_request *r, t_tid target_tid);

	// Create user uri and contact uri
	string create_user_contact(void) const;
	string create_user_uri(void) const;

	// Create a response to an OPTIONS request
	// Argument 'in-dialog' indicates if the OPTIONS response is
	// sent within a dialog.
	t_response *create_options_response(t_request *r,
					bool in_dialog = false) const;

	// Send a response/request
	void send_response(t_response *r, t_tuid tuid, t_tid tid);
	void send_request(t_request *r, t_tuid tuid);

	t_phone *get_phone(void) const;
	unsigned short get_line_number(void) const;
	bool get_is_on_hold(void) const;
	bool get_is_muted(void) const;

	// Seize the line. User wants to make an outgoing call, so
	// the line must be marked as busy, such that an incoming call
	// cannot take this line.
	void seize(void);

	// Unseize the line
	void unseize(void);

	// Return the audio session belonging to this line.
	// Returns NULL if there is no audio session
	t_audio_session *get_audio_session(void) const;
};

#endif
