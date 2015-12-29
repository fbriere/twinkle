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
#include "line.h"
#include "phone.h"
#include "phone_user.h"
#include "session.h"
#include "util.h"
#include "userintf.h"
#include "audits/memman.h"

extern string user_host;
extern t_phone *phone;

t_session::t_session(t_dialog *_dialog, string _receive_host,
		  unsigned short _receive_port)
{
	dialog = _dialog;
	
	user_config = dialog->get_line()->get_user();
	assert(user_config);

	receive_host = _receive_host;
	retrieve_host = _receive_host;
	receive_port = _receive_port;
	src_sdp_version = int2str(rand());
	src_sdp_id = int2str(rand());
	use_codec = 0;
	recv_dtmf_pt = user_config->dtmf_payload_type;
	send_dtmf_pt = 0;

	offer_codecs = user_config->codecs;
	ptime = user_config->ptime;

	recvd_offer = false;
	recvd_answer = false;
	sent_offer = false;
	direction = SDP_SENDRECV;

	audio_rtp_session = NULL;
	is_on_hold = false;
}

t_session::~t_session() {
	if (audio_rtp_session) {
		MEMMAN_DELETE(audio_rtp_session);
		delete audio_rtp_session;
	}
}

t_session *t_session::create_new_version(void) {
	t_session *s = new t_session(*this);
	MEMMAN_NEW(s);
	s->src_sdp_version = int2str(atoi(src_sdp_version.c_str()) + 1);
	s->recvd_codecs.clear();
	s->recvd_offer = false;
	s->recvd_answer = false;
	s->sent_offer = false;

	// Do not copy the RTP session
	s->set_audio_session(NULL);

	return s;
}

t_session *t_session::create_call_hold(void) {
	t_session *s = create_new_version();

	if (user_config->hold_variant == HOLD_RFC2543) {
		s->receive_host = "0.0.0.0";
	} else if (user_config->hold_variant == HOLD_RFC3264) {
		// RFC 3264 8.4
		if (direction == SDP_SENDRECV) {
			s->direction = SDP_SENDONLY;
		}
		else if (direction == SDP_RECVONLY) {
			s->direction = SDP_INACTIVE;
		}
	} else {
		assert(false);
	}

	return s;
}

t_session *t_session::create_call_retrieve(void) {
	t_session *s = create_new_version();

	if (user_config->hold_variant == HOLD_RFC2543) {
		s->receive_host = retrieve_host;
	} else if (user_config->hold_variant == HOLD_RFC3264) {
		// RFC 3264 8.4
		if (direction == SDP_SENDONLY) {
			s->direction = SDP_SENDRECV;
		}
		else if (direction == SDP_INACTIVE) {
			s->direction = SDP_RECVONLY;
		}
	} else {
		assert(false);
	}

	return s;
}

t_session *t_session::create_clean_copy(void) {
	t_session *s = new t_session(*this);
	MEMMAN_NEW(s);
	dst_sdp_version = "";
	dst_sdp_id = "";
	dst_rtp_host = "";
	dst_rtp_port = 0;
	s->recvd_codecs.clear();
	s->recvd_offer = false;
	s->recvd_answer = false;
	s->sent_offer = false;

	// Do not copy the RTP session
	s->set_audio_session(NULL);

	return s;
}

bool t_session::process_sdp_offer(t_sdp *sdp, int &warn_code,
		string &warn_text)
{
	if (!sdp->is_supported(warn_code, warn_text)) return false;

	dst_sdp_version = sdp->origin.session_version;
	dst_sdp_id = sdp->origin.session_id;
	dst_rtp_host = sdp->get_rtp_host(SDP_AUDIO);
	dst_rtp_port = sdp->get_rtp_port(SDP_AUDIO);
	recvd_codecs = sdp->get_codecs(SDP_AUDIO);
	recvd_sdp_offer = *sdp;

	// The direction in the SDP is from the point of view of the
	// far end. Swap the direction to store it as the point of view
	// from the near end.
	switch(sdp->get_direction(SDP_AUDIO)) {
	case SDP_INACTIVE:
		direction = SDP_INACTIVE;
		break;
	case SDP_SENDONLY:
		direction = SDP_RECVONLY;
		break;
	case SDP_RECVONLY:
		direction = SDP_SENDONLY;
		break;
	case SDP_SENDRECV:
		direction = SDP_SENDRECV;
		break;
	default:
		assert(false);
	}

	// Check if the list of received codec has at least 1 codec
	// in common with the list of codecs we can offer. If there
	// is no common codec, then no call can be established.
	bool supported_codec = false;
	for (list<unsigned short>::const_iterator i = recvd_codecs.begin();
	     i != recvd_codecs.end(); i++)
	{
		if (!supported_codec &&
		    find(offer_codecs.begin(), offer_codecs.end(), *i) !=
					offer_codecs.end())
		{
			// Codec supported
			supported_codec = true;
			use_codec = *i; // this codec goes into answer
		} else if (cmp_nocase(sdp->get_codec_description(SDP_AUDIO, *i),
						SDP_RTPMAP_TELEPHONE_EV) == 0)
		{
			// telephone-event payload is supported
			send_dtmf_pt = *i;
			recv_dtmf_pt = *i; // this goes into answer as well
		}
	}

	if (!supported_codec) {
		warn_code = W_305_INCOMPATIBLE_MEDIA_FORMAT;
		warn_text = "None of the audio codecs is supported";
		return false;
	}

	unsigned short p = sdp->get_ptime(SDP_AUDIO);
	if (p > 0) ptime = p;

	return true;
}

bool t_session::process_sdp_answer(t_sdp *sdp, int &warn_code,
		string &warn_text)
{
	if (!sdp->is_supported(warn_code, warn_text)) return false;

	dst_sdp_version = sdp->origin.session_version;
	dst_sdp_id = sdp->origin.session_id;
	dst_rtp_host = sdp->get_rtp_host(SDP_AUDIO);
	dst_rtp_port = sdp->get_rtp_port(SDP_AUDIO);
	recvd_codecs = sdp->get_codecs(SDP_AUDIO);

	// Find the first codec in the received codecs list that
	// is supported.
	// Per the offer/answer model all received codecs should be
	// supported! It seems that some applications put more codecs
	// in the answer though.
	bool codec_found = false;

	for (list<unsigned short>::const_iterator i = recvd_codecs.begin();
	     i != recvd_codecs.end(); i++)
	{
		if (!codec_found &&
		    find(offer_codecs.begin(), offer_codecs.end(), *i) !=
				offer_codecs.end())
		{
			use_codec = *i;
			codec_found = true;
		} else if (cmp_nocase(sdp->get_codec_description(SDP_AUDIO, *i),
						SDP_RTPMAP_TELEPHONE_EV) == 0)
		{
			// telephone-event payload is supported
			send_dtmf_pt = *i;
		}
	}

	if (!codec_found) {
		// None of the answered codecs is supported
		warn_code = W_305_INCOMPATIBLE_MEDIA_FORMAT;
		warn_text = "None of the codecs is supported";
		return false;
	}

	unsigned short p = sdp->get_ptime(SDP_AUDIO);
	if (p > 0) ptime = p;

	return true;
}

void t_session::create_sdp_offer(t_sip_message *m, const string &user) {
	list<unsigned short>::iterator it_g711a, it_g711u;

	// Delete old body if present
	if (m->body) {
		MEMMAN_DELETE(m->body);
		delete m->body;
	}

	m->body = new t_sdp(user, src_sdp_id, src_sdp_version, USER_HOST(user_config),
			receive_host, receive_port, offer_codecs, recv_dtmf_pt);
	MEMMAN_NEW(m->body);


	// Set ptime for G711 codecs
	it_g711a = find(offer_codecs.begin(), offer_codecs.end(), SDP_FORMAT_G711_ALAW);
	it_g711u = find(offer_codecs.begin(), offer_codecs.end(), SDP_FORMAT_G711_ULAW);
	if (it_g711a != offer_codecs.end() || it_g711u != offer_codecs.end()) {
		((t_sdp *)m->body)->set_ptime(SDP_AUDIO, ptime);
	}

	if (direction != SDP_SENDRECV) {
		((t_sdp *)m->body)->set_direction(SDP_AUDIO, direction);
	}

	m->hdr_content_type.set_media(t_media("application", "sdp"));

	sent_offer = true;
}

void t_session::create_sdp_answer(t_sip_message *m, const string &user) const {
	// Delete old body if present
	if (m->body) {
		MEMMAN_DELETE(m->body);
		delete m->body;
	}

	list<unsigned short> answer_codecs;
	answer_codecs.push_back(use_codec);

	// RFC 3264 6
	// The answer must contain an m-line for each m-line in the offer in
	// the same order. Media can be rejected by setting the port to 0.
	// Only the first audio stream is accepted, all other media streams
	// will be rejected.
	m->body = new t_sdp(user, src_sdp_id, src_sdp_version, USER_HOST(user_config),
				receive_host);
	MEMMAN_NEW(m->body);
	bool audio_answered = false;
	for (list<t_sdp_media>::const_iterator i = recvd_sdp_offer.media.begin();
	     i != recvd_sdp_offer.media.end(); i++)
	{
		if (!audio_answered && i->get_media_type() == SDP_AUDIO &&
		    i->port != 0)
		{
			// Accept the first audio stream
			((t_sdp *)m->body)->add_media(t_sdp_media(
				SDP_AUDIO, receive_port, answer_codecs, recv_dtmf_pt));
			audio_answered = true;
		}
		else
		{
			// Reject media stream by setting port to zero
			t_sdp_media reject_media(*i);
			reject_media.port = 0;
			((t_sdp *)m->body)->add_media(reject_media);
		}
	}

	// Set ptime for G711 codecs
	if (use_codec == SDP_FORMAT_G711_ALAW ||
	    use_codec == SDP_FORMAT_G711_ULAW)
	{
		((t_sdp *)m->body)->set_ptime(SDP_AUDIO, ptime);
	}

	if (direction != SDP_SENDRECV) {
		((t_sdp *)m->body)->set_direction(SDP_AUDIO, direction);
	}

	m->hdr_content_type.set_media(t_media("application", "sdp"));
}

void t_session::start_rtp(void) {
	t_audio_codec codec;

	// If a session is on-hold then do not start RTP.
	if (is_on_hold) return;

	if (receive_host.empty()) return;
	if (dst_rtp_host.empty()) return;

	// Local and remote hold
	if (((receive_host == "0.0.0.0" || receive_port == 0) &&
	     (dst_rtp_host == "0.0.0.0" || dst_rtp_port == 0)) ||
 	    direction == SDP_INACTIVE)
	{
		return;
	}

	switch (use_codec) {
	case SDP_FORMAT_G711_ULAW:
		codec = CODEC_G711_ULAW;
		break;
	case SDP_FORMAT_G711_ALAW:
		codec = CODEC_G711_ALAW;
		break;
	case SDP_FORMAT_GSM:
		codec = CODEC_GSM;
		break;
	default:
		assert(false);
	}

	// Inform user about the codecs
	get_line()->ci_set_send_codec(codec);
	get_line()->ci_set_recv_codec(codec);
	ui->cb_send_codec_changed(get_line()->get_line_number(), codec);
	ui->cb_recv_codec_changed(get_line()->get_line_number(), codec);

	// Start the RTP streams
	if (dst_rtp_host == "0.0.0.0" || dst_rtp_port == 0 ||
	    direction == SDP_RECVONLY)
	{
		// Local hold -> do not send RTP
		audio_rtp_session = new t_audio_session(this,
				LOCAL_IP, get_line()->get_rtp_port(), "", 0, codec, ptime);
		MEMMAN_NEW(audio_rtp_session);
	}
	else if (receive_host == "0.0.0.0" || receive_port == 0 ||
	         direction == SDP_SENDONLY)
	{
		// Remote hold
		// For music on-hold music should be played here.
		// Without music on-hold do not send out RTP
		/*
		audio_rtp_session = new t_audio_session(this,
				"", 0, dst_rtp_host, dst_rtp_port, codec, ptime);
		*/
		return;
	} else {
		// Bi-directional audio
		audio_rtp_session = new t_audio_session(this,
				LOCAL_IP, get_line()->get_rtp_port(),
				dst_rtp_host, dst_rtp_port, codec, ptime);
		MEMMAN_NEW(audio_rtp_session);
	}

	// Check if the created audio session is valid.
	if (!audio_rtp_session->is_valid()) {
		MEMMAN_DELETE(audio_rtp_session);
		delete audio_rtp_session;
		audio_rtp_session = NULL;
		return;
	}

	// Set dynamic payload type for DTMF events
	if (recv_dtmf_pt > 0) {
		audio_rtp_session->set_pt_in_dtmf(recv_dtmf_pt, send_dtmf_pt);
	}

	if (send_dtmf_pt > 0) {
		audio_rtp_session->set_pt_out_dtmf(send_dtmf_pt);
		get_line()->ci_set_dtmf_supported(true);
		ui->cb_dtmf_supported(get_line()->get_line_number());
	} else {
		get_line()->ci_set_dtmf_supported(false);
		ui->cb_line_state_changed();
	}

	audio_rtp_session->run();
}

void t_session::stop_rtp(void) {
	if (audio_rtp_session) {
		MEMMAN_DELETE(audio_rtp_session);
		delete audio_rtp_session;
		audio_rtp_session = NULL;
	}
}

t_audio_session *t_session::get_audio_session(void) const {
	return audio_rtp_session;
}

void t_session::set_audio_session(t_audio_session *as) {
	audio_rtp_session = as;
}

bool t_session::equal_audio(const t_session &s) const {
	// According to RFC 2327, the SDP version in the o= line
	// must be updated when the SDP is changed.
	return (receive_host == s.receive_host &&
		receive_port == s.receive_port &&
		dst_rtp_host == s.dst_rtp_host &&
		dst_rtp_port == s.dst_rtp_port &&
		direction == s.direction &&
		src_sdp_version == s.src_sdp_version &&
		dst_sdp_version == s.dst_sdp_version);
}

void t_session::send_dtmf(char digit) {
	if (audio_rtp_session) audio_rtp_session->send_dtmf(digit);
}

t_line *t_session::get_line(void) const {
	return dialog->get_line();
}

void t_session::set_owner(t_dialog *d) {
	dialog = d;
}

void t_session::hold(void) {
	is_on_hold = true;
}

void t_session::unhold(void) {
	is_on_hold = false;
}

bool t_session::is_rtp_active(void) const {
	return (audio_rtp_session != NULL);
}
