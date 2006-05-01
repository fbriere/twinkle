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

#include <cstdlib>
#include <iostream>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "dnssrv.h"
#include "url.h"
#include "util.h"

// TODO: handle hex charactest (eg. %20x) correctly.

unsigned short get_default_port(const string &protocol) {
	if (protocol == "mailto")	return 25;
	if (protocol == "http")		return 80;
	if (protocol == "sip")		return 5060;
	if (protocol == "sips")		return 5061;
	if (protocol == "stun")		return 3478;

	return 0;
}

unsigned long gethostbyname(const string &name) {
	struct hostent *h;
	
	h = gethostbyname(name.c_str());
	if (h == NULL) return 0;
	return ntohl(*((unsigned long *)h->h_addr));
}

list<unsigned long> gethostbyname_all(const string &name) {
	struct hostent *h;
	list<unsigned long> l;
	
	h = gethostbyname(name.c_str());
	if (h == NULL) return l;
	
	char **ipaddr = h->h_addr_list;
	while (*ipaddr) {
		l.push_back(ntohl(*((unsigned long *)(*ipaddr))));
		ipaddr++;
	}
	
	return l;
}

string display_and_url2str(const string &display, const string &url) {
	string s;
	
	if (!display.empty()) {
		if (must_quote(display)) s += '"';
		s += display;
		if (must_quote(display)) s += '"';
		s += " <";
	}
	
	s += url;
	
	if (!display.empty()) s += '>';
	
	return s;
}

// t_ip_port

t_ip_port::t_ip_port(unsigned long _ipaddr, unsigned short _port) :
	ipaddr(_ipaddr), port(_port) {}

// Private

void t_url::construct_user_url(const string &s) {
	int i;
	string r;

	// Determine user/password (both are optional)
	i = s.find('@');
	if (i != string::npos) {
		if (i == 0 || i == s.size()-1) return;
		string userpass = s.substr(0, i);
		r = s.substr(i+1);
		i = userpass.find(':');
		if (i != string::npos) {
			if (i == 0 || i == userpass.size()-1) return;
			user = userpass.substr(0, i);
			if (user.find(' ') != string::npos) return;
			password = userpass.substr(i+1);
			if (password.find(' ') != string::npos) return;
		} else {
			user = userpass;
			if (user.find(' ') != string::npos) return;
		}
	} else {
		r = s;
	}

	// Determine host/port
	string hostport;

	i = r.find_first_of(";?");
	if (i != string::npos) {
		hostport = r.substr(0, i);
		if (!parse_params_headers(r.substr(i))) return;
	} else {
		hostport = r;
	}

	i = hostport.find(':');
	if (i != string::npos) {
		if (i == 0 || i == hostport.size()-1) return;
		host = hostport.substr(0, i);
		unsigned long p = atol(hostport.substr(i+1).c_str());
		if (p > 65535) return; // illegal port value
		port = (unsigned short)p;
	} else {
		host = hostport;
	}

	user_url = true;
	valid = true;
}


void t_url::construct_machine_url(const string &s) {
	int i;

	// Determine host
	string hostport;
	i = s.find_first_of("/?;");
	if ( i != string::npos) {
		hostport = s.substr(0, i);
		if (!parse_params_headers(s.substr(i))) return;
	} else {
		hostport = s;
	}

	i = hostport.find(':');
	if (i != string::npos) {
		if (i == 0 || i == hostport.size()-1) return;
		host = hostport.substr(0, i);
		unsigned long p = atol(hostport.substr(i+1).c_str());
		if (p > 65535) return; // illegal port value
		port = (unsigned short)p;
	} else {
		host = hostport;
	}

	user_url = false;
	valid = true;
}

bool t_url::parse_params_headers(const string &s) {
	string param_str;

	// Find start of headers
	// Note: parameters will not contain / or ?-symbol
	int header_start = s.find_first_of("/?");
	if (header_start != string::npos) {
		headers = s.substr(header_start + 1);

		// The first symbol of the parameter list is ;
		// Remove this.
		param_str = s.substr(1, header_start - 1);
	} else {
		// There are no headers
		// The first symbol of the parameter list is ;
		// Remove this.
		param_str = s.substr(1);
	}

	if (param_str == "") return true;

	// Create a list of single parameters. Parameters are
	// seperated by semi-colons.
	// Note: parameters will not contain a semi-colon in the
	//       name or value.
	list<string> param_lst = split(param_str, ';');

	// Parse the parameters
	for (list<string>::iterator i = param_lst.begin();
	     i != param_lst.end(); i++)
	{
		string pname;
		string pvalue;

		list<string> param = split(*i, '=');
		if (param.size() > 2) return false;

		pname = trim(tolower(param.front()));
		if (param.size() == 2) {
			pvalue = trim(tolower(param.back()));
		}

		if (pname == "transport") {
			transport = pvalue;
		} else if (pname == "maddr") {
			maddr = pvalue;
		} else if (pname == "lr") {
			lr = true;
		} else if (pname == "user") {
			user_param = pvalue;
		} else if (pname == "method") {
			method = pvalue;
		} else if (pname == "ttl") {
			ttl = atoi(pvalue.c_str());
		} else {
			other_params += ';';
			other_params += *i;
		}
	}

	return true;
}

// Public

t_url::t_url(void) {
	valid = false;
	port = 0;
	lr = false;
	ttl = 0;
}

t_url::t_url(const string &s) {
	set_url(s);
}

void t_url::set_url(const string &s) {
	int i;
	string r;

	valid = false;
	port = 0;
	lr = false;
	ttl = 0;
	text_format = s;

	// Determine scheme. A scheme is mandatory. There should
	// be text following the scheme.
	i = s.find(':');
	if (i == string::npos || i == 0 || i == s.size()-1) return;
	scheme = tolower(s.substr(0, i));
	r = s.substr(i+1);

	if (r[0] == '/') {
		if (r.size() == 1) return;
		if (r[1] != '/') return;
		construct_machine_url(r.substr(2));
	} else {
		construct_user_url(r);
	}
}

string t_url::get_scheme(void) const {
	return scheme;
}

string t_url::get_user(void) const {
	return user;
}

string t_url::get_password(void) const {
	return password;
}

string t_url::get_host(void) const {
	return host;
}

int t_url::get_nport(void) const {
	return htons(get_hport());
}

int t_url::get_hport(void) const {
	if (port != 0) return port;
	return get_default_port(scheme);
}

int t_url::get_port(void) const {
	return port;
}

unsigned long t_url::get_n_ip(void) const {
	struct hostent *h;

	// TODO: handle multiple A RR's
	
	h = gethostbyname(host.c_str());
	if (h == NULL) return 0;
	return *((unsigned long *)h->h_addr);
}

unsigned long t_url::get_h_ip(void) const {
	return gethostbyname(host);
}

list<unsigned long> t_url::get_h_ip_all(void) const {
	return gethostbyname_all(host);
}

string t_url::get_ip(void) const {
	struct hostent *h;

	// TODO: handle multiple A RR's
	
	h = gethostbyname(host.c_str());
	if (h == NULL) return "";
	return inet_ntoa(*((struct in_addr *)h->h_addr));
}

list<t_ip_port> t_url::get_h_ip_srv(const string &transport) const {
	list<t_ip_port> ip_list;
	list<t_dns_result> srv_list;
	list<unsigned long> ipaddr_list;
		
	// RFC 3263 4.2
	// Only do an SRV lookup if host is a hostname and no port is specified.
	if (!is_ipaddr(host) && port == 0) {
		int ret = insrv_lookup(scheme.c_str(), transport.c_str(), 
				host.c_str(), srv_list);
		
		if (ret >= 0 && !srv_list.empty()) {
			// SRV RR's found
			for (list<t_dns_result>::iterator i = srv_list.begin();
			i != srv_list.end(); i++)
			{
				// Get A RR's
				t_ip_port ip_port;
				ipaddr_list = gethostbyname_all(i->hostname);
				for (list<unsigned long>::iterator j = ipaddr_list.begin();
				     j != ipaddr_list.end(); j++)
				{
					ip_list.push_back(t_ip_port(*j, i->port));
				}
			}
			
			return ip_list;
		}
	}
	
	// No SRV RR's found, do an A RR lookup
	t_ip_port ip_port;
	ipaddr_list = get_h_ip_all();
	for (list<unsigned long>::iterator j = ipaddr_list.begin();
		j != ipaddr_list.end(); j++)
	{
		ip_list.push_back(t_ip_port(*j, get_hport()));
	}
	
	return ip_list;
}

string t_url::get_transport(void) const {
	return transport;
}

string t_url::get_maddr(void) const {
	return maddr;
}

bool t_url::get_lr(void) const {
	return lr;
}

string t_url::get_user_param(void) const {
	return user_param;
}

string t_url::get_method(void) const {
	return method;
}

int t_url::get_ttl(void) const {
	return ttl;
}

string t_url::get_other_params(void) const {
	return other_params;
}

string t_url::get_headers(void) const {
	return headers;
}

bool t_url::is_valid(void) const {
	return valid;
}

// RCF 3261 19.1.4
bool t_url::sip_match(const t_url &u) const {
	// Compare schemes
	if (scheme != "sip" && scheme != "sips") return false;
	if (u.get_scheme() != "sip" && u.get_scheme() != "sips") {
		return false;
	}
	if (scheme != u.get_scheme()) return false;

	// Compare user info
	if (user != u.get_user()) return false;
	if (password != u.get_password()) return false;

	// Compare host/port
	if (cmp_nocase(host, u.get_host()) != 0) return false;
	if (port != u.get_port()) return false;

	// Compare parameters
	if (transport != "" || u.get_transport() != "" &&
	    cmp_nocase(transport, u.get_transport()) != 0)
	{
		return false;
	}
	if (maddr != u.get_maddr()) return false;
	if (cmp_nocase(user_param, u.get_user_param()) != 0) return false;
	if (cmp_nocase(method, u.get_method()) != 0) return false;
	if (ttl != u.get_ttl()) return false;

	// TODO: compare other params and headers

	return true;
}

bool t_url::operator==(const t_url &u) const {
	return sip_match(u);
}

bool t_url::user_looks_like_phone(const string &special_symbols) const {
	return looks_like_phone(user, special_symbols);
}

bool t_url::is_phone(bool looks_like_phone, const string &special_symbols) const {
	// RFC 3261 19.1.1
	if (user_param == "phone") return true;
	return (looks_like_phone && user_looks_like_phone(special_symbols));
}

string t_url::encode(void) const {
	return text_format;
}

string t_url::encode_noscheme(void) const {
	string s = encode();
	int i = s.find(':');

	if (i != string::npos && i < s.size()) {
		s = s.substr(i + 1);
	}

	return s;
}

t_display_url::t_display_url() {}

t_display_url::t_display_url(const t_url &_url, const string &_display) :
	url(_url), display(_display) {}
	
bool t_display_url::is_valid() {
	return url.is_valid();
}
	
string t_display_url::encode(void) const {
	string s;
	
	if (!display.empty()) {
		if (must_quote(display)) s += '"';
		s += display;
		if (must_quote(display)) s += '"';
		s += " <";
	}
	
	s += url.encode();
	
	if (!display.empty()) s += '>';
	
	return s;
}

