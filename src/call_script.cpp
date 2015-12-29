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

#include <cstdio>
#include <cstring>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "call_script.h"
#include "log.h"
#include "userintf.h"
#include "util.h"

// Maximum length of the reason value
#define MAX_LEN_REASON		50

// Script result fields
#define SCR_ACTION		"action"
#define SCR_REASON		"reason"
#define SCR_CONTACT		"contact"
#define SCR_RINGTONE		"ringtone"
#define SCR_INTERNAL_ERROR	"internal_error"

/////////////////////////
// class t_script_result
/////////////////////////

t_script_result::t_script_result() {
	clear();
}

t_script_result::t_action t_script_result::str2action(const string action_string) {
	string s = tolower(action_string);
	
	t_action result;	
	if (s == "continue") {
		result = ACTION_CONTINUE;
	} else if (s == "reject") {
		result = ACTION_REJECT;
	} else if (s == "dnd") {
		result = ACTION_DND;
	} else if (s == "redirect") {
		result = ACTION_REDIRECT;
	} else if (s == "autoanswer") {
		result = ACTION_AUTOANSWER;
	} else {
		// Unknown action
		result = ACTION_ERROR;
	}
	
	return result;
}

void t_script_result::clear(void) {
	action = ACTION_CONTINUE;
	reason.clear();
	ringtone.clear();
}

void t_script_result::set_parameter(const string &parameter, const string &value) {
	if (parameter == SCR_ACTION) {
		action = str2action(value);
	} else if (parameter == SCR_REASON) {
		if (value.size() <= MAX_LEN_REASON) {
			reason = value;
		} else {
			reason = value.substr(0, MAX_LEN_REASON);
		}
	} else if (parameter == SCR_CONTACT) {
		contact = value;
	} else if (parameter == SCR_RINGTONE) {
		ringtone = value;
	}
	// Unknown parameters are ignored
}

/////////////////////////
// class t_call_script
/////////////////////////

t_call_script::t_call_script(const string &command) : script_command(command)
{}

void t_call_script::exec(t_script_result &result, t_user *user_config, t_request *r) const 
{
	result.clear();
	
	if (script_command.empty()) return;
	
	log_file->write_header("t_call_script::exec");
	log_file->write_raw("Execute script: ");
	log_file->write_raw(script_command);
	log_file->write_endl();
	log_file->write_footer();
	
	// Create pipe for communication with child process
	int fds[2];
	if (pipe(fds) == -1) {
		// Failed to create pipe
		log_file->write_header("t_call_script::exec",
			LOG_NORMAL, LOG_WARNING);
		log_file->write_raw("Failed to create pipe: ");
		log_file->write_raw(strerror(errno));
		log_file->write_endl();
		log_file->write_footer();
		return;
	}
	
	// Fork child process
	pid_t pid = fork();
	if (pid == -1) {
		// Failed to fork child process
		log_file->write_header("t_call_script::exec",
			LOG_NORMAL, LOG_WARNING);
		log_file->write_raw("Failed to fork child process: ");
		log_file->write_raw(strerror(errno));
		log_file->write_endl();
		log_file->write_footer();
		
		close(fds[0]);
		close(fds[1]);
		return;
	} else if (pid == 0) {
		// Child process
		
		// Close the read end of the pipe
		close(fds[0]);
		
		// Redirect stdout to the write end of the pipe
		dup2(fds[1], STDOUT_FILENO);
		
		// Determine script agument list
		list<string> arg_list = split_ws(script_command, true);
		
		// NOTE: MEMMAN audits are not called as all pointers will be deleted
		//       automatically when the child process dies
		//	 Also, the child process has a copy of the MEMMAN object
		char **argv = new char *[arg_list.size() + 1];
		
		int idx = 0;
		for (list<string>::iterator i = arg_list.begin(); 
		     i != arg_list.end(); i++, idx++) 
		{
			argv[idx] = strdup(i->c_str());
		}
		argv[arg_list.size()] = NULL;
		
		// Determine environment
		// Number of existing environment variables
		int environ_size = 0;
		for (int i = 0; environ[i] != NULL; i++) {
			environ_size++;
		}
		
		// Number of SIP environment variables
		int start_sip_env = environ_size; // Position of SIP variables
		list<string> l = r->encode_env();
		environ_size += l.size();
		
		// Number of Twinkle environment variables
		int start_twinkle_env = environ_size; // Position of Twinkle variables
		environ_size += 1;
		
		char **env = new char *[environ_size + 1];
		
		// Copy current environment to child
		for (int i = 0; environ[i] != NULL; i++) {
			env[i] = strdup(environ[i]);
		}
		
		// Add environment variables for SIP request
		int j = start_sip_env;
		for (list<string>::iterator i = l.begin(); i != l.end(); i++, j++) {
			env[j] = strdup(i->c_str());
		}
		
		// Add Twinkle specific environment variables
		string var_twinkle = "TWINKLE_USER_PROFILE=";
		var_twinkle += user_config->get_profile_name();
		env[start_twinkle_env] = strdup(var_twinkle.c_str());
		
		// Terminate array with NULL
		env[environ_size] = NULL;
		
		// Replace the child process by the script
		if (execve(argv[0], argv, env) == -1) {
			// Failed to execute script. Report error to parent.
			string err_msg;
			err_msg = strerror(errno);
			err_msg += ": ";
			err_msg += argv[0];
			cout << SCR_INTERNAL_ERROR << '=' << err_msg << endl;
			exit(0);
		}
	} else {
		// Parent process
		
		// Close the write end of the pipe
		close(fds[1]);
		
		// Read the script results
		FILE *fp_result = fdopen(fds[0], "r");
		if (!fp_result) {
			log_file->write_header("t_call_script::exec",
				LOG_NORMAL, LOG_WARNING);
			log_file->write_raw("Failed to open pipe to child: ");
			log_file->write_raw(strerror(errno));
			log_file->write_endl();
			log_file->write_footer();
			
			// Wait for the child process to die
			waitpid(pid, NULL, 0);
			close(fds[0]);
			return;
		}
		
		char *line_buf = NULL;
		size_t line_buf_len = 0;
		ssize_t num_read;
		
		// Read and parse script results.
		while ((num_read = getline(&line_buf, &line_buf_len, fp_result)) != -1) {
			// Strip newline if present
			if (line_buf[num_read - 1] == '\n') {
				line_buf[num_read - 1] = 0;
			}

			// Convert the read line to a C++ string
			string line(line_buf);	
			line = trim(line);
	
			// Skip empty lines
			if (line.empty()) continue;
	
			// Skip comment lines
			if (line[0] == '#') continue;
	
			list<string> l = split_on_first(line, '=');
			
			// SKip invalid lines
			if (l.size() != 2) continue;
	
			string parameter = trim(l.front());
			string value = trim(l.back());
			
			if (parameter == SCR_INTERNAL_ERROR) {
				log_file->write_report(value,
					"t_call_script::exec",
					LOG_NORMAL, LOG_WARNING);
				ui->cb_display_msg(value, MSG_WARNING);
				result.clear();
				break;
			}
			
			result.set_parameter(parameter, value);
		}
		
		if (line_buf) free(line_buf);
		fclose(fp_result);
		close(fds[0]);
		
		// Wait for the child process to die
		waitpid(pid, NULL, 0);
	}
}
