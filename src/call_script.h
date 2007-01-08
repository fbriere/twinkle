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

#ifndef _H_CALL_SCRIPT
#define _H_CALL_SCRIPT

#include <string>
#include "user.h"
#include "parser/request.h"

using namespace std;

/*
   A call script is called by Twinkle during call processing.
   Currently only when a call comes in (INVITE received).
   Twinkle calls the script and based of the output of the script, the
   call is further handled.
   
   The following environment variables are passed to the script:
   
     TWINKLE_USER_PROFILE=<user profile name>
     SIPREQUEST_METHOD=<method>
     SIPREQUEST_URI=<request uri>
     SIP_<header_name>=<header value>
   
   The header name is in capitals and dashed are replaced by underscores
   
   The script can return on stdout how the call should be further
   processed. The following output parameters are recognized:
   
     action=[continue|reject|dnd|redirect]
     reason=<reason phrase>, for reject and dnd actions
     contact=<sip uri>, for redirect ation
     ringtone=<name of wav file>, for continue action
   
   If no action is returned, the "continue" action is performed.
   Invalid output will be skipped.
*/

// Results of the incoming call script
class t_script_result {
public:
	enum t_action {
		ACTION_CONTINUE, 	// Continue with incoming call
		ACTION_REJECT, 		// Reject incoming call with 603 response
		ACTION_DND,		// Do not disturb, send 480 response
		ACTION_REDIRECT,	// Redirect call (302 response)
		ACTION_AUTOANSWER,	// Auto answer incoming call
		ACTION_ERROR		// Fail call due to error (500 response)
	};
	
	t_action	action;		// How to proceed with call
	string		reason;		// Reason if call is not continued
	string		contact;	// Redirect destination for redirect action
	string		caller_name;	// Name of caller (can be used to override display name)
	string		ringtone;	// Wav file for ring tone
	string		display_msg;	// Message to show on display
	
	t_script_result();
	static t_action str2action(const string action_string);
	void clear(void);
	
	// Set parameter from values read from the result output of a script
	void set_parameter(const string &parameter, const string &value);
};

class t_call_script {
public:
	enum t_trigger {
		TRIGGER_IN_CALL,
		TRIGGER_IN_CALL_ANSWERED,
		TRIGGER_IN_CALL_FAILED,
		TRIGGER_OUT_CALL,
		TRIGGER_OUT_CALL_ANSWERED,
		TRIGGER_OUT_CALL_FAILED,
		TRIGGER_LOCAL_RELEASE,
		TRIGGER_REMOTE_RELEASE
	};
	
private:
	t_user		*user_config;
	string		script_command;
	t_trigger	trigger;
	
	string trigger2str(t_trigger t) const;
	
	// Create environment for the process running the script.
	// NOTE: this function creates the env array without registering
	//       the memory allocation to MEMMAN
	char **create_env(t_sip_message *m) const;
	
	// Create script command argument list
	// NOTE: this function creates the env array without registering
	//       the memory allocation to MEMMAN
	char **create_argv(void) const;
	
protected:
	t_call_script() {};
	
public:
	t_call_script(t_user *_user_config, t_trigger _trigger);
	
	// Execute call script
	void exec_action(t_script_result &result, t_sip_message *m) const;
	void exec_notify(t_sip_message *m) const;
};

#endif
