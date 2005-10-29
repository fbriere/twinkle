#ifndef TWINKLE_RTP_SESSION_H
#define TWINKLE_RTP_SESSION_H

#include <string>
#include <ccrtp/rtp.h>

using namespace std;
using namespace ost;

class t_twinkle_rtp_session : public SymmetricRTPSession {
public: 
	t_twinkle_rtp_session(const InetHostAddress &host);
	t_twinkle_rtp_session(const InetHostAddress &host, unsigned short port);
	uint32 getLastTimestamp(const SyncSource *src=NULL) const;
};

#endif
