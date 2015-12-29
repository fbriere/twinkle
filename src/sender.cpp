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

extern t_socket_udp *sip_socket;
extern t_event_queue *evq_sender_udp;

void *sender_udp(void *arg) {
	t_event 	*event;
	t_event_network	*e;

	//t_socket_udp sock;

	while (true) {
		event = evq_sender_udp->pop();

		assert(event->get_type() == EV_NETWORK);

		e = (t_event_network *)event;

		assert(e->dst_addr != 0);
		assert(e->dst_port != 0);

		log_file->write_header("::sender_udp", LOG_SIP);
		log_file->write_raw("Send to: ");
		log_file->write_raw(h_ip2str(e->dst_addr));
		log_file->write_raw(":");
		log_file->write_raw(e->dst_port);
		log_file->write_endl();

		string m = e->get_msg()->encode();
		log_file->write_raw(m);
		log_file->write_footer();

		try {
			sip_socket->sendto(e->dst_addr, e->dst_port, m);
		} catch (int err) {
			string msg("Failed to send to SIP UDP socket.\n");
			msg += strerror(err);
			log_file->write_report(msg, "::sender_udp",
				LOG_NORMAL, LOG_CRITICAL);
			ui->cb_show_msg(msg, MSG_CRITICAL);
			exit(1);
		}

		MEMMAN_DELETE(e);
		delete e;
	}
}
