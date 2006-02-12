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

#ifndef _SYS_SETTINGS_H
#define _SYS_SETTINGS_H

#include <cstdlib>
#include <string>
#include <list>
#include "sockets/url.h"
#include "twinkle_config.h"

using namespace std;

// General system settings

// User directory, relative to the home directory ($HOME)
#define DIR_USER	".twinkle"

// Home directory
#define DIR_HOME	(getenv("HOME"))

// Device file for DSP
#define DEV_DSP		"/dev/dsp"

// Device prefixes in settings file
#define PFX_OSS		"oss:"
#define PFX_ALSA	"alsa:"

// File with SIP providers for the wizard
#define FILE_PROVIDERS	"providers.csv"


class t_audio_device {
public:
	enum t_audio_device_type {
		OSS, ALSA
	} type;
	string		device; 	// eg. /dev/dsp, /dev/dsp1 for OSS or hw:0,0 for ALSA
	string		sym_link;	// real device if the device is a symbolic link
	string		name;		// name of the sound card

	// Get a one-line description
	string get_description(void) const;
	
	// Get string to be written in settings file
	string get_settings_value(void) const;
};

class t_sys_settings {
private:
	// Share directory for files applicable to all users
	string		dir_share;
	
	// Full file name for config file
	string		filename;
	
	// The SIP UDP port that is currently used
	unsigned short	active_sip_udp_port;
	
public:
	// Sound devices
	t_audio_device		dev_ringtone;
	t_audio_device		dev_speaker;
	t_audio_device		dev_mic;
	bool			au_reduce_noise_mic;
	int			alsa_play_period_size;
	int			alsa_capture_period_size;
	int			oss_fragment_size;
	
	// Log file settings
	unsigned short	log_max_size; // in MB
	bool		log_show_sip;
	bool		log_show_stun;
	bool		log_show_memory;
	bool		log_show_debug;
	
	// GUI settings
	bool		gui_use_systray;
	bool		gui_hide_on_close;
	
	// Address book settings
	bool		ab_show_sip_only;
	
	// Call history settings
	int		ch_max_size; // #calls
	
	// Service settings
	// Call waiting allows an incoming call if one line is busy.
	bool		call_waiting;
	
	// Indicates if both lines should be hung up when ending a
	// 3-way conference call.
	// If false, then only the active line will be hung up.
	bool		hangup_both_3way;
	
	// Startup settings
	list<string>	start_user_profiles;
	string		start_user_host;
	bool		start_hidden;
	
	// Network settings
	// Port for sending and receiving SIP messages. This is the value
	// written in the system settings file. This value can differ from
	// active_sip_udp_port value if the user changed the system
	// settings while Twinkle is running.
	unsigned short	config_sip_udp_port;
	
	// rtp_port is the base port for RTP streams. Each phone line
	// uses has its own RTP port number.
	// line x has RTP port = rtp_port + x * 2 and
	//           RTCP port = rtp_port + x * 2 + 1
	// Where x starts at 0
	//
	// NOTE: for call transfer scenario, line 2 (3rd line) is used
	//       which is not a line that is visible to the user. The user
	//       only sees 2 lines for its use. By having a dedicated port
	//       for line 2, the  RTP stream for a referred call uses another
	//       port than the RTP stream for an original call, preventing
	//       the RTP streams for these calls to become mixed.
	//
	// NOTE: during a call transfer, line 2 will be swapped with another
	//       line, so the ports swap accordingly.
	unsigned short		rtp_port;
	
	// Ring tone settings
	bool		play_ringtone;
	string		ringtone_file;
	bool		play_ringback;
	string		ringback_file;
	
	// Persistent storage for user interface state
	// The profile that was last used before Twinkle was terminated.
	string		last_used_profile;
	
	// Call information for redial last call function
	t_url		redial_url;
	string		redial_display;
	string		redial_subject;
	string		redial_profile; // profile used to make the call
	
	// History of latest dialed addresses
	list<string>	dial_history;
	
	t_sys_settings();
	
	// Return "about" text
	string about(bool html) const;
	
	// Return a string of options that are built, e.g. ALSA, KDE
	string get_options_built(void) const;

	// Check if the environment of the machine satisfies all requirements.
	// If not, then false is returned and error_msg contains an appropriate
	// error message to show the user.
	bool check_environment(string &error_msg) const;

	// Set the share directory
	void set_dir_share(const string &dir);

	// Get the share directory
	string get_dir_share(void) const;
	
	// Get the user directory
	string get_dir_user(void) const;

	// Lock file operations
	bool create_lock_file(string &error_msg, bool &already_running) const;
	void delete_lock_file(void) const;
	
	// Read and parse a config file into the t_sys_settings object.
	// Returns false if it fails. error_msg is an error message that can
	// be give to the user.
	bool read_config(string &error_msg);

	// Write the settings into a config file
	bool write_config(string &error_msg);
	
	// Get all OSS devices
	list<t_audio_device> get_oss_devices(void) const;
	
#ifdef HAVE_LIBASOUND
	// Get all ALSA devices
	list<t_audio_device> get_alsa_devices(void) const;
#endif
	
	// Get all audio devices
	list<t_audio_device> get_audio_devices(void) const;
	
	// Check if two OSS devices are equal
	bool equal_audio_dev(const t_audio_device &dev1, const t_audio_device &dev2) const;
	
	static t_audio_device audio_device(string device = "");
	
	// Get the active value of the SIP UDP port
	unsigned short get_sip_udp_port(void);
};

extern t_sys_settings *sys_config;

#endif
