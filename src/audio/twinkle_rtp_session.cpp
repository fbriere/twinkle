#include "twinkle_rtp_session.h"

t_twinkle_rtp_session::t_twinkle_rtp_session(const InetHostAddress &host) : SymmetricRTPSession(host) {}

t_twinkle_rtp_session::t_twinkle_rtp_session(const InetHostAddress &host, unsigned short port) : 
	SymmetricRTPSession(host, port) {}

uint32 t_twinkle_rtp_session::getLastTimestamp(const SyncSource *src) const {
	if ( src && !isMine(*src) ) return 0L;
	
	recvLock.readLock();

	uint32 ts = 0;	
	if (src != NULL) {
		SyncSourceLink* srcm = getLink(*src);
		IncomingRTPPktLink* l = srcm->getFirst();
		
		while (l) {
			ts = l->getTimestamp();
			l = l->getSrcNext();
		}
	} else {
		IncomingRTPPktLink* l = recvFirst;
		
		while (l) {
			ts = l->getTimestamp();
			l = l->getNext();
		}
	}
	
	recvLock.unlock();
	return ts;
}
