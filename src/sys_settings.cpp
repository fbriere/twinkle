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

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include "sys_settings.h"
#include "userintf.h"

// Share directory containing files applicable to all users
#define DIR_SHARE	DATADIR

// Lock file to guarantee that a user is running the application only once
#define LOCK_FILENAME	"twinkle.lck"

t_sys_settings::t_sys_settings() {
	dir_share = DIR_SHARE;
}

bool t_sys_settings::check_environment(string &error_msg) const {
	struct stat stat_buf;
	string filename, dirname;

	// Check if share directory exists
	if (stat(dir_share.c_str(), &stat_buf) != 0) {
		error_msg = "Directory ";
		error_msg += dir_share;
		error_msg += " does not exist.";
		return false;
	}

	// Check if audio file for ring tone exist
	filename = dir_share;
	filename += '/';
	filename += FILE_RINGTONE;
	ifstream f_ringtone(filename.c_str());
	if (!f_ringtone) {
		error_msg = "Cannot open file ";
		error_msg += filename;
		return false;
	}

	// Check if audio file for ring back exist
	filename = dir_share;
	filename += '/';
	filename += FILE_RINGBACK;
	ifstream f_ringback(filename.c_str());
	if (!f_ringback) {
		error_msg = "Cannot open file ";
		error_msg += filename;
		return false;
	}

	// Check if $HOME is set correctly
	if (string(DIR_HOME) == "") {
		error_msg = "$HOME is not set to your home directory.";
		return false;
	}
	if (stat(DIR_HOME, &stat_buf) != 0) {
		error_msg = "Directory ";
		error_msg += DIR_HOME;
		error_msg += " ($HOME) does not exist.";
		return false;
	}

	// Check if user directory exists
	dirname = DIR_HOME;
	dirname += '/';
	dirname += DIR_USER;
	if (stat(dirname.c_str(), &stat_buf) != 0) {
		// User directory does not exist. Create it now.
		if (mkdir(dirname.c_str(), S_IRUSR | S_IWUSR | S_IXUSR) != 0) {
			// Failed to create the user directory
			error_msg = "Cannot create directory ";
			error_msg += dirname;
			return false;
		}
	}

	return true;
}

void t_sys_settings::set_dir_share(const string &dir) {
	dir_share = dir;
}

string t_sys_settings::get_dir_share(void) const {
	return dir_share;
}

bool t_sys_settings::create_lock_file(string &error_msg) const {
	struct stat stat_buf;
	string lck_filename;

        lck_filename = DIR_HOME;
        lck_filename += "/";
        lck_filename += DIR_USER;
        lck_filename += "/";
        lck_filename += LOCK_FILENAME;

	// Check if a lock file already exists
	if (stat(lck_filename.c_str(), &stat_buf) == 0) {
		ifstream f(lck_filename.c_str());
		if (!f) {
			error_msg = "Lock file ";
			error_msg += lck_filename;
			error_msg += " already exists.\n";
			error_msg += "File cannot be opened however.";
			return false;
		}

		// Check if lock is stale
		pid_t lock_pid;
		f >> lock_pid;
		if (kill(lock_pid, 0) == 0) {
			// The pid in the lock file exists, so Twinkle is
			// already running.
			error_msg = PRODUCT_NAME;
			error_msg += " is already running.\n";
			error_msg += "Lock file ";
			error_msg += lck_filename;
			error_msg += " already exists.";
			return false;
		}

		// The lock is stale; delete it
		f.close();
		unlink(lck_filename.c_str());
	}

	// Create lock file
	ofstream f(lck_filename.c_str());
	if (!f) {
		error_msg = "Cannot create ";
		error_msg += lck_filename;
		return false;
	}

	f << getpid();
	if (!f.good()) {
		error_msg = "Cannot write to ";
		error_msg += lck_filename;
		return false;
	}

	return true;
}

void t_sys_settings::delete_lock_file(void) const {
	string lck_filename;

        lck_filename = DIR_HOME;
        lck_filename += "/";
        lck_filename += DIR_USER;
        lck_filename += "/";
        lck_filename += LOCK_FILENAME;

	unlink(lck_filename.c_str());
}
