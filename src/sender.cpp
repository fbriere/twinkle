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
#include "events.h"
#include "log.h"
#include "sender.h"
#include "userintf.h"
#include "sockets/socket.h"
#include "parser/parse_ctrl.h"
#include "parser/sip_message.h"
#include "audits/memman.h"
#include "stun/stun.h"

extern t_socket_udp *sip_socket;
extern t_event_queue *evq_sender_udp;

void send_sip_udp(t_event *event) {
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
		
	try {
		sip_socket->sendto(e->dst_addr, e->dst_port, m.c_str(), m.size());
	} catch (int err) {
		string msg("Failed to send to SIP UDP socket.\n");
		msg += strerror(err);
		log_file->write_report(msg, "::send_sip_udp",
			LOG_NORMAL, LOG_CRITICAL);
		ui->cb_show_msg(msg, MSG_CRITICAL);
		exit(1);
	}
}

void send_stun(t_event *event) {
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
	
	try {
		sip_socket->sendto(e->dst_addr, e->dst_port, m, msg_size);
	} catch (int err) {
		string msg("Failed to send STUN request to SIP UDP socket.\n");
		msg += strerror(err);
		log_file->write_report(msg, "::send_stun",
			LOG_NORMAL, LOG_CRITICAL);
		ui->cb_show_msg(msg, MSG_CRITICAL);
		exit(1);
	}	
}

void send_nat_keepalive(t_event *event) {
	t_event_nat_keepalive 	*e;
	
	e = (t_event_nat_keepalive *)event;

	assert(e->dst_addr != 0);
	assert(e->dst_port != 0);	
	
	char m[2] = { 'M', 'B' };
	
	try {
		sip_socket->sendto(e->dst_addr, e->dst_port, m, 2);
	} catch (int err) {
		string msg("Failed to send NAT keepalive packet.\n");
		msg += strerror(err);
		log_file->write_report(msg, "::send_nat_keepalive",
			LOG_NORMAL, LOG_CRITICAL);
		// Do not exit the program as failing to send a NAT keepalive
		// is not fatal. If this is a persistent error, then the program
		// will end with sending the next STUN or SIP message.
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
