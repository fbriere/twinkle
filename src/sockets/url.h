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

#ifndef _H_URL
#define _H_URL

#include <list>
#include <string>

using namespace std;

class t_ip_port {
public:
	unsigned long	ipaddr;
	unsigned short	port;
	
	t_ip_port() {};
	t_ip_port(unsigned long _ipaddr, unsigned short _port);
};

// Return the default port for a protocol (host order)
unsigned short get_default_port(const string &protocol);

// Return the first IP address of host name.
// Return 0 if no IP address can be found.
unsigned long gethostbyname(const string &name);

// Return all IP address of host name
list<unsigned long> gethostbyname_all(const string &name);

class t_url {
private:
	string		scheme;
	string		user;
	string		password;
	string		host;
	unsigned short	port; 		// host order

	// parameters
	string		transport;
	string		maddr;
	bool		lr;
	string		user_param;
	string		method;
	int		ttl;
	string		other_params;	// unparsed other parameters

	// headers
	string		headers;	// unparsed headers

	bool		user_url;	// true -> user url
					// false -> machine
	bool		valid;		// indicates if the url is valid

	string		text_format;	// url in string format

	void construct_user_url(const string &s);    // eg sip:, mailto:
	void construct_machine_url(const string &s); // eg http:, ftp:

	// Parse uri parameters and headers. Returns false if parsing
	// fails.
	bool parse_params_headers(const string &s);

public:
	t_url();
	t_url(const string &s);

	void set_url(const string &s);

	// Returns "" or 0 if item cannot be found
	string get_scheme(void) const;
	string get_user(void) const;
	string get_password(void) const;
	string get_host(void) const;

	// The following methods will return the default port if
	// no port is present in the url.
	int get_nport(void) const; // Get port in network order.
	int get_hport(void) const; // get port in host order.

	// The following method returns 0 if no port is present
	// in the url.
	int get_port(void) const;

	// ip address network order. Return 0 if address not found
	// DNS A RR lookup
	unsigned long get_n_ip(void) const;

	// ip address host order. Return 0 if address not found
	// DNS A RR lookup
	unsigned long get_h_ip(void) const;
	list<unsigned long> get_h_ip_all(void) const;

	// DNS A RR lookup
	string get_ip(void) const; // ip address as string
	
	// Get list op IP address/ports in host order.
	// First do DNS SRV lookup. If no SRV RR's are found, then
	// do a DNS A RR lookup.
	// transport = the transport protocol for the service
	list<t_ip_port> get_h_ip_srv(const string &transport) const;
	
	string get_transport(void) const;
	string get_maddr(void) const;
	bool get_lr(void) const;
	string get_user_param(void) const;
	string get_method(void) const;
	int get_ttl(void) const;
	string get_other_params(void) const;
	string get_headers(void) const;

	bool is_valid(void) const;

	// Check if 2 sip or sips url's are equivalent
	bool sip_match(const t_url &u) const;
	bool operator==(const t_url &u) const;

	// Return true if the user part looks like a phone number, i.e.
	// consists of digits, *, # and special symbols
	bool user_looks_like_phone(const string &special_symbols) const;

	// Return true if the URI indicates a phone number, i.e.
	// - the user=phone parameter is present
	// or
	// - if looks_like_phone == true and the user part looks like
	//   a phone number
	bool is_phone(bool looks_like_phone, const string &special_symbols) const;

	// Return string encoding of url
	string encode(void) const;

	// Return string encoding of url without scheme information
	string encode_noscheme(void) const;
};

// Display name and url combined

class t_display_url {
public:
	t_url		url;
	string		display;
	
	t_display_url();
	t_display_url(const t_url &_url, const string &_display);
	
	bool is_valid();
	string encode(void) const;
};

#endif
