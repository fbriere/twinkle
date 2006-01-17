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

// NOTE: the date functions are not thread safe

#include <sys/time.h>
#include "hdr_date.h"
#include "definitions.h"
#include "util.h"

string weekday2str(int wkday) {
	switch (wkday) {
	case 0:	return "Sun";
	case 1: return "Mon";
	case 2: return "Tue";
	case 3: return "Wed";
	case 4: return "Thu";
	case 5: return "Fri";
	case 6: return "Sat";
	default: return "XXX";
	}
}

string month2str(int month) {
	switch (month) {
	case 0: return "Jan";
	case 1: return "Feb";
	case 2: return "Mar";
	case 3: return "Apr";
	case 4: return "May";
	case 5: return "Jun";
	case 6: return "Jul";
	case 7: return "Aug";
	case 8: return "Sep";
	case 9: return "Oct";
	case 10: return "Nov";
	case 11: return "Dec";
	default: return "XXX";
	}
}

t_hdr_date::t_hdr_date() : t_header() {}

void t_hdr_date::set_date_gm(struct tm *tm) {
	populated = true;
	date = timegm(tm);
}

void t_hdr_date::set_now(void) {
	struct timeval t;

	populated = true;
	gettimeofday(&t, NULL);
	date = t.tv_sec;
}

string t_hdr_date::encode(void) const {
	string s;
	struct tm tm;

	if (!populated) return s;

	gmtime_r(&date, &tm);
	s = "Date: ";
	s += weekday2str(tm.tm_wday);
	s += ", ";
	s += int2str(tm.tm_mday, "%02d");
	s += ' ';
	s += month2str(tm.tm_mon);
	s += ' ';
	s += int2str(tm.tm_year + 1900, "%04d");
	s += ' ';
	s += int2str(tm.tm_hour, "%02d");
	s += ':';
	s += int2str(tm.tm_min, "%02d");
	s += ':';
	s += int2str(tm.tm_sec, "%02d");
	s += " GMT";
	s += CRLF;

	return s;
}
