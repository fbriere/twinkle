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

#include "address_book.h"

#include "sys_settings.h"
#include "translator.h"
#include "userintf.h"
#include "util.h"

// Call history file
#define ADDRESS_BOOK_FILE	"twinkle.ab";

// Field seperator in call history file
#define REC_SEPERATOR		'|'

////////////////////////////
// class t_address_card
////////////////////////////

string t_address_card::get_display_name(void) const {
	string s;
	
	if (!name_first.empty()) {
		s = name_first;
	}
	
	if (!name_infix.empty()) {
		if (!s.empty()) s += ' ';
		s += name_infix;
	}
	
	if (!name_last.empty()) {
		if (!s.empty()) s += ' ';
		s += name_last;
	}
	
	return s;
}
	
string t_address_card::create_file_record(void) const {
	string record;
	
	record += escape(name_first, REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += escape(name_infix, REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += escape(name_last, REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += escape(sip_address, REC_SEPERATOR);
	record += REC_SEPERATOR;
	record += escape(remark, REC_SEPERATOR);
	
	return record;
}
	
bool t_address_card::populate_from_file_record(const string &record) {
	vector<string> v = split_escaped(record, REC_SEPERATOR);
	
	// Check number of fields
	if (v.size() != 5) return false;
	
	name_first = unescape(v[0]);
	name_infix = unescape(v[1]);
	name_last = unescape(v[2]);
	sip_address = unescape(v[3]);
	remark = unescape(v[4]);
	
	return true;
}
	
bool t_address_card::operator==(const t_address_card other) const {
	return (name_first == other.name_first &&
		name_infix == other.name_infix &&
		name_last == other.name_last &&
		sip_address == other.sip_address &&
		remark == other.remark);
}


////////////////////////////
// class t_address_book
////////////////////////////

// Private

void t_address_book::find_address(t_user *user_config, const t_url &u) const {
	if (u == last_url) return;
	
	last_url = u;
	last_name.clear();
	
	// Normalize url using number conversion rules
	t_url u_normalized(u);
	string normalized_user = user_config->convert_number(u.get_user());
	u_normalized.set_user(normalized_user);
	
	for (list<t_address_card>::const_iterator i = address_list.begin();
	     i != address_list.end(); i++)
	{
		string full_address = ui->expand_destination(user_config, i->sip_address);
		t_url url_phone(full_address);
		if (!url_phone.is_valid()) continue;
		
		if (u_normalized.user_host_match(url_phone,
			user_config->get_remove_special_phone_symbols(),
			user_config->get_special_phone_symbols()))
		{
			last_name = i->get_display_name();
			return;
		}
	}
}


// Public

t_address_book::t_address_book() {
	filename = string(DIR_HOME);
	filename += "/";
	filename += USER_DIR;
	filename += "/";
	filename += ADDRESS_BOOK_FILE;
}

void t_address_book::add_address(const t_address_card &address) {
	mtx_ab.lock();
	address_list.push_back(address);
	mtx_ab.unlock();
}

bool t_address_book::del_address(const t_address_card &address) {
	mtx_ab.lock();
	
	list<t_address_card>::iterator it = find(address_list.begin(), address_list.end(),
			address);
			
	if (it == address_list.end()) {
		mtx_ab.unlock();
		return false;
	}	
	
	address_list.erase(it);
	
	// Invalidate the cache for the address finder
	last_url.set_url("");
	
	mtx_ab.unlock();
	return true;
}

bool t_address_book::update_address(const t_address_card &old_address,
	const t_address_card &new_address)
{
	mtx_ab.lock();
	
	if (!del_address(old_address)) {
		mtx_ab.unlock();
		return false;
	}
	
	address_list.push_back(new_address);
	
	mtx_ab.unlock();
	return true;
}

string t_address_book::find_name(t_user *user_config, const t_url &u) const {
	mtx_ab.lock();
	find_address(user_config, u);
	string name = last_name;
	mtx_ab.unlock();
	
	return name;
}

bool t_address_book::read_address_book(string &error_msg) {
	struct stat stat_buf;
	
	mtx_ab.lock();
	
	address_list.clear();
	
	// Check if address book file exists
	if (stat(filename.c_str(), &stat_buf) != 0) {
		// There is no call history file.
		mtx_ab.unlock();
		return true;
	}
	
	// Open call history file
	ifstream ab(filename.c_str());
	if (!ab) {
		error_msg = TRANSLATE("Cannot open file for reading: %1");
		error_msg = replace_first(error_msg, "%1", filename);
		mtx_ab.unlock();
		return false;
	}
	
	// Read and parse history file.
	while (!ab.eof()) {
		string line;
		t_address_card card;
		
		getline(ab, line);

		// Check if read operation succeeded
		if (!ab.good() && !ab.eof()) {
			error_msg = TRANSLATE("File system error while reading file %1 .");
			error_msg = replace_first(error_msg, "%1", filename);
			mtx_ab.unlock();
			return false;
		}

		line = trim(line);

		// Skip empty lines
		if (line.size() == 0) continue;

		// Skip comment lines
		if (line[0] == '#') continue;
		
		// Add record. Skip records that cannot be parsed.
		if (card.populate_from_file_record(line)) {
			address_list.push_back(card);
		}
	}
	
	mtx_ab.unlock();
	
	return true;
}

bool t_address_book::write_address_book(string &error_msg) const {
	struct stat stat_buf;
	
	mtx_ab.lock();
	
	// Open file
	ofstream ab(filename.c_str());
	if (!ab) {
		error_msg = TRANSLATE("Cannot open file for writing: %1");
		error_msg = replace_first(error_msg, "%1", filename);
		mtx_ab.unlock();
		return false;
	}
	
	// Write file header
	ab << "# first_name|infix_name|last_name|sip_address|remark";
	ab << endl;
	      
	// Write records
	for (list<t_address_card>::const_iterator i = address_list.begin();
	     i != address_list.end(); i++)
	{
		ab << i->create_file_record();
		ab << endl;
	}
	
	mtx_ab.unlock();
	 
	if (!ab.good()) {
		error_msg = TRANSLATE("File system error while writing file %1 .");
		error_msg = replace_first(error_msg, "%1", filename);
		return false;
	}
	
	return true;
}

const list<t_address_card> &t_address_book::get_address_list(void) const {
	return address_list;
}
