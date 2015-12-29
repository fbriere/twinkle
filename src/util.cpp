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

#include <iostream>
#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <sys/time.h>
#include "util.h"

string month_abbrv[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", 
			"Aug", "Sep", "Oct", "Nov", "Dec"};

string random_token(int length) {
	string s;

	for (int i = 0; i < length; i++) {
		s += char(rand() % 26 + 97);
	}

	return s;
}

string random_hexstr(int length) {
	string s;
	int x;

	for (int i = 0; i < length; i++) {
		x = rand() % 15;
		if (x <= 9)
			s += '0' + x;
		else
			s += 'a' + x;
	}

	return s;
}

string float2str(float f, const char *format) {
	char buf[128];

	snprintf(buf, 128, format, f);
	return string(buf);
}

string int2str(int i, const char *format) {
	char buf[32];

	snprintf(buf, 32, format, i);
	return string(buf);
}

string int2str(int i) {
	return int2str(i, "%d");
}

string ulong2str(unsigned long i, const char *format) {
	char buf[32];

	snprintf(buf, 32, format, i);
	return string(buf);
}

string ulong2str(unsigned long i) {
	return ulong2str(i, "%u");
}

string ptr2str(void *p) {
	char buf[32];
	
	snprintf(buf, 32, "%p", p);
	return string(buf);
}

string bool2str(bool b) {
	return (b ? "true" : "false");
}

string time2str(time_t t) {
	string s;
	struct tm tm;
	
	localtime_r(&t, &tm);
	s += int2str(tm.tm_mday, "%02d ");
	assert(tm.tm_mon < 12);
	assert(tm.tm_mon >= 0);
	s += month_abbrv[tm.tm_mon];
	s += ' ';
	s += int2str(tm.tm_year + 1900);
	s += ' ';
	s += int2str(tm.tm_hour, "%02d");
	s += ':';
	s += int2str(tm.tm_min, "%02d");
	s += ':';
	s += int2str(tm.tm_sec, "%02d");
	
	return s;
}

unsigned long hex2int(const string &h) {
	unsigned long u = 0;

	int power = 1;
	for (string::const_reverse_iterator i = h.rbegin(); i != h.rend(); i++) {
		if (*i >= '0' && *i <= '9')
			u += (*i - '0') * power;
		else if (*i >= 'a' && *i <= 'f')
			u += (*i - 'a' + 10) * power;
		else if (*i >= 'A' && *i <= 'F')
			u += (*i - 'A' + 10) * power;

		power = power * 16;
	}

	return u;
}

string tolower(const string &s) {
	string result;

	for (string::const_iterator i = s.begin(); i != s.end(); i++) {
		result += tolower(*i);
	}

	return result;
}

string toupper(const string &s) {
	string result;

	for (string::const_iterator i = s.begin(); i != s.end(); i++) {
		result += toupper(*i);
	}

	return result;
}

string rtrim(const string &s) {
	int i;

	i = s.find_last_not_of(' ');
	if (i == string::npos) return "";
	if (i == s.size()-1) return s;
	return s.substr(0, i+1);
}

string ltrim(const string &s) {
	int i;

	i = s.find_first_not_of(' ');
	if (i == string::npos) return "";
	if (i == 0) return s;
	return s.substr(i, s.size()-i+1);
}

string trim(const string &s) {
	return ltrim(rtrim(s));
}

int cmp_nocase(const string &s1, const string &s2) {
	string::const_iterator i1 = s1.begin();
	string::const_iterator i2 = s2.begin();

	while (i1 != s1.end() && i2 != s2.end()) {
		if (toupper(*i1) != toupper(*i2)) {
			return (toupper(*i1) < toupper(*i2)) ? -1 : 1;
		}
		i1++;
		i2++;
	}

	if (s1.size() == s2.size()) return 0;
	if (s1.size() < s2.size()) return -1;
	return 1;
}

bool must_quote(const string &s) {
	string special("()<>@,;:\\\"/[]?={} \t");

	if (s.size() == 0) return true;
	return (s.find_first_of(special) != string::npos);
}

string escape(const string &s, char c) {
	string result;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '\\' || s[i] == c) {
			result += '\\';
		}
		
		result += s[i];
	}
	
	return result;
}

string unescape(const string &s) {
	string result;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '\\' && i < s.size()) {
			i++;
		}
		
		result += s[i];
	}
	
	return result;
}

list<string> split(const string &s, char c) {
	int i;
	int j = 0;
	list<string> l;

	while (true) {
		i = s.find(c, j);
		if (i == string::npos) {
			l.push_back(s.substr(j));
			return l;
		}

		if (i == j)
			l.push_back("");
		else
			l.push_back(s.substr(j, i-j));

		j = i+1;

		if (j == s.size()) {
			l.push_back("");
			return l;
		}
	}
}

list<string> split_escaped(const string &s, char c) {
	list<string> l;
	
	int start_pos = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '\\') {
			// Skip escaped character
			if (i < s.size()) i++;
			continue;
		}
		
		if (s[i] == c) {
			l.push_back(s.substr(start_pos, i - start_pos));
			start_pos = i + 1;
		}
	}
	
	if (start_pos < s.size()) {
		l.push_back(s.substr(start_pos, s.size() - start_pos));
	} else if (start_pos == s.size()) {
		l.push_back("");
	}
	
	return l;
}

list<string> split_ws(const string &s, bool quote_sensitive) {
        list<string> l;
        bool in_quotes = false;

        int start_pos = 0;
        for (int i = 0; i < s.size(); i++ ) {
                if (quote_sensitive && s[i] == '"') {
                        in_quotes = !in_quotes;
                        continue;
                }

                if (in_quotes) continue;

                if (s[i] == ' ' || s[i] == '\t') {
                        // Skip consecutive white space
                        if (start_pos != i) {
                                l.push_back(s.substr(start_pos, i - start_pos));
                        }
                        start_pos = i + 1;
                }
        }

        if (start_pos < s.size()) {
                l.push_back(s.substr(start_pos, s.size() - start_pos));
        }

        return l;
}

string unquote(const string &s) {
        if (s.size() <= 1) return s;

        if (s[0] == '"' && s[s.size() - 1] == '"')
                return s.substr(1, s.size() - 2);

        return s;
}

bool is_number(const string &s) {
	if (s.empty()) return false;
	
        for (int i = 0; i < s.size(); i++ ) {
		if (!isdigit(s[i])) return false;
	}

	return true;
}

bool is_ipaddr(const string &s) {
	list<string> l = split(s, '.');
	if (l.size() != 4) return false;
	
	for (list<string>::iterator i = l.begin(); i != l.end(); i++) {
		if (!is_number(*i) || atoi(i->c_str()) > 255) return false;
	}
	
	return true;
}

bool yesno2bool(const string &yesno) {
	return (yesno == "yes" ? true : false);
}
string bool2yesno(bool b) {
	return (b ? "yes" : "no");
}

