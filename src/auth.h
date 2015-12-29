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

#ifndef _AUTH_H
#define _AUTH_H

#include "parser/credentials.h"
#include "parser/request.h"
#include "sockets/url.h"
#include <list>

using namespace std;

#define AUTH_CACHE_SIZE	10

class t_cr_cache_entry {
public:
	t_url		to; // this is not used for SIP authentication
	t_credentials	credentials;
	string 		passwd;
	bool		proxy;

	t_cr_cache_entry(const t_url &_to, const t_credentials &_cr,
		const string &_passwd, bool _proxy);
};


// An object of this class authorizes a request given some credentials
class t_auth {
private:
	// LRU cache credentials for a destination.
	// The first entry in the list is the least recently used.
	list<t_cr_cache_entry>	cache;

	// Find a cache entry that matches the realm
	list<t_cr_cache_entry>::iterator find_cache_entry(
		const t_url &_to, const string &realm, bool proxy=false);

	// If the cache does not contain the credentials already
	// then it will be added to the end of the list. If the cache
	// already contains the maximum number of entries, then the least
	// recently used entry will be removed.
	// If the cache already contains an entry for credentials, then
	// this entry will be moved to the end of the list.
	void update_cache(const t_url &to, const t_credentials &cr,
		const string &passwd, bool proxy);

	// Return true if authorization failed.
	// Authorization failed if the challenge is for a realm for which
	// the request already contains an authorization header and the
	// challenge is not stale.
	bool auth_failed(t_request *r, const t_challenge &c,
		bool proxy=false) const;

	// Remove existing credentials for this challenge from the
	// authorization or proxy-authorization header.
	void remove_credentials(t_request *r, const t_challenge &c,
		bool proxy=false) const;

public:
	// Authorize the request based on the challenge in the response
	// Returns false if authorization fails.
	bool authorize(t_request *r, t_response *resp);
};

#endif
