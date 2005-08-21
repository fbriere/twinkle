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

#ifndef _AUDIO_SESSION_H
#define _AUDIO_SESSION_H

#include <string>
#include <ccrtp/rtp.h>
#include "audio_rx.h"
#include "audio_tx.h"
#include "session.h"
#include "threads/thread.h"
#include "threads/mutex.h"

using namespace std;
using namespace ost;

// Forward declarations
class t_session;
class t_line;

class t_audio_session {
private:
	// SIP session owning this audio session
	t_session	*session;

	// This flag indicates if the created audio session is valid.
	// It might be invalid because, the RTP session could not be created
	// or the soundcard could not be opened.
	bool		valid;

	// file descriptor audio device
	int		fd_speaker;
	int		fd_mic;
	SymmetricRTPSession *rtp_session;

	t_audio_codec	codec;
	unsigned short	ptime;	// in milliseconds

	t_thread	*thr_audio_rx; // recording thread
	t_thread	*thr_audio_tx; // playing thread

	// 3-way conference data
	// Returns if this audio session is part of a 3-way conference
	bool is_3way(void) const;

	// Returns the peer audio session of a 3-way conference
	t_audio_session *get_peer_3way(void) const;

	// Open the sound card
	bool open_dsp(void);
	bool open_dsp_full_duplex(void);
	bool open_dsp_speaker(void);
	bool open_dsp_mic(void);

public:
	t_audio_rx	*audio_rx;
	t_audio_tx	*audio_tx;

	t_audio_session(t_session *_session,
			const string &_recv_host, unsigned short _recv_port,
		        const string &_dst_host, unsigned short _dst_port,
			t_audio_codec _codec, unsigned short _ptime = 0);

	~t_audio_session();

	void run(void);

	// Set outgoing/incoming DTMF dynamic payload types
	void set_pt_out_dtmf(unsigned short pt);
	void set_pt_in_dtmf(unsigned short pt, unsigned short pt_alt);

	// Send DTMF digit
	void send_dtmf(char digit);

	// Get the line that belongs to this audio session
	t_line *get_line(void) const;

	// Become the first session in a 3-way conference
	void start_3way(void);

	// Leave a 3-way conference
	void stop_3way(void);

	// Check if audio session is valid
	bool is_valid(void) const;

	// Get filedescriptor for soundcard
	int get_fd_dsp_speaker(void) const;
	int get_fd_dsp_mic(void) const;
};

// Main functions for rx and tx threads
void *main_audio_rx(void *arg);
void *main_audio_tx(void *arg);

#endif
