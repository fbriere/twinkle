/*
    Copyright (C) 2005-2008  Michel de Boer <michel@twinklephone.com>

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
#include "threads/mutex.h"
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

// Device string for other device
#define DEV_OTHER	"other device"

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
	// Mutex to avoid sync concurrent access
	mutable t_recursive_mutex	mtx_sys;
	
	// Share directory for files applicable to all users
	string		dir_share;
	
	// Full file name for config file
	string		filename;
	
	/** The SIP port that is currently used */
	unsigned short	active_sip_port;
	
	// Sound devices
	t_audio_device		dev_ringtone;
	t_audio_device		dev_speaker;
	t_audio_device		dev_mic;
	
	// Indicates if audio devices should be validated before
	// usage.
	bool			validate_audio_dev;
	
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
	
	// Show main window on incoming call after a few seconds
	bool		gui_auto_show_incoming;
	int		gui_auto_show_timeout;
	
	// Address book settings
	bool		ab_show_sip_only;
	bool		ab_lookup_name;
	bool		ab_override_display;
	bool		ab_lookup_photo;
	
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
	
#if 0
	// DEPRECATED
	string		start_user_host;
	string		start_user_nic;
#endif

	bool		start_hidden;
	
	/** @name Network settings */
	//@{
	/** Port for sending and receiving SIP messages. This is the value
	 * written in the system settings file. This value can differ from
	 * active_sip_port value if the user changed the system
	 * settings while Twinkle is running.
	 */
	unsigned short	config_sip_port;
	
	/** SIP UDP port overridden by the command options. */
	unsigned short	override_sip_port;
	
	/** Port for RTP.
	 * rtp_port is the base port for RTP streams. Each phone line
	 * uses has its own RTP port number.
	 * line x has RTP port = rtp_port + x * 2 and
	 *           RTCP port = rtp_port + x * 2 + 1
	 * Where x starts at 0
	 *
	 * NOTE: for call transfer scenario, line 2 (3rd line) is used
	 *       which is not a line that is visible to the user. The user
	 *       only sees 2 lines for its use. By having a dedicated port
	 *       for line 2, the  RTP stream for a referred call uses another
	 *       port than the RTP stream for an original call, preventing
	 *       the RTP streams for these calls to become mixed.
	 *
	 * NOTE: during a call transfer, line 2 will be swapped with another
	 *       line, so the ports swap accordingly.
	 */
	unsigned short	rtp_port;
	
	/** RTP port overridden by the command options. */
	unsigned short	override_rtp_port; 
	
	/** Maximum size of a SIP message received over UDP. */
	unsigned short	sip_max_udp_size;
	
	/** Maximum size of a SIP message received over TCP. */
	unsigned long	sip_max_tcp_size;
	//@}
	
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
	bool		redial_hide_user; // Did the user request hiding?
	
	// History of latest dialed addresses
	list<string>	dial_history;
	
	/** @name GUI view settings */
	//@{
	bool		show_display;
	bool		compact_line_status;
	bool		show_buddy_list;
	//@}
	
	// One time warnings
	bool		warn_hide_user; // Warn use that provider may not support hiding.
	
public:
	t_sys_settings();
	
	// Getters
	t_audio_device get_dev_ringtone(void) const;
	t_audio_device get_dev_speaker(void) const;
	t_audio_device get_dev_mic(void) const;
	bool get_validate_audio_dev(void) const;
	bool get_au_reduce_noise_mic(void) const;
	int get_alsa_play_period_size(void) const;
	int get_alsa_capture_period_size(void) const;
	int get_oss_fragment_size(void) const;
	unsigned short get_log_max_size(void) const;
	bool get_log_show_sip(void) const;
	bool get_log_show_stun(void) const;
	bool get_log_show_memory(void) const;
	bool get_log_show_debug(void) const;
	bool get_gui_use_systray(void) const;
	bool get_gui_hide_on_close(void) const;
	bool get_gui_auto_show_incoming(void) const;
	int get_gui_auto_show_timeout(void) const;
	bool get_ab_show_sip_only(void) const;
	bool get_ab_lookup_name(void) const;
	bool get_ab_override_display(void) const;
	bool get_ab_lookup_photo(void) const;
	int get_ch_max_size(void) const;
	bool get_call_waiting(void) const;
	bool get_hangup_both_3way(void) const;
	list<string> get_start_user_profiles(void) const;
#if 0
	// DEPRECATED
	string get_start_user_host(void) const;
	string get_start_user_nic(void) const;
#endif
	bool get_start_hidden(void) const;
	unsigned short get_config_sip_port(void) const;
	unsigned short get_rtp_port(void) const;
	unsigned short get_sip_max_udp_size(void) const;
	unsigned long get_sip_max_tcp_size(void) const;
	bool get_play_ringtone(void) const;
	string get_ringtone_file(void) const;
	bool get_play_ringback(void) const;
	string get_ringback_file(void) const;
	string get_last_used_profile(void) const;
	t_url get_redial_url(void) const;
	string get_redial_display(void) const;
	string get_redial_subject(void) const;
	string get_redial_profile(void) const;
	bool get_redial_hide_user(void) const;
	list<string> get_dial_history(void) const;
	bool get_show_display(void) const;
	bool get_compact_line_status(void) const;
	bool get_show_buddy_list(void) const;
	bool get_warn_hide_user(void) const;
	
	// Setters
	void set_dev_ringtone(const t_audio_device &dev);
	void set_dev_speaker(const t_audio_device &dev);
	void set_dev_mic(const t_audio_device &dev);
	void set_validate_audio_dev(bool b);
	void set_au_reduce_noise_mic(bool b);
	void set_alsa_play_period_size(int size);
	void set_alsa_capture_period_size(int size);
	void set_oss_fragment_size(int size);
	void set_log_max_size(unsigned short size);
	void set_log_show_sip(bool b);
	void set_log_show_stun(bool b);
	void set_log_show_memory(bool b);
	void set_log_show_debug(bool b);
	void set_gui_use_systray(bool b);
	void set_gui_hide_on_close(bool b);
	void set_gui_auto_show_incoming(bool b);
	void set_gui_auto_show_timeout(int timeout);
	void set_ab_show_sip_only(bool b);
	void set_ab_lookup_name(bool b);
	void set_ab_override_display(bool b);
	void set_ab_lookup_photo(bool b);
	void set_ch_max_size(int size);
	void set_call_waiting(bool b);
	void set_hangup_both_3way(bool b);
	void set_start_user_profiles(const list<string> &profiles);
#if 0
	// DEPRECATED
	void set_start_user_host(const string &host);
	void set_start_user_nic(const string &dev);
#endif
	void set_start_hidden(bool b);
	void set_config_sip_port(unsigned short port);
	void set_override_sip_port(unsigned short port);
	void set_rtp_port(unsigned short port);
	void set_override_rtp_port(unsigned short port);
	void set_sip_max_udp_size(unsigned short size);
	void set_sip_max_tcp_size(unsigned long size);
	void set_play_ringtone(bool b);
	void set_ringtone_file(const string &file);
	void set_play_ringback(bool b);
	void set_ringback_file(const string &file);
	void set_last_used_profile(const string &profile);
	void set_redial_url(const t_url &url);
	void set_redial_display(const string &display);
	void set_redial_subject(const string &subject);
	void set_redial_profile(const string &profile);
	void set_redial_hide_user(bool b);
	void set_dial_history(const list<string> &history);
	void set_show_display(bool b);
	void set_compact_line_status(bool b);
	void set_show_buddy_list(bool b);
	void set_warn_hide_user(bool b);
	
	// Return "about" text
	string about(bool html) const;
	
	// Return product release date in locale format
	string get_product_date(void) const;
	
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
	
	// Get the directory containing language translation files
	string get_dir_lang(void) const;
	
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
	list<t_audio_device> get_oss_devices(bool playback) const;
	
#ifdef HAVE_LIBASOUND
	// Get all ALSA devices
	list<t_audio_device> get_alsa_devices(bool playback) const;
#endif
	
	// Get all audio devices
	list<t_audio_device> get_audio_devices(bool playback) const;
	
	// Check if two OSS devices are equal
	bool equal_audio_dev(const t_audio_device &dev1, const t_audio_device &dev2) const;
	
	static t_audio_device audio_device(string device = "");
	
	// Check validate the audio devices flagged as true.
	// If audio validation is turned off then always true is returned.
	bool exec_audio_validation(bool ringtone, bool speaker, bool mic, 
		string &error_msg) const;
	
	// Get the active value of the SIP UDP port
	// Once the SIP UDP port is retrieved from the system settings, it
	// is stored as the active port. A next call to get_sip_port
	// returns the active port, even when the SIP UDP port in the settings
	// has changed.
	// If force_active == true, then always the SIP UDP port is returned
	// and made active
	unsigned short get_sip_port(bool force_active = false);
};

extern t_sys_settings *sys_config;

#endif
