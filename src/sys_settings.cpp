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
#include <sys/soundcard.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include "sys_settings.h"
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

// LOG fields
#define FLD_LOG_MAX_SIZE	"log_max_size"
#define FLD_LOG_SHOW_SIP	"log_show_sip"
#define FLD_LOG_SHOW_STUN	"log_show_stun"
#define FLD_LOG_SHOW_MEMORY	"log_show_memory"
#define FLD_LOG_SHOW_DEBUG	"log_show_debug"

string t_oss_device::get_description(void) const {
	string s = device;
	if (sym_link.size() > 0) {
		s += " -> ";
		s += sym_link;
	}
	
	if (name.size() > 0) {
		s += ": ";
		s += name;
	}
	
	return s;
}

t_sys_settings::t_sys_settings() {
	dir_share = DIR_SHARE;
	filename = string(DIR_HOME);
	filename += "/";
	filename += USER_DIR;
	filename += "/";
	filename += SYS_CONFIG_FILE;
	
	// Default settings
	dev_ringtone = DEV_DSP;
	dev_speaker = DEV_DSP;
	dev_mic = DEV_DSP;
	
	log_max_size = 5;
	log_show_sip = true;
	log_show_stun = true;
	log_show_memory = true;
	log_show_debug = false;
}

string t_sys_settings::about(bool html) const {
	string s = PRODUCT_NAME;
	s += ' ';
	s += PRODUCT_VERSION;
	s += " - ";
	s += PRODUCT_DATE;
	if (html) s += "<BR>";
	s += "\n";
	
	s += "Copyright (C) 2005  ";
	s += PRODUCT_AUTHOR;
	if (html) s += "<BR>";
	s += "\n";

	s += "http://www.twinklephone.com";
	if (html) s += "<BR><BR>";
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

bool t_sys_settings::read_config(string &error_msg) {
	struct stat stat_buf;
	
	// Check if config file directory exists
	if (stat(filename.c_str(), &stat_buf) != 0) {
		// There is no config file. Default settings will be used.
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

		list<string> l = split(line, '=');
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
			dev_ringtone = value;
		} else if (parameter == FLD_DEV_SPEAKER) {
			dev_speaker = value;
		} else if (parameter == FLD_DEV_MIC) {
			dev_mic = value;
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
	config << FLD_DEV_RINGTONE << '=' << dev_ringtone << endl;
	config << FLD_DEV_SPEAKER << '=' << dev_speaker << endl;
	config << FLD_DEV_MIC << '=' << dev_mic << endl;
	config << endl;
	
	// Write LOG settings
	config << "# LOG\n";
	config << FLD_LOG_MAX_SIZE << '=' << log_max_size << endl;
	config << FLD_LOG_SHOW_SIP << '=' << bool2yesno(log_show_sip) << endl;
	config << FLD_LOG_SHOW_STUN << '=' << bool2yesno(log_show_stun) << endl;
	config << FLD_LOG_SHOW_MEMORY << '=' << bool2yesno(log_show_memory) << endl;
	config << FLD_LOG_SHOW_DEBUG << '=' << bool2yesno(log_show_debug) << endl;
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

list<t_oss_device> t_sys_settings::get_oss_devices(void) const {
	struct stat stat_buf;
	list<t_oss_device> l;
	
	for (int i = -1; i <= 15; i ++) {
		string dev = "/dev/dsp";
		if (i >= 0) dev += int2str(i);
		t_oss_device oss_dev;
		
		// Check if device exists
		if (stat(dev.c_str(), &stat_buf) != 0) continue;
		
		oss_dev.device = dev;
		
		// Get sound card name
		int fd = open(dev.c_str(), O_RDONLY | O_NONBLOCK);
		if (fd >= 0) {
			struct mixer_info soundcard_info;
			if (ioctl(fd, SOUND_MIXER_INFO, &soundcard_info) != -1) {
				oss_dev.name = soundcard_info.name;
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
		
		l.push_back(oss_dev);
	}
	
	// If no OSS devices can be found (this should not happen), then
	// just add /dev/dsp as the default device.
	if (l.empty()) {
		t_oss_device oss_dev;
		oss_dev.device = "/dev/dsp";
		l.push_back(oss_dev);
	}
	
	return l;
}

bool t_sys_settings::equal_oss_dev(const string &dev1, const string &dev2) const {
	if (dev1 == dev2) return true;
	
	char symlink1[32], symlink2[32];
	int len_link1, len_link2;
	
	len_link1 = readlink(dev1.c_str(), symlink1, 31);
	len_link2 = readlink(dev2.c_str(), symlink2, 31);

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
			return dev2 == symdev1;
		}
	} else {
		if (len_link2 > 0) {
			symlink2[len_link2] = 0;
			string symdev2 = "/dev/";
			symdev2 += symlink2;
			return dev1 == symdev2;
		}
	}
		
	return false;
}
