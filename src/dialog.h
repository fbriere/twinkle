/*
    Copyright (C) 2005-2007  Michel de Boer <michel@twinklephone.com>

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

#ifndef _DIALOG_H
#define _DIALOG_H

#include <string>
#include <list>
#include <set>
#include <queue>
#include "abstract_dialog.h"
#include "client_request.h"
#include "phone.h"
#include "transaction_layer.h"
#include "protocol.h"
#include "redirect.h"
#include "session.h"
#include "user.h"
#include "sockets/url.h"
#include "threads/mutex.h"
#include "parser/request.h"
#include "sdp/sdp.h"
#include "stun/stun.h"

using namespace std;

// Forward declarations
class t_phone;
class t_line;
class t_session;
class t_sub_refer;

enum t_dialog_type {
	DT_INVITE,
	DT_SUBSCRIPTION
};

enum t_dialog_state {
	DS_NULL,

	// UAC states
	DS_W4INVITE_RESP,	// INVITE sent, waiting for response
	DS_W4INVITE_RESP2,	// Provisional response received
	DS_EARLY,		// Provisional response with to-tag received
	DS_W4BYE_RESP,		// BYE sent, waiting for resp

	// UAS states
	DS_W4ACK,		// Waiting for ACK on INVITE
	DS_W4ANSWER,		// INVITE received, waiting for user to
				// answer

	// UAS and UAC states
	DS_CONFIRMED,		// Success received/sent
	DS_W4ACK_RE_INVITE,	// Waiting for ACK on re-INVITE
	DS_W4RE_INVITE_RESP,	// re-INVITE sent, waiting for response
	DS_W4RE_INVITE_RESP2,	// re-INVITE sent, provisional response recvd
	DS_TERMINATED,		// Dialog terminated

	// Subscription states
	DS_NULL_SUB,		// Null state for subscription dialog
	DS_W4SUBSCRIBE_RESP,	// SUBSCRIBE sent, waiting for response
	DS_CONFIRMED_SUB,	// Confirmed subscription dialog
};

enum t_reinvite_purpose {
	REINVITE_HOLD,		// Re-invite for call hold
	REINVITE_RETRIEVE,	// Re-invite for call retrieve
};

class t_dialog : public t_abstract_dialog {
	friend class t_phone;
	
protected:
	t_line			*line;
	t_dialog_state		state;
	t_dialog_type		dialog_type;

	// Session information
	t_session	*session;

	// New session information being established during re-invite.
	// When the re-INVITE transaction finishes successfully, then
	// this session information will override the general session
	// information.
	t_session	*session_re_invite;

	// The purpose of an outgoing re-INVITE request
	t_reinvite_purpose	reinvite_purpose;

	// Indicates if the last call hold action failed.
	bool			hold_failed;

	// Pending request
	t_client_request	*req_out;	  // outgoing non-invite req
	t_client_request	*req_out_invite;  // outgoing INVITE
	t_client_request	*req_in_invite;   // incoming INVITE
	t_client_request	*req_cancel;      // outgoing CANCEL
	t_client_request	*req_refer;	  // outgoing REFER
	t_client_request	*req_info;	  // outgoing INFO

	// Last outgoing PRACK. While a PRACK is still pending a new 1xx
	// response might come in. A PRACK will be sent for this 1xx without
	// waiting for the response for the previous PRACK.
	t_client_request	*req_prack;
	
	// Pending STUN request
	t_client_request	*req_stun;
	
	// Incoming request queue. A request may come in when it cannot be
	// served yet. Such a request is stored in the queue to be served
	// later.
	list<t_client_request *>	inc_req_queue;
	
	// Indication if request must be cancelled
	bool request_cancelled;
	
	// Indication that the dialog must be terminated after a 2XX
	// on an INVITE is received (e.g. when 2XX glares with CANCEL)
	bool end_after_2xx_invite;

	// Indication that the dialog must be terminated after ACK.
	bool end_after_ack;

	// Indication that the user wants to answer the call, but the
	// sending the answer must be delay as we are still waiting for
	// a PRACK to acknowledge a 1xx containing SDP from the
	// far end (RFC 3262 3)
	bool answer_after_prack;
	
	// Indication if 180 ringing has already been received
	bool ringing_received;

	// Cached success response to INVITE needed for retransmission
	t_response		*resp_invite;

	// Cached provisional response to INVITE needed for retransmission
	// when provisional responses are sent reliable (100rel)
	t_response		*resp_1xx_invite;

	// Cached ack needed for retransmission
	t_request		*ack;

	// Subscription created by REFER (RFC 3515)
	t_sub_refer		*sub_refer;
	
	// Queue of DTMF digits to be sent via INFO requests
	queue<char>		dtmf_queue;

	// Process responses
	void state_w4invite_resp(t_response *r, t_tuid tuid, t_tid tid);
	void state_early(t_response *r, t_tuid tuid, t_tid tid);
	void state_w4bye_resp(t_response *r, t_tuid tuid, t_tid tid);
	void state_confirmed_resp(t_response *r, t_tuid tuid, t_tid tid);
	void state_w4re_invite_resp(t_response *r, t_tuid tuid, t_tid tid);

	// Process requests
	void state_null(t_request *r, t_tuid tuid, t_tid tid);
	void state_w4answer(t_request *r, t_tuid tuid, t_tid tid);
	void state_w4ack(t_request *r, t_tuid tuid, t_tid tid);
	void state_w4ack_re_invite(t_request *r, t_tuid tuid, t_tid tid);
	void state_w4re_invite_resp(t_request *r, t_tuid tuid, t_tid tid);
	void state_w4bye_resp(t_request *r, t_tuid tuid, t_tid tid);
	void state_confirmed(t_request *r, t_tuid tuid, t_tid tid);
	void state_confirmed_sub(t_request *r, t_tuid tuid, t_tid tid);
	void state_conf_retr_stun(t_request *r, t_tuid tuid, t_tid tid);
	
	// Process a re-INVITE request in the confirmed state
	void process_re_invite(t_request *r, t_tuid tuid, t_tid tid);
	void process_refer(t_request *r, t_tuid tuid, t_tid tid);
	void process_subscribe(t_request *r, t_tuid tuid, t_tid tid);
	void process_notify(t_request *r, t_tuid tuid, t_tid tid);
	void process_info(t_request *r, t_tuid tuid, t_tid tid);

	// Process timeouts
	void state_w4invite_resp(t_line_timer timer);
	void state_early(t_line_timer timer);
	void state_w4ack(t_line_timer timer);
	void state_w4ack_re_invite(t_line_timer timer);
	void state_w4re_invite_resp(t_line_timer timer);
	void state_w4answer(t_line_timer timer);
	void state_confirmed(t_line_timer timer);

	// Make the re-INVITE session the current session
	void activate_new_session(void);

	// Process SDP answer in 1xx and 2xx responses if present.
	// Apply ringing tone for a 180 response.
	// Determine if call should be canceled due to unsupported
	// or missing SDP.
	// The re_invite parameter indicates if this is a response to a
	// re-INVITE.
	void process_1xx_2xx_invite_resp(t_response *r);

	// Acknowledge a reveived 2xx response on an INVITE
	void ack_2xx_invite(t_response *r);

	// Send PRACK if the response requires it.
	void send_prack_if_required(t_response *r);

	// Returns true if a reliable provisional response must be
	// discarded because it is a retransmission or received out
	// of order.
	// Initializes the remote response nr if the response is the
	// first response.
	bool must_discard_100rel(t_response *r);

	// Respond to an incoming PRACK.
	// Returns true if a success response was given.
	// Returns false if an error response was given.
	bool respond_prack(t_request *r, t_tuid tuid, t_tid tid);

	// Send a request
	virtual void send_request(t_request *r, t_tuid tuid);
public:
	// Timer durations and timer id's
	unsigned long		dur_ack_timeout;
	t_object_id		id_ack_timeout;
	t_object_id		id_ack_guard;
	t_object_id		id_re_invite_guard;
	t_object_id		id_glare_retry;
	t_object_id		id_cancel_guard;

	// RFC 3262
	// 100rel timers
	unsigned long		dur_100rel_timeout;
	t_object_id		id_100rel_timeout;
	t_object_id		id_100rel_guard;

	// Indicates if last incoming REFER was accepted.
	bool			refer_accepted;
	
	// Indicates if the call transfer triggered by the last outgoing
	// REFER succeeded.
	bool			refer_succeeded;
	
	// Indicates if the last outgoing REFER request failed.
	bool			out_refer_req_failed;

	// Indicates if this dialog is setup because the user told to do
	// so by a REFER.
	bool			is_referred_call;

	// State of an outgoing REFER
	t_refer_state		refer_state;

	t_dialog(t_line *_line, t_dialog_type _dialog_type = DT_INVITE);
	virtual ~t_dialog();

	// Create a request using the stored state information
	virtual t_request *create_request(t_method m);

	virtual t_dialog *copy(void);

	// Send requests
	void send_invite(const t_url &to_uri, const string &to_display,
		const string &subject, const t_hdr_referred_by &hdr_referred_by,
		const t_hdr_replaces &hdr_replaces, 
		const t_hdr_require &hdr_require, bool anonymous);

	// Resend the INVITE with an authorization header containing credentials
	// for the challenge in the response. The response must be a 401 or 407.
	// Returns false if credentials could not be determined.
	bool resend_invite_auth(t_response *resp);

	// Resend the INVITE because the far-end did not support all required
	// extensions. Extensions that could not be supported will not be
	// required this time.
	// Returns false if far-end did not indicate which extensions are
	// unsupported. Or if a required extension could not be disabled.
	bool resend_invite_unsupported(t_response *resp);

	// Redirect INVITE to the next destination
	// Returns false if there is no next destination.
	bool redirect_invite(t_response *resp);
	
	// Failover INVITE to the next destination from DNS lookup.
	// Returns false if there is no next destination.
	bool failover_invite(void);

	void send_bye(void);
	void send_options(void);

	// If an early dialog exists, then the CANCEL can be sent
	// right away as a response has been received for the INVITE.
	void send_cancel(bool early_dialog_exists);
	
	// Indicate that the dialog must be ended if a 2XX is received
	// on an INVITE
	void set_end_after_2xx_invite(bool on);

	// Send re-INVITE.
	// Precondition: session_re_invite attribute contains the session
	//               information for the re-INVITE
	void send_re_invite(void);

	// Resend mid-dialog request with an authorization header containing
	// credentials for the challenge in the response. The response
	// must be a 401 or 407.
	// Returns false if credentials could not be determined.
	virtual bool resend_request_auth(t_response *resp);

	// Redirect mid-dialog request to the next destination
	// Returns false if there is no next destination.
	virtual bool redirect_request(t_response *resp);
	
	// Failover request to the next destination from DNS lookup.
	// Returns false if there is no next destination.
	virtual bool failover_request(t_response *resp);

	// Call hold/retrieve (send re-INVITE)
	// rtponly indicates if only the RTP streams should be stopped and
	// the soundcard freed without any SIP signaling.
	void hold(bool rtponly = false);
	void retrieve(void);
	
	// Kill all RTP stream associated with this dialog
	void kill_rtp(void);

	// Refer a call (send REFER)
	void send_refer(const t_url &uri, const string &display);

	// Send DTMF digit
	void send_dtmf(char digit, bool inband, bool info);
	
	// Create a binding for the media port via STUN.
	// Returns false if binding cannot be created.
	bool stun_bind_media(void);

	// Handle received events
	void recvd_response(t_response *r, t_tuid tuid, t_tid tid);
	void recvd_request(t_request *r, t_tuid tuid, t_tid tid);
	void recvd_cancel(t_request *r, t_tid cancel_tid, t_tid target_tid);
	void recvd_stun_resp(StunMessage *r, t_tuid tuid, t_tid tid);
	
	// Handle the response from the user on the question for refer
	// permission. This response is received on the dialog that received
	// the REFER before.
	// The request (r) is the REFER request that was received.
	void recvd_refer_permission(bool permission, t_request *r);

	// Answer a call (send 200 OK)
	void answer(void);

	// Reject a call with error = code (>=400)
	// A specific reason may be give to the error code. If no
	// reason is specified the default reason is used.
	void reject(int code, string reason = "");

	// Redirect a call with error = code (3XX)
	// A specific reason may be give to the error code. If no
	// reason is specified the default reason is used.
	// destinations is the list of redirect destinations in order of
	// preference.
	void redirect(const list<t_display_url> &destinations, int code, string reason = "");

	// Match response with dialog
	virtual bool match_response(t_response *r, t_tuid tuid);
	bool match_response(StunMessage *r, t_tuid tuid);

	// Match request with dialog
	bool match_cancel(t_request *r, t_tid target_tid);

	// Check if an incoming INVITE is a retransmission
	bool is_invite_retrans(t_request *r);

	// Process a retransmission of an incoming INVITE
	void process_invite_retrans(void);

	t_dialog_state get_state(void) const;

	// Process dialog timer timeout
	void timeout(t_line_timer timer);

	// Process subcribe timer timeout
	void timeout_sub(t_subscribe_timer timer, const string &event_type,
		const string &event_id);

	// Get the phone that belongs to this dialog
	t_phone *get_phone(void) const;

	// Get the line that belongs to this dialog
	t_line *get_line(void) const;

	// Return the (audio) session belonging to this dialog.
	// Returns NULL if there is no (audio) session
	t_session * get_session(void) const;
	t_audio_session *get_audio_session(void) const;

	// Notify the dialog of the progress of a reference
	void notify_refer_progress(t_response *r);
	
	// Returns is a dialog will be released.
	bool will_release(void) const;
};

#endif
