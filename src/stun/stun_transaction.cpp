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

#include <cstring>
#include "stun_transaction.h"
#include "events.h"
#include "log.h"
#include "phone.h"
#include "transaction_mgr.h"
#include "util.h"
#include "audits/memman.h"

#define MAX_STUN_TRANSMISSIONS	9

extern t_transaction_mgr	*transaction_mgr;
extern t_event_queue		*evq_trans_layer;
extern t_event_queue		*evq_trans_mgr;
extern t_event_queue		*evq_sender_udp;
extern t_phone			*phone;


bool get_stun_binding(unsigned short src_port, unsigned long &mapped_ip,
	unsigned short &mapped_port, int &err_code, string &err_reason)
{
	unsigned long dst_ipaddr = user_config->stun_server.get_h_ip();
	unsigned short dst_port = user_config->stun_server.get_hport();
	
	if (dst_ipaddr == 0 || dst_port == 0) {
		// Cannot resolve STUN server address.
		log_file->write_header("::get_stun_binding", LOG_NORMAL, LOG_CRITICAL);
		log_file->write_raw("Failed to resolve: ");
		log_file->write_raw(user_config->stun_server.encode());
		log_file->write_endl();
		log_file->write_raw("Return internal STUN bind error: 404 Not Found");
		log_file->write_endl();
		log_file->write_footer();
		
		err_code = 404;
		err_reason = "Not Found";
		return false;
	}
	
	int num_transmissions = 0;
	int wait_intval = DUR_STUN_START_INTVAL;
		
	t_socket_udp sock(src_port);
	sock.connect(dst_ipaddr, dst_port);
		
	StunMessage req_bind;
	StunAtrString stun_null_str;
	stun_null_str.sizeValue = 0;	
		
	while (num_transmissions < MAX_STUN_TRANSMISSIONS) {
		bool ret;
		char buf[STUN_MAX_MESSAGE_SIZE + 1];
		stunBuildReqSimple(&req_bind, stun_null_str, false, false);	
		char m[STUN_MAX_MESSAGE_SIZE];
		int msg_size = stunEncodeMessage(req_bind, m, 
			STUN_MAX_MESSAGE_SIZE, stun_null_str, false);
		sock.send(m, msg_size);
		
		log_file->write_header("::get_stun_binding", LOG_STUN);
		log_file->write_raw("Send to: ");
		log_file->write_raw(h_ip2str(dst_ipaddr));
		log_file->write_raw(":");
		log_file->write_raw(dst_port);
		log_file->write_endl();
		log_file->write_raw(stunMsg2Str(req_bind));
		log_file->write_footer();
			
		try {
			ret = sock.select_read(wait_intval);
		}
		catch (int err) {
			num_transmissions++;
			if (wait_intval < DUR_STUN_MAX_INTVAL) {
				wait_intval *= 2;
			}
			continue;	
		}
			
		if (!ret) {
			num_transmissions++;
			if (wait_intval < DUR_STUN_MAX_INTVAL) {
				wait_intval *= 2;
			}
			continue;
		}
			
		// A message has been received
		msg_size = sock.recv(buf, STUN_MAX_MESSAGE_SIZE + 1);
			
		StunMessage resp_bind;
		
		if (!stunParseMessage(buf, msg_size, resp_bind, false)) {
			log_file->write_report(
				"Received faulty STUN message", "::get_stun_binding", 
					LOG_STUN);
			if (wait_intval < DUR_STUN_MAX_INTVAL) {
				wait_intval *= 2;
			}
			continue;
		}
		
		log_file->write_header("::get_stun_binding", LOG_STUN);
		log_file->write_raw("Received from: ");
		log_file->write_raw(h_ip2str(dst_ipaddr));
		log_file->write_raw(":");
		log_file->write_raw(dst_port);
		log_file->write_endl();
		log_file->write_raw(stunMsg2Str(resp_bind));
		log_file->write_footer();
		
		// Check if id in msgHdr matches
		if (!stunEqualId(resp_bind, req_bind)) {
			if (wait_intval < DUR_STUN_MAX_INTVAL) {
				wait_intval *= 2;
			}
			continue;
		}	
			
		if (resp_bind.msgHdr.msgType == BindResponseMsg && 
		    resp_bind.hasMappedAddress) {
		    	// Bind response received
			mapped_ip = resp_bind.mappedAddress.ipv4.addr;
			mapped_port = resp_bind.mappedAddress.ipv4.port;
			return true;
		}
			
		if (resp_bind.msgHdr.msgType == BindErrorResponseMsg &&
		    resp_bind.hasErrorCode) 
		{
			// Bind error received
			err_code = resp_bind.errorCode.errorClass * 100 +
				   resp_bind.errorCode.number;
			char s[STUN_MAX_STRING + 1];
			strncpy(s, resp_bind.errorCode.reason, STUN_MAX_STRING);
			s[STUN_MAX_STRING] = 0;
			err_reason = s;
			return false;
		}
			
		// A wrong response has been received.
		log_file->write_report(
			"Invalid STUN response received", "::get_stun_binding", 
				LOG_NORMAL);

		err_code = 500;
		err_reason = "Server Error";
		return false;
	}
		
	// Request timed out
	log_file->write_report("STUN request timeout", "::get_stun_binding", 
			LOG_NORMAL);
				
	err_code = 408;
	err_reason = "Request Timeout";
	return false;
}

bool stun_discover_nat(string &err_msg) {
		phone->use_stun = false;
		phone->use_nat_keepalive = false;

		StunAddress4 stun_ip4;
		stun_ip4.addr = user_config->stun_server.get_h_ip();
		stun_ip4.port = user_config->stun_server.get_hport();
	
		if (stun_ip4.addr == 0 || stun_ip4.port == 0) {
			// Cannot resolve STUN server address.
			log_file->write_header("::main", LOG_NORMAL, LOG_CRITICAL);
			log_file->write_raw("Failed to resolve: ");
			log_file->write_raw(user_config->stun_server.encode());
			log_file->write_endl();
			log_file->write_footer();

			err_msg = "Cannot resolve STUN server: ";
			err_msg += user_config->stun_server.encode().c_str();
			return false;
		}

		NatType nat_type = stunNatType(stun_ip4, false);
		log_file->write_header("::main");
		log_file->write_raw("STUN NAT type discovery\n");
		log_file->write_raw("NAT type: ");
		log_file->write_raw(stunNatType2Str(nat_type));
		log_file->write_endl();
		log_file->write_footer();
		
		switch (nat_type) {
		case StunTypeOpen:
			// STUN is not needed.
			break;
		case StunTypeSymNat:
			err_msg = "You are behind a symmetric NAT.\n";
			err_msg += "STUN will not work.\n";
			err_msg += "Configure a public IP address in the user profile\n";
			err_msg += "and create the following static bindings (UDP) in your NAT.\n\n";
			err_msg += "public IP:";
			err_msg += int2str(user_config->sip_udp_port);
			err_msg += " --> private IP:";
			err_msg += int2str(user_config->sip_udp_port);
			err_msg += " (for SIP signaling)\n";
			err_msg += "public IP:";
			err_msg += int2str(user_config->rtp_port);
			err_msg += "-";
			err_msg += int2str(user_config->rtp_port + 5);
			err_msg += " --> private IP:";
			err_msg += int2str(user_config->rtp_port);
			err_msg += "-";
			err_msg += int2str(user_config->rtp_port + 5);
			err_msg += " (for RTP/RTCP)";
			return false;
		case StunTypeSymFirewall:
			// STUN is not needed as we are on a pubic IP.
			// NAT keep alive is needed however to keep the firewall open.
			phone->use_nat_keepalive = true;
			break;
		case StunTypeBlocked:
			err_msg = "Cannot reach the STUN server: ";
			err_msg += user_config->stun_server.encode().c_str();
			err_msg += "\n\n";
			err_msg += "If you are behind a firewall then you need to open ";
			err_msg += "the following UDP ports for a proper working of ";
			err_msg += PRODUCT_NAME;
			err_msg += ":\n";
			err_msg += "Port ";
			err_msg += int2str(user_config->sip_udp_port);
			err_msg += " (for SIP signaling)\n";
			err_msg += "Ports ";
			err_msg += int2str(user_config->rtp_port);
			err_msg += "-";
			err_msg += int2str(user_config->rtp_port + 5);
			err_msg += " (for RTP/RTCP)";
			return false;
		case StunTypeFailure:
			err_msg = "NAT type discovery via STUN failed.\n";
			return false;
		default:
			// Use STUN.
			phone->use_stun = true;
			phone->use_nat_keepalive = true;
		}
		
		return true;
}


// Main function for STUN listener thread for media STUN requests.
void *stun_listen_main(void *arg) {
	char		buf[STUN_MAX_MESSAGE_SIZE + 1];
	int		data_size;
	
	t_socket_udp *sock = (t_socket_udp *)arg;
	
	while(true) {
		try {
			data_size = sock->recv(buf, STUN_MAX_MESSAGE_SIZE + 1);
		} catch (int err) {
			string msg("Failed to receive STUN response for media.\n");
			msg += strerror(err);
			log_file->write_report(msg, "::stun_listen_main",
				LOG_NORMAL, LOG_CRITICAL);
				
			// The request will timeout, no need to send a response now.
				
			return NULL;
		}
		
		StunMessage m;
		
		if (!stunParseMessage(buf, data_size, m, false)) {
			log_file->write_report("Faulty STUN message", "::stun_listen_main");
			continue;
		}
		
		log_file->write_header("::stun_listen_main", LOG_STUN);
		log_file->write_raw("Received: ");
		log_file->write_raw(stunMsg2Str(m));
		log_file->write_footer();
	
		evq_trans_mgr->push_stun_response(&m, 0, 0);
	}
}

//////////////////////////////////////////////
// Base STUN transaction
//////////////////////////////////////////////

t_mutex t_stun_transaction::mtx_class;
t_tid t_stun_transaction::next_id = 1;

t_stun_transaction::t_stun_transaction(StunMessage *r,
			   unsigned short _tuid, unsigned long ipaddr,
			   unsigned short port) 
{
	mtx_class.lock();
	id = next_id++;
	if (next_id == 65535) next_id = 1;
	mtx_class.unlock();
	
	state = TS_NULL;
	request = new StunMessage(*r);
	MEMMAN_NEW(request);
	tuid = _tuid;
	
	dur_req_timeout = DUR_STUN_START_INTVAL;
	num_transmissions = 0;
	
	dst_ipaddr = ipaddr;
	dst_port = port;
}

t_stun_transaction::~t_stun_transaction() {
	MEMMAN_DELETE(request);
	delete request;
}

t_tid t_stun_transaction::get_id(void) const {
	return id;
}

t_trans_state t_stun_transaction::get_state(void) const {
	return state;
}

void t_stun_transaction::start_timer_req_timeout(void) {
	timer_req_timeout = transaction_mgr->start_stun_timer(dur_req_timeout,
		STUN_TMR_REQ_TIMEOUT, id);
		
	// RFC 3489 9.3
	// Double the retransmision interval till a maximum
	if (dur_req_timeout < DUR_STUN_MAX_INTVAL) {
		dur_req_timeout = 2 * dur_req_timeout;
	}
}

void t_stun_transaction::stop_timer_req_timeout(void) {
	if (timer_req_timeout) {
		transaction_mgr->stop_timer(timer_req_timeout);
		timer_req_timeout = 0;
	}
}

void t_stun_transaction::process_response(StunMessage *r) {
	stop_timer_req_timeout();
	evq_trans_layer->push_stun_response(r, tuid, id);
	state = TS_TERMINATED;
}

void t_stun_transaction::timeout(t_stun_timer t) {
	// RFC 3489 9.3
	if (num_transmissions < MAX_STUN_TRANSMISSIONS) {
		retransmit();
		start_timer_req_timeout();
		return;
	}
	
	// Report timeout to TU
	StunMessage *timeout_resp;
	timeout_resp = stunBuildError(*request, 408, "Request Timeout");
	log_file->write_report("STUN request timeout", "t_stun_transaction::timeout", 
			LOG_NORMAL);
	
	evq_trans_layer->push_stun_response(timeout_resp, tuid, id);
	MEMMAN_DELETE(timeout_resp);
	delete timeout_resp;
	
	state = TS_TERMINATED;
}

bool t_stun_transaction::match(StunMessage *resp) const {
	return stunEqualId(*resp, *request);
}

//////////////////////////////////////////////
// SIP STUN transaction
//////////////////////////////////////////////

void t_sip_stun_trans::retransmit(void) {
	// The SIP UDP sender will send out the STUN request.
	evq_sender_udp->push_stun_request(request, TYPE_STUN_SIP, tuid, id,
		dst_ipaddr, dst_port);
	num_transmissions++;
}

t_sip_stun_trans::t_sip_stun_trans(StunMessage *r,
			unsigned short _tuid, unsigned long ipaddr,
			unsigned short port) :
		t_stun_transaction(r, _tuid, ipaddr, port)
{
	// The SIP UDP sender will send out the STUN request.
	evq_sender_udp->push_stun_request(request, TYPE_STUN_SIP, tuid, id,
		dst_ipaddr, dst_port);
	num_transmissions++;
	start_timer_req_timeout();	
	state = TS_PROCEEDING;
}

//////////////////////////////////////////////
// Media STUN transaction
//////////////////////////////////////////////

void t_media_stun_trans::retransmit(void) {
	// Retransmit the STUN request
	StunAtrString stun_pass;
	stun_pass.sizeValue = 0;
	char m[STUN_MAX_MESSAGE_SIZE];
	int msg_size = stunEncodeMessage(*request, m, STUN_MAX_MESSAGE_SIZE, stun_pass, false);
	
	try {
		sock->sendto(dst_ipaddr, dst_port, m, msg_size);
	} catch (int err) {
		string msg("Failed to send STUN request for media.\n");
		msg += strerror(err);
		log_file->write_report(msg, "::t_media_stun_trans::retransmit",
			LOG_NORMAL, LOG_CRITICAL);
			
		StunMessage *resp;
		resp = stunBuildError(*request, 500, "Could not send request");

		evq_trans_layer->push_stun_response(resp, tuid, id);
		MEMMAN_DELETE(resp);
		delete resp;
			
		return;
	}
	
	num_transmissions++;
}

t_media_stun_trans::t_media_stun_trans(StunMessage *r,
			 unsigned short _tuid, unsigned long _dst_ipaddr,
			 unsigned short _dst_port, unsigned short src_port) :
		t_stun_transaction(r, _tuid, _dst_ipaddr, _dst_port)
{
	thr_listen = NULL;
	
	try {
		sock = new t_socket_udp(src_port);
		MEMMAN_NEW(sock);
		sock->connect(dst_ipaddr, dst_port);
	} catch (int err) {
		string msg("Failed to create a UDP socket (STUN) on port ");
		msg += int2str(src_port);
		msg += "\n";
		// NOTE: I tried to use strerror_r, but it fails with Illegal seek
		msg += strerror(err);
		log_file->write_report(msg, "t_media_stun_trans::t_media_stun_trans", LOG_NORMAL, 
			LOG_CRITICAL);
		delete sock;
		sock = NULL;
		
		StunMessage *resp;
		resp = stunBuildError(*request, 500, "Could not create socket");

		evq_trans_layer->push_stun_response(resp, tuid, id);
		MEMMAN_DELETE(resp);
		delete resp;
		
		return;
	}
	
	// Send STUN request
	StunAtrString stun_pass;
	stun_pass.sizeValue = 0;
	char m[STUN_MAX_MESSAGE_SIZE];
	int msg_size = stunEncodeMessage(*r, m, STUN_MAX_MESSAGE_SIZE, stun_pass, false);
	
	try {
		sock->send(m, msg_size);
	} catch (int err) {
		string msg("Failed to send STUN request for media.\n");
		msg += strerror(err);
		log_file->write_report(msg, "::t_media_stun_trans::t_media_stun_trans",
			LOG_NORMAL, LOG_CRITICAL);

		StunMessage *resp;
		resp = stunBuildError(*request, 500, "Failed to send request");

		evq_trans_layer->push_stun_response(resp, tuid, id);
		MEMMAN_DELETE(resp);
		delete resp;
		
		return;
	}
	
	num_transmissions++;
	
	try {
		thr_listen = new t_thread(stun_listen_main, sock);
		MEMMAN_NEW(thr_listen);
	} catch (int) {
		log_file->write_report("Failed to create STUN listener thread.",
			"::t_media_stun_trans::t_media_stun_trans",
			LOG_NORMAL, LOG_CRITICAL);
		delete thr_listen;
		thr_listen = NULL;

		StunMessage *resp;
		resp = stunBuildError(*request, 500, "Failed to create STUN listen thread");

		evq_trans_layer->push_stun_response(resp, tuid, id);
		MEMMAN_DELETE(resp);
		delete resp;		
		
		return;
	}
	
	start_timer_req_timeout();
	state = TS_PROCEEDING;
}

t_media_stun_trans::~t_media_stun_trans() {
	if (sock) {
		MEMMAN_DELETE(sock);
		delete sock;
	}
	
	if (thr_listen) {
		thr_listen->cancel();
		thr_listen->join();
		MEMMAN_DELETE(thr_listen);
		delete thr_listen;
	}
}


