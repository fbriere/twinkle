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

#include <cstdio>
#include <iostream>
#include <fstream>
#include <sys/time.h>
#include "log.h"
#include "sys_settings.h"
#include "userintf.h"
#include "user.h"
#include "util.h"

// Maximum size of log file in byte
#define LOG_MAX_SIZE	5000000

// Pointer allocations/de-allocations are not checked by MEMMAN as the
// log file will be deleted after the MEMMAN reports are logged and hence
// would show false memory leaks.

extern t_userintf cli;

bool t_log::move_current_to_old(void) {
        string old_log = log_filename + ".old";
        if (rename(log_filename.c_str(), old_log.c_str()) != 0) {
		return false;
	}

	return true;
}

t_log::t_log() {
	log_disabled = false;

        log_filename = DIR_HOME;
        log_filename += "/";
        log_filename += DIR_USER;
        log_filename += "/";
        log_filename += LOG_FILENAME;

        // If there is a previous log file, then move that to the .old file
        // before zapping the current log file.
        (void)move_current_to_old();

	log_stream = new ofstream(log_filename.c_str());
	if (!*log_stream) {
		log_disabled = true;
		string err = "Failed to create log file ";
		err += log_filename;
		err += "\nLogging is now disabled.";
		ui->cb_show_msg(err, MSG_WARNING);
		return;
	}

	string s = PRODUCT_NAME;
	s += ' ';
	s += PRODUCT_VERSION;
	s += ", ";
	s += PRODUCT_DATE;
	write_report(s, "t_log::t_log");
}

t_log::~t_log() {
	delete log_stream;
}

void t_log::write_report(const string &report, const string &func_name) {
	write_report(report, func_name, LOG_NORMAL, LOG_INFO);
}

void t_log::write_report(const string &report, const string &func_name,
		t_log_class log_class, t_log_severity severity)
{
	if (log_disabled) return;

	write_header(func_name, log_class, severity);
	write_raw(report);
	write_endl();
	write_footer();
}

void t_log::write_header(const string &func_name) {
	write_header(func_name, LOG_NORMAL, LOG_INFO);
}

void t_log::write_header(const string &func_name, t_log_class log_class,
	                  t_log_severity severity)
{
	if (log_disabled) return;

	struct timeval t;
	struct tm tm;
	time_t	date;

	mtx_log.lock();

	gettimeofday(&t, NULL);
	date = t.tv_sec;
	localtime_r(&date, &tm);

	*log_stream << "+++ ";
	*log_stream << tm.tm_mday;
	*log_stream << "-";
	*log_stream << tm.tm_mon + 1;
	*log_stream << "-";
	*log_stream << tm.tm_year + 1900;
	*log_stream << " ";
	*log_stream << int2str(tm.tm_hour, "%02d");
	*log_stream << ":";
	*log_stream << int2str(tm.tm_min, "%02d");
	*log_stream << ":";
	*log_stream << int2str(tm.tm_sec, "%02d");
	*log_stream << " ";

	// Severity
	switch (severity) {
	case LOG_INFO:
		*log_stream << "INFO";
		break;
	case LOG_WARNING:
		*log_stream << "WARNING";
		break;
	case LOG_CRITICAL:
		*log_stream << "CIRITICAL";
		break;
	default:
		*log_stream << "UNNKOWN";
		break;
	}
	*log_stream << " ";

	// Message class
	switch (log_class) {
	case LOG_NORMAL:
		*log_stream << "NORMAL";
		break;
	case LOG_SIP:
		*log_stream << "SIP";
		break;
	case LOG_DEBUG:
		*log_stream << "DEBUG";
		break;
	case LOG_DEBUG_MEM:
		*log_stream << "DEBUG_MEMORY";
		break;
	default:
		*log_stream << "UNNKOWN";
		break;
	}
	*log_stream << " ";

	*log_stream << func_name;
	*log_stream << endl;
}

void t_log::write_footer(void) {
	if (log_disabled) return;

	*log_stream << "---\n\n";
	log_stream->flush();

	// Check if log file is still in a good state
	if (!log_stream->good()) {
		// Log file is bad, disable logging
		log_disabled = true;
		ui->cb_display_msg("Writing to log file failed. Logging disabled.",
			MSG_WARNING);
		mtx_log.unlock();
		return;
	}

	if (log_stream->tellp() >= LOG_MAX_SIZE) {
		log_stream->close();

		if (!move_current_to_old()) {
			// Failed to move log file. Disable logging
			ui->cb_display_msg("Renaming log file failed. Logging disbaled.",
				MSG_WARNING);
			log_disabled = true;
			mtx_log.unlock();
			return;
		}

		delete log_stream;

		log_stream = new ofstream(log_filename.c_str());
		if (!*log_stream) {
			// Failed to create a new log file. Disable logging
			ui->cb_display_msg("Creating log file failed. Logging disbaled.",
				MSG_WARNING);
			log_disabled = true;
			mtx_log.unlock();
			return;
		}
	}

	mtx_log.unlock();
}

void t_log::write_raw(const string &raw) {
	if (log_disabled) return;

	*log_stream << raw;
}

void t_log::write_raw(int raw) {
	if (log_disabled) return;

	*log_stream << raw;
}

void t_log::write_raw(unsigned short raw) {
	if (log_disabled) return;

	*log_stream << raw;
}

void t_log::write_raw(unsigned long raw) {
	if (log_disabled) return;

	*log_stream << raw;
}

void t_log::write_raw(long raw) {
	if (log_disabled) return;

	*log_stream << raw;
}

void t_log::write_endl(void) {
	if (log_disabled) return;

	*log_stream << endl;
}
