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

#include "twinkle_config.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/soundcard.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include "sys_settings.h"
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

// Address book settings
#define FLD_AB_SHOW_SIP_ONLY	"ab_show_sip_only"

// Call history fields
#define FLD_CH_MAX_SIZE		"ch_max_size"

// Service settings
#define FLD_CALL_WAITING	"call_waiting"
#define FLD_HANGUP_BOTH_3WAY	"hangup_both_3way"

// Startup settings
#define FLD_START_USER_PROFILE	"start_user_profile"
#define FLD_START_USER_HOST	"start_user_host"
#define FLD_START_HIDDEN	"start_hidden"

// Network settings
#define FLD_SIP_UDP_PORT	"sip_udp_port"
#define FLD_RTP_PORT		"rtp_port"

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
#define FLD_DIAL_HISTORY	"dial_history"

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
	
	ab_show_sip_only = false;
	
	ch_max_size = 50;
	
	call_waiting = true;
	hangup_both_3way = true;
	
	start_user_profiles.clear();
	start_user_host.clear();
	start_hidden = false;
	
	config_sip_udp_port = 5060;
	active_sip_udp_port = 0;
	rtp_port = 8000;
	
	play_ringtone = true;
	ringtone_file.clear();
	play_ringback = true;
	ringback_file.clear();
	
	last_used_profile.clear();
	redial_url.set_url("");
	redial_display.clear();
	redial_subject.clear();
	redial_profile.clear();
	dial_history.clear();
}

string t_sys_settings::about(bool html) const {
	string s = PRODUCT_NAME;
	s += ' ';
	s += PRODUCT_VERSION;
	s += " - ";
	s += PRODUCT_DATE;
	if (html) s += "<BR>";
	s += "\n";
	
	s += "Copyright (C) 2005-2006  ";
	s += PRODUCT_AUTHOR;
	if (html) s += "<BR>";
	s += "\n";

	s += "http://www.twinklephone.com";
	if (html) s += "<BR><BR>";
	s += "\n\n";
	
	string options_built = get_options_built();
	if (!options_built.empty()) {
		s += "Built with support for: ";
		s += options_built;
		if (html) s += "<BR><BR>";
		s += "\n\n";
	}
	
	s += "Contributions:";
	if (html) s += "<BR>";
	s += "\n";
	
	if (html) {
		s += "* Initial code for ALSA support was written by Rickard Petz&auml;ll";
		s += "<BR><BR>";
	} else {
		s += "* Initial code for ALSA support was written by Rickard Petzall";
	}
	s += "\n\n";

	s += "This software contains the following software from 3rd parties:";		
	if (html) s += "<BR>";
	s += "\n";

	s += "* GSM codec from Jutta Degener and Carsten Bormann, University of Berlin";
	if (html) s += "<BR>";
	s += "\n";

	s += "* G.711 codecs from Sun Microsystems (public domain)";	
	if (html) s += "<BR>";
	s += "\n";
	
	s += "* Parts of the STUN project at http://sourceforge.net/projects/stun";
	if (html) s += "<BR>";
	s += "\n";
	
	s += "* Parts of libsrv at http://libsrv.sourceforge.net/";
	if (html) s += "<BR>";
	s += "\n";
	
	if (html) s += "<BR>";
	s += "\n";
	
	s += "For RTP the following dynamic libraries are linked:";
	if (html) s += "<BR>";
	s += "\n";
	
	s += "* GNU ccRTP - http://www.gnu.org/software/ccrtp";
	if (html) s += "<BR>";
	s += "\n";

	s += "* GNU CommonC++ - http://www.gnu.org/software/commoncpp";
	if (html) s += "<BR><BR>";
	s += "\n\n";
	
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
	return options_built;
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
			already_running = true;
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

bool t_sys_settings::read_config(string &error_msg) {
	struct stat stat_buf;
	
	// Check if config file exists
	if (stat(filename.c_str(), &stat_buf) != 0) {
		return true;
	}
	
	// Open config file
	ifstream config(filename.c_str());
	if (!config) {
		error_msg = "Cannot open file for reading: ";
		error_msg += filename;
		return false;
	}
	
	// Read and parse config file.
	while (!config.eof()) {
		string line;
		getline(config, line);

		// Check if read operation succeeded
		if (!config.good() && !config.eof()) {
			error_msg = "File system error while reading file ";
			error_msg += filename;
			return false;
		}

		line = trim(line);

		// Skip empty lines
		if (line.size() == 0) continue;

		// Skip comment lines
		if (line[0] == '#') continue;

		list<string> l = split_on_first(line, '=');
		if (l.size() != 2) {
			error_msg = "Syntax error in file ";
			error_msg += filename;
			error_msg += "\n";
			error_msg += line;
			return false;
		}

		string parameter = trim(l.front());
		string value = trim(l.back());

		if (parameter == FLD_DEV_RINGTONE) {
			dev_ringtone = audio_device(value);
		} else if (parameter == FLD_DEV_SPEAKER) {
			dev_speaker = audio_device(value);
		} else if (parameter == FLD_DEV_MIC) {
			dev_mic = audio_device(value);
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
		} else if (parameter == FLD_AB_SHOW_SIP_ONLY) {
			ab_show_sip_only = yesno2bool(value);
		} else if (parameter == FLD_CH_MAX_SIZE) {
			ch_max_size = atoi(value.c_str());
		} else if (parameter == FLD_CALL_WAITING) {
			call_waiting = yesno2bool(value);
		} else if (parameter == FLD_HANGUP_BOTH_3WAY) {
			hangup_both_3way = yesno2bool(value);
		} else if (parameter == FLD_START_USER_PROFILE) {
			if (!value.empty()) start_user_profiles.push_back(value);
		} else if (parameter == FLD_START_USER_HOST) {
			start_user_host = value;
		} else if (parameter == FLD_START_HIDDEN) {
			start_hidden = yesno2bool(value);
		} else if (parameter == FLD_SIP_UDP_PORT) {
			config_sip_udp_port = atoi(value.c_str());
		} else if (parameter == FLD_RTP_PORT) {
			rtp_port = atoi(value.c_str());
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
		} else if (parameter == FLD_DIAL_HISTORY) {
			dial_history.push_back(value);
		}
			
		// Unknown field names are skipped.
	}
		
	return true;
}

bool t_sys_settings::write_config(string &error_msg) {
	struct stat stat_buf;
	
	// Make a backup of the file if we are editing an existing file, so
	// that can be restored when writing fails.
	string f_backup = filename + '~';
	if (stat(filename.c_str(), &stat_buf) == 0) {
		if (rename(filename.c_str(), f_backup.c_str()) != 0) {
			char *err = strerror(errno);
			error_msg = "Failed to backup ";
			error_msg += filename;
			error_msg += " to ";
			error_msg += f_backup;
			error_msg += "\n";
			error_msg += err;
			return false;
		}
	}
	
	// Open file
	ofstream config(filename.c_str());
	if (!config) {
		error_msg = "Cannot open file for writing: ";
		error_msg += filename;
		return false;
	}
	
	// Write AUDIO settings
	config << "# AUDIO\n";
	config << FLD_DEV_RINGTONE << '=' << dev_ringtone.get_settings_value() << endl;
	config << FLD_DEV_SPEAKER << '=' << dev_speaker.get_settings_value() << endl;
	config << FLD_DEV_MIC << '=' << dev_mic.get_settings_value() << endl;
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
	config << endl;
	
	// Write address book settings
	config << "# Address book\n";
	config << FLD_AB_SHOW_SIP_ONLY << '=' << bool2yesno(ab_show_sip_only) << endl;
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
	config << FLD_START_USER_HOST << '=' << start_user_host << endl;
	config << FLD_START_HIDDEN << '=' << bool2yesno(start_hidden) << endl;
	config << endl;
	
	// Write network settings
	config << "# Network\n";
	config << FLD_SIP_UDP_PORT << '=' << config_sip_udp_port << endl;
	config << FLD_RTP_PORT << '=' << rtp_port << endl;
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

		error_msg = "File system error while writing file ";
		error_msg += filename;
		return false;
	}
	
	return true;
}

list<t_audio_device> t_sys_settings::get_oss_devices(void) const {
	struct stat stat_buf;
	list<t_audio_device> l;
	
	for (int i = -1; i <= 15; i ++) {
		string dev = "/dev/dsp";
		if (i >= 0) dev += int2str(i);
		t_audio_device oss_dev;
		
		// Check if device exists
		if (stat(dev.c_str(), &stat_buf) != 0) continue;
		
		oss_dev.device = dev;
		
		// Get sound card name
		int fd = open(dev.c_str(), O_RDONLY | O_NONBLOCK);
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
				oss_dev.name = "cannot get name (device is busy)";
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
		l.push_back(oss_dev);
	}
	
	return l;
}

#ifdef HAVE_LIBASOUND
// Defined in audio_device.cpp
void alsa_fill_soundcards(list<t_audio_device>& l);

list<t_audio_device> t_sys_settings::get_alsa_devices(void) const {
	t_audio_device defaultDevice;
	defaultDevice.device = "default";
	defaultDevice.name = "Default device";
	defaultDevice.type = t_audio_device::ALSA;
	list<t_audio_device> l;
	l.push_back(defaultDevice);
	
	alsa_fill_soundcards(l);
	
	return l;
}
#endif

list<t_audio_device> t_sys_settings::get_audio_devices(void) const {
	list<t_audio_device> d, d0;
	
#ifdef HAVE_LIBASOUND
	d = get_alsa_devices();
#endif
	d0 = get_oss_devices();
	for (list<t_audio_device>::iterator i = d0.begin(); i != d0.end(); i++) {
		d.push_back(*i);
	}
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

unsigned short t_sys_settings::get_sip_udp_port(void) {
	// The configured port becomes the active port after first
	// usage of the port.
	if (!active_sip_udp_port) {
		active_sip_udp_port = config_sip_udp_port;
	}
	
	return active_sip_udp_port;
}
