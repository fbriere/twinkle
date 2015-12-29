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


#ifndef __TWINKLEZRTPUI_H_
#define __TWINKLEZRTPUI_H_

#include "twinkle_config.h"

#ifdef HAVE_ZRTP

#include <iostream>
#include <libzrtpcpp/ZrtpQueue.h>
#include <libzrtpcpp/ZrtpUserCallback.h>
#include "audio_session.h"
#include "userintf.h"

class TwinkleZrtpUI : public ZrtpUserCallback {

    public:
    	TwinkleZrtpUI(ZrtpQueue* queue, t_audio_session* session);
    	virtual ~TwinkleZrtpUI() {};
    
        // ZRTP call back functions called from the ZRTP thread
        virtual void secureOn(std::string cipher);
        virtual void secureOff();
        virtual void showSAS(std::string sas); 
        virtual void confirmGoClear();
        virtual void showMessage(MessageSeverity sev, std::string message);
        virtual void zrtpNegotiationFailed(MessageSeverity severity, std::string msg);
        virtual void zrtpNotSuppOther();

    private:
        t_audio_session* audioSession;
};

#endif // HAVE_ZRTP
#endif // __TWINKLEZRTPUI_H_
