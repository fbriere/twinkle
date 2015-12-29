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

// Session description of an established session.
// A session is the media part of a dialog.

#ifndef _SESSION_H
#define _SESSION_H

#include <list>
#include <string>
#include "dialog.h"
#include "sdp/sdp.h"
#include "parser/sip_message.h"
#include "audio/audio_session.h"

// Forward declarations
class t_dialog;
class t_line;

using namespace std;

class t_session {
private:
	// The owning dialog
	t_dialog		*dialog;

	// Copy of host needed for call-retrieve after call-hold
	string			retrieve_host;

	// Audio RTP session
	t_audio_session		*audio_rtp_session;

public:
	// Audio session information

	// Near end information
	string			src_sdp_version;
	string			src_sdp_id;
	string			receive_host; // RTP receive host address
	unsigned short		receive_port; // RTP receive port

	// Far end information
	string			dst_sdp_version;
	string			dst_sdp_id;
	string			dst_rtp_host;
	unsigned short		dst_rtp_port;

	// Direction of the audio stream from this phone's point of view
	t_sdp_media_direction	direction;

	list<unsigned short>	offer_codecs;	// codecs to offer in outgoing INVITE
	list<unsigned short>	recvd_codecs;	// codecs received from far-end
	unsigned short		use_codec;	// codec to be used
	unsigned short		ptime;		// payload size (ms)
	bool			recvd_offer;  	// offer received?
	bool			recvd_answer; 	// answer received?
	bool			sent_offer;	// offer sent?
	unsigned short		recv_dtmf_pt;	// payload type for DTMF receiving
	unsigned short		send_dtmf_pt;	// payload type for DTMF sending
	t_sdp			recvd_sdp_offer;

	t_session(t_dialog *_dialog, string _receive_host,
		  unsigned short _receive_port);

	// The destructor will destroy the RTP session and stop the
	// RTP streams
	~t_session();

	// NOTE: copies of a session do not copy the audio RTP session!

	// Create a session based on an existing session, i.e.
	// same reveive user and host, same version. new id.
	t_session *create_new_version(void);

	// Create a copy of the session. The destination paramters
	// and recvd/offer and answer are erased in the copy.
	t_session *create_clean_copy(void);

	// Create a session for call-hold
	t_session *create_call_hold(void);

	// Create a session for call-retrieve
	t_session *create_call_retrieve(void);

	// Process incoming SDP offer. Return false if SDP is not
	// supported. If SDP is supported then use_codec will be
	// set to the first codec in the received offer that is
	// supported by this phone, i.e. this is the codec that should
	// be put in the answer.
	bool process_sdp_offer(t_sdp *sdp, int &warn_code, string &warn_text);

	// Process incoming SDP answer. Return false if SDP is not
	// supported. It is expected that the answer contains 1 codec
	// only. If more codecs are answered, then only the first supported
	// codec is considered.
	bool process_sdp_answer(t_sdp *sdp, int &warn_code, string &warn_text);

	// Create an SDP offer body for a SIP message
	void create_sdp_offer(t_sip_message *m, const string &user);

	// Create an SDP answer body for a SIP message
	void create_sdp_answer(t_sip_message *m, const string &user) const;

	// Start/stop the RTP streams
	void start_rtp(void);
	void stop_rtp(void);

	t_audio_session *get_audio_session(void) const;
	void set_audio_session(t_audio_session *as);

	// Check if two session are equal wrt the audio parameters
	bool equal_audio(const t_session &s) const;

	// Send DTMF digit
	void send_dtmf(char digit);

	// Get the line that belongs to this session
	t_line *get_line(void) const;

	// Transfer ownership of this session to a new dialog
	void set_owner(t_dialog *d);
};

#endif
