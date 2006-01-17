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

#include <cassert>
#include <cstdlib>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "call_history.h"
#include "log.h"
#include "sys_settings.h"
#include "userintf.h"
#include "util.h"

// Call history file
#define CALL_HISTORY_FILE	"twinkle.ch";

// Field seperator in call history file
#define REC_SEPERATOR		'|'

////////////////////////
// class t_call_record
////////////////////////

t_mutex t_call_record::mtx_class;
unsigned short t_call_record::next_id = 1;

t_call_record::t_call_record() {
	mtx_class.lock();
	id = next_id++;
	if (next_id == 65535) next_id = 1;
	mtx_class.unlock();

	time_start = 0;
	time_answer = 0;
	time_end = 0;
	invite_resp_code = 0;
}

void t_call_record::renew() {
	mtx_class.lock();
	id = next_id++;
	if (next_id == 65535) next_id = 1;
	mtx_class.unlock();

	time_start = 0;
	time_answer = 0;
	time_end = 0;
	direction = DIR_IN;
	from_display.clear();
	from_uri.set_url("");
	from_organization.clear();
	to_display.clear();
	to_uri.set_url("");
	to_organization.clear();
	reply_to_display.clear();
	reply_to_uri.set_url("");
	referred_by_display.clear();
	referred_by_uri.set_url("");
	subject.clear();
	rel_cause = CS_A_PARTY;
	invite_resp_code = 0;
	invite_resp_reason.clear();
	far_end_device.clear();
	user_profile.clear();
}

void t_call_record::start_call(const t_request *invite, t_direction dir, 
		const string &_user_profile) 
{
	assert(invite->method == INVITE);

	struct timeval t;
	
	gettimeofday(&t, NULL);
	time_start = t.tv_sec;
	
	from_display = invite->hdr_from.display;
	from_uri = invite->hdr_from.uri;
	
	if (invite->hdr_organization.is_populated()) {
		from_organization = invite->hdr_organization.name;
	}
	
	to_display = invite->hdr_to.display;
	to_uri = invite->hdr_to.uri;

	if (invite->hdr_reply_to.is_populated()) {
		reply_to_display = invite->hdr_reply_to.display;
		reply_to_uri = invite->hdr_reply_to.uri;
	}
	
	if (invite->hdr_referred_by.is_populated()) {
		referred_by_display = invite->hdr_referred_by.display;
		referred_by_uri = invite->hdr_referred_by.uri;
	}
		
	if (invite->hdr_subject.is_populated()) {
		subject = invite->hdr_subject.subject;
	}
	
	direction = dir;
	user_profile = _user_profile;
	
	if (direction == DIR_IN && invite->hdr_user_agent.is_populated()) {
		far_end_device = invite->hdr_user_agent.get_ua_info();
	}
}

void t_call_record::fail_call(const t_response *resp) {
	assert(resp->get_class() >= 3);
	assert(resp->hdr_cseq.method == INVITE);
	
	struct timeval t;
	
	gettimeofday(&t, NULL);
	time_end = t.tv_sec;
	rel_cause = CS_FAILURE;
	invite_resp_code = resp->code;
	invite_resp_reason = resp->reason;
	
	if (resp->hdr_organization.is_populated()) {
		to_organization = resp->hdr_organization.name;
	}
	
	if (direction == DIR_OUT && resp->hdr_server.is_populated()) {
		far_end_device = resp->hdr_server.get_server_info();
	}
}

void t_call_record::answer_call(const t_response *resp) {
	assert(resp->is_success());
	
	struct timeval t;
	
	gettimeofday(&t, NULL);
	time_answer = t.tv_sec;
	invite_resp_code = resp->code;
	invite_resp_reason = resp->reason;
	
	if (resp->hdr_organization.is_populated()) {
		to_organization = resp->hdr_organization.name;
	}
	
	if (direction == DIR_OUT && resp->hdr_server.is_populated()) {
		far_end_device = resp->hdr_server.get_server_info();
	}
}

void t_call_record::end_call(t_rel_cause cause) {
	struct timeval t;
	
	gettimeofday(&t, NULL);
	time_end = t.tv_sec;
	rel_cause = cause;
}

string t_call_record::get_rel_cause(void) const {
	switch (rel_cause) {
	case CS_A_PARTY:
		return "caller";
	case CS_B_PARTY:
		return "callee";
	case CS_FAILURE:
		return "failure";
	}
	
	return "unknown";
}

string t_call_record::get_direction(void) const {
	switch (direction) {
	case DIR_IN:
		return "in";
	case DIR_OUT:
		return "out";
	}
	
	return "unknown";
}

bool t_call_record::set_rel_cause(const string &cause) {
	if (cause == "caller") {
		rel_cause = CS_A_PARTY;
	} else if (cause == "callee") {
		rel_cause = CS_B_PARTY;
	} else if (cause == "failure") {
		rel_cause = CS_FAILURE;
	} else {
		return false;
	}
	
	return true;
}

bool t_call_record::set_direction(const string &dir) {
	if (dir == "in") {
		direction = DIR_IN;
	} else if (dir == "out") {
		direction = DIR_OUT;
	} else {
		return false;
	}
	
	return true;
}

string t_call_record::create_file_record(void) const {
	string record;
	
	record += ulong2str(time_start);
	record += REC_SEPERATOR;
	record += ulong2str(time_answer);
	record += REC_SEPERATOR;
	record += ulong2str(time_end);
	record += REC_SEPERATOR;
	record += get_direction();
	record += REC_SEPERATOR;
	record += escape(from_display, REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += escape(from_uri.encode(), REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += escape(from_organization, REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += escape(to_display, REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += escape(to_uri.encode(), REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += escape(to_organization, REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += escape(reply_to_display, REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += escape(reply_to_uri.encode(), REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += escape(referred_by_display, REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += escape(referred_by_uri.encode(), REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += escape(subject, REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += get_rel_cause();
	record += REC_SEPERATOR;
	record += int2str(invite_resp_code);
	record += REC_SEPERATOR;
	record += escape(invite_resp_reason, REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += escape(far_end_device, REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += escape(user_profile, REC_SEPERATOR);
	
	return record;
}

bool t_call_record::populate_from_file_record(const string &record) {
	list<string> l = split_escaped(record, REC_SEPERATOR);
	vector<string> v;
	
	// Check number of fields
	if (l.size() != 20) return false;
	
	for (list<string>::iterator i = l.begin(); i != l.end(); i++) {
		v.push_back(*i);
	}
	
	time_start = strtoul(v[0].c_str(), NULL, 10);
	time_answer = strtoul(v[1].c_str(), NULL, 10);
	time_end = strtoul(v[2].c_str(), NULL, 10);
	
	if (!set_direction(v[3])) return false;
	
	from_display = unescape(v[4]);
	from_uri.set_url(unescape(v[5]));
	if (!from_uri.is_valid()) return false;
	from_organization = unescape(v[6]);
	
	to_display = unescape(v[7]);
	to_uri.set_url(unescape(v[8]));
	if (!to_uri.is_valid()) return false;
	to_organization = unescape(v[9]);
	
	reply_to_display = unescape(v[10]);
	reply_to_uri.set_url(unescape(v[11]));
	
	referred_by_display = unescape(v[12]);
	referred_by_uri.set_url(unescape(v[13]));
	
	subject = unescape(v[14]);
	
	if (!set_rel_cause(v[15])) return false;
	
	invite_resp_code = atoi(v[16].c_str());
	invite_resp_reason = unescape(v[17]);
	far_end_device = unescape(v[18]);
	user_profile = unescape(v[19]);
	
	return true;
}

bool t_call_record::is_valid(void) const {
	if (time_start == 0 || time_end == 0) return false;
	if (time_answer > 0 && rel_cause == CS_FAILURE) return false;
	
	return true;
}

unsigned short t_call_record::get_id(void) const {
	return id;
}

////////////////////////
// class t_call_history
////////////////////////

t_call_history::t_call_history() {
	filename = string(DIR_HOME);
	filename += "/";
	filename += USER_DIR;
	filename += "/";
	filename += CALL_HISTORY_FILE;
}

void t_call_history::add_call_record(const t_call_record &call_record, bool write) {
	if (!call_record.is_valid()) {
		log_file->write_report("Call history record is not valid.",
			"t_call_history::add_call_record", LOG_NORMAL, LOG_WARNING);
		return;
	}
	
	mtx_ch.lock();

	call_records.push_back(call_record);
	
	while (call_records.size() > sys_config->ch_max_size) {
		call_records.pop_front();
	}
	
	mtx_ch.unlock();
	
	if (write) {
		string msg;
		if (!write_history(msg)) {
			log_file->write_report(msg, "t_call_history::add_call_record",
				LOG_NORMAL, LOG_WARNING);
		}
	}
	
	// Update call history in user interface.
	ui->cb_call_history_updated();
}

void t_call_history::delete_call_record(unsigned short id, bool write) {
	mtx_ch.lock();
	for (list<t_call_record>::iterator i = call_records.begin();
	     i != call_records.end(); i++)
	{
		if (i->get_id() == id) {
			call_records.erase(i);
			break;
		}
	}
	mtx_ch.unlock();
	
	if (write) {
		string msg;
		if (!write_history(msg)) {
			log_file->write_report(msg, "t_call_history::delete_call_record",
				LOG_NORMAL, LOG_WARNING);
		}
	}
	
	// Update call history in user interface.
	ui->cb_call_history_updated();
}

bool t_call_history::read_history(string &error_msg) {
	struct stat stat_buf;
	
	mtx_ch.lock();
	
	call_records.clear();
	
	// Check if call history file exists
	if (stat(filename.c_str(), &stat_buf) != 0) {
		// There is no call history file.
		mtx_ch.unlock();
		return true;
	}
	
	// Open call history file
	ifstream ch(filename.c_str());
	if (!ch) {
		error_msg = "Cannot open file for reading: ";
		error_msg += filename;
		mtx_ch.unlock();
		return false;
	}
	
	// Read and parse history file.
	while (!ch.eof()) {
		string line;
		t_call_record rec;
		
		getline(ch, line);

		// Check if read operation succeeded
		if (!ch.good() && !ch.eof()) {
			error_msg = "File system error while reading file ";
			error_msg += filename;
			mtx_ch.unlock();
			return false;
		}

		line = trim(line);

		// Skip empty lines
		if (line.size() == 0) continue;

		// Skip comment lines
		if (line[0] == '#') continue;
		
		// Add record. Skip records that cannot be parsed.
		if (rec.populate_from_file_record(line)) {
			add_call_record(rec, false);
		}
	}
	
	mtx_ch.unlock();
	return true;
}

bool t_call_history::write_history(string &error_msg) const {
	struct stat stat_buf;
	
	t_call_history *self = const_cast<t_call_history *>(this);
	
	self->mtx_ch.lock();
	
	// Open file
	ofstream ch(filename.c_str());
	if (!ch) {
		error_msg = "Cannot open file for writing: ";
		error_msg += filename;
		self->mtx_ch.unlock();
		return false;
	}
	
	// Write file header
	ch << "# time_start|time_answer|time_end|direction|from_display|from_uri|"
	      "from_organization|to_display|to_uri|to_organization|"
	      "reply_to_display|reply_to_uri|referred_by_display|referred_by_uri|"
	      "subject|rel_cause|invite_resp_code|invite_resp_reason|"
	      "far_end_device|user_profile";
	ch << endl;
	      
	// Write records
	for (list<t_call_record>::const_iterator i = call_records.begin();
	     i != call_records.end(); i++)
	{
		ch << i->create_file_record();
		ch << endl;
	}
	
	self->mtx_ch.unlock();
	 
	if (!ch.good()) {
		error_msg = "File system error while writing file ";
		error_msg += filename;
		return false;
	}
	
	return true;
}

void t_call_history::get_history(list<t_call_record> &history) {
	mtx_ch.lock();
	history = call_records;
	mtx_ch.unlock();
}

void t_call_history::clear(bool write) {
	mtx_ch.lock();
	call_records.clear();
	mtx_ch.unlock();
	
	if (write) {
		string msg;
		if (!write_history(msg)) {
			log_file->write_report(msg, "t_call_history::clear",
				LOG_NORMAL, LOG_WARNING);
		}
	}
	
	// Update call history in user interface.
	ui->cb_call_history_updated();		
}
