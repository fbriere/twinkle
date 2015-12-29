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

#ifndef _SYS_SETTINGS_H
#define _SYS_SETTINGS_H

#include <cstdlib>
#include <string>

using namespace std;

// General system settings

// User directory, relative to the home directory ($HOME)
#define DIR_USER	".twinkle"

// Home directory
#define DIR_HOME	(getenv("HOME"))

// Device file for DSP
#define DEV_DSP		"/dev/dsp"

class t_sys_settings {
private:
	// Share directory for files applicable to all users
	string		dir_share;

public:
	t_sys_settings();

	// Check if the environment of the machine satisfies all requirements.
	// If not, then false is returned and error_msg contains an appropriate
	// error message to show the user.
	bool check_environment(string &error_msg) const;

	// Set the share directory
	void set_dir_share(const string &dir);

	// Get the share directory
	string get_dir_share(void) const;

	// Lock file operations
	bool create_lock_file(string &error_msg) const;
	void delete_lock_file(void) const;
};

extern t_sys_settings *sys_config;

#endif
