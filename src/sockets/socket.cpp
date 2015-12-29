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

#include <cstdio>
#include <cerrno>
#include "socket.h"

t_socket_udp::t_socket_udp() {
	struct sockaddr_in addr;
	int ret;

	sd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sd < 0) throw errno;

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(0);
	ret = bind(sd, (struct sockaddr *)&addr, sizeof(addr));
	if (ret < 0) throw errno;
}

t_socket_udp::t_socket_udp(unsigned short port) {
	struct sockaddr_in addr;
	int ret;

	sd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sd < 0) throw errno;

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(port);
	ret = bind(sd, (struct sockaddr *)&addr, sizeof(addr));
	if (ret < 0) throw errno;
}

t_socket_udp::~t_socket_udp() {
	close(sd);
}

int t_socket_udp::sendto(unsigned long dest_addr, unsigned short dest_port,
	           const string &data) {
	struct sockaddr_in addr;
	int ret;

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(dest_addr);
	addr.sin_port = htons(dest_port);
	ret = ::sendto(sd, data.c_str(), data.size(), 0,
		     (struct sockaddr *)&addr, sizeof(addr));
	if (ret < 0) throw errno;

	return ret;
}

int t_socket_udp::recvfrom(unsigned long &src_addr, unsigned short &src_port,
		     string &data) {
	struct sockaddr_in addr;
	int ret, len_addr;
	char buf[MAX_UDP_SIZE + 1];

	len_addr = sizeof(addr);
	memset(buf, 0, MAX_UDP_SIZE + 1);
	ret = ::recvfrom(sd, buf, MAX_UDP_SIZE, 0,
		       (struct sockaddr *)&addr, (socklen_t *)&len_addr);
	if (ret < 0) throw errno;

	data = buf;
	src_addr = ntohl(addr.sin_addr.s_addr);
	src_port = ntohs(addr.sin_port);

	return ret;
}

string h_ip2str(unsigned long ipaddr) {
	char buf[16];
	unsigned long x = htonl(ipaddr);
	unsigned char *ipbuf = (unsigned char *)&x;

	snprintf(buf, 16, "%u.%u.%u.%u", ipbuf[0], ipbuf[1], ipbuf[2],
		ipbuf[3]);

	return string(buf);
}
