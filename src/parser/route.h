/*
    Copyright (C) 2005-2009  Michel de Boer <michel@twinklephone.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

// Route item

#ifndef _H_ROUTE
#define _H_ROUTE

#include <list>
#include <string>
#include "parameter.h"
#include "sockets/url.h"

using namespace std;

class t_route {
public:
	string			display;
	t_url			uri;
	list<t_parameter>	params;

	void add_param(const t_parameter &p);
	void set_params(const list<t_parameter> &l);
	string encode(void) const;
};

#endif
