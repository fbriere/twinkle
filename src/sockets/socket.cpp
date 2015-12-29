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

int t_socket_udp::connect(unsigned long dest_addr, unsigned short dest_port) {
	struct sockaddr_in addr;
	int ret;

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(dest_addr);
	addr.sin_port = htons(dest_port);
	ret = ::connect(sd, (struct sockaddr *)&addr, sizeof(addr));
	if (ret < 0) throw errno;
	
	return ret;
}

int t_socket_udp::sendto(unsigned long dest_addr, unsigned short dest_port,
	           const char *data, int data_size) {
	struct sockaddr_in addr;
	int ret;

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(dest_addr);
	addr.sin_port = htons(dest_port);
	ret = ::sendto(sd, data, data_size, 0,
		     (struct sockaddr *)&addr, sizeof(addr));
	if (ret < 0) throw errno;

	return ret;
}

int t_socket_udp::send(const char *data, int data_size) {
	int ret = ::send(sd, data, data_size, 0);
	if (ret < 0) throw errno;

	return ret;
}

int t_socket_udp::recvfrom(unsigned long &src_addr, unsigned short &src_port,
		     char *buf, int buf_size) {
	struct sockaddr_in addr;
	int ret, len_addr;

	len_addr = sizeof(addr);
	memset(buf, 0, buf_size);
	ret = ::recvfrom(sd, buf, buf_size - 1, 0,
		       (struct sockaddr *)&addr, (socklen_t *)&len_addr);
	if (ret < 0) throw errno;

	src_addr = ntohl(addr.sin_addr.s_addr);
	src_port = ntohs(addr.sin_port);

	return ret;
}

int t_socket_udp::recv(char *buf, int buf_size) {
	int ret;

	memset(buf, 0, buf_size);
	ret = ::recv(sd, buf, buf_size - 1, 0);
	if (ret < 0) throw errno;

	return ret;
}

bool t_socket_udp::select_read(unsigned long timeout) {
	fd_set fds;
	struct timeval t;
	
	FD_ZERO(&fds);
	FD_SET(sd, &fds);
	
	t.tv_sec = timeout / 1000;
	t.tv_usec = (timeout % 1000) * 1000;
	
	int ret = select(sd + 1, &fds, NULL, NULL, &t);
	
	if (ret < 0) throw errno;
	if (ret == 0) return false;
	return true;
}

string h_ip2str(unsigned long ipaddr) {
	char buf[16];
	unsigned long x = htonl(ipaddr);
	unsigned char *ipbuf = (unsigned char *)&x;

	snprintf(buf, 16, "%u.%u.%u.%u", ipbuf[0], ipbuf[1], ipbuf[2],
		ipbuf[3]);

	return string(buf);
}
