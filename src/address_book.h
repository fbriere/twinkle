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

#ifndef _ADDRESS_BOOK_H
#define _ADDRESS_BOOK_H

#include <string>
#include <list>

#include "user.h"
#include "sockets/url.h"
#include "threads/mutex.h"

using namespace std;

// A single address card
class t_address_card {
public:
	string		name_last;
	string		name_first;
	string		name_infix;
	string		sip_address;
	string		remark;

	// Return the display name derived from first, last and infix.
	string get_display_name(void) const;
	
	// Create a record for write to a file
	string create_file_record(void) const;
	
	// Populate from a file record
	// Return false if file record could not be parsed
	bool populate_from_file_record(const string &record);
	
	bool operator==(const t_address_card other) const;
};

// A book containing address cards. The user can
// create different address books.
class t_address_book {
private:
	// Full file name for call history file
	string		filename;
	
	// Mutex to protect concurrent access
	mutable t_recursive_mutex	mtx_ab;
	
	// List of address cards
	list<t_address_card>	address_list;
	
	// Cache for last searched name/url mapping
	mutable t_url		last_url;
	mutable string		last_name;
	
	// Find a matching address for a url and cache the display name
	void find_address(t_user *user_config, const t_url &u) const;

public:
	t_address_book();

	void add_address(const t_address_card &address);
	
	// Returns falls if the address does not exist
	bool del_address(const t_address_card &address);

	// Returns false if the old address does not exist
	bool update_address(const t_address_card &old_address,
		const t_address_card &new_address);
		
	// Find the display name for a SIP url.
	// Returns the empty string if no match can be found.
	string find_name(t_user *user_config, const t_url &u) const;
	
	// Read an address book file.
	// Returns false if it fails. error_msg is an error to be given to
	// the user.
	bool read_address_book(string &error_msg);

	// Write an address book file.
	bool write_address_book(string &error_msg) const;

	const list<t_address_card> &get_address_list(void) const;
};

extern t_address_book *ab_local;

#endif
