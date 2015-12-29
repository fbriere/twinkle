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

#ifndef _H_SOCKET
#define _H_SOCKET

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_UDP_SIZE	4096	// Maximum size of an UDP packet

using namespace std;

// ports and addresses should be in host order

class t_socket_udp {
private:
	int	sd;

public:
	// Create a socket and bind it to any port.
	// Throws an int exception if it fails. The int thrown is the value
	// of errno as set by 'socket' or 'bind'.
	t_socket_udp();

	// Create a socket and bind it to port.
	// Throws an int exception if it fails. The int thrown is the value
	// of errno as set by 'socket' or 'bind'.
	t_socket_udp(unsigned short port);

	~t_socket_udp();

	// Throws an int exception if it fails (errno as set by 'sendto')
	int sendto(unsigned long dest_addr, unsigned short dest_port,
	           const string &data);

	// Throws an int exception if it fails (errno as set by 'recvfrom')
	int recvfrom(unsigned long &src_addr, unsigned short &src_port,
		     string &data);
};

// Convert an IP address in host order to a string.
string h_ip2str(unsigned long ipaddr);

#endif
