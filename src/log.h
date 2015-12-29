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

#ifndef _LOG_H
#define _LOG_H

#include <string>
#include <fstream>
#include "threads/mutex.h"

using namespace std;

#define LOG_FILENAME    "twinkle.log"

// Severity of a log message
enum t_log_severity {
	LOG_INFO,
	LOG_WARNING,
	LOG_CRITICAL
};

// Message class
enum t_log_class {
	LOG_NORMAL,
	LOG_SIP,
	LOG_DEBUG,
	LOG_DEBUG_MEM
};

class t_log {
private:
        string          log_filename;
        ofstream        *log_stream;

	// Mutex for exclusive acces to the log file
	t_mutex		mtx_log;

	// Indicates if logging is disabled
	bool		log_disabled;

        // Move the current log file to the .old log file
        bool move_current_to_old(void);

public:
        t_log();
        ~t_log();

        // Write a report with header and footer
        void write_report(const string &report, const string &func_name); // normal, info
	void write_report(const string &report, const string &func_name,
		t_log_class log_class, t_log_severity severity);

        // Write header
	// This locks the mtx_log. So you must call write footer to release
	// the log again!
        void write_header(const string &func_name); // class normal, severity info
	void write_header(const string &func_name, t_log_class log_class,
	                  t_log_severity severity = LOG_INFO);

        // Write footer
	// This unlocks the mtx_log.
        void write_footer(void);

        // Write raw data
        void write_raw(const string &raw);
        void write_raw(int raw);
        void write_raw(unsigned short raw);
        void write_raw(unsigned long raw);
	void write_raw(long raw);

        // Write end of line
        void write_endl(void);
};

extern t_log *log_file;

#endif
