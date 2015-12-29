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

#ifndef _CALL_HISTORY_H
#define _CALL_HISTORY_H

#include <list>
#include <string>
#include <sys/time.h>
#include "parser/request.h"
#include "parser/response.h"
#include "sockets/url.h"
#include "threads/mutex.h"

using namespace std;

class t_call_record {
public:

enum t_rel_cause {
	CS_LOCAL_USER,
	CS_REMOTE_USER,
	CS_FAILURE
};

enum t_direction {
	DIR_IN,
	DIR_OUT
};

private:
	static t_mutex		mtx_class; // protect static members
	static unsigned short	next_id; // next id to be used
	
	unsigned short		id; // record id

public:
	time_t		time_start;
	time_t		time_answer;
	time_t		time_end;
	t_direction	direction;
	string		from_display;
	t_url		from_uri;
	string		from_organization;
	string		to_display;
	t_url		to_uri;
	string		to_organization;
	string		reply_to_display;
	t_url		reply_to_uri;
	string		referred_by_display;
	t_url		referred_by_uri;
	string		subject;
	t_rel_cause	rel_cause;
	int		invite_resp_code;
	string		invite_resp_reason;
	string		far_end_device;
	string		user_profile;
	
	t_call_record();
	
	// Clear current settings and get a new record id.
	// So this action creates a brand new call record.
	void renew();
	
	// Record call start
	void start_call(const t_request *invite, t_direction dir, const string &_user_profile);
	
	// Record call failure. This is also the end of the call
	void fail_call(const t_response *resp);
	
	// Record successful call answer
	void answer_call(const t_response *resp);
	
	// Record end of a successful call with an explicit cause
	void end_call(t_rel_cause cause);
	
	// Record end of a successful call
	// If far_end is true, then the far-end ended the call, otherwise
	// the near-end ended the call. This indication together with the
	// direction determines the correct cause of the call end.
	void end_call(bool far_end);
	
	string get_rel_cause(void) const;
	string get_rel_cause_internal(void) const;
	string get_direction(void) const;
	string get_direction_internal(void) const;
	bool set_rel_cause(const string &cause);
	bool set_direction(const string &dir);
	
	// Create a record for write to a file
	string create_file_record(void) const;
	
	// Populate from a file record
	// Return false if file record could not be parsed
	bool populate_from_file_record(const string &record);
	
	bool is_valid(void) const;
	unsigned short get_id(void) const;
};

class t_call_history {
private:
	// Full file name for call history file
	string		filename;
	
	// Mutex to protect concurrent access
	t_recursive_mutex	mtx_ch;
	
	list<t_call_record>	call_records;
	
	// Number of missed calls since this counter was cleared
	int		num_missed_calls;
	
public:
	
	t_call_history();
	
	
	// Add a call record to the history.
	// 'write' indicates if history must be written to file
	void add_call_record(const t_call_record &call_record, bool write = true);
	
	// Delete record with a given id.
	void delete_call_record(unsigned short id, bool write = true);
	
	// Read call history file.
	// Returns false if it fails. error_msg is an error message that can
	// be give to the user.
	bool read_history(string &error_msg);
	
	// Write call history file.
	bool write_history(string &error_msg) const;
	
	void get_history(list<t_call_record> &history);
	
	// Clear call history file
	void clear(bool write = true);
	
	int get_num_missed_calls(void) const;
	void clear_num_missed_calls(void);
};

extern t_call_history *call_history;

#endif
