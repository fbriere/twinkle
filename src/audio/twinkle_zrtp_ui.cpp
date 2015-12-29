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

// Author: Werner Dittmann <Werner.Dittmann@t-online.de>, (C) 2006
//         Michel de Boer <michel@twinklephone.com>
#include "twinkle_zrtp_ui.h"

#ifdef HAVE_ZRTP

#include "phone.h"
#include "line.h"
#include "log.h"
#include "util.h"

using namespace std;

extern t_phone *phone;

TwinkleZrtpUI::TwinkleZrtpUI(ZrtpQueue* queue, t_audio_session* session) :
            ZrtpUserCallback(queue), audioSession(session) 
{}

void TwinkleZrtpUI::secureOn(std::string cipher) {
	audioSession->set_is_encrypted(true);
	audioSession->set_srtp_cipher_mode(cipher);
	
	t_line *line = audioSession->get_line();
	int lineno = line->get_line_number();

	log_file->write_header("TwinkleZrtpUI::secureOn");
	log_file->write_raw("Line ");
	log_file->write_raw(lineno + 1);
	log_file->write_raw(": audio encryption enabled: ");
	log_file->write_raw(cipher);
	log_file->write_endl();
	log_file->write_footer();
	
	ui->cb_async_line_encrypted(lineno, true);
	ui->cb_async_line_state_changed();
}

void TwinkleZrtpUI::secureOff() {
	audioSession->set_is_encrypted(false);
	
	t_line *line = audioSession->get_line();
	int lineno = line->get_line_number();

	log_file->write_header("TwinkleZrtpUI::secureOff");
	log_file->write_raw("Line ");
	log_file->write_raw(lineno + 1);
	log_file->write_raw(": audio encryption disabled.\n");
	log_file->write_footer();
	
	ui->cb_async_line_encrypted(lineno, false);
	ui->cb_async_line_state_changed();
}

void TwinkleZrtpUI::showSAS(std::string sas) {
	audioSession->set_zrtp_sas(sas);
	audioSession->set_zrtp_sas_confirmed(false);
	
	t_line *line = audioSession->get_line();
	int lineno = line->get_line_number();

	log_file->write_header("TwinkleZrtpUI::showSAS");
	log_file->write_raw("Line ");
	log_file->write_raw(lineno + 1);
	log_file->write_raw(": SAS =");
	log_file->write_raw(sas);
	log_file->write_endl();
	log_file->write_footer();

	ui->cb_async_show_zrtp_sas(lineno, sas);
	ui->cb_async_line_state_changed();
}

void TwinkleZrtpUI::confirmGoClear() {
	t_line *line = audioSession->get_line();
	int lineno = line->get_line_number();
	
	ui->cb_async_zrtp_confirm_go_clear(lineno);
}

void TwinkleZrtpUI::showMessage(MessageSeverity sev, std::string message) {
	t_line *line = audioSession->get_line();
	int lineno = line->get_line_number();
	
	string msg = "Line ";
	msg += int2str(lineno + 1);
	msg += ": ";
	msg += message;
	
	switch (sev) {
	case Info:
		log_file->write_report(msg, "TwinkleZrtpUI::showMessage", LOG_NORMAL,
			LOG_INFO);
		break;
	case Warning:
		log_file->write_report(msg, "TwinkleZrtpUI::showMessage", LOG_NORMAL,
			LOG_WARNING);
		break;
	default:
		log_file->write_report(msg, "TwinkleZrtpUI::showMessage", LOG_NORMAL,
			LOG_CRITICAL);
	}
}

void TwinkleZrtpUI::zrtpNegotiationFailed(MessageSeverity severity, std::string msg) {
	t_line *line = audioSession->get_line();
	int lineno = line->get_line_number();
	
	string m = "Line ";
	m += int2str(lineno + 1);
	m += ": ZRTP negotiation failed.\n";
	m += msg;
	
	switch (severity) {
	case Info:
		log_file->write_report(m, "TwinkleZrtpUI::zrtpNegotiationFailed", LOG_NORMAL,
			LOG_INFO);
		break;
	case Warning:
		log_file->write_report(m, "TwinkleZrtpUI::zrtpNegotiationFailed", LOG_NORMAL,
			LOG_WARNING);
		break;
	default:
		log_file->write_report(m, "TwinkleZrtpUI::zrtpNegotiationFailed", LOG_NORMAL,
			LOG_CRITICAL);
	}
}

void TwinkleZrtpUI::zrtpNotSuppOther() {
	t_line *line = audioSession->get_line();
	int lineno = line->get_line_number();
	
	string msg = "Line ";
	msg += int2str(lineno + 1);
	msg += ": remote party does not support ZRTP.";
	log_file->write_report(msg, "TwinkleZrtpUI::zrtpNotSuppOther");
}

#endif
