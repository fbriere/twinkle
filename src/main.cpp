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

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "events.h"
#include "line.h"
#include "listener.h"
#include "log.h"
#include "phone.h"
#include "protocol.h"
#include "sender.h"
#include "sys_settings.h"
#include "transaction_mgr.h"
#include "user.h"
#include "userintf.h"
#include "util.h"
#include "sockets/socket.h"
#include "threads/thread.h"
#include "audits/memman.h"

using namespace std;

// Class to initialize the random generator before objects of
// other classes are created. Initializing just from the main function
// is too late.
class t_init_rand {
public:
	t_init_rand();
};

t_init_rand::t_init_rand() { srand(time(NULL)); }

// Memory manager for memory leak tracing
t_memman 		*memman;

// Initialize random generator
t_init_rand init_rand;

// IP address on which the phone is running
string user_host;

// SIP socket for sending and receiving signaling
t_socket_udp *sip_socket;

// Event queue that is handled by the transaction manager thread
// The following threads write to this queue
// - UDP listener
// - transaction layer
// - timekeeper
t_event_queue		*evq_trans_mgr;

// Event queue that is handled by the UDP sender thread
// The following threads write to this queue:
// - phone UAS
// - phone UAC
// - transaction manager
t_event_queue		*evq_sender_udp;

// Event queue that is handled by the transaction layer thread
// The following threads write to this queue
// - transaction manager
// - timekeeper
t_event_queue		*evq_trans_layer;

// Event queue that is handled by the phone timekeeper thread
// The following threads write into this queue
// - phone UAS
// - phone UAC
// - transaction manager
t_event_queue		*evq_timekeeper;

// The timekeeper
t_timekeeper		*timekeeper;

// The transaction manager
t_transaction_mgr	*transaction_mgr;

// The phone
t_phone			*phone;

// User interface
t_userintf		*ui;

// Log file
t_log			*log_file;

// User config
t_user			*user_config;

// System config
t_sys_settings		*sys_config;

// Indicates if LinuxThreads or NPTL is active.
bool			threading_is_LinuxThreads;


main(int argc, char *argv[]) {
	string error_msg;

	memman = new t_memman();
	MEMMAN_NEW(memman);
	evq_trans_mgr = new t_event_queue();
	MEMMAN_NEW(evq_trans_mgr);
	evq_sender_udp = new t_event_queue();
	MEMMAN_NEW(evq_sender_udp);
	evq_trans_layer = new t_event_queue();
	MEMMAN_NEW(evq_trans_layer);
	evq_timekeeper = new t_event_queue();
	MEMMAN_NEW(evq_timekeeper);
	timekeeper = new t_timekeeper();
	MEMMAN_NEW(timekeeper);
	transaction_mgr = new t_transaction_mgr();
	MEMMAN_NEW(transaction_mgr);
	phone = new t_phone();
	MEMMAN_NEW(phone);

	sys_config = new t_sys_settings();
	MEMMAN_NEW(sys_config);
	ui = new t_userintf(phone);
	MEMMAN_NEW(ui);

	// Check requirements on environment
	if (!sys_config->check_environment(error_msg)) {
		// Environment is not good
		ui->cb_show_msg(error_msg, MSG_CRITICAL);
		exit(1);
	}
	
	// Read system configuration
	if (!sys_config->read_config(error_msg)) {
		ui->cb_show_msg(error_msg, MSG_CRITICAL);
		exit(1);
	}

	// Create a lock file to guarantee that the application
	// runs only once.
	if (!sys_config->create_lock_file(error_msg)) {
		ui->cb_show_msg(error_msg, MSG_CRITICAL);
		exit(1);
	}

	log_file = new t_log();
	MEMMAN_NEW(log_file);
	user_config = new t_user();
	MEMMAN_NEW(user_config);

	// Determine threading implementation
	threading_is_LinuxThreads = t_thread::is_LinuxThreads();
	if (threading_is_LinuxThreads) {
		log_file->write_report("Threading implementation is LinuxThreads.",
			"::main", LOG_NORMAL, LOG_INFO);
	} else {
		log_file->write_report("Threading implementation is NPTL.",
			"::main", LOG_NORMAL, LOG_INFO);
	}

	string config_file = USER_CONFIG_FILE;

	if (argc == 2) config_file = argv[1];

	// Read user configuration
	if (!user_config->read_config(config_file, error_msg)) {
		ui->cb_show_msg(error_msg, MSG_CRITICAL);
		sys_config->delete_lock_file();
		exit(1);
	}

	// Initialize RTP port settings.
	phone->init_rtp_ports();

	// Open socket for SIP signaling
	try {
		sip_socket = new t_socket_udp(user_config->sip_udp_port);
		MEMMAN_NEW(sip_socket);
	} catch (int err) {
		string msg("Failed to create a UDP socket (SIP) on port ");
		msg += int2str(user_config->sip_udp_port);
		msg += "\n";
		// NOTE: I tried to use strerror_r, but it fails with Illegal seek
		msg += strerror(err);
		log_file->write_report(msg, "::main", LOG_NORMAL, LOG_CRITICAL);
		ui->cb_show_msg(msg, MSG_CRITICAL);
		sys_config->delete_lock_file();
		exit(1);
	}
	
	// Pick network interface
	user_host = ui->select_network_intf();
	if (user_host == "") {
		sys_config->delete_lock_file();
		exit(1);
	}
	
	// Discover NAT type if STUN is enabled
	if (user_config->use_stun) {
		string msg;
		if (!stun_discover_nat(msg)) {
			ui->cb_show_msg(msg, MSG_WARNING);
		}
	}

	// A dedicated thread will catch the SIGALRM signal, therefore
	// all threads must block SIGALRM. Block SIGALRM now, then all
	// created threads will inherit the signal mask.
	// In LinuxThreads the sigwait does not work very well, so
	// in LinuxThreads a signal handler is used instead.
	if (!threading_is_LinuxThreads) {
		sigset_t sigset;
		sigemptyset(&sigset);
		sigaddset(&sigset, SIGALRM);
		sigprocmask(SIG_BLOCK, &sigset, NULL);
	}

	// Create threads
	t_thread *thr_sender_udp;
	t_thread *thr_listen_udp;
	t_thread *thr_timekeeper;
	t_thread *thr_signal_catcher;
	t_thread *thr_trans_mgr;
	t_thread *thr_phone_uas;

	try {
		// UDP sender thread
		thr_sender_udp = new t_thread(sender_udp, NULL);
		MEMMAN_NEW(thr_sender_udp);

		// UDP listener thread
		thr_listen_udp = new t_thread(listen_udp, NULL);
		MEMMAN_NEW(thr_listen_udp);

		// Timekeeper thread
		thr_timekeeper = new t_thread(timekeeper_main, NULL);
		MEMMAN_NEW(thr_timekeeper);

		// Signal catcher thread
		if (!threading_is_LinuxThreads) {
			thr_signal_catcher = new t_thread(timekeeper_sigwait, NULL);
			MEMMAN_NEW(thr_signal_catcher);
		}

		// Transaction manager thread
		thr_trans_mgr = new t_thread(transaction_mgr_main, NULL);
		MEMMAN_NEW(thr_trans_mgr);

		// Phone thread (UAS)
		thr_phone_uas = new t_thread(phone_uas_main, NULL);
		MEMMAN_NEW(thr_phone_uas);
	} catch (int) {
		string msg = "Failed to create threads.";
		log_file->write_report(msg, "::main", LOG_NORMAL, LOG_CRITICAL);
		ui->cb_show_msg(msg, MSG_CRITICAL);
		sys_config->delete_lock_file();
		exit(1);
	}

	try {
		ui->run();
	} catch (string e) {
		string msg = "Exception: ";
		msg += e;
		log_file->write_report(msg, "::main", LOG_NORMAL, LOG_CRITICAL);
		ui->cb_show_msg(msg, MSG_CRITICAL);
		sys_config->delete_lock_file();
		exit(1);
	} catch (...) {
		string msg = "Unknown exception";
		log_file->write_report(msg, "::main", LOG_NORMAL, LOG_CRITICAL);
		ui->cb_show_msg(msg, MSG_CRITICAL);
		sys_config->delete_lock_file();
		exit(1);
	}

	thr_phone_uas->cancel();
	thr_phone_uas->join();
	thr_trans_mgr->cancel();
	thr_trans_mgr->join();

	if (!threading_is_LinuxThreads) {
		thr_signal_catcher->cancel();
		thr_signal_catcher->join();
	}
	
	thr_timekeeper->cancel();
	thr_timekeeper->join();
	thr_listen_udp->cancel();
	thr_listen_udp->join();
	thr_sender_udp->cancel();
	thr_sender_udp->join();

	MEMMAN_DELETE(thr_phone_uas);
	delete thr_phone_uas;
	MEMMAN_DELETE(thr_trans_mgr);
	delete thr_trans_mgr;
	MEMMAN_DELETE(thr_timekeeper);
	delete thr_timekeeper;

	if (!threading_is_LinuxThreads) {
		MEMMAN_DELETE(thr_signal_catcher);
		delete thr_signal_catcher;
	}

	MEMMAN_DELETE(thr_listen_udp);
	delete thr_listen_udp;
	MEMMAN_DELETE(thr_sender_udp);
	delete thr_sender_udp;

	MEMMAN_DELETE(user_config);
	delete user_config;

	MEMMAN_DELETE(ui);
	delete ui;
	ui = NULL;

	MEMMAN_DELETE(sip_socket);
	delete sip_socket;

	MEMMAN_DELETE(phone);
	delete phone;
	MEMMAN_DELETE(transaction_mgr);
	delete transaction_mgr;
	MEMMAN_DELETE(timekeeper);
	delete timekeeper;
	MEMMAN_DELETE(evq_trans_mgr);
	delete evq_trans_mgr;
	MEMMAN_DELETE(evq_sender_udp);
	delete evq_sender_udp;
	MEMMAN_DELETE(evq_trans_layer);
	delete evq_trans_layer;
	MEMMAN_DELETE(evq_timekeeper);
	delete evq_timekeeper;

	// Report memory leaks
	// Report deletion of log_file and sys_config already to get
	// a correct report.
	MEMMAN_DELETE(sys_config);
	MEMMAN_DELETE(log_file);
	MEMMAN_DELETE(memman);
	MEMMAN_REPORT;

	delete log_file;
	delete memman;

	sys_config->delete_lock_file();
	delete sys_config;
}
