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

#include <iostream>
#include "events.h"
#include "listener.h"
#include "log.h"
#include "userintf.h"
#include "sockets/socket.h"
#include "parser/parse_ctrl.h"
#include "parser/sip_message.h"
#include "sdp/sdp_parse_ctrl.h"
#include "audits/memman.h"

extern t_socket_udp *sip_socket;
extern t_event_queue *evq_trans_mgr;

t_sip_body *parse_body(string &data, const t_sip_message *msg) {
	if (!msg->hdr_content_type.is_populated()) {
		// Content-Type header is missing. Pass body
		// unparsed. The upper application layer will
		// decide what to do.
		t_sip_body_opaque *p = new t_sip_body_opaque(data);
		MEMMAN_NEW(p);
		return p;
	}

	if (msg->hdr_content_type.media.type != "application" ||
	    msg->hdr_content_type.media.subtype != "sdp")
	{
		// Currenttly only SDP bodies are supported.
		// Pass other bodies unparsed. The upper application
		// layer will decide what to do.
		t_sip_body_opaque *p = new t_sip_body_opaque(data);
		MEMMAN_NEW(p);
		return p;
	}

	// Parse SDP body
	return t_sdp_parser::parse(data);
}

void *listen_udp(void *arg) {
	string 		datagram;
	unsigned long	src_addr;
	unsigned short	src_port;
	t_sip_message	*msg;
	t_event_network	*ev_network;
	int		pos_body;	// position of body in msg

	while(true) {
		try {
			sip_socket->recvfrom(src_addr, src_port, datagram);
		} catch (int err) {
			string msg("Failed to receive from SIP UDP socket.\n");
			msg += strerror(err);
			log_file->write_report(msg, "::listen_udp",
				LOG_NORMAL, LOG_CRITICAL);
			ui->cb_show_msg(msg, MSG_CRITICAL);
			return NULL;
		}

		log_file->write_header("::listen_udp", LOG_SIP);
		log_file->write_raw("Received from: ");
		log_file->write_raw(h_ip2str(src_addr));
		log_file->write_raw(":");
		log_file->write_raw(src_port);
		log_file->write_endl();

		// Split body from header
		string seperator = string(CRLF) + string(CRLF);
		pos_body = datagram.find(seperator);

		// According to RFC 3261 syntax an empty line at
		// the end of the headers is mandatory in all SIP messages.
		// Here a missing empty line is accepted, but maybe
		// the message should be discarded.
		if (pos_body != string::npos) {
			pos_body += seperator.size();
			if (pos_body >= datagram.size()) {
				// No body is present
				pos_body = string::npos;
			}
		}

		// Parse SIP headers
		try {
			msg = t_parser::parse(datagram);
		}
		catch (int) {
			// Discard malformed SIP messages.
			log_file->write_raw("Invalid SIP message.\n");
			log_file->write_raw("Fatal parse error in headers.\n");
			log_file->write_footer();
			continue;
		}

		// Log non-fatal parse errors.
		list<string> l = t_parser::get_parse_errors();
		if (!l.empty()) {
			log_file->write_endl();
			for (list<string>::iterator i = l.begin(); i != l.end(); i++) {
				log_file->write_raw(*i);
				log_file->write_endl();
			}
			log_file->write_endl();
		}

		// Parse body
		if (pos_body != string::npos) {
			try {
				string raw_body = datagram.substr(pos_body);
				msg->body = parse_body(raw_body, msg);
			}
			catch (int) {
				// Discard a SIP response if the body is malformed.
				// For a SIP request with a malformed body, the
				// transaction layer will give an error response.
				if (msg->get_type() == MSG_RESPONSE) {
					log_file->write_raw("Invalid SIP message.\n");
					log_file->write_raw("Parse error in body.\n");
					log_file->write_footer();
					MEMMAN_DELETE(msg);
					delete msg;
					continue;
				}
			}
		}

		log_file->write_raw(datagram);
		log_file->write_footer();

		// If the message does not satisfy the mandatory
		// requirements from RFC 3261, then discard.
		// If the error is non-fatal, then the transaction layer
		// will send a proper error response.
		// If the message is an invalid response message then
		// discard the message. The transaction layer cannot
		// handle an invalid response as it cannot send an
		// error message back on an answer.
		bool fatal;
		string reason;
		if (!msg->is_valid(fatal, reason) &&
		   (fatal || msg->get_type() == MSG_RESPONSE))
		{
			log_file->write_header("::listen_udp", LOG_SIP);
			log_file->write_raw("Discard invalid message.\n");
			log_file->write_raw(reason);
			log_file->write_endl();
			log_file->write_footer();
			MEMMAN_DELETE(msg);
			delete msg;
			continue;
		}

		if (msg->get_type() == MSG_REQUEST) {
			// RFC 3261 18.2.1
			// Add received-parameter to topmost Via-header if needed.
			string src_ip = h_ip2str(src_addr);
			t_via &top_via = msg->hdr_via.via_list.front();
			if (top_via.host != src_ip) {
				top_via.received = src_ip;
				log_file->write_header("::listen_udp", LOG_SIP);
				log_file->write_raw("Added via-parameter received=");
				log_file->write_raw(h_ip2str(src_addr));
				log_file->write_endl();
				log_file->write_footer();
			}

			// RFC 3581 4
			// Add rport value if requested
			if (top_via.rport_present && top_via.rport == 0) {
				top_via.rport = src_port;
			}
		}

		ev_network = new t_event_network(msg);
		MEMMAN_NEW(ev_network);
		ev_network->src_addr = src_addr;
		ev_network->src_port = src_port;
		evq_trans_mgr->push(ev_network);

		MEMMAN_DELETE(msg);
		delete msg;
	}
}
