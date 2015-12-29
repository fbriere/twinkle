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

#include <cassert>
#include "audio_encoder.h"

//////////////////////////////////////////
// class t_audio_encoder
//////////////////////////////////////////

t_audio_encoder::t_audio_encoder(uint16 payload_id, uint16 ptime, t_user *user_config) :
	_payload_id(payload_id),
	_ptime(ptime),
	_user_config(user_config)
{}

t_audio_codec t_audio_encoder::get_codec(void) const {
	return _codec;
}

uint16 t_audio_encoder::get_payload_id(void) const {
	return _payload_id;
}

uint16 t_audio_encoder::get_ptime(void) const {
	return _ptime;
}

uint16 t_audio_encoder::get_sample_rate(void) const {
	return audio_sample_rate(_codec);
}

uint16 t_audio_encoder::get_max_payload_size(void) const {
	return _max_payload_size;
}


//////////////////////////////////////////
// class t_g711a_audio_encoder
//////////////////////////////////////////

t_g711a_audio_encoder::t_g711a_audio_encoder(uint16 payload_id, uint16 ptime, 
		t_user *user_config) :
	t_audio_encoder(payload_id, ptime, user_config)
{
	_codec = CODEC_G711_ALAW;
	_max_payload_size = audio_sample_rate(_codec)/1000 * ptime;
	if (ptime = 0) _ptime = PTIME_G711_ALAW;
}

uint16 t_g711a_audio_encoder::encode(int16 *sample_buf, uint16 nsamples, 
			uint8 *payload, uint16 payload_size, bool &silence)
{
	assert(nsamples <= payload_size);
	silence = false;
	
	for (int i = 0; i < nsamples; i++) {
		payload[i] = linear2alaw(sample_buf[i]);
	}
	
	return nsamples;	
}


//////////////////////////////////////////
// class t_g711u_audio_encoder
//////////////////////////////////////////

t_g711u_audio_encoder::t_g711u_audio_encoder(uint16 payload_id, uint16 ptime, 
		t_user *user_config) :
	t_audio_encoder(payload_id, ptime, user_config)
{
	_codec = CODEC_G711_ULAW;
	_max_payload_size = audio_sample_rate(_codec)/1000 * ptime;
	if (ptime = 0) _ptime = PTIME_G711_ULAW;
}

uint16 t_g711u_audio_encoder::encode(int16 *sample_buf, uint16 nsamples, 
			uint8 *payload, uint16 payload_size, bool &silence)
{
	assert(nsamples <= payload_size);
	silence = false;

	for (int i = 0; i < nsamples; i++) {
		payload[i] = linear2ulaw(sample_buf[i]);
	}
	
	return nsamples;	
}


//////////////////////////////////////////
// class t_gsm_audio_encoder
//////////////////////////////////////////

t_gsm_audio_encoder::t_gsm_audio_encoder(uint16 payload_id, uint16 ptime, 
		t_user *user_config) :
	t_audio_encoder(payload_id, PTIME_GSM, user_config)
{
	_codec = CODEC_GSM;
	_max_payload_size = 33;
	gsm_encoder = gsm_create();
}

t_gsm_audio_encoder::~t_gsm_audio_encoder() {
	gsm_destroy(gsm_encoder);
}

uint16 t_gsm_audio_encoder::encode(int16 *sample_buf, uint16 nsamples, 
			uint8 *payload, uint16 payload_size, bool &silence)
{
	assert(payload_size >= _max_payload_size);
	silence = false;
	gsm_encode(gsm_encoder, sample_buf, payload);
	return _max_payload_size;
}


#ifdef HAVE_SPEEX
//////////////////////////////////////////
// class t_speex_audio_encoder
//////////////////////////////////////////

t_speex_audio_encoder::t_speex_audio_encoder(uint16 payload_id, uint16 ptime, 
		t_mode mode, t_user *user_config) :
	t_audio_encoder(payload_id, ptime, user_config)
{
	assert(ptime > 0);
	speex_bits_init(&speex_bits);

	switch (mode) {
	case MODE_NB:
		_codec = CODEC_SPEEX_NB;
		speex_enc_state = speex_encoder_init(&speex_nb_mode);
		break;
	case MODE_WB:
		_codec = CODEC_SPEEX_WB;
		speex_enc_state = speex_encoder_init(&speex_wb_mode);
		break;
	case MODE_UWB:
		_codec = CODEC_SPEEX_UWB;
		speex_enc_state = speex_encoder_init(&speex_uwb_mode);
		break;
	default:
		assert(false);
	}
	
	int arg;
	
	// Bit rate type
	switch (_user_config->speex_bit_rate_type) {
	case BIT_RATE_CBR:
		arg = 0;
		speex_encoder_ctl(speex_enc_state, SPEEX_SET_VBR, &arg);
		break;
	case BIT_RATE_VBR:
		arg = 1;
		speex_encoder_ctl(speex_enc_state, SPEEX_SET_VBR, &arg);
		break;
	case BIT_RATE_ABR:
		if (_codec == CODEC_SPEEX_NB) {
			arg = user_config->speex_abr_nb;
			speex_encoder_ctl(speex_enc_state, SPEEX_SET_ABR, &arg);
		} else {
			arg = user_config->speex_abr_wb;
			speex_encoder_ctl(speex_enc_state, SPEEX_SET_ABR, &arg);
		}
		break;
	default:
		assert(false);
	}
	
	// VAD
	arg = (_user_config->speex_vad ? 1 : 0);
	speex_encoder_ctl(speex_enc_state, SPEEX_SET_VAD, &arg);
	
	// DTX
	arg = (_user_config->speex_dtx ? 1 : 0);
	speex_encoder_ctl(speex_enc_state, SPEEX_SET_DTX, &arg);
		
	// Complexity
	arg = _user_config->speex_complexity;
	speex_encoder_ctl(speex_enc_state, SPEEX_SET_COMPLEXITY, &arg);
	
	_max_payload_size = 1500;
}

t_speex_audio_encoder::~t_speex_audio_encoder() {
	speex_bits_destroy(&speex_bits);
	speex_encoder_destroy(speex_enc_state);
}

uint16 t_speex_audio_encoder::encode(int16 *sample_buf, uint16 nsamples, 
			uint8 *payload, uint16 payload_size, bool &silence)
{
	assert(payload_size >= _max_payload_size);

	silence = false;
	speex_bits_reset(&speex_bits);
	if (speex_encode_int(speex_enc_state, sample_buf, &speex_bits) == 0) {
		// Only if DTX is enabled on the speex encoder, then it will 
		// indicate when a frame can be suppressed.
		silence = true;
	}
	return speex_bits_write(&speex_bits, (char *)payload, payload_size);
}
#endif
