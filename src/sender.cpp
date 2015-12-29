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

#include <assert.h>
#include <iostream>
#include "events.h"
#include "log.h"
#include "sender.h"
#include "userintf.h"
#include "util.h"
#include "sockets/socket.h"
#include "parser/parse_ctrl.h"
#include "parser/sip_message.h"
#include "audits/memman.h"
#include "stun/stun.h"

extern t_socket_udp *sip_socket;
extern t_event_queue *evq_sender_udp;
extern t_event_queue *evq_trans_mgr;

// Number of consecutive non-icmp errors received
static int num_non_icmp_errors = 0;

// Check if the error is caused by an incoming ICMP error. If so, then deliver
// the ICMP error to the transaction manager.
//
// err - error returned by sendto
// dst_addr - destination IP address of packet that failed to be sent
// dst_port - destination port of packet that failed to be sent
//
// Returns true if the packet that failed to be sent, should still be sent.
// Returns false if the packet that failed to be sent, should be discarded.
static bool handle_socket_err(int err, unsigned long dst_addr, unsigned short dst_port) {
	t_event_icmp *ev_icmp;
	string log_msg;

	// Check if an ICMP error has been received
	t_icmp_msg icmp;
	if (sip_socket->get_icmp(icmp)) {
		log_msg = "Received ICMP from: ";
		log_msg += h_ip2str(icmp.icmp_src_ipaddr);
		log_msg += "\nICMP type: ";
		log_msg += int2str(icmp.type);
		log_msg += "\nICMP code: ";
		log_msg += int2str(icmp.code);
		log_msg += "\nDestination of packet causing ICMP: ";
		log_msg += h_ip2str(icmp.ipaddr);
		log_msg += ":";
		log_msg += int2str(icmp.port);
		log_msg += "\nSocket error: ";
		log_msg += strerror(err);
		log_file->write_report(log_msg, "::hanlde_socket_err", LOG_NORMAL);
	
		ev_icmp = new t_event_icmp(icmp);
		MEMMAN_NEW(ev_icmp);
		evq_trans_mgr->push(ev_icmp);
		
		num_non_icmp_errors = 0;
		
		// If the ICMP error comes from the same destination is the
		// destination of the packet that failed to be sent, then the
		// packet should be discarded as it can most likely not b
		// delivered and would cause an infinite loop of ICMP errors
		// otherwise.
		if (icmp.ipaddr == dst_addr && icmp.port == dst_port) {
			return false;
		}
	} else {
		// Even if an ICMP message is received this code can get executed.
		// Sometimes the error is already present on the socket, but the ICMP
		// message is not yet queued.
		log_msg = "Failed to send to SIP UDP socket.\n";
		log_msg += strerror(err);
		log_file->write_report(log_msg, "::handle_socket_err");
		
		num_non_icmp_errors++;
		if (num_non_icmp_errors > 100) {
			log_msg = "Excessive number of socket errors.";
			log_file->write_report(log_msg, "::handle_socket_err", 
				LOG_NORMAL, LOG_CRITICAL);
			ui->cb_show_msg(log_msg, MSG_CRITICAL);
			exit(1);
		}
	}
	
	return true;
}

static void send_sip_udp(t_event *event) {
	t_event_network	*e;
	
	e = (t_event_network *)event;
	
	assert(e->dst_addr != 0);
	assert(e->dst_port != 0);

	string m = e->get_msg()->encode();
	log_file->write_header("::send_sip_udp", LOG_SIP);
	log_file->write_raw("Send to: ");
	log_file->write_raw(h_ip2str(e->dst_addr));
	log_file->write_raw(":");
	log_file->write_raw(e->dst_port);
	log_file->write_endl();
	log_file->write_raw(m);
	log_file->write_footer();
		
	bool msg_sent = false;
	while (!msg_sent) {
		try {
			sip_socket->sendto(e->dst_addr, e->dst_port, m.c_str(), m.size());
			num_non_icmp_errors = 0;
			msg_sent = true;
		} catch (int err) {
			if (!handle_socket_err(err, e->dst_addr, e->dst_port)) {
				// Discard packet.
				msg_sent = true;
			}
		}
	}
}

static void send_stun(t_event *event) {
	t_event_stun_request	*e;
	
	e = (t_event_stun_request *)event;
	
	assert(e->dst_addr != 0);
	assert(e->dst_port != 0);
	
	log_file->write_header("::send_stun", LOG_STUN);
	log_file->write_raw("Send to: ");
	log_file->write_raw(h_ip2str(e->dst_addr));
	log_file->write_raw(":");
	log_file->write_raw(e->dst_port);
	log_file->write_endl();
	log_file->write_raw(stunMsg2Str(*e->get_msg()));
	log_file->write_footer();
	
	StunAtrString stun_pass;
	stun_pass.sizeValue = 0;
	char m[STUN_MAX_MESSAGE_SIZE];
	int msg_size = stunEncodeMessage(*e->get_msg(), m, 
		STUN_MAX_MESSAGE_SIZE, stun_pass, false);

	bool msg_sent = false;
	while (!msg_sent) {	
		try {
			sip_socket->sendto(e->dst_addr, e->dst_port, m, msg_size);
			num_non_icmp_errors = 0;
			msg_sent = true;
		} catch (int err) {
			if (!handle_socket_err(err, e->dst_addr, e->dst_port)) {
				// Discard packet.
				msg_sent = true;
			}
		}
	}
}

static void send_nat_keepalive(t_event *event) {
	t_event_nat_keepalive 	*e;
	
	e = (t_event_nat_keepalive *)event;

	assert(e->dst_addr != 0);
	assert(e->dst_port != 0);	
	
	char m[2] = { '\r', '\n' };
	
	bool msg_sent = false;
	while (!msg_sent) {
		try {
			sip_socket->sendto(e->dst_addr, e->dst_port, m, 2);
			num_non_icmp_errors = 0;
			msg_sent = true;
		} catch (int err) {
			if (!handle_socket_err(err, e->dst_addr, e->dst_port)) {
				// Discard packet.
				msg_sent = true;
			}
		}
	}
}

void *sender_udp(void *arg) {
	t_event 	*event;
	t_event_network	*e;

	//t_socket_udp sock;

	while (true) {
		event = evq_sender_udp->pop();
		
		switch(event->get_type()) {
		case EV_NETWORK:
			send_sip_udp(event);
			break;
		case EV_STUN_REQUEST:
			send_stun(event);
			break;
		case EV_NAT_KEEPALIVE:
			send_nat_keepalive(event);
			break;
		default:
			assert(false);
		}


		MEMMAN_DELETE(event);
		delete event;
	}
}
