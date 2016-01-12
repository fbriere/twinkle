/*
    Copyright (C) 2005-2009  Michel de Boer <michel@twinklephone.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef _AUDIO_RX_H
#define _AUDIO_RX_H

// Receive audio from the soundcard and send it to the RTP thread.

#include <assert.h>
#include <queue>
#include <string>

#include "audio_codecs.h"
#include "audio_device.h"
#include "audio_encoder.h"
#include "dtmf_player.h"
#include "media_buffer.h"
#include "user.h"
#include "threads/mutex.h"
#include "threads/sema.h"
#include "twinkle_rtp_session.h"
#include "twinkle_config.h"

#ifdef HAVE_SPEEX
#include <speex/speex.h>
#include <speex/speex_preprocess.h> 
#endif

using namespace std;
using namespace ost;

// Forward declarations
class t_audio_session;
class t_line;

class t_audio_rx {
private:
	// audio_session owning this audio receiver
	t_audio_session *audio_session;
	
	// User profile of user using the line
	// This is a pointer to the user_config owned by a phone user.
	// So this pointer should never be deleted.
	t_user			*user_config;

	// file descriptor audio capture device
	t_audio_io* input_device;

	// RTP session
	t_twinkle_rtp_session *rtp_session;

	// Media buffer to buffer media from the peer audio trasmitter in a
	// 3-way call. This media stream will be mixed with the
	// audio captured from the soundcard.
	t_media_buffer	*media_3way_peer_tx;

	// Media captured by the peer audio receiver in a 3-way conference
	t_media_buffer	*media_3way_peer_rx;

	// The peer audio receiver in a 3-way conference.
	t_audio_rx	*peer_rx_3way;

	// Buffer for mixing purposes in 3-way conference.
	unsigned char	*mix_buf_3way;

	// Indicates if this receiver is part of a 3-way conference call
	bool 		is_3way;

	// Indicates if this is this receiver has to capture sound from the
	// soundcard. In a 3-way call, one receiver captures sound, while the
	// other receiver simply takes the sound from the main receiver.
	bool		is_main_rx_3way;

	// Mutex to protect actions on 3-way conference data
	t_mutex		mtx_3way;
	
	// Audio encoder
	t_audio_encoder	*audio_encoder;

	// Buffer to store PCM samples for ptime ms
	unsigned char	*input_sample_buf;
	
	// Indicates if NAT keep alive packets must be sent during silence
	// suppression.
	bool		use_nat_keepalive;

	// RTP payload
	unsigned short payload_size;
	unsigned char *payload;
	unsigned short nsamples; // number of samples taken per packet

	// Payload type for telephone-event payload.
	int pt_telephone_event;

	// Queue of DTMF tones to be sent
	struct t_dtmf_event {
		t_dtmf_ev	dtmf_tone;
		bool		inband;
	};
	
	queue<t_dtmf_event>	dtmf_queue;
	t_mutex			mtx_dtmf_q;
	t_semaphore		sema_dtmf_q;

	// DTMF player
	t_dtmf_player	*dtmf_player;

	// Inidicates if the recording thread is running
	volatile bool is_running;

	// The thread exits when this indicator is set to true
	volatile bool stop_running;

	// Indicates if a capture failure was already logged (log throttling).
	bool logged_capture_failure;

	// Timestamp for next RTP packet
	unsigned long timestamp;

#ifdef HAVE_SPEEX
	/** Speex preprocessor state */
	SpeexPreprocessState *speex_preprocess_state;
	
	/** Speex VAD enabled? */
	bool speex_dsp_vad;
#endif

	// Get sound samples for 1 RTP packet from the soundcard.
	// Returns false if the main loop has to start another cycle to get
	// samples (e.g. no samples available yet).
	// If not enough samples are available yet, then a 1 ms sleep will be taken.
	// Also returns false if capturing samples from the soundcard failed.
	// Returns true if sounds samples are received. The samples are stored
	// in the payload buffer in the proper encoding.
	// The number bytes of the sound payload is returned in sound_payload_size
	// The silence flag indicates if the returned sound samples represent silence
	// that may be suppressed.
	bool get_sound_samples(unsigned short &sound_payload_size, bool &silence);

	// Get next DTMF event generated by the user.
	// Returns false if there is no next DTMF event
	bool get_dtmf_event(void);

	// Set RTP payload for outgoing sound packets based on the codec.
	void set_sound_payload_format(void);

public:
	// Create the audio receiver
	// _fd		file descriptor of capture device
	// _rtp_session	RTP socket tp send the RTP stream
	// _codec	audio codec to use
	// _ptime	length of the audio packets in ms
	// _ptime = 0 means use default ptime value for the codec
	t_audio_rx(t_audio_session *_audio_session, t_audio_io *_input_device,
		   t_twinkle_rtp_session *_rtp_session,
	           t_audio_codec _codec, unsigned short _payload_id, 
	           unsigned short _ptime = 0);

	~t_audio_rx();
	
	// Set the is running flag
	void set_running(bool running);

	void run(void);

	// Set the dynamic payload type for telephone events
	void set_pt_telephone_event(int pt);

	// Push a new DTMF tone in the DTMF queue
	void push_dtmf(char digit, bool inband);

	// Get phone line belonging to this audio transmitter
	t_line *get_line(void) const;

	// Join a 3-way conference call.
	// main_rx indicates if this receiver must be the main receiver capturing
	// the sound from the soundcard.
	// The peer_rx is the peer receiver (may be NULL(
	void join_3way(bool main_rx, t_audio_rx *peer_rx);

	// Change the peer receiver in a 3-way (set to NULL to erase).
	void set_peer_rx_3way(t_audio_rx *peer_rx);

	// Change the main rx role in a 3-way
	void set_main_rx_3way(bool main_rx);

	// Delete 3rd party from a 3-way conference.
	void stop_3way(void);

	// Post media from the peer transmitter in a 3-way.
	void post_media_peer_tx_3way(unsigned char *media, int len,
		unsigned short peer_sample_rate);

	// Post media from the peer receiver in a 3-way.
	void post_media_peer_rx_3way(unsigned char *media, int len,
		unsigned short peer_sample_rate);

	// Returns if this receiver is the main receiver in a 3-way
	bool get_is_main_rx_3way(void) const;
};

#endif
