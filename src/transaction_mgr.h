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

#ifndef _TRANSACTION_MGR_H
#define _TRANSACTION_MGR_H

#include <map>
#include "events.h"
#include "transaction.h"
#include "parser/request.h"
#include "parser/response.h"

using namespace std;

class t_transaction_mgr {
private:
	// Mapping from transaction id to transaction
	map<t_tid, t_trans_client *>	map_trans_client;
	map<t_tid, t_trans_server *>	map_trans_server;

	// Find existing transactions. Return NULL if not found
	t_trans_client *find_trans_client(t_response *r) const;
	t_trans_client *find_trans_client(t_tid tid) const;
	t_trans_server *find_trans_server(t_request *r) const;
	t_trans_server *find_trans_server(t_tid tid) const;

	// Create new transactions.
	// Return NULL if creation failed.
	t_tc_invite *create_tc_invite(t_request *r, unsigned short tuid);
	t_tc_non_invite *create_tc_non_invite(t_request *r,
		unsigned short tuid);
	t_ts_invite *create_ts_invite(t_request *r);
	t_ts_non_invite *create_ts_non_invite(t_request *r);

	// Delete transactions
	void delete_trans_client(t_trans_client *tc);
	void delete_trans_server(t_trans_server *ts);

	// Handle events
	void handle_event_network(t_event_network *e);
	void handle_event_user(t_event_user *e);
	void handle_event_timeout(t_event_timeout *e);
	void handle_event_abort(t_event_abort_trans *e);

public:
	~t_transaction_mgr();

	// Find the target transaction for a CANCEL.
	// Return NULL if not found.
	t_trans_server *find_cancel_target(t_request *r) const;

	// Start transaction timer. Return timer id (needed for stopping)
	unsigned short start_timer(long dur, t_sip_timer tmr,
						unsigned short tid);

	// Stop timer. Pass id that is returned by start_timer
	void stop_timer(unsigned short id);

	// Main loop of the transaction manager (infinite)
	void run (void);
};

// Thread that runs the transaction manager
void *transaction_mgr_main(void *arg);

#endif
