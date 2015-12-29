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

#ifndef _ABSTRACT_DIALOG_H
#define _ABSTRACT_DIALOG_H

#include <string>
#include <list>
#include <set>
#include <queue>
#include "client_request.h"
#include "id_object.h"
#include "protocol.h"
#include "user.h"
#include "sockets/url.h"
#include "parser/request.h"

using namespace std;

class t_abstract_dialog : public t_id_object {
protected:	
	// User profile of user for which this dialog is created.
	// This is a pointer to the user_config owned by a phone user.
	// So this pointer should never be deleted.
	t_user			*user_config;

	// Dialog state information
	string		call_id;
	bool		call_id_owner;	// indicates if call_id generated locally
	string		local_tag;
	string		remote_tag;
	unsigned long	local_seqnr;	// last local seqnr issued
	unsigned long	remote_seqnr;	// last remote seqnr received

	// RFC 3261 allows the CSeq sequence to be 0. So there is no
	// invalid sequence number. The remote_seqnr_set indicates if
	// the remote_seqnr is set by the far-end.
	bool		remote_seqnr_set;
	
	t_url		local_uri;
	string		local_display;
	t_url		remote_uri;
	string		remote_display;
	t_url		remote_target_uri;
	string		remote_target_display;
	list<t_route>	route_set;
	unsigned long	local_resp_nr;	// last local response nr issued
	unsigned long	remote_resp_nr;	// last remote response nr received
	set<string>	remote_extensions; // extensions supported by remote end

	// Remove a client request. Pass one of the client request
	// pointers to this member. The reference count of the
	// request will be decremented. If it becomes zero, then
	// the request object is deleted.
	// In all cases the pointer will be set to NULL.
	void remove_client_request(t_client_request **cr);

	// Create route set based on a response.
	void create_route_set(t_response *r);

	// Create remote target uri and display based on a response.
	void create_remote_target(t_response *r);
	
	// Send a request
	virtual void send_request(t_request *r, t_tuid tuid) = 0;

	// Resend an existing client request.
	// A new Via and CSeq header will be put in the request.
	virtual void resend_request(t_client_request *cr);
	
	// Resend mid-dialog request with an authorization header containing
	// credentials for the challenge in the response. The response
	// must be a 401 or 407.
	// Returns false if credentials could not be determined.
	bool resend_request_auth(t_client_request *cr, t_response *resp);
	
	// Redirect mid-dialog request to the next destination
	// @param contact contains the contact to which the request is sent.
	// Returns false if there is no next destination.
	bool redirect_request(t_client_request *cr, t_response *resp,
			t_contact_param &contact);
	
	// Failover request to the next destination from DNS lookup.
	// Returns false if there is no next destination.
	bool failover_request(t_client_request *cr);

public:
	t_abstract_dialog(t_user *user);
	virtual ~t_abstract_dialog();

	// Create a request using the stored state information
	virtual t_request *create_request(t_method m);

	virtual t_abstract_dialog *copy(void) = 0;
	
	t_user *get_user(void) const;

	// Resend mid-dialog request with an authorization header containing
	// credentials for the challenge in the response. The response
	// must be a 401 or 407.
	// Returns false if credentials could not be determined.
	virtual bool resend_request_auth(t_response *resp) = 0;

	// Redirect mid-dialog request to the next destination
	// Returns false if there is no next destination.
	virtual bool redirect_request(t_response *resp) = 0;
	
	// Failover request to the next destination from DNS lookup.
	// Returns false if there is no next destination.
	virtual bool failover_request(t_response *resp) = 0;

	// Handle received events
	virtual void recvd_response(t_response *r, t_tuid tuid, t_tid tid) = 0;
	virtual void recvd_request(t_request *r, t_tuid tuid, t_tid tid) = 0;

	// Match response with dialog
	virtual bool match_response(t_response *r, t_tuid tuid);

	// Match request with dialog
	virtual bool match_request(t_request *r);
	
	// Partially match request with dialog, i.e. do not match remote tag
	virtual bool match_partial_request(t_request *r);
	
	// Match call-id and tags with dialog
	virtual bool match(const string &_call_id, const string &to_tag, 
		const string &from_tag) const;
	
	// Get the target uri/display
	t_url get_remote_target_uri(void) const;
	string get_remote_target_display(void) const;
	
	// Get the remote uri/display
	t_url get_remote_uri(void) const;
	string get_remote_display(void) const;
	
	// Get call-id and tags
	string get_call_id(void) const;
	string get_local_tag(void) const;
	string get_remote_tag(void) const;
	
	// Returns true if remote end supports the extension
	virtual bool remote_extension_supported(const string &extension) const;

	// Returns true if we are the owner of the call id, i.e. the
	// value is generated locally.
	bool is_call_id_owner(void) const;
};

#endif
