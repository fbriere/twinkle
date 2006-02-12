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

// Twinkle listens on a local socket for external commands.
// Currently only a call command can be given

#define CMD_SOCKNAME	".cmdsock"

#ifndef _H_CMD_SOCKET
#define _H_CMD_SOCKET

#include <string>

using namespace std;

// Create the local socket and listen for commands
void *listen_cmd(void *arg);

// Send a command to the local socket
void cmd_call(const string &destination);

#endif
