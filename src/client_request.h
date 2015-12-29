/*
    Copyright (C) 2005-2007  Michel de Boer <michel@twinklephone.com>

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

// Object for storing a request together with its TU id and transaction id.

#ifndef _CLIENT_REQUEST_H
#define _CLIENT_REQUEST_H

#include "protocol.h"
#include "redirect.h"
#include "user.h"
#include "transaction_layer.h"
#include "threads/mutex.h"
#include "parser/request.h"
#include "stun/stun.h"

using namespace std;

class t_client_request {
private:
	static t_mutex	mtx_next_tuid; // protect updates on next_tuid
	static t_tuid	next_tuid;

	// A client request is either a SIP or a STUN request
	t_request	*request;
	StunMessage	*stun_request;
	
	t_tuid		tuid;
	t_tid		tid;

	// Number of references to this object (#dialogs)
	int		ref_count;

public:
	// Redirector for 3XX redirections
	t_redirector	redirector;

	// A copy of the request is stored in the client_request object
	t_client_request(t_user *user, t_request *r, const t_tid _tid);
	t_client_request(t_user *user, StunMessage *r, const t_tid _tid);
	~t_client_request();

	t_client_request *copy(void);

	// Returns the request pointer
	t_request *get_request(void) const;
	StunMessage *get_stun_request(void) const;

	t_tuid get_tuid(void) const;
	t_tid get_tid(void) const;
	void set_tid(t_tid _tid);

	// Create a new tuid and set tid
	void renew(t_tid _tid);

	// Get the reference count
	int get_ref_count(void) const;

	// Increment reference count. Returns the value after increment.
	int inc_ref_count(void);

	// Decrement reference count. Returns the value after decrement.
	int dec_ref_count(void);
};

#endif
