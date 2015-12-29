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

#ifndef _PHONE_H
#define _PHONE_H

#include <list>
#include <string>
#include "auth.h"
#include "call_history.h"
#include "dialog.h"
#include "phone_user.h"
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

// Number of seconds to wait till all lines are idle when terminating
// Twinkle
#define QUIT_IDLE_WAIT	5

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

class t_phone : public t_transaction_layer {
private:
	// Indicates if the phone is active, accepting calls.
	bool			is_active;

	// Phone users
	list<t_phone_user *>	phone_users;

	// Phone lines
	t_line			*lines[NUM_LINES];

	// Operations like invite, end_call work on the active line
	unsigned short		active_line;

	// 3-way conference data
	bool			is_3way;	// indicates an acitive 3-way
	t_line			*line1_3way;	// first line in 3-way conf
	t_line			*line2_3way;	// second line in 3-way conf

	// Actions
	void invite(t_phone_user *pu, const t_url &to_uri, const string &to_display,
		const string &subject);
	void answer(void);
	void redirect(const list<t_display_url> &destinations, int code, string reason = "");
	void reject(void);
	void end_call(void);
	void registration(t_phone_user *pu, t_register_type register_type,
					unsigned long expires = 0);

	// OPTIONS outside dialog
	void options(t_phone_user *pu, const t_url &to_uri, const string &to_display = "");

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
	void send_dtmf(char digit, bool inband);

	void set_active_line(unsigned short l);
	t_line *get_line(unsigned short lineno) const;

	// Handle responses for out-of-dialog requests
	void handle_response_out_of_dialog(t_response *r, t_tuid tuid);
	void handle_response_out_of_dialog(StunMessage *r, t_tuid tuid);
	
	// Find active phone user
	t_phone_user *find_phone_user(const string &profile_name);
	
	// Match an incoming message to a phone user
	t_phone_user *match_phone_user(t_response *r, t_tuid tuid);
	t_phone_user *match_phone_user(t_request *r);
	t_phone_user *match_phone_user(StunMessage *r, t_tuid tuid);

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
	t_phone();
	virtual ~t_phone();

	// Get busy/idle state of the phone
	// PS_IDLE - at least one line is idle
	// PS_BUSY - all lines are busy
	t_phone_state get_state(void) const;
	
	// Returns true if all lines are in the LSSUB_IDLE state
	bool all_lines_idle(void) const;

	// Actions to be called by the user interface.
	// These methods first lock the phone, then call the corresponding
	// private method and then unlock the phone.
	// The private methods should only be called by the phone, line,
	// and dialog objects to avoid deadlocks.
	void pub_invite(t_user *user,
		const t_url &to_uri, const string &to_display,
		const string &subject);
	void pub_answer(void);
	void pub_reject(void);
	void pub_redirect(const list<t_display_url> &destinations, int code, string reason = "");
	void pub_end_call(void);
	void pub_registration(t_user *user, t_register_type register_type,
						int unsigned long = 0);
	void pub_options(t_user *user, 
			const t_url &to_uri, const string &to_display = "");
	void pub_options(void);
	bool pub_hold(void);
	void pub_retrieve(void);
	void pub_refer(const t_url &uri, const string &display);
	void mute(bool enable);
	void pub_activate_line(unsigned short l);
	void pub_send_dtmf(char digit, bool inband);

	// Join 2 lines in a 3-way conference. Returns false if 3-way cannot
	// be setup
	bool join_3way(unsigned short lineno1, unsigned short lineno2);

	// Seize the line.
	// Returns false if seizure failed.
	bool pub_seize(void);

	// Unseize the line
	void pub_unseize(void);

	void timeout(t_phone_timer timer, unsigned short id_timer);

	unsigned short get_active_line(void) const;

	// Authorize the request based on the challenge in the response
	// Returns false if authorization fails.
	bool authorize(t_user *user, t_request *r, t_response *resp);
	
	// Remove cached credentials for a particular user/realm
	void remove_cached_credentials(t_user *user, const string &realm);

	bool get_is_registered(t_user *user);
	bool get_last_reg_failed(t_user *user);
	t_line_state get_line_state(unsigned short lineno) const;
	t_line_substate get_line_substate(unsigned short lineno) const;
	bool is_line_on_hold(unsigned short lineno) const;
	bool is_line_muted(unsigned short lineno) const;
	bool is_line_auto_answered(unsigned short lineno) const;
	t_refer_state get_line_refer_state(unsigned short lineno) const;
	t_user *get_line_user(unsigned short lineno);

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
	
	// Get the call history record for a line
	t_call_record get_call_hist(unsigned short lineno) const;
	
	// Get ring tone for a line
	string get_ringtone(unsigned short lineno) const;

	// Initialize the RTP port values for all lines.
	void init_rtp_ports(void);
	
	// Add a phone user
	// Returns false if there is already a phone user with the same name
	// and domain. In this case dup_user is a pointer to the user config
	// of that user.
	// NOTE: if there is already a user with exactly the same user config
	// then true is returned, but the user is not added again. The user
	// will be activated if it was inactive though.
	bool add_phone_user(const t_user &user_config, t_user **dup_user);
	
	// Deactivate/delete the phone user.
	void remove_phone_user(const t_user &user_config);

	// Get a list of user profiles of all phone users
	list<t_user *> ref_users(void);
	
	// Get the user profile of a user for which user->get_display_uri() ==
	// display_uri.
	t_user *ref_user_display_uri(const string &display_uri);
	
	// Get the user profile matching the profile name
	t_user *ref_user_profile(const string &profile_name);
	
	// Get service information for a phone user
	t_service get_service(t_user *user);
	t_service *ref_service(t_user *user);
	
	// Get IP address and port for SIP
	string get_ip_sip(t_user *user);
	unsigned short get_public_port_sip(t_user *user);
	
	// Indicates if STUN is used
	bool use_stun(t_user *user);
	
	// Indicates if a NAT keepalive mechanism is used
	bool use_nat_keepalive(t_user *user);
	
	// Disable STUN for a user
	void disable_stun(t_user *user);
	
	// Perform NAT discovery for all users having STUN enabled.
	// If NAT discovery indicates that STUN cannot be used for 1 or more
	// users, then false will be returned and msg_list contains a list
	// of messages to be shown to the user.
	bool stun_discover_nat(list<string> &msg_list);
	
	// Perform NAT discovery for a single user.
	bool stun_discover_nat(t_user *user, string &msg);
	
	// Create a response to an OPTIONS request
	// Argument 'in-dialog' indicates if the OPTIONS response is
	// sent within a dialog.
	t_response *create_options_response(t_user *user, t_request *r,
					bool in_dialog = false);
					
	// Timer operations
	void start_timer(t_phone_timer timer, t_phone_user *pu);
	void stop_timer(t_phone_timer timer, t_phone_user *pu);

	// Start a timer with the time set in the time-argument.
	void start_set_timer(t_phone_timer timer, long time, t_phone_user *pu);
	
	// Initialize the phone functions.
	// Register all active users with auto register
	void init(void);
	
	// Terminate the phone functions.
	// Release all calls, don't accept any new calls.
	// Deregister all active users.
	void terminate(void);
};

// Main function for the UAS part of the phone
void *phone_uas_main(void *arg);

// Entry function of thread catching signals to terminate
// the application in a graceful manner
void *phone_sigwait(void *arg);

#endif
