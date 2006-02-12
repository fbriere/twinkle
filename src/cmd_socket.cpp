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

#include <cstdlib>
#include <cstring>
#include <iostream>
#include "cmd_socket.h"
#include "log.h"
#include "sys_settings.h"
#include "userintf.h"
#include "audits/memman.h"
#include "sockets/socket.h"

void exec_cmd(t_socket_local &sock_client) {
	int len;
	string log_msg;

	try {
		if (sock_client.read(&len, sizeof(len)) != sizeof(len)) {
			log_file->write_report("Failed to read length from socket.",
				"::exec_cmd", LOG_NORMAL, LOG_WARNING);
			return;
		}
		
		char cmd[len];
		
		if (sock_client.read(cmd, len) != len) {
			log_file->write_report("Failed to read command from socket.",
				"::exec_cmd", LOG_NORMAL, LOG_WARNING);
			return;
		}
		
		ui->cmd_call(cmd);
	}
	catch (int e) {
		log_msg = "Failed to read from socket.\n";
		log_msg += strerror(e);
		log_msg += "\n";
		log_file->write_report(log_msg, "::exec_cmd", LOG_NORMAL, LOG_WARNING);
	}
}

void *listen_cmd(void *arg) {
	t_socket_local *sock_cmd = (t_socket_local *)arg;
	string log_msg;
	
	while (true) {
		try {
			int fd = sock_cmd->accept();
			t_socket_local sock_client(fd);
			exec_cmd(sock_client);
		}
		catch (int e) {
			log_msg = "Accept failed on socket.\n";
			log_msg += strerror(e);
			log_msg += "\n";
			log_file->write_report(log_msg, "::listen_cmd", LOG_NORMAL, 
				LOG_WARNING);
			return NULL;
		}
	}
}

void cmd_call(const string &destination) {
	string name = sys_config->get_dir_user();
	name += '/';
	name += CMD_SOCKNAME;

	try {
		t_socket_local sock_cmd;
		sock_cmd.connect(name);
		int len = destination.size() + 1;
		sock_cmd.write(&len, sizeof(len));
		char *buf = strdup(destination.c_str());
		MEMMAN_NEW(buf);
		sock_cmd.write(buf, len);
		MEMMAN_DELETE(buf);
		free(buf);
	}
	catch (int e) {
		// This function will be called from Twinkle when it
		// notices another Twinkle is already running. In that
		// case this process does not have a log file. So write
		// errors to stderr
		cerr << "Failed to send call command to " << name << endl;
		cerr << strerror(e) << endl;
	}
}
