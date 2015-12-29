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

#include "interfaces.h"

t_interface::t_interface(string _name) : name(_name) {}

string t_interface::get_ip_addr(void) const {
	return inet_ntoa(address);
}

string t_interface::get_ip_netmask(void) const {
	return inet_ntoa(netmask);
}

list <t_interface> *get_interfaces(void) {
    	struct ifaddrs *ifa, *ifaddrs;
    	struct sockaddr_in *sin;
    	int i;
	t_interface *intf;

	list<t_interface> *result = new list<t_interface>;

    	if (getifaddrs(&ifaddrs)) {
		// No interfaces found
		return result;
    	}

    	for (ifa = ifaddrs; ifa ; ifa = ifa -> ifa_next) {
		// Skip interface without address
		// Skip interfaces marked DOWN and LOOPBACK.
		if (ifa->ifa_addr == NULL || !(ifa->ifa_flags & IFF_UP) ||
	    	    (ifa->ifa_flags & IFF_LOOPBACK)) {
	    		continue;
		}

		// Add the interface to the list if it has an IP4 address
		switch(ifa->ifa_addr->sa_family) {
	    	case AF_INET:
			intf = new t_interface(ifa->ifa_name);
			sin = (struct sockaddr_in *)ifa->ifa_addr;
			memcpy(&intf->address, &sin->sin_addr,
			       sizeof(struct in_addr));
			sin = (struct sockaddr_in *)ifa->ifa_netmask;
			memcpy(&intf->netmask, &sin->sin_addr,
		    	       sizeof(struct in_addr));

			result->push_back(*intf);
			delete intf;
			break;
		}
    	}

    	freeifaddrs(ifaddrs);

	return result;
}
