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

#include <iostream>
#include "events.h"
#include "listener.h"
#include "log.h"
#include "translator.h"
#include "user.h"
#include "userintf.h"
#include "util.h"
#include "sockets/socket.h"
#include "parser/parse_ctrl.h"
#include "parser/sip_message.h"
#include "sdp/sdp_parse_ctrl.h"
#include "stun/stun.h"
#include "audits/memman.h"

extern t_phone *phone;
extern t_socket_udp *sip_socket;
extern t_event_queue *evq_trans_mgr;

// Minimal size of a message. Messages below this size will
// be silently discarded.
#define MIN_MESSAGE_SIZE	10

void recvd_stun_msg(char *datagram, int datagram_size, 
	unsigned long src_addr, unsigned short src_port) 
{
	StunMessage m;
	
	if (!stunParseMessage(datagram, datagram_size, m, false)) {
		log_file->write_report("Received faulty STUN message", 
				"::recvd_stun_msg", LOG_STUN, LOG_DEBUG);
		return;
	}
	
	log_file->write_header("::recvd_stun_msg", LOG_STUN);
	log_file->write_raw("Received from: ");
	log_file->write_raw(h_ip2str(src_addr));
	log_file->write_raw(":");
	log_file->write_raw(src_port);
	log_file->write_endl();
	log_file->write_raw(stunMsg2Str(m));
	log_file->write_footer();
	
	evq_trans_mgr->push_stun_response(&m, 0, 0);
}

t_sip_body *parse_body(const string &data, const t_sip_message *msg) {
	if (!msg->hdr_content_type.is_populated()) {
		// Content-Type header is missing. Pass body
		// unparsed. The upper application layer will
		// decide what to do.
		t_sip_body_opaque *p = new t_sip_body_opaque(data);
		MEMMAN_NEW(p);
		return p;
	}

	if (msg->hdr_content_type.media.type == "application" &&
	    msg->hdr_content_type.media.subtype == "sdp")
	{
		// Parse SDP body
		return t_sdp_parser::parse(data);
	} else if (msg->hdr_content_type.media.type == "message" &&
	           msg->hdr_content_type.media.subtype == "sipfrag")
	{
		t_sip_body_sipfrag *b;

		// Parse sipfrag body (RFC 3420)
		try {
			// If the sipfrag does not contain a body itself,
			// then the CRLF at the end of the headers is optional!
			// Add an additional CRLF such that the SIP parser will
			// parse a sipfrag if the CRLF is not present. The SIP
			// parser will stop after it finds the double CRLF. So
			// a 3rd CRLF will not be detected by the parser (yuck).
			t_sip_message *m = t_parser::parse(data + CRLF);
			b = new t_sip_body_sipfrag(m);
			MEMMAN_NEW(b);
			MEMMAN_DELETE(m);
			delete m;
			return b;
		} catch (int) {
			// Parsing failed, maybe because a request or status
			// line is not present, which is not mandatory for a
			// sipfrag body. Add a fake status line and try to parse
			// again.
			string tmp = "SIP/2.0 100 Trying";
			tmp += CRLF;
			tmp += data;
			tmp += CRLF;
			t_sip_message *resp = t_parser::parse(tmp);

			// Parsing succeeded. Now strip the fake header
			t_sip_message *m = new t_sip_message(*resp);
			MEMMAN_NEW(m);
			MEMMAN_DELETE(resp);
			delete (resp);
			b = new t_sip_body_sipfrag(m);
			MEMMAN_NEW(b);
			MEMMAN_DELETE(m);
			delete m;
			return b;
		}
	} else if (msg->hdr_content_type.media.type == "application" &&
	           msg->hdr_content_type.media.subtype == "dtmf-relay")
	{
		t_sip_body_dtmf_relay *b = new t_sip_body_dtmf_relay();
		MEMMAN_NEW(b);
		if (b->parse(data)) return b;
		MEMMAN_DELETE(b);
		delete b;
		throw -1;
	} else if (msg->hdr_content_type.media.type == "application" &&
	           msg->hdr_content_type.media.subtype == "simple-message-summary")
	{
		t_simple_msg_sum_body *b = new t_simple_msg_sum_body();
		MEMMAN_NEW(b);
		if (b->parse(data)) return b;
		MEMMAN_DELETE(b);
		delete b;
		throw -1;
	} else {
		// Pass other bodies unparsed. The upper application
		// layer will decide what to do.
		t_sip_body_opaque *p = new t_sip_body_opaque(data);
		MEMMAN_NEW(p);
		return p;
	}
}

void *listen_udp(void *arg) {
	char		buf[MAX_UDP_SIZE + 1];
	int		data_size;
	string 		datagram;
	unsigned long	src_addr;
	unsigned short	src_port;
	t_sip_message	*msg;
	t_event_network	*ev_network;
	t_event_icmp	*ev_icmp;
	string::size_type	pos_body;	// position of body in msg
	string		log_msg;

	// Number of consecutive non-icmp errors received
	int num_non_icmp_errors = 0;

	while(true) {
		try {
			data_size = sip_socket->recvfrom(src_addr, src_port, buf, 
				MAX_UDP_SIZE + 1);
			num_non_icmp_errors = 0;
		} catch (int err) {
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
				log_msg += strerror(err);
				log_file->write_report(log_msg, "::listen_udp", LOG_NORMAL);
			
				ev_icmp = new t_event_icmp(icmp);
				MEMMAN_NEW(ev_icmp);
				evq_trans_mgr->push(ev_icmp);
				
				num_non_icmp_errors = 0;
			} else {
				// Even if an ICMP message is received this code can get
				//  executed. Sometimes the error is already present on 
				// the socket, but the ICMP message is not yet queued.
				log_msg = "Failed to receive from SIP UDP socket.\n";
				log_msg += "Error code: ";
				log_msg += int2str(err);
				log_msg += "\n";
				log_msg += strerror(err);
				log_file->write_report(log_msg, "::listen_udp");
				
				num_non_icmp_errors++;
				
				/*
				 * non-ICMP errors occur when a destination on the same
				 * subnet cannot be reached. So this code seems to be
				 * harmful.
				if (num_non_icmp_errors > 100) {
					log_msg = "Excessive number of socket errors.";
					log_file->write_report(log_msg, "::listen_udp", 
						LOG_NORMAL, LOG_CRITICAL);
					log_msg = TRANSLATE("Excessive number of socket errors.");
					ui->cb_show_msg(log_msg, MSG_CRITICAL);
					exit(1);
				}
				*/
			}			
			
			continue;
		}
		
		// Some SIP proxies send small keep alive packets to keep
		// NAT bindings open. Discard such small packets as these
		// are not SIP or STUN messages.
		if (data_size < MIN_MESSAGE_SIZE) continue;
		
		// Check if this is a STUN message
		// The first byte of a STUN message is 0x00 or 0x01.
		// A SIP message is ASCII so the first byte for SIP is
		// never 0x00 or 0x01
		if (buf[0] <= 1)
		{
			recvd_stun_msg(buf, data_size, src_addr, src_port);
			continue;
		}
		
		// SIP message received
		log_msg = "Received from: ";
		log_msg += h_ip2str(src_addr);
		log_msg += ":";
		log_msg += int2str(src_port);
		log_msg += "\n";
		
		// The datagram is a SIP message. A SIP message does not
		// contain a 0, so it can be safely converted to a string
		// as recvfrom added a trailing zero.
		datagram = buf;

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
			log_msg += "Invalid SIP message.\n";
			log_msg += "Fatal parse error in headers.\n\n";
			log_msg += to_printable(datagram);
			log_msg += "\n";
			log_file->write_report(log_msg, "::listen_udp", LOG_SIP, LOG_DEBUG);
			continue;
		}

		// Log non-fatal parse errors.
		list<string> l = t_parser::get_parse_errors();
		if (!l.empty()) {
			log_msg += "\n";
			for (list<string>::iterator i = l.begin(); i != l.end(); i++) {
				log_msg += *i;
				log_msg += "\n";
			}
			log_msg += "\n";
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
					log_msg += "Invalid SIP message.\n";
					log_msg += "Parse error in body.\n";
					log_msg += to_printable(datagram);
					log_msg += "\n";
					log_file->write_report(log_msg, "::listen_udp", LOG_SIP, LOG_DEBUG);
					MEMMAN_DELETE(msg);
					delete msg;
					continue;
				}
			}
		}

		log_msg += datagram;
		log_file->write_report(log_msg, "::listen_udp", LOG_SIP);

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
			// When the server transport receives a request over any transport, it
			// MUST examine the value of the "sent-by" parameter in the top Via
			// header field value.  If the host portion of the "sent-by" parameter
			// contains a domain name, or if it contains an IP address that differs
			// from the packet source address, the server MUST add a "received"
			// parameter to that Via header field value.  This parameter MUST
			// contain the source address from which the packet was received.
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
