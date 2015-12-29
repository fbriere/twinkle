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

#include <assert.h>
#include <iostream>
#include <signal.h>
#include "log.h"
#include "transaction_mgr.h"
#include "sockets/url.h"
#include "user.h"
#include "util.h"
#include "audits/memman.h"

extern t_event_queue		*evq_trans_mgr;
extern t_event_queue		*evq_trans_layer;
extern t_event_queue		*evq_timekeeper;
extern t_transaction_mgr	*transaction_mgr;

t_trans_client *t_transaction_mgr::find_trans_client(t_response *r) const {
	map<t_tid, t_trans_client *>::const_iterator i;

	for (i = map_trans_client.begin(); i != map_trans_client.end();
			i++)
	{
		if (i->second->match(r)) return i->second;
	}

	return NULL;
}

t_trans_client *t_transaction_mgr::find_trans_client(t_tid tid) const {
	map<t_tid, t_trans_client *>::const_iterator i;

	i = map_trans_client.find(tid);
	if (i == map_trans_client.end()) return NULL;
	return i->second;
}

t_trans_server *t_transaction_mgr::find_trans_server(t_request *r) const {
	map<t_tid, t_trans_server *>::const_iterator i;

	for (i = map_trans_server.begin(); i != map_trans_server.end();
			i++)
	{
		if (i->second->match(r)) return i->second;
	}

	return NULL;
}

t_trans_server *t_transaction_mgr::find_trans_server(t_tid tid) const {
	map<t_tid, t_trans_server *>::const_iterator i;

	i = map_trans_server.find(tid);
	if (i == map_trans_server.end()) return NULL;
	return i->second;
}

t_trans_server *t_transaction_mgr::find_cancel_target(t_request *r) const {
	map<t_tid, t_trans_server *>::const_iterator i;

	for (i = map_trans_server.begin(); i != map_trans_server.end();
			i++)
	{
		if (i->second->match_cancel(r)) return i->second;
	}

	return NULL;
}

t_tc_invite *t_transaction_mgr::create_tc_invite(t_request *r,
		unsigned short tuid)
{
	unsigned long	ipaddr;
	unsigned short	port;

	r->get_destination(ipaddr, port, *user_config);
	if (ipaddr == 0) return NULL;
	if (port == 0) return NULL;

	t_tc_invite *t = new t_tc_invite(r, ipaddr, port, tuid);
	MEMMAN_NEW(t);
	map_trans_client[t->get_id()] = (t_trans_client *)t;
	return t;
}

t_tc_non_invite *t_transaction_mgr::create_tc_non_invite(t_request *r,
		unsigned short tuid)
{
	unsigned long	ipaddr;
	unsigned short	port;

	r->get_destination(ipaddr, port, *user_config);
	if (ipaddr == 0) return NULL;
	if (port == 0) return NULL;

	t_tc_non_invite *t = new t_tc_non_invite(r, ipaddr, port, tuid);
	MEMMAN_NEW(t);
	map_trans_client[t->get_id()] = (t_trans_client *)t;
	return t;
}

t_ts_invite *t_transaction_mgr::create_ts_invite(t_request *r) {
	t_ts_invite *t = new t_ts_invite(r, 0);
	MEMMAN_NEW(t);
	map_trans_server[t->get_id()] = (t_trans_server *)t;
	return t;
}

t_ts_non_invite *t_transaction_mgr::create_ts_non_invite(t_request *r) {
	t_ts_non_invite *t = new t_ts_non_invite(r, 0);
	MEMMAN_NEW(t);
	map_trans_server[t->get_id()] = (t_trans_server *)t;
	return t;
}

void t_transaction_mgr::delete_trans_client(t_trans_client *tc) {
	map_trans_client.erase(tc->get_id());
	MEMMAN_DELETE(tc);
	delete tc;
}

void t_transaction_mgr::delete_trans_server(t_trans_server *ts) {
	map_trans_server.erase(ts->get_id());
	MEMMAN_DELETE(ts);
	delete ts;
}

t_transaction_mgr::~t_transaction_mgr() {
	log_file->write_header("t_transaction_mgr::~t_transaction_mgr",
		LOG_DEBUG, LOG_INFO);
	log_file->write_raw("Clean up transaction manager.\n");

	map<t_tid, t_trans_client *>::iterator i;
	for (i = map_trans_client.begin(); i != map_trans_client.end();
	     i++)
	{
		log_file->write_raw("\nDeleting client transaction: \n");
		log_file->write_raw("Tid: ");
		log_file->write_raw(i->first);
		log_file->write_raw(", Method: ");
		log_file->write_raw(method2str(i->second->get_method()));
		log_file->write_raw(", State: ");
		log_file->write_raw(trans_state2str(i->second->get_state()));
		log_file->write_endl();
		MEMMAN_DELETE(i->second);
		delete i->second;
	}

	map<t_tid, t_trans_server *>::iterator j;
	for (j = map_trans_server.begin(); j != map_trans_server.end();
	     j++)
	{
		log_file->write_raw("\nDeleting server transaction: \n");
		log_file->write_raw("Tid: ");
		log_file->write_raw(j->first);
		log_file->write_raw(", Method: ");
		log_file->write_raw(method2str(j->second->get_method()));
		log_file->write_raw(", State: ");
		log_file->write_raw(trans_state2str(j->second->get_state()));
		log_file->write_endl();
		MEMMAN_DELETE(j->second);
		delete j->second;
	}

	log_file->write_footer();
}

void t_transaction_mgr::handle_event_network(t_event_network *e) {
	t_trans_server	*ts;
	t_ts_invite	*ts_invite;
	t_ts_non_invite	*ts_non_invite;
	t_trans_client	*tc;
	t_sip_message	*msg = e->get_msg();
	t_request	*request;
	t_response	*response;

	switch(msg->get_type()) {
	case MSG_REQUEST:
		// Request from network is for a server transaction
		request = (t_request *)msg;
		ts = find_trans_server(request);
		if (ts) {
			switch (request->method) {
			case ACK:
				// ACK for an INVITE transaction
				ts_invite = (t_ts_invite *)ts;
				ts_invite->acknowledge(request);
				break;
			default:
				// A request that matches an existing
				// transaction is a retransmission
				ts->process_retransmission();
				break;
			}

			if (ts->get_state() == TS_TERMINATED) {
				delete_trans_server(ts);
			}

			return;
		}

		// Create a new transaction
		switch (request->method) {
		case INVITE:
			create_ts_invite(request);
			break;
		case ACK:
			// ACK should be passed to TU
			evq_trans_layer->push_user(request, 0, 0);
			break;
		default:
			create_ts_non_invite(request);
			break;
		}

		break;
	case MSG_RESPONSE:
		// Response from network is for a client transaction
		response = (t_response *)msg;
		tc = find_trans_client(response);
		if (!tc) {
			// Only a 2XX for an INVITE transaction can be
			// received while no transaction exists anymore.
			// RFC 3261 17.1.1.2
			if (response->is_success() &&
			    response->hdr_cseq.method == INVITE)
			{
				// Report to TU
				evq_trans_layer->push_user(response, 0, 0);
			}
			break;
		}
		tc->process_response(response);

		if (tc->get_state() == TS_TERMINATED) {
			delete_trans_client(tc);
		}
		break;
	default:
		assert(false);
		break;
	}
}

void t_transaction_mgr::handle_event_user(t_event_user *e) {
	t_trans_server	*ts;
	t_ts_invite	*ts_invite;
	t_ts_non_invite	*ts_non_invite;
	t_sip_message	*msg = e->get_msg();
	t_request	*request;
	t_response	*response;

	switch(msg->get_type()) {
	case MSG_REQUEST:
		// A user request creates a client transaction
		request = (t_request *)msg;
		switch (request->method) {
		case INVITE:
			t_tc_invite *t1;
			t1 = create_tc_invite(request, e->get_tuid());
			if (t1 == NULL) {
				// Report 404 to TU
				response = request->create_response(
					R_404_NOT_FOUND);

				log_file->write_header(
					"t_transaction_mgr::handle_event_user",
					LOG_NORMAL, LOG_INFO);
				log_file->write_raw("Cannot resolve destination for:\n");
				log_file->write_raw(request->encode());
				log_file->write_endl();
				log_file->write_raw("Send internal:\n");
				log_file->write_raw(response->encode());
				log_file->write_footer();

				evq_trans_layer->push_user(response,
					e->get_tuid(), 0);
				MEMMAN_DELETE(response);
				delete response;
			}
			break;
		default:
			t_tc_non_invite *t2;
			t2 = create_tc_non_invite(request, e->get_tuid());
			if (t2 == NULL) {
				// Report 404 to TU
				response = request->create_response(
					R_404_NOT_FOUND);

				log_file->write_header(
					"t_transaction_mgr::handle_event_user",
					LOG_NORMAL, LOG_INFO);
				log_file->write_raw("Cannot resolve destination for:\n");
				log_file->write_raw(request->encode());
				log_file->write_endl();
				log_file->write_raw("Send internal:\n");
				log_file->write_raw(response->encode());
				log_file->write_footer();
				
				evq_trans_layer->push_user(response,
					e->get_tuid(), 0);
				MEMMAN_DELETE(response);
				delete response;
			}
			break;
		}
		break;
	case MSG_RESPONSE:
		// A user repsonse is for a server transaction
		response = (t_response *)msg;
		ts = find_trans_server(e->get_tid());
		if (!ts) {
			// This is an error. A response should match a
			// transaction. Ignore it.
			return;
		}
		ts->process_response(response);

		if (ts->get_state() == TS_TERMINATED) {
			delete_trans_server(ts);
		}

		break;
	default:
		assert(false);
		break;
	}
}

void t_transaction_mgr::handle_event_timeout(t_event_timeout *e) {
	t_timer			*t = e->get_timer();
	t_tmr_transaction	*tmr_trans;
	t_tid			tid;
	t_trans_client		*tc;
	t_trans_server		*ts;

	switch (t->get_type()) {
	case TMR_TRANSACTION:
		tmr_trans = (t_tmr_transaction *)t;
		tid = tmr_trans->get_tid();
		tc = find_trans_client(tid);
		if (tc) {
			tc->timeout(tmr_trans->get_sip_timer());

			if (tc->get_state() == TS_TERMINATED) {
				delete_trans_client(tc);
			}

			return;
		}

		ts = find_trans_server(tid);
		if (ts) {
			ts->timeout(tmr_trans->get_sip_timer());

			if (ts->get_state() == TS_TERMINATED) {
				delete_trans_server(ts);
			}

			return;
		}

		// The transaction is already gone. Discard timeout.
		break;
	default:
		assert(false);
		break;
	}
}

void t_transaction_mgr::handle_event_abort(t_event_abort_trans *e) {
	t_tid			tid;
	t_trans_client		*tc;

	// Only a client transaction can be aborted.
	tid = e->get_tid();
	tc = find_trans_client(tid);
	if (tc) {
		tc->abort();

		if (tc->get_state() == TS_TERMINATED) {
			delete_trans_client(tc);
		}

		return;
	}
}

unsigned short t_transaction_mgr::start_timer(long dur, t_sip_timer tmr,
			unsigned short tid)
{
	t_tmr_transaction *t = new t_tmr_transaction(dur, tmr, tid);
	MEMMAN_NEW(t);
	evq_timekeeper->push_start_timer(t);
	unsigned short timer_id = t->get_id();
	MEMMAN_DELETE(t);
	delete t;
	return timer_id;
}

void t_transaction_mgr::stop_timer(unsigned short id) {
	evq_timekeeper->push_stop_timer(id);
}

void t_transaction_mgr::run(void) {
	t_event			*event;
	t_event_network		*ev_network;
	t_event_user		*ev_user;
	t_event_timeout		*ev_timeout;
	t_event_abort_trans	*ev_abort;

	while (true) {
		event = evq_trans_mgr->pop();

		switch (event->get_type()) {
		case EV_NETWORK:
			ev_network = (t_event_network *)event;
			handle_event_network(ev_network);
			break;
		case EV_USER:
			ev_user = (t_event_user *)event;
			handle_event_user(ev_user);
			break;
		case EV_TIMEOUT:
			ev_timeout = (t_event_timeout *)event;
			handle_event_timeout(ev_timeout);
			break;
		case EV_ABORT_TRANS:
			ev_abort = (t_event_abort_trans *)event;
			handle_event_abort(ev_abort);
			break;
		default:
			assert(false);
			break;
		}

		MEMMAN_DELETE(event);
		delete event;
	}
}

// Main function to be started in a separate thread.
void *transaction_mgr_main(void *arg) {
	transaction_mgr->run();
}
