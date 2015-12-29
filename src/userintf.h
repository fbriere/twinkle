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

#ifndef _USERINTF_H
#define _USERINTF_H

#include <list>
#include <string>
#include "phone.h"
#include "parser/request.h"
#include "parser/response.h"
#include "audio/tone_gen.h"

#include "twinkle_config.h"

#define PRODUCT_DATE VERSION_DATE
#define PRODUCT_AUTHOR	"Michel de Boer"

// Tone definitions
// The intervals indicate the length of silence between repetitions
// of the wav file. Duration is in ms
#define FILE_RINGTONE           "ringtone.wav"
#define INTERVAL_RINGTONE       3000
#define FILE_RINGBACK           "ringback.wav"
#define INTERVAL_RINGBACK       3000

using namespace std;

// Message prioritoes
enum t_msg_priority {
	MSG_INFO,
	MSG_WARNING,
	MSG_CRITICAL
};

struct t_command_arg {
        char    flag;
        string  value;
};

class t_userintf {
private:
        bool            end_interface; // indicates if interface loop should quit
        list<string>    all_commands;  // list of all commands
        t_tone_gen      *tone_gen;     // tone generator for ringing
        
        // The user for which out-of-dialog requests are executed.
        t_user		*active_user;

        // The user can type a prefix of the command only. This method
        // completes a prefix to a full command.
        // If no command is found then the empty string is returned.
        // If the prefix is ambiguous, then argument ambiguous is set to true
        // and the empty string is returned.
        string complete_command(const string &c, bool &ambiguous);

        // Parse command arguments. The list must contain the command as first
        // element followed by the arguments.
        bool parse_args(const list<string> command_list, list<t_command_arg> &al);

        // The command_list must contain the command itself as first
        // argument. Subsequent elements are the arguments.
        bool exec_invite(const list<string> command_list);
        bool exec_answer(const list<string> command_list);
        bool exec_reject(const list<string> command_list);
	bool exec_redirect(const list<string> command_list);
	bool exec_dnd(const list<string> command_list);
	bool exec_auto_answer(const list<string> command_list);
        bool exec_bye(const list<string> command_list);
        bool exec_hold(const list<string> command_list);
        bool exec_retrieve(const list<string> command_list);
	bool exec_refer(const list<string> command_list);
	bool exec_conference(const list<string> command_list);
	bool exec_mute(const list<string> command_list);
	bool exec_dtmf(const list<string> command_list);
        bool exec_register(const list<string> command_list);
        bool exec_deregister(const list<string> command_list);
        bool exec_fetch_registrations(const list<string> command_list);
        bool exec_options(const list<string> command_list);
        bool exec_line(const list<string> command_list);
        bool exec_user(const list<string> command_list);
        bool exec_quit(const list<string> command_list);
        bool exec_help(const list<string> command_list);

protected:
        t_phone         *phone;

	// Throttle dtmtf not supported messages
	bool		throttle_dtmf_not_supported;

	// Last call information
	t_url		last_called_url;
	string		last_called_display;
	string		last_called_subject;
	string		last_called_profile; // profile used to make the call

public:
        t_userintf(t_phone *_phone);
        virtual ~t_userintf();

        // Expand a SIP destination to a full SIP uri, i.e. add sip: scheme
        // and domain if these are missing.
        string expand_destination(t_user *user_config, const string &dst);
        
        // Expand a SIP destination into a display and a full SIP uri
        void expand_destination(t_user *user_config, 
        	const string &dst, string &display, string &dst_url);
        void expand_destination(t_user *user_config, 
        	const string &dst, t_display_url &display_url);

	// Format a SIP address for user display
	virtual string format_sip_address(t_user *user_config, const string &display,
	                                  const t_url &uri) const;

	// Format a warning for user display
	virtual list<string> format_warnings(const t_hdr_warning &hdr_warning) const;

	// Format a codec for user display
	virtual string format_codec(t_audio_codec codec) const;

        bool exec_command(const string &command_line);
        virtual void run(void);

	// Lock the user interface to synchornize output
	virtual void lock(void);
	virtual void unlock(void);

        // Select a network interface. Returns string representation of IP address.
        virtual string select_network_intf(void);

	// Select a user configuration file. Returns false if selection failed.
	virtual bool select_user_config(list<string> &config_files);

        // Call back functions
        virtual void cb_incoming_call(t_user *user_config, int line, const t_request *r);
        virtual void cb_call_cancelled(int line);
        virtual void cb_far_end_hung_up(int line);
        virtual void cb_answer_timeout(int line);
        virtual void cb_sdp_answer_not_supported(int line, const string &reason);
        virtual void cb_sdp_answer_missing(int line);
	virtual void cb_unsupported_content_type(int line, const t_sip_message *r);
        virtual void cb_ack_timeout(int line);
	virtual void cb_100rel_timeout(int line);
	virtual void cb_prack_failed(int line, const t_response *r);
        virtual void cb_provisional_resp_invite(int line, const t_response *r);
        virtual void cb_cancel_failed(int line, const t_response *r);
        virtual void cb_call_answered(t_user *user_config, int line, const t_response *r);
        virtual void cb_call_failed(t_user *user_config, int line, const t_response *r);
        virtual void cb_stun_failed_call_ended(int line);
        virtual void cb_call_ended(int line, const t_response *r);
        virtual void cb_call_established(int line);
        virtual void cb_options_response(const t_response *r);
        virtual void cb_reinvite_success(int line, const t_response *r);
        virtual void cb_reinvite_failed(int line, const t_response *r);
	virtual void cb_retrieve_failed(int line, const t_response *r);
        virtual void cb_invalid_reg_resp(t_user *user_config, 
        		const t_response *r, const string &reason);
        virtual void cb_register_success(t_user *user_config, 
        		const t_response *r, unsigned long expires, bool first_success);
        virtual void cb_register_failed(t_user *user_config, 
        		const t_response *r, bool first_failure);
        virtual void cb_register_stun_failed(t_user *user_config, bool first_failure);
        virtual void cb_deregister_success(t_user *user_config, const t_response *r);
        virtual void cb_deregister_failed(t_user *user_config, const t_response *r);
        virtual void cb_fetch_reg_failed(t_user *user_config, const t_response *r);
        virtual void cb_fetch_reg_result(t_user *user_config, const t_response *r);
	virtual void cb_register_inprog(t_user *user_config, t_register_type register_type);
	virtual void cb_redirecting_request(t_user *user_config, 
			int line, const t_contact_param &contact);
	virtual void cb_redirecting_request(t_user *user_config, 
			const t_contact_param &contact);
        virtual void cb_play_ringtone(void);
	virtual void cb_play_ringback(void);
        virtual void cb_stop_tone(int line);
	virtual void cb_dtmf_detected(int line, char dtmf_event);
	virtual void cb_dtmf_not_supported(int line);
	virtual void cb_dtmf_supported(int line);
	virtual void cb_line_state_changed(void);
	virtual void cb_send_codec_changed(int line, t_audio_codec codec);
	virtual void cb_recv_codec_changed(int line, t_audio_codec codec);
	virtual void cb_notify_recvd(int line, const t_request *r);
	virtual void cb_refer_failed(int line, const t_response *r);
	virtual void cb_refer_result_success(int line);
	virtual void cb_refer_result_failed(int line);
	virtual void cb_refer_result_inprog(int line);

	// A call is being referred by the far end. r must be the REFER request.
	virtual void cb_call_referred(t_user *user_config, int line, t_request *r);

	// The reference failed. Call to referrer is retrieved.
	virtual void cb_retrieve_referrer(t_user *user_config, int line);
	
	// STUN errors
	virtual void cb_stun_failed(int err_code, const string &err_reason);
	virtual void cb_stun_failed(void);

	// Interactive call back functions
	virtual bool cb_ask_user_to_redirect_invite(t_user *user_config, 
			const t_url &destination, const string &display);
	virtual bool cb_ask_user_to_redirect_request(t_user *user_config, 
			const t_url &destination, const string &display, t_method method);
	virtual bool cb_ask_credentials(t_user *user_config, 
			const string &realm, string &username, string &password);
	virtual bool cb_ask_user_to_refer(t_user *user_config, 
			const t_url &refer_to_uri,
			const string &refer_to_display,
			const t_url &referred_by_uri,
			const string &referred_by_display);

	// Show an error message to the user. Depending on the interface mode
	// the user has to acknowledge the error before processing continues.
	virtual void cb_show_msg(const string &msg, t_msg_priority prio = MSG_INFO);

	// Display an error message.
	virtual void cb_display_msg(const string &msg,
			t_msg_priority prio = MSG_INFO);
			
	// Log file has been updated
	virtual void cb_log_updated(bool log_zapped = false);
	
	// Call history has been updated
	virtual void cb_call_history_updated(void);
	
	// Show firewall/NAT discovery progress
	virtual void cb_nat_discovery_progress_start(int num_steps);
	virtual void cb_nat_discovery_progress_step(int step);
	virtual bool cb_nat_discovery_cancelled(void);

	// Get last call information
	// Returns true if last call information is valid
	// Returns false is there is no valid last call information
	virtual bool get_last_call_info(t_url &url, string &display,
				string &subject, t_user **user_config) const;
	virtual bool can_redial(void) const;
};

extern t_userintf *ui;

#endif
