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
#include <list>

using namespace std;

// General system settings

// User directory, relative to the home directory ($HOME)
#define DIR_USER	".twinkle"

// Home directory
#define DIR_HOME	(getenv("HOME"))

// Device file for DSP
#define DEV_DSP		"/dev/dsp"

// File with SIP providers for the wizard
#define FILE_PROVIDERS	"providers.csv"

class t_oss_device {
public:
	string		device; 	// eg. /dev/dsp, /dev/dsp1
	string		sym_link;	// real device if the device is a symbolic link
	string		name;		// name of the sound card
	
	// Get a one-line description
	string get_description(void) const;
};

class t_sys_settings {
private:
	// Share directory for files applicable to all users
	string		dir_share;
	
	// Full file name for config file
	string		filename;

public:
	// Sound devices
	string		dev_ringtone;
	string		dev_speaker;
	string		dev_mic;
	
	// Log file settings
	unsigned short	log_max_size; // in MB
	bool		log_show_sip;
	bool		log_show_stun;
	bool		log_show_memory;
	bool		log_show_debug;

	t_sys_settings();
	
	// Return "about" text
	string about(bool html) const;

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
	
	// Read and parse a config file into the t_sys_settings object.
	// Returns false if it fails. error_msg is an error message that can
	// be give to the user.
	bool read_config(string &error_msg);

	// Write the settings into a config file
	bool write_config(string &error_msg);
	
	// Get all OSS devices
	list<t_oss_device> get_oss_devices(void) const;
	
	// Check if two OSS devices are equal
	bool equal_oss_dev(const string &dev1, const string &dev2) const;
};

extern t_sys_settings *sys_config;

#endif
