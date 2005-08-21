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

#ifndef _PHONE_H
#define _PHONE_H

#include <list>
#include <string>
#include "auth.h"
#include "dialog.h"
#include "protocol.h"
#include "service.h"
#include "transaction_layer.h"
#include "sockets/url.h"
#include "parser/request.h"
#include "parser/response.h"

// Number of phone lines
// One line is used by Twinkle internally to park the call towards a
// referrer while the refer is in progress.
#define NUM_LINES	3	// Total numbers of phone lines
#define NUM_USER_LINES	2	// #lines usable for the user

#define LINENO_REFERRER	2	// Internal lineno for referrer

using namespace std;

// Forward declarations
class t_dialog;
class t_client_request;
class t_line;
class t_call_info;

enum t_phone_state {
	PS_IDLE,
	PS_BUSY
};

enum t_line_state {
	LS_IDLE,
	LS_BUSY
};

enum t_line_substate {
	// Idle sub states
	LSSUB_IDLE,			// line is idle
	LSSUB_SEIZED,			// user has seized the line to call

	// Busy sub states
	LSSUB_INCOMING_PROGRESS,	// incoming call in progress
	LSSUB_OUTGOING_PROGRESS,	// outgoing call in progress
	LSSUB_ANSWERING,		// sent 200 OK, waiting for ACK
	LSSUB_ESTABLISHED,		// call established
	LSSUB_RELEASING			// call is being released (BYE sent)
};

enum t_register_type {
	REG_REGISTER,
	REG_QUERY,
	REG_DEREGISTER,
	REG_DEREGISTER_ALL
};

class t_phone : public t_transaction_layer {
private:
	// Phone lines
	t_line			*lines[NUM_LINES];

	// Operations like invite, end_call work on the active line
	unsigned short		active_line;

	// 3-way conference data
	bool			is_3way;	// indicates an acitive 3-way
	t_line			*line1_3way;	// first line in 3-way conf
	t_line			*line2_3way;	// second line in 3-way conf

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

	// Timers
	unsigned short		id_registration;
	unsigned short		id_nat_keepalive;

	// Authorizor
	t_auth			authorizor;
	
	// STUN data
	unsigned long		stun_public_ip_sip; // Public IP for SIP
	unsigned short		stun_public_port_sip; // Public port for SIP

	// Actions
	void invite(const t_url &to_uri, const string &to_display,
		const string &subject);
	void answer(void);
	void redirect(const list<t_url> &destinations, int code, string reason = "");
	void reject(void);
	void end_call(void);
	void registration(t_register_type register_type,
					unsigned long expires = 0);

	// OPTIONS outside dialog
	void options(const t_url &to_uri, const string &to_display = "");

	// OPTIONS inside dialog
	void options(void);

	bool hold(bool rtponly = false); // returns false is call cannot be put on hold
	void retrieve(void);

	// Transfer a call (send REFER to far-end)
	void refer(const t_url &uri, const string &display);

	// Make line l active. If the current line is busy, then that call
	// will be put on-hold. If line l has a call on-hold, then that
	// call will be retrieved.
	void activate_line(unsigned short l);

	// Send a DTMF digit
	void send_dtmf(char digit);

	void set_active_line(unsigned short l);
	t_line *get_line(unsigned short lineno) const;

	// Check if all required extensions are supported
	bool check_required_ext(t_request *r, list<string> &unsupported) const;

	// Timer operations
	void start_timer(t_phone_timer timer);
	void stop_timer(t_phone_timer timer);

	// Start a timer with the time set in the time-argument.
	void start_set_timer(t_phone_timer timer, long time);

	// Handle responses for out-of-dialog requests
	void handle_response_out_of_dialog(t_response *r, t_tuid tuid);
	void handle_response_out_of_dialog(StunMessage *r, t_tuid tuid);

	// Handle REGISTER repsonses. On return the re-register indicates
	// if an automatic re-registration needs to be done.
	void handle_response_register(t_response *r, bool &re_register);
	void handle_response_deregister(t_response *r);
	void handle_response_query_register(t_response *r);

	void handle_response_options(t_response *r);
	
	// Send a NAT keep alive packet
	void send_nat_keepalive(void);

protected:
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
	void recvd_subscribe(t_request *r, t_tid tid);
	void recvd_notify(t_request *r, t_tid tid);
	void recvd_refer(t_request *r, t_tid tid);

	void failure(t_failure failure, t_tid tid);
	
	void recvd_stun_resp(StunMessage *r, t_tuid tuid, t_tid tid);

public:
	// Supplementary services
	t_service	service;
	
	// STUN
	bool		use_stun; // Indicates if STUN must be used

	t_phone();
	virtual ~t_phone();

	t_phone_state get_state(void) const;

	// Actions to be called by the user interface.
	// These methods first lock the phone, then call the corresponding
	// private method and then unlock the phone.
	// The private methods should only be called by the phone, line,
	// and dialog objects to avoid deadlocks.
	void pub_invite(const t_url &to_uri, const string &to_display,
		const string &subject);
	void pub_answer(void);
	void pub_reject(void);
	void pub_redirect(const list<t_url> &destinations, int code, string reason = "");
	void pub_end_call(void);
	void pub_registration(t_register_type register_type,
						int unsigned long = 0);
	void pub_options(const t_url &to_uri, const string &to_display = "");
	void pub_options(void);
	bool pub_hold(void);
	void pub_retrieve(void);
	void pub_refer(const t_url &uri, const string &display);
	void mute(bool enable);
	void pub_activate_line(unsigned short l);
	void pub_send_dtmf(char digit);

	// Join 2 lines in a 3-way conference. Returns false if 3-way cannot
	// be setup
	bool join_3way(unsigned short lineno1, unsigned short lineno2);

	// Seize the line.
	void pub_seize(void);

	// Unseize the line
	void pub_unseize(void);

	// Create user uri and contact uri
	string create_user_contact(void) const;
	string create_user_uri(void) const;

	// Create request. Headers that are the same for each request
	// are already populated.
	t_request *create_request(t_method m) const;

	// Create a response to an OPTIONS request
	// Argument 'in-dialog' indicates if the OPTIONS response is
	// sent within a dialog.
	t_response *create_options_response(t_request *r,
					bool in_dialog = false) const;

	void timeout(t_phone_timer timer);

	unsigned short get_active_line(void) const;

	// Authorize the request based on the challenge in the response
	// Returns false if authorization fails.
	bool authorize(t_request *r, t_response *resp);

	bool get_is_registered(void) const;
	bool get_last_reg_failed(void) const;
	t_line_state get_line_state(unsigned short lineno) const;
	t_line_substate get_line_substate(unsigned short lineno) const;
	bool is_line_on_hold(unsigned short lineno) const;
	bool is_line_muted(unsigned short lineno) const;
	t_refer_state get_line_refer_state(unsigned short lineno) const;

	// Return if a line is part of a 3-way conference
	bool part_of_3way(unsigned short lineno);

	// Get the peer line in a 3-way conference
	t_line *get_3way_peer_line(unsigned short lineno);

	// This method is called by the line object when the line becomes idle.
	// The phone object can then cleanup any line related data, eg. 3-way data
	void line_cleared(unsigned short lineno);

	// Notify progress of a reference. r is the response to the INVITE
	// caused by a REFER. referee_lineno is the line number of the line
	// that is setting up there reference call.
	void notify_refer_progress(t_response *r, unsigned short referee_lineno);

	// Get call info record for a line.
	t_call_info get_call_info(unsigned short lineno) const;

	// Initialize the RTP port values for all lines.
	void init_rtp_ports(void);
	
	// Get IP address and port for SIP
	string get_ip_sip(void) const;
	unsigned short get_public_port_sip(void) const;
};

// Main function for the UAS part of the phone
void *phone_uas_main(void *arg);

#endif
