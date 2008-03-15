/*
    Copyright (C) 2005-2008  Michel de Boer <michel@twinklephone.com>

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
#include <ctime>
#include <cstring>
#include <cerrno>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "events.h"
#include "log.h"
#include "sender.h"
#include "translator.h"
#include "userintf.h"
#include "util.h"
#include "sockets/connection_table.h"
#include "sockets/socket.h"
#include "parser/parse_ctrl.h"
#include "parser/sip_message.h"
#include "audits/memman.h"
#include "stun/stun.h"

#define MAX_TRANSMIT_RETRIES	3

extern t_socket_udp *sip_socket;
extern t_connection_table *connection_table;
extern t_event_queue *evq_sender;
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
		log_msg += int2str(err);
		log_msg += " ";
		log_msg += get_error_str(err);
		log_file->write_report(log_msg, "::hanlde_socket_err", LOG_NORMAL);

		evq_trans_mgr->push_icmp(icmp);
		
		num_non_icmp_errors = 0;
		
		// If the ICMP error comes from the same destination as the
		// destination of the packet that failed to be sent, then the
		// packet should be discarded as it can most likely not be
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
		log_msg += "Error code: ";
		log_msg += int2str(err);
		log_msg += "\n";
		log_msg += get_error_str(err);
		log_file->write_report(log_msg, "::handle_socket_err");
		
		num_non_icmp_errors++;
		
		/*
		 * non-ICMP errors occur when a destination on the same
		 * subnet cannot be reached. So this code seems to be
		 * harmful.
		if (num_non_icmp_errors > 100) {
			log_msg = "Excessive number of socket errors.";
			log_file->write_report(log_msg, "::handle_socket_err", 
				LOG_NORMAL, LOG_CRITICAL);
			log_msg = TRANSLATE("Excessive number of socket errors.");
			ui->cb_show_msg(log_msg, MSG_CRITICAL);
			exit(1);
		}
		*/
	}
	
	return true;
}

static void send_sip_udp(t_event *event) {
	t_event_network	*e;
	
	e = (t_event_network *)event;
	
	assert(e->dst_addr != 0);
	assert(e->dst_port != 0);

	// Set correct transport in topmost Via header of a request.
	// For a response the Via header is copied from the incoming request.
	t_sip_message *sip_msg = e->get_msg();
	if (sip_msg->get_type() == MSG_REQUEST) {
		sip_msg->hdr_via.via_list.front().transport = "UDP";
	}
	
	string m = sip_msg->encode();
	log_file->write_header("::send_sip_udp", LOG_SIP);
	log_file->write_raw("Send to: udp:");
	log_file->write_raw(h_ip2str(e->dst_addr));
	log_file->write_raw(":");
	log_file->write_raw(e->dst_port);
	log_file->write_endl();
	log_file->write_raw(m);
	log_file->write_endl();
	log_file->write_footer();
		
	bool msg_sent = false;
	int transmit_count = 0;
	while (!msg_sent && transmit_count++ <= MAX_TRANSMIT_RETRIES) {
		try {
			sip_socket->sendto(e->dst_addr, e->dst_port, m.c_str(), m.size());
			num_non_icmp_errors = 0;
			msg_sent = true;
		} catch (int err) {
			if (!handle_socket_err(err, e->dst_addr, e->dst_port)) {
				// Discard packet.
				msg_sent = true;
			} else {
				if (transmit_count <= MAX_TRANSMIT_RETRIES) {
					// Sleep 100 ms
					struct timespec sleeptimer;
					sleeptimer.tv_sec = 0;
					sleeptimer.tv_nsec = 100000000;
					nanosleep(&sleeptimer, NULL);
				}
			}
		}
	}
}

static void send_sip_tcp(t_event *event) {
	t_event_network	*e;
	bool new_connection = false;
	
	e = (t_event_network *)event;
	unsigned long dst_addr = e->dst_addr;
	unsigned short dst_port = e->dst_port;
	
	assert(dst_addr != 0);
	assert(dst_port != 0);
	
	// Set correct transport in topmost Via header of a request.
	// For a response the Via header is copied from the incoming request.
	t_sip_message *sip_msg = e->get_msg();
	if (sip_msg->get_type() == MSG_REQUEST) {
		sip_msg->hdr_via.via_list.front().transport = "TCP";
	}
	
	t_connection *conn = connection_table->get_connection(dst_addr, dst_port);
	
	// If a connection exists then re-use this connection. Otherwise a new connection
	// must be opened.
	// For a request a connection to the destination address and port of the event
	// must be opened.
	// For a response a connection to the sent-by address and port in the Via header
	// must be opened.
	
	if (!conn) {
		if (sip_msg->get_type() == MSG_RESPONSE) {
			t_ip_port dst_ip_port;
			sip_msg->hdr_via.get_response_dst(dst_ip_port);
			dst_addr = dst_ip_port.ipaddr;
			dst_port = dst_ip_port.port;
		}
		
		t_socket_tcp *tcp = new t_socket_tcp();
		MEMMAN_NEW(tcp);
		
		log_file->write_header("::send_sip_tcp", LOG_SIP, LOG_DEBUG);
		log_file->write_raw("Open connection to ");
		log_file->write_raw(h_ip2str(dst_addr));
		log_file->write_raw(":");
		log_file->write_raw(dst_port);
		log_file->write_endl();
		log_file->write_footer();
		
		try {
			tcp->connect(dst_addr, dst_port);
		} catch (int err) {
			evq_trans_mgr->push_failure(FAIL_TRANSPORT,
				sip_msg->hdr_via.via_list.front().branch,
				sip_msg->hdr_cseq.method);
			
			log_file->write_header("::send_sip_tcp", LOG_SIP, LOG_WARNING);
			log_file->write_raw("Failed to open connection to ");
			log_file->write_raw(h_ip2str(dst_addr));
			log_file->write_raw(":");
			log_file->write_raw(dst_port);
			log_file->write_endl();
			log_file->write_footer();
			
			delete tcp;
			MEMMAN_DELETE(tcp);
			
			return;
		}
		
		conn = new t_connection(tcp);
		MEMMAN_NEW(conn);
		
		new_connection = true;
	}
		
	// NOTE: if an existing connection was found, the connection table is now locked.

	string m = sip_msg->encode();
	log_file->write_header("::send_sip_tcp", LOG_SIP);
	log_file->write_raw("Send to: tcp:");
	log_file->write_raw(h_ip2str(dst_addr));
	log_file->write_raw(":");
	log_file->write_raw(dst_port);
	log_file->write_endl();
	log_file->write_raw(m);
	log_file->write_endl();
	log_file->write_footer();
	
	conn->async_send(m.c_str(), m.size());
	
	if (new_connection) {
		connection_table->add_connection(conn);
	} else {
		connection_table->unlock();
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
	int transmit_count = 0;
	while (!msg_sent && transmit_count++ <= MAX_TRANSMIT_RETRIES) {	
		try {
			sip_socket->sendto(e->dst_addr, e->dst_port, m, msg_size);
			num_non_icmp_errors = 0;
			msg_sent = true;
		} catch (int err) {
			if (!handle_socket_err(err, e->dst_addr, e->dst_port)) {
				// Discard packet.
				msg_sent = true;
			} else {
				if (transmit_count <= MAX_TRANSMIT_RETRIES) {
					// Sleep 100 ms
					struct timespec sleeptimer;
					sleeptimer.tv_sec = 0;
					sleeptimer.tv_nsec = 100000000;
					nanosleep(&sleeptimer, NULL);
				}
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
	int transmit_count = 0;
	while (!msg_sent && transmit_count++ <= MAX_TRANSMIT_RETRIES) {
		try {
			sip_socket->sendto(e->dst_addr, e->dst_port, m, 2);
			num_non_icmp_errors = 0;
			msg_sent = true;
		} catch (int err) {
			if (!handle_socket_err(err, e->dst_addr, e->dst_port)) {
				// Discard packet.
				msg_sent = true;
			} else {
				if (transmit_count <= MAX_TRANSMIT_RETRIES) {
					// Sleep 100 ms
					struct timespec sleeptimer;
					sleeptimer.tv_sec = 0;
					sleeptimer.tv_nsec = 100000000;
					nanosleep(&sleeptimer, NULL);
				}
			}
		}
	}
}

void *tcp_sender_loop(void *arg) {
	string log_msg;
	list<t_connection *> writable_connections;
	
	while(true) {
		writable_connections.clear();
		writable_connections = connection_table->select_write(NULL);
		
		if (writable_connections.empty()) {
			// Another thread cancelled the select command.
			// Stop listening.
			break;
		}
		
		// NOTE: The connection table is now locked.
		
		for (list<t_connection *>::iterator it = writable_connections.begin();
			it != writable_connections.end(); ++it)
		{
			try {
				(*it)->write();
			} catch (int err) {
				if (err == EAGAIN || err == EWOULDBLOCK || err == EINTR) {
					continue;
				}
				
				unsigned long remote_addr;
				unsigned short remote_port;
			
				(*it)->get_remote_address(remote_addr, remote_port);
				
				log_msg = "Got error on socket to ";
				log_msg += h_ip2str(remote_addr);
				log_msg += ":";
				log_msg += int2str(remote_port);
				log_msg += " - ";
				log_msg += get_error_str(err);
				log_file->write_report(log_msg, "::tcp_sender_loop", LOG_SIP, LOG_WARNING);
				
				// Connection is broken. Remove it.
				connection_table->remove_connection(*it);
				MEMMAN_DELETE(*it);
				delete *it;
				
				continue;
			}
		}
		
		connection_table->unlock();
	}
	
	log_file->write_report("TCP sender terminated.", "::tcp_sender_loop");
}

void *sender_loop(void *arg) {
	t_event 	*event;
	t_event_network	*ev_network;
	unsigned long	local_ipaddr;

	bool quit = false;
	while (!quit) {
		event = evq_sender->pop();
		
		switch(event->get_type()) {
		case EV_NETWORK:
			ev_network = dynamic_cast<t_event_network *>(event);
			local_ipaddr = get_src_ip4_address_for_dst(ev_network->dst_addr);
			
			if (local_ipaddr == 0) {
				log_file->write_header("::sender_loop", LOG_NORMAL, LOG_CRITICAL);
				log_file->write_raw("Cannot get source IP address for destination: ");
				log_file->write_raw(h_ip2str(ev_network->dst_addr));
				log_file->write_endl();
				log_file->write_footer();
				
				evq_trans_mgr->push_failure(FAIL_TRANSPORT,
					ev_network->get_msg()->hdr_via.via_list.front().branch,
					ev_network->get_msg()->hdr_cseq.method);
				break;
			}
			
			if (!ev_network->get_msg()->local_ip_check()) {
				log_file->write_report("Local IP check failed",
					"::sender_loop", LOG_NORMAL, LOG_CRITICAL);
				break;
			}
			
			if (ev_network->transport == "udp") {
				send_sip_udp(event);
			} else if (ev_network->transport == "tcp") {
				send_sip_tcp(event);
			} else {
				log_file->write_header("::sender_loop", LOG_NORMAL, LOG_WARNING);
				log_file->write_raw("Received unsupported transport: ");
				log_file->write_raw(ev_network->transport);
				log_file->write_endl();
				log_file->write_footer();
			}
			break;
		case EV_STUN_REQUEST:
			send_stun(event);
			break;
		case EV_NAT_KEEPALIVE:
			send_nat_keepalive(event);
			break;
		case EV_QUIT:
			quit = true;
			break;
		default:
			assert(false);
		}

		MEMMAN_DELETE(event);
		delete event;
	}
}
