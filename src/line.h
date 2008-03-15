/*
    Copyright (C) 2005-2008  Michel de Boer <michel@twinklephone.com>

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
#include "call_history.h"
#include "dialog.h"
#include "id_object.h"
#include "phone.h"
#include "protocol.h"
#include "user.h"
#include "audio/audio_codecs.h"
#include "sockets/url.h"
#include "parser/request.h"
#include "parser/response.h"
#include "stun/stun.h"

using namespace std;

// Forward declarations
class t_dialog;
class t_phone;

// Info about the current call.
// This info can be used by the user interface to render the
// call state to the user.
class t_call_info {
public:
	t_url			from_uri;
	string			from_display;
	
	// Override of display for presentation to user, e.g. name from
	// address book lookup.
	string			from_display_override;
	
	string			from_organization;
	t_url			to_uri;
	string			to_display;
	string			to_organization;
	string			subject;
	bool			dtmf_supported;
	bool			dtmf_inband; // DTMF must be sent inband
	bool			dtmf_info; // DTMF must be sent via SIP INFO
	t_hdr_referred_by	hdr_referred_by;

	// The reason phrase of the last received provisional response
	// on an outgoing INVITE.
	string		last_provisional_reason;

	t_audio_codec	send_codec;
	t_audio_codec	recv_codec;
	bool		refer_supported;
	
	t_call_info();
	void clear(void);
	
	// Get the from display name to show to the user.
	string get_from_display_presentation(void) const;
};

class t_line : public t_id_object {
	friend class t_phone;
	
private:
	t_line_state		state;
	t_line_substate		substate;
	bool			is_on_hold;
	bool			is_muted;
	bool			hide_user; // Anonymous call
	
	// Indicates if a call is a consultation for a transfer
	bool			is_transfer_consult;
	
	// The line about which this consultation handles.
	unsigned short		consult_transfer_from_line;
	
	// Indicates if this call is to be transferred after consultation.
	bool			to_be_transferred;
	
	// After consultation this line should be transferred to the
	// transfer_to_line.
	unsigned short		consult_transfer_to_line;
	
	// Indicates if media encryption should be negotiated.
	bool			try_to_encrypt;
	
	// Indicates if call must be auto answered
	bool			auto_answer;

	// Line number (starting from 0)
	// The number of a line may change when it moves from the user lines
	// to the pool of dying lines. So a line number cannot be used as
	// unique line identification over longer times.
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
	t_object_id		id_invite_comp;
	t_object_id		id_no_answer;

	// Call info
	t_call_info		call_info;

	/** RTP port to be used for this line. */
	unsigned short		rtp_port;
	
	// User profile of user using the line
	// This is a pointer to the user_config owned by a phone user.
	// So this pointer should never be deleted.
	t_user			*user_config;
	
	// The incoming call script can return a specific ring tone
	// to be played for an incoming call. This ring tone is
	// stored here. If there is no specific ring tone to be played
	// then this attribute is empty
	string			user_defined_ringtone;
	
	// Indicates if the line must go to seized state when it
	// becomes idle.
	bool			keep_seized;

	// Find a dialog from the list that matches the response.
	t_dialog *match_response(t_response *r,
				const list<t_dialog *> &l) const;
	t_dialog *match_response(StunMessage *r, t_tuid tuid,
				const list<t_dialog *> &l) const;
	t_dialog *match_call_id_tags(const string &call_id,
		const string &to_tag, const string &from_tag,
		const list<t_dialog *> &l) const;

	// Get the dialog with id == did. If dialog does not exist
	// then NULL is returned.
	t_dialog *get_dialog(t_object_id did) const;

	// Clean up terminated dialogs
	void cleanup(void);

	// Cleanup all open and pending dialogs
	void cleanup_open_pending(void);
	
	// Forcefully cleanup all dialogs
	void cleanup_forced(void);
	
	// Cleanup state for a transfer with consultation.
	// If the call on this line is a consult, then the consult state of 
	// the line that is to be transferred will be cleaned too.
	// If the call on this line is to be transferred, then the consult
	// state of the consultation line will be cleared too.
	void cleanup_transfer_consult_state(void);

public:
	// Call history record
	t_call_record		call_hist_record;
	
	t_line(t_phone *_phone, unsigned short _line_number);
	~t_line();

	t_line_state get_state(void) const;
	t_line_substate get_substate(void) const;
	t_refer_state get_refer_state(void) const;

	// Timer operations
	void start_timer(t_line_timer timer, t_object_id did = 0);
	void stop_timer(t_line_timer timer, t_object_id did = 0);

	// Actions
	void invite(t_user *user, const t_url &to_uri, const string &to_display,
		const string &subject, const t_hdr_referred_by &hdr_referred_by,
		const t_hdr_replaces &hdr_replaces, const t_hdr_require &hdr_require, 
		bool anonymous);
	void invite(t_user *user, const t_url &to_uri, const string &to_display,
		const string &subject, bool anonymous);
	void answer(void);
	void reject(void);
	void redirect(const list<t_display_url> &destinations, int code, string reason = "");
	void end_call(void);
	void send_dtmf(char digit, bool inband, bool info);

	// OPTIONS inside dialog
	void options(void);

	bool hold(bool rtponly = false); // returns false if call cannot be put on hold
	void retrieve(void);
	
	// Kill all RTP stream associated with this line
	void kill_rtp(void);
	
	void refer(const t_url &uri, const string &display);

	// Mute/unmute a call
	// - enable = true -> mute
	// - enable = false -> unmute
	void mute(bool enable);

	/** @name Handle incoming responses */
	//@{
	void recvd_provisional(t_response *r, t_tuid tuid, t_tid tid);
	void recvd_success(t_response *r, t_tuid tuid, t_tid tid);
	void recvd_redirect(t_response *r, t_tuid tuid, t_tid tid);
	void recvd_client_error(t_response *r, t_tuid tuid, t_tid tid);
	void recvd_server_error(t_response *r, t_tuid tuid, t_tid tid);
	void recvd_global_error(t_response *r, t_tuid tuid, t_tid tid);
	//@}

	/** @name Handle incoming requests */
	//@{
	void recvd_invite(t_user *user, t_request *r, t_tid tid, const string &ringtone);
	void recvd_ack(t_request *r, t_tid tid);
	void recvd_cancel(t_request *r, t_tid cancel_tid, t_tid target_tid);
	void recvd_bye(t_request *r, t_tid tid);
	void recvd_options(t_request *r, t_tid tid);
	void recvd_register(t_request *r, t_tid tid);
	void recvd_prack(t_request *r, t_tid tid);
	void recvd_subscribe(t_request *r, t_tid tid);
	void recvd_notify(t_request *r, t_tid tid);
	void recvd_info(t_request *r, t_tid tid);
	void recvd_message(t_request *r, t_tid tid);

	/**
	 * Process REFER request.
	 * @return true, if refer has been accepted sofar. The refer may still
	 * be rejected by the user.
	 * @return false, if the refer has been rejected.
	 */
	bool recvd_refer(t_request *r, t_tid tid);
	//@}
	
	// Handle the response from the user on the question for refer
	// permission. This response is received on the dialog that received
	// the REFER before.
	// The request (r) is the REFER request that was received.
	void recvd_refer_permission(bool permission, t_request *r);
	
	void recvd_stun_resp(StunMessage *r, t_tuid tuid, t_tid tid);

	void failure(t_failure failure, t_tid tid);

	void timeout(t_line_timer timer, t_object_id did);
	void timeout_sub(t_subscribe_timer timer, t_object_id did,
		const string &event_type, const string &event_id);

	// Return true if the response or request matches a dialog that
	// is owned by this line
	bool match(t_response *r, t_tuid tuid) const;
	bool match(t_request *r) const;
	bool match_cancel(t_request *r, t_tid target_tid) const;
	bool match(StunMessage *r, t_tuid tuid) const;
	
	// RFC 3891
	// Match for info from Replaces header
	// Match call id, to-tag and from tag like an incoming request.
	// Return true if a match is found with an associated dialog.
	// When a match is found, early_matched indicates if the match
	// was on an early dialog.
	bool match_replaces(const string &call_id, const string &to_tag, 
		const string &from_tag, bool &early_matched) const;

	// Check if an incoming INVITE is a retransmission of an INVITE
	// that is already being processed by this line
	bool is_invite_retrans(t_request *r);

	// Process a retransmission of an incoming INVITE
	void process_invite_retrans(void);

	// Create user uri and contact uri
	string create_user_contact(const string &auto_ip) const;
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
	bool get_hide_user(void) const;
	
	// If this is a transfer consult, then true will be returned and
	// lineno will be set to the line that must be transferred.
	bool get_is_transfer_consult(unsigned short &lineno) const;
	
	// When setting the transfer consult indication to true, the
	// line that must be transferred must be passed.
	void set_is_transfer_consult(bool enable, unsigned short lineno);
	
	// If this line is to be transferred after consultation, then
	// true will be returned and lineno will be set to the line
	// where this line should be transferred to.
	bool get_to_be_transferred(unsigned short &lineno) const;
	
	// When setting the to be transferred indication to true, the
	// line to which must be transferred must be passed.
	void set_to_be_transferred(bool enable, unsigned short lineno);
	
	bool get_is_encrypted(void) const;
	bool get_try_to_encrypt(void) const;
	bool get_auto_answer(void) const;
	void set_auto_answer(bool enable);
	bool is_refer_succeeded(void) const;
	bool has_media(void) const;
	
	// Return the remote (target) uri/display of the active dialog.
	// If there is no active dialog, then an empty url/display will
	// be returned.
	t_url get_remote_target_uri(void) const;
	string get_remote_target_display(void) const;
	t_url get_remote_uri(void) const;
	string get_remote_display(void) const;
	
	// Get call-id and tags of the active dialog
	// If there is no active dialog, then empty strings are returned.
	string get_call_id(void) const;
	string get_local_tag(void) const;
	string get_remote_tag(void) const;
	
	// Returns true if the remote party of the active dialog supports
	// the extension.
	// If there is no active dialog, then false is returned.
	bool remote_extension_supported(const string &extension) const;

	// Seize the line. User wants to make an outgoing call, so
	// the line must be marked as busy, such that an incoming call
	// cannot take this line.
	// Returns false if seizure failed
	bool seize(void);

	// Unseize the line
	void unseize(void);

	// Return the (audio) session belonging to this line.
	// Returns NULL if there is no (audio) session
	t_session *get_session(void) const;
	t_audio_session *get_audio_session(void) const;

	void notify_refer_progress(t_response *r);

	// Called by dialog if retrieve/hold actions failed.
	void failed_retrieve(void);
	void failed_hold(void);

	// Called by dialog if retry of a retrieve after a glare (491 response)
	// succeeded.
	void retry_retrieve_succeeded(void);

	// Get the call info record
	t_call_info get_call_info(void) const;
	void ci_set_dtmf_supported(bool supported, bool inband = false, bool info = false);
	void ci_set_last_provisional_reason(const string &reason);
	void ci_set_send_codec(t_audio_codec codec);
	void ci_set_recv_codec(t_audio_codec codec);
	void ci_set_refer_supported(bool supported);

	// Initialize the RTP port for this line based on the settings
	// in the user profile.
	void init_rtp_port(void);

	/** Get the RTP port to be used for a call on this line. */
	unsigned short get_rtp_port(void) const;
	
	// Get the user using the phone.
	// Returns a pointer to the user object owned by the line.
	// NOT a copy.
	t_user *get_user(void) const;
	
	// Get the ring tone to be played for an incoming call
	string get_ringtone(void) const;
	
	// ZRTP actions
	void confirm_zrtp_sas(void);
	void reset_zrtp_sas_confirmation(void);
	void enable_zrtp(void);
	void zrtp_request_go_clear(void);
	void zrtp_go_clear_ok(void);
	
	// Force a line to the idle state (during termination of Twinkle)
	void force_idle(void);
	
	// Indicate if the line must be seized after releasing
	void set_keep_seized(bool seize);
	bool get_keep_seized(void) const;
	
	/**
	 * Get a dialog that has an active session (RTP stream).
	 * @return The dialog that has an active session.
	 * @return NULL, if there is no dialog with an active session.
	 * @note There can be at most 1 dialog with an active session.
	 */
	t_dialog *get_dialog_with_active_session(void) const;
};

#endif
