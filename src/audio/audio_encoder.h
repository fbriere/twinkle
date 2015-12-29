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

// Audio encoders

#ifndef _AUDIO_ENCODER_H
#define _AUDIO_ENCODER_H

#include <cc++/config.h>
#include "twinkle_config.h"
#include "audio_codecs.h"
#include "user.h"
#include "gsm/inc/gsm.h"

#ifdef HAVE_SPEEX
#include <speex/speex.h>
#endif

#ifdef HAVE_ILBC
#include "ilbc/iLBC_define.h"
#endif

// Abstract definition of an audio encoder
class t_audio_encoder {
protected:
	t_audio_codec	_codec;
	uint16		_payload_id;		// payload id for the codec
	uint16		_ptime;			// in milliseconds
	uint16		_max_payload_size;	// maximum size of payload
	
	t_user		*_user_config;
	
	t_audio_encoder(uint16 payload_id, uint16 ptime, t_user *user_config);
	
public:
	virtual ~t_audio_encoder() {};
	
	t_audio_codec get_codec(void) const;
	uint16 get_payload_id(void) const;
	uint16 get_ptime(void) const;
	uint16 get_sample_rate(void) const;
	uint16 get_max_payload_size(void) const;
	
	// Encode a 16-bit PCM sample buffer to a encoded payload
	// Returns the number of bytes written into the payload.
	// The silence flag indicates if the returned sound samples represent silence
	// that may be suppressed.
	virtual uint16 encode(int16 *sample_buf, uint16 nsamples, 
			uint8 *payload, uint16 payload_size, bool &silence) = 0;
};


// G.711 A-law
class t_g711a_audio_encoder : public t_audio_encoder {
public:
	t_g711a_audio_encoder(uint16 payload_id, uint16 ptime, t_user *user_config);
	
	virtual uint16 encode(int16 *sample_buf, uint16 nsamples, 
			uint8 *payload, uint16 payload_size, bool &silence);
};


// G.711 u-law
class t_g711u_audio_encoder : public t_audio_encoder {
public:
	t_g711u_audio_encoder(uint16 payload_id, uint16 ptime, t_user *user_config);
	
	virtual uint16 encode(int16 *sample_buf, uint16 nsamples, 
			uint8 *payload, uint16 payload_size, bool &silence);
};


// GSM
class t_gsm_audio_encoder : public t_audio_encoder {
private:
	gsm 		gsm_encoder;
	
public:
	t_gsm_audio_encoder(uint16 payload_id, uint16 ptime, t_user *user_config);
	virtual ~t_gsm_audio_encoder();
	
	virtual uint16 encode(int16 *sample_buf, uint16 nsamples, 
			uint8 *payload, uint16 payload_size, bool &silence);
};


#ifdef HAVE_SPEEX
class t_speex_audio_encoder : public t_audio_encoder {
public:
	enum t_mode {
		MODE_NB,	// Narrow band
		MODE_WB,	// Wide band
		MODE_UWB	// Ultra wide band
	};
	
private:
	SpeexBits	speex_bits;
	void		*speex_enc_state;
	t_mode		_mode;
	
public:
	t_speex_audio_encoder(uint16 payload_id, uint16 ptime, t_mode mode, 
		t_user *user_config);
	virtual ~t_speex_audio_encoder();
	
	virtual uint16 encode(int16 *sample_buf, uint16 nsamples, 
			uint8 *payload, uint16 payload_size, bool &silence);
};
#endif

#ifdef HAVE_ILBC
class t_ilbc_audio_encoder : public t_audio_encoder {
private:
	iLBC_Enc_Inst_t	_ilbc_encoder;
	uint8		_mode;		// 20, 30 ms (frame size)
	
public:
	t_ilbc_audio_encoder(uint16 payload_id, uint16 ptime, 
		t_user *user_config);
	
	virtual uint16 encode(int16 *sample_buf, uint16 nsamples, 
			uint8 *payload, uint16 payload_size, bool &silence);
};
#endif

#endif
