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

#include "twinkle_config.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/soundcard.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include "sys_settings.h"
#include "translator.h"
#include "user.h"
#include "userintf.h"
#include "util.h"

// Share directory containing files applicable to all users
#define DIR_SHARE	DATADIR

// Lock file to guarantee that a user is running the application only once
#define LOCK_FILENAME	"twinkle.lck"

// System config file
#define SYS_CONFIG_FILE	"twinkle.sys"

// Field names in the config file
// AUDIO fields
#define FLD_DEV_RINGTONE	"dev_ringtone"
#define FLD_DEV_SPEAKER		"dev_speaker"
#define FLD_DEV_MIC		"dev_mic"
#define FLD_VALIDATE_AUDIO_DEV	"validate_audio_dev"
#define FLD_AU_REDUCE_NOISE_MIC	"au_reduce_noise_mic"
#define FLD_ALSA_PLAY_PERIOD_SIZE	"alsa_play_period_size"
#define FLD_ALSA_CAPTURE_PERIOD_SIZE	"alsa_capture_period_size"
#define FLD_OSS_FRAGMENT_SIZE	"oss_fragment_size"

// LOG fields
#define FLD_LOG_MAX_SIZE	"log_max_size"
#define FLD_LOG_SHOW_SIP	"log_show_sip"
#define FLD_LOG_SHOW_STUN	"log_show_stun"
#define FLD_LOG_SHOW_MEMORY	"log_show_memory"
#define FLD_LOG_SHOW_DEBUG	"log_show_debug"

// GUI settings
#define FLD_GUI_USE_SYSTRAY	"gui_use_systray"
#define FLD_GUI_HIDE_ON_CLOSE	"gui_hide_on_close"
#define FLD_GUI_AUTO_SHOW_INCOMING	"gui_auto_show_incoming"
#define FLD_GUI_AUTO_SHOW_TIMEOUT	"gui_auto_show_timeout"

// Address book settings
#define FLD_AB_SHOW_SIP_ONLY	"ab_show_sip_only"
#define FLD_AB_LOOKUP_NAME	"ab_lookup_name"
#define FLD_AB_OVERRIDE_DISPLAY	"ab_override_display"
#define FLD_AB_LOOKUP_PHOTO	"ab_lookup_photo"

// Call history fields
#define FLD_CH_MAX_SIZE		"ch_max_size"

// Service settings
#define FLD_CALL_WAITING	"call_waiting"
#define FLD_HANGUP_BOTH_3WAY	"hangup_both_3way"

// Startup settings
#define FLD_START_USER_PROFILE	"start_user_profile"
#if 0
// DEPRECATED
#define FLD_START_USER_HOST	"start_user_host"
#define FLD_START_USER_NIC	"start_user_nic"
#endif
#define FLD_START_HIDDEN	"start_hidden"

// Network settings
#define FLD_sip_udp_port	"sip_udp_port"
#define FLD_sip_port		"sip_port"
#define FLD_RTP_PORT		"rtp_port"
#define FLD_SIP_MAX_UDP_SIZE	"sip_max_udp_size"
#define FLD_SIP_MAX_TCP_SIZE	"sip_max_tcp_size"

// Ring tone settings
#define FLD_PLAY_RINGTONE	"play_ringtone"
#define FLD_RINGTONE_FILE	"ringtone_file"
#define FLD_PLAY_RINGBACK	"play_ringback"
#define FLD_RINGBACK_FILE	"ringback_file"

// Persistent storage for user interface state
#define FLD_LAST_USED_PROFILE	"last_used_profile"
#define FLD_REDIAL_URL		"redial_url"
#define FLD_REDIAL_DISPLAY	"redial_display"
#define FLD_REDIAL_SUBJECT	"redial_subject"
#define FLD_REDIAL_PROFILE	"redial_profile"
#define FLD_REDIAL_HIDE_USER	"redial_hide_user"
#define FLD_DIAL_HISTORY	"dial_history"
#define FLD_SHOW_DISPLAY	"show_display"
#define FLD_COMPACT_LINE_STATUS	"compact_line_status"
#define FLD_SHOW_BUDDY_LIST	"show_buddy_list"
#define FLD_WARN_HIDE_USER	"warn_hide_user"

/////////////////////////
// class t_audio_device
/////////////////////////

string t_audio_device::get_description(void) const {
	string s = device;
	if (type == OSS) {
		s = "OSS: " + s;
		if (sym_link.size() > 0) {
			s += " -> ";
			s += sym_link;
		}
		
		if (name.size() > 0) {
			s += ": ";
			s += name;
		}
	} else if (type == ALSA) {
		s = "ALSA: " + s;
		if (!name.empty()) {
			s += ": ";
			s += name;
		}
	} else {
		s = "Unknown: " + s;
	}
	
	return s;
}

string t_audio_device::get_settings_value(void) const {
	string s;
	
	switch (type) {
	case OSS:
		s = PFX_OSS;
		break;
	case ALSA:
		s = PFX_ALSA;
		break;
	default:
		assert(false);
	}
	
	s += device;
	return s;
}


/////////////////////////
// class t_sys_settings
/////////////////////////

t_sys_settings::t_sys_settings() {
	dir_share = DIR_SHARE;
	filename = string(DIR_HOME);
	filename += "/";
	filename += USER_DIR;
	filename += "/";
	filename += SYS_CONFIG_FILE;
	
	// OSS Default settings
	dev_ringtone = audio_device();
	dev_speaker = audio_device();
	dev_mic = audio_device();
	validate_audio_dev = true;
	au_reduce_noise_mic = true;
	alsa_play_period_size = 128;
	alsa_capture_period_size = 32;
	oss_fragment_size = 128;
	
	log_max_size = 5;
	log_show_sip = true;
	log_show_stun = true;
	log_show_memory = true;
	log_show_debug = false;
	
	gui_use_systray = true;
	gui_hide_on_close = true;
	gui_auto_show_incoming = false;
	gui_auto_show_timeout = 10;
	
	ab_show_sip_only = false;
	ab_lookup_name = true;
	ab_override_display = true;
	ab_lookup_photo = true;
	
	ch_max_size = 50;
	
	call_waiting = true;
	hangup_both_3way = true;
	
	start_user_profiles.clear();
#if 0
	// DEPRECATED
	start_user_host.clear();
	start_user_nic.clear();
#endif
	start_hidden = false;
	
	config_sip_port = 5060;
	active_sip_port = 0;
	override_sip_port = 0;
	rtp_port = 8000;
	override_rtp_port = 0;
	sip_max_udp_size = 65535;
	sip_max_tcp_size = 1000000;
	
	play_ringtone = true;
	ringtone_file.clear();
	play_ringback = true;
	ringback_file.clear();
	
	last_used_profile.clear();
	redial_url.set_url("");
	redial_display.clear();
	redial_subject.clear();
	redial_profile.clear();
	redial_hide_user = false;
	dial_history.clear();
	show_display = true;
	compact_line_status = false;
	show_buddy_list = true;
	warn_hide_user = true;
}

// Getters
t_audio_device t_sys_settings::get_dev_ringtone(void) const {
	t_audio_device result;
	mtx_sys.lock();
	result = dev_ringtone;
	mtx_sys.unlock();
	return result;	
}

t_audio_device t_sys_settings::get_dev_speaker(void) const {
	t_audio_device result;
	mtx_sys.lock();
	result = dev_speaker;
	mtx_sys.unlock();
	return result;	
}

t_audio_device t_sys_settings::get_dev_mic(void) const {
	t_audio_device result;
	mtx_sys.lock();
	result = dev_mic;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_validate_audio_dev(void) const {
	bool result;
	mtx_sys.lock();
	result = validate_audio_dev;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_au_reduce_noise_mic(void) const {
	bool result;
	mtx_sys.lock();
	result = au_reduce_noise_mic;
	mtx_sys.unlock();
	return result;	
}

int t_sys_settings::get_alsa_play_period_size(void) const {
	int result;
	mtx_sys.lock();
	result = alsa_play_period_size;
	mtx_sys.unlock();
	return result;	
}

int t_sys_settings::get_alsa_capture_period_size(void) const {
	int result;
	mtx_sys.lock();
	result = alsa_capture_period_size;
	mtx_sys.unlock();
	return result;	
}

int t_sys_settings::get_oss_fragment_size(void) const {
	int result;
	mtx_sys.lock();
	result = oss_fragment_size;
	mtx_sys.unlock();
	return result;	
}

unsigned short t_sys_settings::get_log_max_size(void) const {
	unsigned short result;
	mtx_sys.lock();
	result = log_max_size;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_log_show_sip(void) const {
	bool result;
	mtx_sys.lock();
	result = log_show_sip;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_log_show_stun(void) const {
	bool result;
	mtx_sys.lock();
	result = log_show_stun;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_log_show_memory(void) const {
	bool result;
	mtx_sys.lock();
	result = log_show_memory;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_log_show_debug(void) const {
	bool result;
	mtx_sys.lock();
	result = log_show_debug;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_gui_use_systray(void) const {
	bool result;
	mtx_sys.lock();
	result = gui_use_systray;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_gui_auto_show_incoming(void) const {
	bool result;
	mtx_sys.lock();
	result = gui_auto_show_incoming;
	mtx_sys.unlock();
	return result;
}

int t_sys_settings::get_gui_auto_show_timeout(void) const {
	int result;
	mtx_sys.lock();
	result = gui_auto_show_timeout;
	mtx_sys.unlock();
	return result;
}

bool t_sys_settings::get_gui_hide_on_close(void) const {
	bool result;
	mtx_sys.lock();
	result = gui_hide_on_close;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_ab_show_sip_only(void) const {
	bool result;
	mtx_sys.lock();
	result = ab_show_sip_only;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_ab_lookup_name(void) const {
	bool result;
	mtx_sys.lock();
	result = ab_lookup_name;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_ab_override_display(void) const {
	bool result;
	mtx_sys.lock();
	result = ab_override_display;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_ab_lookup_photo(void) const {
	bool result;
	mtx_sys.lock();
	result = ab_lookup_photo;
	mtx_sys.unlock();
	return result;	
}

int t_sys_settings::get_ch_max_size(void) const {
	int result;
	mtx_sys.lock();
	result = ch_max_size;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_call_waiting(void) const {
	bool result;
	mtx_sys.lock();
	result = call_waiting;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_hangup_both_3way(void) const {
	bool result;
	mtx_sys.lock();
	result = hangup_both_3way;
	mtx_sys.unlock();
	return result;	
}

list<string> t_sys_settings::get_start_user_profiles(void) const {
	list<string> result;
	mtx_sys.lock();
	result = start_user_profiles;
	mtx_sys.unlock();
	return result;	
}

#if 0
// DEPRECATED
string t_sys_settings::get_start_user_host(void) const {
	string result;
	mtx_sys.lock();
	result = start_user_host;
	mtx_sys.unlock();
	return result;	
}

string t_sys_settings::get_start_user_nic(void) const {
	string result;
	mtx_sys.lock();
	result = start_user_nic;
	mtx_sys.unlock();
	return result;
}
#endif

bool t_sys_settings::get_start_hidden(void) const {
	bool result;
	mtx_sys.lock();
	result = start_hidden;
	mtx_sys.unlock();
	return result;	
}

unsigned short t_sys_settings::get_config_sip_port(void) const {
	unsigned short result;
	mtx_sys.lock();
	result = config_sip_port;
	mtx_sys.unlock();
	return result;	
}

unsigned short t_sys_settings::get_rtp_port(void) const {
	unsigned short result;
	mtx_sys.lock();
	if (override_rtp_port > 0) {
		result = override_rtp_port;
	} else {
		result = rtp_port;
	}
	mtx_sys.unlock();
	return result;	
}

unsigned short t_sys_settings::get_sip_max_udp_size(void) const {
	t_mutex_guard guard(mtx_sys);
	return sip_max_udp_size;
}

unsigned long t_sys_settings::get_sip_max_tcp_size(void) const {
	t_mutex_guard guard(mtx_sys);
	return sip_max_tcp_size;
}

bool t_sys_settings::get_play_ringtone(void) const {
	bool result;
	mtx_sys.lock();
	result = play_ringtone;
	mtx_sys.unlock();
	return result;	
}

string t_sys_settings::get_ringtone_file(void) const {
	string result;
	mtx_sys.lock();
	result = ringtone_file;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_play_ringback(void) const {
	bool result;
	mtx_sys.lock();
	result = play_ringback;
	mtx_sys.unlock();
	return result;	
}

string t_sys_settings::get_ringback_file(void) const {
	string result;
	mtx_sys.lock();
	result = ringback_file;
	mtx_sys.unlock();
	return result;	
}

string t_sys_settings::get_last_used_profile(void) const {
	string result;
	mtx_sys.lock();
	result = last_used_profile;
	mtx_sys.unlock();
	return result;	
}

t_url t_sys_settings::get_redial_url(void) const {
	t_url result;
	mtx_sys.lock();
	result = redial_url;
	mtx_sys.unlock();
	return result;	
}

string t_sys_settings::get_redial_display(void) const {
	string result;
	mtx_sys.lock();
	result = redial_display;
	mtx_sys.unlock();
	return result;	
}

string t_sys_settings::get_redial_subject(void) const {
	string result;
	mtx_sys.lock();
	result = redial_subject;
	mtx_sys.unlock();
	return result;	
}

string t_sys_settings::get_redial_profile(void) const {
	string result;
	mtx_sys.lock();
	result = redial_profile;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_redial_hide_user(void) const {
	bool result;
	mtx_sys.lock();
	result = redial_hide_user;
	mtx_sys.unlock();
	return result;
}

list<string> t_sys_settings::get_dial_history(void) const {
	list<string> result;
	mtx_sys.lock();
	result = dial_history;
	mtx_sys.unlock();
	return result;	
}

bool t_sys_settings::get_show_display(void) const {
	bool result;
	mtx_sys.lock();
	result = show_display;
	mtx_sys.unlock();
	return result;
}

bool t_sys_settings::get_compact_line_status(void) const {
	bool result;
	mtx_sys.lock();
	result = compact_line_status;
	mtx_sys.unlock();
	return result;
}

bool t_sys_settings::get_show_buddy_list(void) const {
	bool result;
	mtx_sys.lock();
	result = show_buddy_list;
	mtx_sys.unlock();
	return result;
}

bool t_sys_settings::get_warn_hide_user(void) const {
	bool result;
	mtx_sys.lock();
	result = warn_hide_user;
	mtx_sys.unlock();
	return result;
}


// Setters
void t_sys_settings::set_dev_ringtone(const t_audio_device &dev) {
	mtx_sys.lock();
	dev_ringtone = dev;
	mtx_sys.unlock();
}

void t_sys_settings::set_dev_speaker(const t_audio_device &dev) {
	mtx_sys.lock();
	dev_speaker = dev;
	mtx_sys.unlock();
}

void t_sys_settings::set_dev_mic(const t_audio_device &dev) {
	mtx_sys.lock();
	dev_mic = dev;
	mtx_sys.unlock();
}

void t_sys_settings::set_validate_audio_dev(bool b) {
	mtx_sys.lock();
	validate_audio_dev = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_au_reduce_noise_mic(bool b) {
	mtx_sys.lock();
	au_reduce_noise_mic = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_alsa_play_period_size(int size) {
	mtx_sys.lock();
	alsa_play_period_size = size;
	mtx_sys.unlock();
}

void t_sys_settings::set_alsa_capture_period_size(int size) {
	mtx_sys.lock();
	alsa_capture_period_size = size;
	mtx_sys.unlock();
}

void t_sys_settings::set_oss_fragment_size(int size) {
	mtx_sys.lock();
	oss_fragment_size = size;
	mtx_sys.unlock();
}

void t_sys_settings::set_log_max_size(unsigned short size) {
	mtx_sys.lock();
	log_max_size = size;
	mtx_sys.unlock();
}

void t_sys_settings::set_log_show_sip(bool b) {
	mtx_sys.lock();
	log_show_sip = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_log_show_stun(bool b) {
	mtx_sys.lock();
	log_show_stun = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_log_show_memory(bool b) {
	mtx_sys.lock();
	log_show_memory = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_log_show_debug(bool b) {
	mtx_sys.lock();
	log_show_debug = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_gui_use_systray(bool b) {
	mtx_sys.lock();
	gui_use_systray = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_gui_hide_on_close(bool b) {
	mtx_sys.lock();
	gui_hide_on_close = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_gui_auto_show_incoming(bool b) {
	mtx_sys.lock();
	gui_auto_show_incoming = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_gui_auto_show_timeout(int timeout) {
	mtx_sys.lock();
	gui_auto_show_timeout = timeout;
	mtx_sys.unlock();
}

void t_sys_settings::set_ab_show_sip_only(bool b) {
	mtx_sys.lock();
	ab_show_sip_only = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_ab_lookup_name(bool b) {
	mtx_sys.lock();
	ab_lookup_name = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_ab_override_display(bool b) {
	mtx_sys.lock();
	ab_override_display = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_ab_lookup_photo(bool b) {
	mtx_sys.lock();
	ab_lookup_photo = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_ch_max_size(int size) {
	mtx_sys.lock();
	ch_max_size = size;
	mtx_sys.unlock();
}

void t_sys_settings::set_call_waiting(bool b) {
	mtx_sys.lock();
	call_waiting = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_hangup_both_3way(bool b) {
	mtx_sys.lock();
	hangup_both_3way = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_start_user_profiles(const list<string> &profiles) {
	mtx_sys.lock();
	start_user_profiles = profiles;
	mtx_sys.unlock();
}

#if 0
// DEPRECATED
void t_sys_settings::set_start_user_host(const string &host) {
	mtx_sys.lock();
	start_user_host = host;
	mtx_sys.unlock();
}

void t_sys_settings::set_start_user_nic(const string &dev) {
	mtx_sys.lock();
	start_user_nic = dev;
	mtx_sys.unlock();
}
#endif

void t_sys_settings::set_start_hidden(bool b) {
	mtx_sys.lock();
	start_hidden = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_config_sip_port(unsigned short port) {
	mtx_sys.lock();
	config_sip_port = port;
	mtx_sys.unlock();
}

void t_sys_settings::set_override_sip_port(unsigned short port) {
	mtx_sys.lock();
	override_sip_port = port;
	mtx_sys.unlock();
}

void t_sys_settings::set_rtp_port(unsigned short port) {
	mtx_sys.lock();
	rtp_port = port;
	mtx_sys.unlock();
}

void t_sys_settings::set_override_rtp_port(unsigned short port) {
	mtx_sys.lock();
	override_rtp_port = port;
	mtx_sys.unlock();
}

void t_sys_settings::set_sip_max_udp_size(unsigned short size) {
	t_mutex_guard guard(mtx_sys);
	sip_max_udp_size = size;
}

void t_sys_settings::set_sip_max_tcp_size(unsigned long size) {
	t_mutex_guard guard(mtx_sys);
	sip_max_tcp_size = size;
}

void t_sys_settings::set_play_ringtone(bool b) {
	mtx_sys.lock();
	play_ringtone = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_ringtone_file(const string &file) {
	mtx_sys.lock();
	ringtone_file = file;
	mtx_sys.unlock();
}

void t_sys_settings::set_play_ringback(bool b) {
	mtx_sys.lock();
	play_ringback = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_ringback_file(const string &file) {
	mtx_sys.lock();
	ringback_file = file;
	mtx_sys.unlock();
}

void t_sys_settings::set_last_used_profile(const string &profile) {
	mtx_sys.lock();
	last_used_profile = profile;
	mtx_sys.unlock();
}

void t_sys_settings::set_redial_url(const t_url &url) {
	mtx_sys.lock();
	redial_url = url;
	mtx_sys.unlock();
}

void t_sys_settings::set_redial_display(const string &display) {
	mtx_sys.lock();
	redial_display = display;
	mtx_sys.unlock();
}

void t_sys_settings::set_redial_subject(const string &subject) {
	mtx_sys.lock();
	redial_subject = subject;
	mtx_sys.unlock();
}

void t_sys_settings::set_redial_profile(const string &profile) {
	mtx_sys.lock();
	redial_profile = profile;
	mtx_sys.unlock();
}

void t_sys_settings::set_redial_hide_user(const bool b) {
	mtx_sys.lock();
	redial_hide_user = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_dial_history(const list<string> &history) {
	mtx_sys.lock();
	dial_history = history;
	mtx_sys.unlock();
}

void t_sys_settings::set_show_display(bool b) {
	mtx_sys.lock();
	show_display = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_compact_line_status(bool b) {
	mtx_sys.lock();
	compact_line_status = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_show_buddy_list(bool b) {
	mtx_sys.lock();
	show_buddy_list = b;
	mtx_sys.unlock();
}

void t_sys_settings::set_warn_hide_user(bool b) {
	mtx_sys.lock();
	warn_hide_user = b;
	mtx_sys.unlock();
}


string t_sys_settings::about(bool html) const {
	string s = PRODUCT_NAME;
	s += ' ';
	s += PRODUCT_VERSION;
	s += " - ";
	s += get_product_date();
	if (html) s += "<BR>";
	s += "\n";
	
	s += "Copyright (C) 2005-2008  ";
	s += PRODUCT_AUTHOR;
	if (html) s += "<BR>";
	s += "\n";

	s += "http://www.twinklephone.com";
	if (html) s += "<BR><BR>";
	s += "\n\n";
	
	string options_built = get_options_built();
	if (!options_built.empty()) {
		s += TRANSLATE("Built with support for:");
		s += " ";
		s += options_built;
		if (html) s += "<BR><BR>";
		s += "\n\n";
	}
	
	s += TRANSLATE("Contributions:");
	if (html) s += "<BR>";
	s += "\n";
	
	if (html) {
		s += "* ALSA - Rickard Petz&auml;ll";
		s += "<BR>";
	} else {
		s += "* ALSA - Rickard Petzall";
	}
	s += "\n";
	s += "* ZRTP/SRTP - Werner Dittmann";
	if (html) s += "<BR><BR>";
	s += "\n\n";

	s += TRANSLATE("This software contains the following software from 3rd parties:");		
	if (html) s += "<BR>";
	s += "\n";

	s += TRANSLATE("* GSM codec from Jutta Degener and Carsten Bormann, University of Berlin");
	if (html) s += "<BR>";
	s += "\n";

	s += TRANSLATE("* G.711/G.726 codecs from Sun Microsystems (public domain)");	
	if (html) s += "<BR>";
	s += "\n";
	
#ifdef HAVE_ILBC
	s += TRANSLATE("* iLBC implementation from RFC 3951 (www.ilbcfreeware.org)");	
	if (html) s += "<BR>";
	s += "\n";
#endif
	
	s += TRANSLATE("* Parts of the STUN project at http://sourceforge.net/projects/stun");
	if (html) s += "<BR>";
	s += "\n";
	
	s += TRANSLATE("* Parts of libsrv at http://libsrv.sourceforge.net/");
	if (html) s += "<BR>";
	s += "\n";
	
	if (html) s += "<BR>";
	s += "\n";
	
	s += TRANSLATE("For RTP the following dynamic libraries are linked:");
	if (html) s += "<BR>";
	s += "\n";
	
	s += "* GNU ccRTP - http://www.gnu.org/software/ccrtp";
	if (html) s += "<BR>";
	s += "\n";

	s += "* GNU CommonC++ - http://www.gnu.org/software/commoncpp";
	if (html) s += "<BR><BR>";
	s += "\n\n";
	
	// Display information about translator only on non-english version.
	string translated_by = TRANSLATE("Translated to english by <your name>");
	if (translated_by != "Translated to english by <your name>") {
		s += translated_by;
		if (html) s += "<BR><BR>";
		s += "\n\n";
	}
	
	s += PRODUCT_NAME;
	s += " comes with ABSOLUTELY NO WARRANTY.";
	if (html) s += "<BR>";
	s += "\n";
	
	s += "This program is free software; you can redistribute it and/or modify";
	if (html) s += "<BR>";
	s += "\n";
	
	s += "it under the terms of the GNU General Public License as published by";
	if (html) s += "<BR>";
	s += "\n";
	
	s += "the Free Software Foundation; either version 2 of the License, or";
	if (html) s += "<BR>";
	s += "\n";
	
	s += "(at your option) any later version.";
	if (html) s += "<BR>";
	s += "\n";
	
	return s;
}

string t_sys_settings::get_product_date(void) const {
	struct tm t;
	t.tm_sec = 0;
	t.tm_min = 0;
	t.tm_hour = 0;
	
	vector<string> l = split(PRODUCT_DATE, ' ');
	assert(l.size() == 3);
	t.tm_mon = str2month_full(l[0]);
	t.tm_mday = atoi(l[1].c_str());
	t.tm_year = atoi(l[2].c_str()) - 1900;
	
	char buf[64];
	strftime(buf, 64, "%d %B %Y", &t);
	return string(buf);
}

string t_sys_settings::get_options_built(void) const {
	string options_built;
#ifdef HAVE_LIBASOUND
	if (!options_built.empty()) options_built += ", ";
	options_built += "ALSA";
#endif
#ifdef HAVE_KDE
	if (!options_built.empty()) options_built += ", ";
	options_built += "KDE";
#endif
#ifdef HAVE_SPEEX
	if (!options_built.empty()) options_built += ", ";
	options_built += "Speex";
#endif
#ifdef HAVE_ILBC
	if (!options_built.empty()) options_built += ", ";
	options_built += "iLBC";
#endif
#ifdef HAVE_ZRTP
	if (!options_built.empty()) options_built += ", ";
	options_built += "ZRTP";
#endif

	return options_built;
}

bool t_sys_settings::check_environment(string &error_msg) const {
	struct stat stat_buf;
	string filename, dirname;
	
	mtx_sys.lock();

	// Check if share directory exists
	if (stat(dir_share.c_str(), &stat_buf) != 0) {
		error_msg = TRANSLATE("Directory %1 does not exist.");
		error_msg = replace_first(error_msg, "%1", dir_share);
		mtx_sys.unlock();
		return false;
	}

	// Check if audio file for ring tone exist
	filename = dir_share;
	filename += '/';
	filename += FILE_RINGTONE;
	ifstream f_ringtone(filename.c_str());
	if (!f_ringtone) {
		error_msg = TRANSLATE("Cannot open file %1 .");
		error_msg = replace_first(error_msg, "%1", filename);
		mtx_sys.unlock();
		return false;
	}

	// Check if audio file for ring back exist
	filename = dir_share;
	filename += '/';
	filename += FILE_RINGBACK;
	ifstream f_ringback(filename.c_str());
	if (!f_ringback) {
		error_msg = TRANSLATE("Cannot open file %1 .");
		error_msg = replace_first(error_msg, "%1", filename);
		mtx_sys.unlock();
		return false;
	}

	// Check if $HOME is set correctly
	if (string(DIR_HOME) == "") {
		error_msg = TRANSLATE("%1 is not set to your home directory.");
		error_msg = replace_first(error_msg, "%1", "$HOME");
		mtx_sys.unlock();
		return false;
	}
	if (stat(DIR_HOME, &stat_buf) != 0) {
		error_msg = TRANSLATE("Directory %1 (%2) does not exist.");
		error_msg = replace_first(error_msg, "%1", DIR_HOME);
		error_msg = replace_first(error_msg, "%2", "$HOME");	
		mtx_sys.unlock();
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
			error_msg = TRANSLATE("Cannot create directory %1 .");
			error_msg = replace_first(error_msg, "%1", dirname);
			mtx_sys.unlock();
			return false;
		}
	}

	mtx_sys.unlock();
	return true;
}

void t_sys_settings::set_dir_share(const string &dir) {
	mtx_sys.lock();
	dir_share = dir;
	mtx_sys.unlock();
}

string t_sys_settings::get_dir_share(void) const {
	string result;
	mtx_sys.lock();
	result = dir_share;
	mtx_sys.unlock();
	return result;
}

string t_sys_settings::get_dir_lang(void) const {
	string result = get_dir_share();
	result += "/lang";
	return result;
}

string t_sys_settings::get_dir_user(void) const {
	string dir = DIR_HOME;
	dir += "/";
	dir += DIR_USER;
	
	return dir;
}

bool t_sys_settings::create_lock_file(string &error_msg, bool &already_running) const {
	struct stat stat_buf;
	string lck_filename;
	already_running = false;

        lck_filename = DIR_HOME;
        lck_filename += "/";
        lck_filename += DIR_USER;
        lck_filename += "/";
        lck_filename += LOCK_FILENAME;

	// Check if a lock file already exists
	if (stat(lck_filename.c_str(), &stat_buf) == 0) {
		ifstream f(lck_filename.c_str());
		if (!f) {
			error_msg =  TRANSLATE("Lock file %1 already exist, but cannot be opened.");
			error_msg = replace_first(error_msg, "%1", lck_filename);
			return false;
		}

		// Check if lock is stale
		pid_t lock_pid;
		f >> lock_pid;
		if (kill(lock_pid, 0) == 0) {
			// The pid in the lock file exists, so Twinkle is
			// already running.
			already_running = true;
			error_msg = TRANSLATE("%1 is already running.\nLock file %2 already exists.");
			error_msg = replace_first(error_msg, "%1", PRODUCT_NAME);
			error_msg = replace_first(error_msg, "%2", lck_filename);
			return false;
		}

		// The lock is stale; delete it
		f.close();
		unlink(lck_filename.c_str());
	}

	// Create lock file
	ofstream f(lck_filename.c_str());
	if (!f) {
		error_msg = TRANSLATE("Cannot create %1 .");
		error_msg = replace_first(error_msg, "%1", lck_filename);
		return false;
	}

	f << getpid();
	if (!f.good()) {
		error_msg = TRANSLATE("Cannot write to %1 .");
		error_msg = replace_first(error_msg, "%1", lck_filename);
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

bool t_sys_settings::read_config(string &error_msg) {
	struct stat stat_buf;
	
	mtx_sys.lock();
	
	// Check if config file exists
	if (stat(filename.c_str(), &stat_buf) != 0) {
		mtx_sys.unlock();
		return true;
	}
	
	// Open config file
	ifstream config(filename.c_str());
	if (!config) {
		error_msg = TRANSLATE("Cannot open file for reading: %1");
		error_msg = replace_first(error_msg, "%1", filename);
		mtx_sys.unlock();
		return false;
	}
	
	// Read and parse config file.
	while (!config.eof()) {
		string line;
		getline(config, line);

		// Check if read operation succeeded
		if (!config.good() && !config.eof()) {
			error_msg = TRANSLATE("File system error while reading file %1 .");
			error_msg = replace_first(error_msg, "%1", filename);
			mtx_sys.unlock();
			return false;
		}

		line = trim(line);

		// Skip empty lines
		if (line.size() == 0) continue;

		// Skip comment lines
		if (line[0] == '#') continue;

		vector<string> l = split_on_first(line, '=');
		if (l.size() != 2) {
			error_msg = TRANSLATE("Syntax error in file %1 .");
			error_msg = replace_first(error_msg, "%1", filename);
			error_msg += "\n";
			error_msg += line;
			mtx_sys.unlock();
			return false;
		}

		string parameter = trim(l[0]);
		string value = trim(l[1]);

		if (parameter == FLD_DEV_RINGTONE) {
			dev_ringtone = audio_device(value);
		} else if (parameter == FLD_DEV_SPEAKER) {
			dev_speaker = audio_device(value);
		} else if (parameter == FLD_DEV_MIC) {
			dev_mic = audio_device(value);
		} else if (parameter == FLD_VALIDATE_AUDIO_DEV) {
			validate_audio_dev = yesno2bool(value);
		} else if (parameter == FLD_AU_REDUCE_NOISE_MIC) {
			au_reduce_noise_mic = yesno2bool(value);
		} else if (parameter == FLD_ALSA_PLAY_PERIOD_SIZE) {
			alsa_play_period_size = atoi(value.c_str());
		} else if (parameter == FLD_ALSA_CAPTURE_PERIOD_SIZE) {
			alsa_capture_period_size = atoi(value.c_str());
		} else if (parameter == FLD_OSS_FRAGMENT_SIZE) {
			oss_fragment_size = atoi(value.c_str());
		} else if (parameter == FLD_LOG_MAX_SIZE) {
			log_max_size = atoi(value.c_str());
		} else if (parameter == FLD_LOG_SHOW_SIP) {
			log_show_sip = yesno2bool(value);
		} else if (parameter == FLD_LOG_SHOW_STUN) {
			log_show_stun = yesno2bool(value);
		} else if (parameter == FLD_LOG_SHOW_MEMORY) {
			log_show_memory = yesno2bool(value);
		} else if (parameter == FLD_LOG_SHOW_DEBUG) {
			log_show_debug = yesno2bool(value);
		} else if (parameter == FLD_GUI_USE_SYSTRAY) {
			gui_use_systray = yesno2bool(value);
		} else if (parameter == FLD_GUI_HIDE_ON_CLOSE) {
			gui_hide_on_close = yesno2bool(value);
		} else if (parameter == FLD_GUI_AUTO_SHOW_INCOMING) {
			gui_auto_show_incoming = yesno2bool(value);
		} else if (parameter == FLD_GUI_AUTO_SHOW_TIMEOUT) {
			gui_auto_show_timeout = atoi(value.c_str());
		} else if (parameter == FLD_AB_SHOW_SIP_ONLY) {
			ab_show_sip_only = yesno2bool(value);
		} else if (parameter == FLD_AB_LOOKUP_NAME) {
			ab_lookup_name = yesno2bool(value);
		} else if (parameter == FLD_AB_OVERRIDE_DISPLAY) {
			ab_override_display = yesno2bool(value);
		} else if (parameter == FLD_AB_LOOKUP_PHOTO) {
			ab_lookup_photo = yesno2bool(value);
		} else if (parameter == FLD_CH_MAX_SIZE) {
			ch_max_size = atoi(value.c_str());
		} else if (parameter == FLD_CALL_WAITING) {
			call_waiting = yesno2bool(value);
		} else if (parameter == FLD_HANGUP_BOTH_3WAY) {
			hangup_both_3way = yesno2bool(value);
		} else if (parameter == FLD_START_USER_PROFILE) {
			if (!value.empty()) start_user_profiles.push_back(value);
#if 0
		// DEPRECATED
		} else if (parameter == FLD_START_USER_HOST) {
			start_user_host = value;
		} else if (parameter == FLD_START_USER_NIC) {
			start_user_nic = value;
#endif
		} else if (parameter == FLD_START_HIDDEN) {
			start_hidden = yesno2bool(value);
		} else if (parameter == FLD_sip_udp_port) { // Deprecated parameter
			config_sip_port = atoi(value.c_str());
		} else if (parameter == FLD_sip_port) {
			config_sip_port = atoi(value.c_str());
		} else if (parameter == FLD_RTP_PORT) {
			rtp_port = atoi(value.c_str());
		} else if (parameter == FLD_SIP_MAX_UDP_SIZE) {
			sip_max_udp_size = atoi(value.c_str());
		} else if (parameter == FLD_SIP_MAX_TCP_SIZE) {
			sip_max_tcp_size = atoi(value.c_str());
		} else if (parameter == FLD_PLAY_RINGTONE) {
			play_ringtone = yesno2bool(value);
		} else if (parameter == FLD_RINGTONE_FILE) {
			ringtone_file = value;
		} else if (parameter == FLD_PLAY_RINGBACK) {
			play_ringback = yesno2bool(value);
		} else if (parameter == FLD_RINGBACK_FILE) {
			ringback_file = value;
		} else if (parameter == FLD_LAST_USED_PROFILE) {
			last_used_profile = value;
		} else if (parameter == FLD_REDIAL_URL) {
			redial_url.set_url(value);
			if (!redial_url.is_valid()) {
				redial_url.set_url("");
			}
		} else if (parameter == FLD_REDIAL_DISPLAY) {
			redial_display = value;
		} else if (parameter == FLD_REDIAL_SUBJECT) {
			redial_subject = value;
		} else if (parameter == FLD_REDIAL_PROFILE) {
			redial_profile = value;
		} else if (parameter == FLD_REDIAL_HIDE_USER) {
			redial_hide_user = yesno2bool(value);
		} else if (parameter == FLD_DIAL_HISTORY) {
			dial_history.push_back(value);
		} else if (parameter == FLD_SHOW_DISPLAY) {
			show_display = yesno2bool(value);
		} else if (parameter == FLD_COMPACT_LINE_STATUS) {
			//compact_line_status = yesno2bool(value);
		} else if (parameter == FLD_SHOW_BUDDY_LIST) {
			show_buddy_list = yesno2bool(value);
		} else if (parameter == FLD_WARN_HIDE_USER) {
			warn_hide_user = yesno2bool(value);
		}
			
		// Unknown field names are skipped.
	}
		
	mtx_sys.unlock();
	return true;
}

bool t_sys_settings::write_config(string &error_msg) {
	struct stat stat_buf;
	
	mtx_sys.lock();
	
	// Make a backup of the file if we are editing an existing file, so
	// that can be restored when writing fails.
	string f_backup = filename + '~';
	if (stat(filename.c_str(), &stat_buf) == 0) {
		if (rename(filename.c_str(), f_backup.c_str()) != 0) {
			string err = get_error_str(errno);
			error_msg = TRANSLATE("Failed to backup %1 to %2");
			error_msg = replace_first(error_msg, "%1", filename);
			error_msg = replace_first(error_msg, "%2", f_backup);
			error_msg += "\n";
			error_msg += err;
			mtx_sys.unlock();
			return false;
		}
	}
	
	// Open file
	ofstream config(filename.c_str());
	if (!config) {
		error_msg = TRANSLATE("Cannot open file for writing: %1");
		error_msg = replace_first(error_msg, "%1", filename);
		mtx_sys.unlock();
		return false;
	}
	
	// Write AUDIO settings
	config << "# AUDIO\n";
	config << FLD_DEV_RINGTONE << '=' << dev_ringtone.get_settings_value() << endl;
	config << FLD_DEV_SPEAKER << '=' << dev_speaker.get_settings_value() << endl;
	config << FLD_DEV_MIC << '=' << dev_mic.get_settings_value() << endl;
	config << FLD_VALIDATE_AUDIO_DEV << '=' << bool2yesno(validate_audio_dev) << endl;
	config << FLD_AU_REDUCE_NOISE_MIC << '=' << bool2yesno(au_reduce_noise_mic) << endl;
	config << FLD_ALSA_PLAY_PERIOD_SIZE << '=' << alsa_play_period_size << endl;
	config << FLD_ALSA_CAPTURE_PERIOD_SIZE << '=' << alsa_capture_period_size << endl;
	config << FLD_OSS_FRAGMENT_SIZE << '=' << oss_fragment_size << endl;
	config << endl;
	
	// Write LOG settings
	config << "# LOG\n";
	config << FLD_LOG_MAX_SIZE << '=' << log_max_size << endl;
	config << FLD_LOG_SHOW_SIP << '=' << bool2yesno(log_show_sip) << endl;
	config << FLD_LOG_SHOW_STUN << '=' << bool2yesno(log_show_stun) << endl;
	config << FLD_LOG_SHOW_MEMORY << '=' << bool2yesno(log_show_memory) << endl;
	config << FLD_LOG_SHOW_DEBUG << '=' << bool2yesno(log_show_debug) << endl;
	config << endl;
	
	// Write GUI settings
	config << "# GUI\n";
	config << FLD_GUI_USE_SYSTRAY << '=' << bool2yesno(gui_use_systray) << endl;
	config << FLD_GUI_HIDE_ON_CLOSE << '=' << bool2yesno(gui_hide_on_close) << endl;
	config << FLD_GUI_AUTO_SHOW_INCOMING << '=' << bool2yesno(gui_auto_show_incoming) << endl;
	config << FLD_GUI_AUTO_SHOW_TIMEOUT << '=' << gui_auto_show_timeout << endl;
	config << endl;
	
	// Write address book settings
	config << "# Address book\n";
	config << FLD_AB_SHOW_SIP_ONLY << '=' << bool2yesno(ab_show_sip_only) << endl;
	config << FLD_AB_LOOKUP_NAME << '=' << bool2yesno(ab_lookup_name) << endl;
	config << FLD_AB_OVERRIDE_DISPLAY << '=' << bool2yesno(ab_override_display) << endl;
	config << FLD_AB_LOOKUP_PHOTO << '=' << bool2yesno(ab_lookup_photo) << endl;
	config << endl;
	
	// Write call history settings
	config << "# Call history\n";
	config << FLD_CH_MAX_SIZE << '=' << ch_max_size << endl;
	config << endl;
	
	// Write service settings
	config << "# Services\n";
	config << FLD_CALL_WAITING << '=' << bool2yesno(call_waiting) << endl;
	config << FLD_HANGUP_BOTH_3WAY << '=' << bool2yesno(hangup_both_3way) << endl;
	config << endl;
	
	// Write startup settings
	config << "# Startup\n";
	
	for (list<string>::iterator i = start_user_profiles.begin();
	     i != start_user_profiles.end(); i++)
	{
		config << FLD_START_USER_PROFILE << '=' << *i << endl;
	}
#if 0
	// DEPRECATED
	config << FLD_START_USER_HOST << '=' << start_user_host << endl;
	config << FLD_START_USER_NIC  << '=' << start_user_nic << endl;
#endif
	config << FLD_START_HIDDEN << '=' << bool2yesno(start_hidden) << endl;
	config << endl;
	
	// Write network settings
	config << "# Network\n";
	config << FLD_sip_port << '=' << config_sip_port << endl;
	config << FLD_RTP_PORT << '=' << rtp_port << endl;
	config << FLD_SIP_MAX_UDP_SIZE << '=' << sip_max_udp_size << endl;
	config << FLD_SIP_MAX_TCP_SIZE << '=' << sip_max_tcp_size << endl;
	config << endl;
	
	// Write ring tone settings
	config << "# Ring tones\n";
	config << FLD_PLAY_RINGTONE << '=' << bool2yesno(play_ringtone) << endl;
	config << FLD_RINGTONE_FILE << '=' << ringtone_file << endl;
	config << FLD_PLAY_RINGBACK << '=' << bool2yesno(play_ringback) << endl;
	config << FLD_RINGBACK_FILE << '=' << ringback_file << endl;
	config << endl;
	
	// Write persistent user interface state
	config << "# Persistent user interface state\n";
	config << FLD_LAST_USED_PROFILE << '=' << last_used_profile << endl;
	config << FLD_REDIAL_URL << '=' << redial_url.encode() << endl;
	config << FLD_REDIAL_DISPLAY << '=' << redial_display << endl; 
	config << FLD_REDIAL_SUBJECT << '=' << redial_subject << endl;
	config << FLD_REDIAL_PROFILE << '=' << redial_profile << endl;
	config << FLD_REDIAL_HIDE_USER << '=' << bool2yesno(redial_hide_user) << endl;
	config << FLD_SHOW_DISPLAY << '=' << bool2yesno(show_display) << endl;
	//config << FLD_COMPACT_LINE_STATUS << '=' << bool2yesno(compact_line_status) << endl;
	config << FLD_SHOW_BUDDY_LIST << '=' << bool2yesno(show_buddy_list) << endl;
	config << FLD_WARN_HIDE_USER << '=' << bool2yesno(warn_hide_user) << endl;
	
	for (list<string>::iterator i = dial_history.begin();
	     i != dial_history.end(); i++)
	{
		config << FLD_DIAL_HISTORY << '=' << *i << endl;
	}
	
	config << endl;
	
	// Check if writing succeeded
	if (!config.good()) {
		// Restore backup
		config.close();
		rename(f_backup.c_str(), filename.c_str());

		error_msg = TRANSLATE("File system error while writing file %1 .");
		error_msg = replace_first(error_msg, "%1", filename);
		mtx_sys.unlock();
		return false;
	}
	
	mtx_sys.unlock();
	return true;
}

list<t_audio_device> t_sys_settings::get_oss_devices(bool playback) const {
	struct stat stat_buf;
	list<t_audio_device> l;
	
	for (int i = -1; i <= 15; i ++) {
		string dev = "/dev/dsp";
		if (i >= 0) dev += int2str(i);
		t_audio_device oss_dev;
		oss_dev.type = t_audio_device::OSS;
		
		// Check if device exists
		if (stat(dev.c_str(), &stat_buf) != 0) continue;
		
		oss_dev.device = dev;
		
		// Get sound card name
		int fd;
		
		if (playback) {
			fd = open(dev.c_str(), O_WRONLY | O_NONBLOCK);
		} else {
			fd = open(dev.c_str(), O_RDONLY | O_NONBLOCK);
		}
		
		if (fd >= 0) {
			struct mixer_info soundcard_info;
			if (ioctl(fd, SOUND_MIXER_INFO, &soundcard_info) != -1) {
				oss_dev.name = "";
				oss_dev.name += soundcard_info.name;
				oss_dev.name += " (";
				oss_dev.name += soundcard_info.id;
				oss_dev.name += ")";
			}
			
			close(fd);
		} else {
			if (errno == EBUSY) {
				oss_dev.name = TRANSLATE("unknown name (device is busy)");
			} else {
				// Device is not available.
				continue;
			}
		}
		
		// Check if the device is a symbolic link
		char buf[32];
		int len_link;
		if ((len_link = readlink(dev.c_str(), buf, 31)) != -1) {
			buf[len_link] = 0;
			oss_dev.sym_link = buf;
		}
		oss_dev.type = t_audio_device::OSS;
		l.push_back(oss_dev);
	}
	
	// If no OSS devices can be found (this should not happen), then
	// just add /dev/dsp as the default device.
	if (l.empty()) {
		t_audio_device oss_dev;
		oss_dev.device = "/dev/dsp";
		oss_dev.type = t_audio_device::OSS;
		l.push_back(oss_dev);
	}
	
	// Add other device option
	t_audio_device other_dev;
	other_dev.device = DEV_OTHER;
	other_dev.type = t_audio_device::OSS;
	l.push_back(other_dev);
	
	return l;
}

#ifdef HAVE_LIBASOUND
// Defined in audio_device.cpp
void alsa_fill_soundcards(list<t_audio_device>& l, bool playback);

list<t_audio_device> t_sys_settings::get_alsa_devices(bool playback) const {
	t_audio_device defaultDevice;
	defaultDevice.device = "default";
	defaultDevice.name = TRANSLATE("Default device");
	defaultDevice.type = t_audio_device::ALSA;
	list<t_audio_device> l;
	l.push_back(defaultDevice);
	
	alsa_fill_soundcards(l, playback);
	
	// Add other device option
	t_audio_device other_dev;
	other_dev.device = DEV_OTHER;
	other_dev.type = t_audio_device::ALSA;
	l.push_back(other_dev);
	
	return l;
}
#endif

list<t_audio_device> t_sys_settings::get_audio_devices(bool playback) const {
	list<t_audio_device> d, d0;
	
#ifdef HAVE_LIBASOUND
	d = get_alsa_devices(playback);
#endif
	d0 = get_oss_devices(playback);
	d.insert(d.end(), d0.begin(), d0.end());
	return d;
}

bool t_sys_settings::equal_audio_dev(const t_audio_device &dev1, const t_audio_device &dev2) const {
	if (dev1.type == t_audio_device::OSS) {
		if (dev2.type != t_audio_device::OSS) return false;
		if (dev1.device == dev2.device) return true;
		
		char symlink1[32], symlink2[32];
		int len_link1, len_link2;
		
		len_link1 = readlink(dev1.device.c_str(), symlink1, 31);
		len_link2 = readlink(dev2.device.c_str(), symlink2, 31);
	
		if (len_link1 > 0) {
			symlink1[len_link1] = 0;
			string symdev1 = "/dev/";
			symdev1 += symlink1;
			if (len_link2 > 0) {
				symlink2[len_link2] = 0;
				string symdev2 = "/dev/";
				symdev2 += symlink2;
				return symdev1 == symdev2;
			} else {
				return dev2.device == symdev1;
			}
		} else {
			if (len_link2 > 0) {
				symlink2[len_link2] = 0;
				string symdev2 = "/dev/";
				symdev2 += symlink2;
				return dev1.device == symdev2;
			}
		}
	} else if (dev1.type == t_audio_device::ALSA) {
		if (dev2.type != t_audio_device::ALSA) return false;
		return dev1.device == dev2.device;
	}
		
	return false;
}


t_audio_device t_sys_settings::audio_device(string device) {
	t_audio_device d;

	if (device.empty()) device = DEV_DSP; //This is the default device
	
	if (device.substr(0, strlen(PFX_OSS)) == PFX_OSS) {
		// OSS device
		d.device = device.substr(strlen(PFX_OSS));
		d.type = t_audio_device::OSS;
		d.name = "";
		char symlink[32];
		int len_link = readlink(device.c_str(), symlink, 31);
		if(len_link > 0) {
			d.sym_link = symlink;
		}
	} else if (device.substr(0, strlen(PFX_ALSA)) == PFX_ALSA) {
		// ALSA device
		d.device = device.substr(strlen(PFX_ALSA));
		d.type = t_audio_device::ALSA;
		d.name = "";
		d.sym_link = "";
	} else {
		// Assume it is an OSS device. Version 0.2.1 and lower
		// only supported OSS and the value only consisted of
		// the device name without "oss:"
		d.device = device;
		d.type = t_audio_device::OSS;
		d.name = "";
		char symlink[32];
		int len_link = readlink(device.c_str(), symlink, 31);
		if(len_link > 0) {
			d.sym_link = symlink;
		}
	}
	
	return d;	
}

bool t_sys_settings::exec_audio_validation(bool ringtone, bool speaker, bool mic, 
	string &error_msg) const 
{
	error_msg.clear();
	if (!validate_audio_dev) return true;
	
	bool valid = true;
	bool full_duplex = speaker && mic && equal_audio_dev(dev_speaker, dev_mic);
	
	if (ringtone && !t_audio_io::validate(dev_ringtone, true, false)) {
		string msg = TRANSLATE("Cannot access the ring tone device (%1).");
		error_msg += replace_first(msg, "%1", dev_ringtone.get_description());
		error_msg += "\n";
		valid = false;
	}
	if (speaker && !t_audio_io::validate(dev_speaker, true, full_duplex)) {
		string msg = TRANSLATE("Cannot access the speaker (%1).");
		error_msg += replace_first(msg, "%1", dev_speaker.get_description());
		error_msg += "\n";
		valid = false;
	}
	if (mic && !t_audio_io::validate(dev_mic, full_duplex, true)) {
		string msg = TRANSLATE("Cannot access the microphone (%1).");
		error_msg += replace_first(msg, "%1", dev_mic.get_description());
		error_msg += "\n";
		valid = false;
	}
	
	return valid;
}

unsigned short t_sys_settings::get_sip_port(bool force_active) {
	mtx_sys.lock();
	
	// The configured port becomes the active port after first
	// usage of the port.
	if (!active_sip_port || force_active) {
		if (override_sip_port > 0) {
			// The port provided on the command line overrides
			// the configured port.
			active_sip_port = override_sip_port;
		} else {
			active_sip_port = config_sip_port;
		}
	}
	
	mtx_sys.unlock();
	return active_sip_port;
}
