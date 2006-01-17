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

#ifndef _UTIL_H
#define _UTIL_H

#include <list>
#include <string>

using namespace std;

string random_token(int length);
string random_hexstr(int length);

// Convert a float to a string. format is a printf format
string float2str(float f, const char *format);

// Convert an int to a string. format is a printf format
string int2str(int i, const char *format);
string int2str(int i);

// Convert a ulong to a string. format is a printf format
string ulong2str(unsigned long i, const char *format);
string ulong2str(unsigned long i);

// Convert a pointer to a string (hexadecimal)
string ptr2str(void *p);

// Convert a bool to a string: "false", "true"
string bool2str(bool b);

// Convert time/dat to string
string time2str(time_t t);

// Convert a hex string to an integer
unsigned long hex2int(const string &h);

// Convert a string to lower case
string tolower(const string &s);

// Convert a string to upper case
string toupper(const string &s);

// Trim a string
string rtrim(const string &s);
string ltrim(const string &s);
string trim(const string &s);

// Compare 2 strings case insensive, return
// -1 --> s1 < s2
// 0  --> s1 == s2
// 1  --> s1 > s2
int cmp_nocase(const string &s1, const string &s2);

// Return true if a string must be quoted in text encoding
bool must_quote(const string &s);

// Escape character c in string by prepending it with a backslash.
// Backslashed are automatically escaped as well
string escape(const string &s, char c);

// Unescape a string
string unescape(const string &s);

// Split a string into elements using c as a separator
list<string> split(const string &s, char c);

// Split an escaped string into elements using c as a separator
// Escaped means: \c will not be seen as a seperator and backslash is
//                escaped itself (\\)
list<string> split_escaped(const string &s, char c);

// Split a string into elements using spaces as separator
// If quote_sensitive = true, then spaces within quoted strings will
// not be used to split the string.
list<string> split_ws(const string &s, bool quote_sensitive = false);

// Remove surrounding quotes of a string if present.
string unquote(const string &s);

// Check if a string is a number
bool is_number(const string &s);

// Check if a string is an IP address
bool is_ipaddr(const string &s);

// Conversion between yes/no values and bool
bool yesno2bool(const string &yesno);
string bool2yesno(bool b);

#endif
