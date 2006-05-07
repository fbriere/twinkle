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

#include "twinkle_config.h"

#ifdef HAVE_KDE
#include <kapplication.h>
#include <kcmdlineargs.h>
#endif

#include <qapplication.h>
#include <qmime.h>
#include <qprogressdialog.h>
#include "mphoneform.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <unistd.h>
#include "call_history.h"
#include "cmd_socket.h"
#include "events.h"
#include "listener.h"
#include "log.h"
#include "protocol.h"
#include "sender.h"
#include "transaction_mgr.h"
#include "user.h"
#include "util.h"
#include "phone.h"
#include "gui.h"
#include "sockets/interfaces.h"
#include "sockets/socket.h"
#include "threads/thread.h"
#include "audits/memman.h"
#include "qtextcodec.h"

using namespace std;

// Class to initialize the random generator before objects of
// other classes are created. Initializing just from the main function
// is too late.
class t_init_rand {
public:
	t_init_rand();
};

t_init_rand::t_init_rand() { srand(time(NULL)); }

// Initialize random generator
t_init_rand init_rand;

// Indicates if application is ending (because user pressed Quit)
bool end_app;

// Memory manager for memory leak tracing
t_memman 		*memman;

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

// System config
t_sys_settings		*sys_config;

// Call history
t_call_history		*call_history;

// SIP URI to be called passed via the --call command line parameter
QString			callto_destination;

// CLI command passed via the --cmd command line parameter
QString			cli_command;

// Indicates if the --call or --cmd must be performed immediately
bool			cmd_immediate_mode;

// Indicates the profile that should be made active before performing
// --call or --cmd
QString			cmd_set_profile;

// Thread id of main thread
pthread_t		thread_id_main;

// Indicates if LinuxThreads or NPTL is active.
bool			threading_is_LinuxThreads;


void parse_main_args(int argc, char **argv, bool &cli_mode, list<string> &config_files) {
	cli_mode = false;
	config_files.clear();

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
			// Help
			cout << "Usage: twinkle [options]\n\n";
			cout << "Options:\n";
			cout << " -c";
			cout << "\t\tRun in command line interface (CLI) mode\n";
			cout << endl;
			cout << " --share <dir>";
			cout << "\tSet the share directory.\n";
			cout << endl;
			cout << " -f <profile>";
			cout << "\tStartup with a specific profile. You will not be requested\n";
			cout << "\t\tto choose a profile at startup. The profiles that you created\n";
			cout << "\t\tare the .cfg files in your .twinkle directory.\n";
			cout << "\t\tYou may specify multiple profiles separated by spaces.\n";
			cout << endl;
			cout << " -i <IP addr>";
			cout << "\tIf you have multiple IP addresses on your computer,\n";
			cout << "\t\tthen you can supply the IP address to use here.\n";
			cout << endl;
			cout << " --call <address>\n";
			cout << "\t\tInstruct Twinkle to call the address.\n";
			cout << "\t\tWhen Twinkle is already running, this will instruct the running\n";
			cout << "\t\tprocess to call the address.\n";
			cout << "\t\tThe address may be a full or partial SIP URI. A partial SIP URI\n";
			cout << "\t\twill be completed with the information from the user profile.\n";
			cout << endl;
			cout << "\t\tA subject may be passed by appending '?subject=<subject>'\n";
			cout << "\t\tto the address.\n";
			cout << endl;
			cout << "\t\tExamples:\n";
			cout << "\t\ttwinkle --call 123456\n";
			cout << "\t\ttwinkle --call sip:example@example.com?subject=hello\n";
			cout << endl;
			cout << " --cmd <cli command>\n";
			cout << "\t\tInstruct Twinkle to execute the CLI command. You can run\n";
			cout << "\t\tall commands from the command line interface mode.\n";
			cout << "\t\tWhen Twinkle is already running, this will instruct the running\n";
			cout << "\t\tprocess to execute the CLI command.\n";
			cout << endl;
			cout << "\t\tExamples:\n";
			cout << "\t\ttwinkle --cmd answer\n";
			cout << "\t\ttwinkle --cmd mute\n";
			cout << "\t\ttwinkle --cmd 'transfer 12345'\n";
			cout << endl;
			cout << " --immediate\n";
			cout << "\t\tThis option can be used in conjunction with --call or --cmd\n";
			cout << "\t\tIt indicates the the command or call is to be performed\n";
			cout << "\t\timmediately without asking the user for any confirmation.\n";
			cout << endl;
			cout << " --set-profile <profile>\n";
			cout << "\t\tMake <profile> the active profile.\n";
			cout << "\t\tWhen using this option in conjuction with --call and --cmd,\n";
			cout << "\t\tthen the profile is activated before executing --call or \n";
			cout << "\t\t--cmd.\n";
			cout << endl;
			cout << " --help-cli [cli command]\n";
			cout << "\t\tWithout a cli command this option lists all available CLI\n";
			cout << "\t\tcommands. With a CLI command this option prints help on\n";
			cout << "\t\tthe CLI command.\n";
			cout << endl;
			cout << " --version";
			cout << "\tGet version information.\n";
			exit(0);
		} else if (strcmp(argv[i], "--version") == 0) {
			// Get version
			QString s = sys_config->about(false).c_str();
			cout << s;
			exit(0);
		} else if (strcmp(argv[i], "-c") == 0) {
			// CLI mode
			cli_mode = true;
		} else if (strcmp(argv[i], "--share") == 0) {
			if (i < argc - 1 && argv[i+1][0] != '-') {
				i++;
				sys_config->set_dir_share(argv[i]);
			} else {
				cout << argv[0] << ": ";
				cout << "Directory missing for option '-share'.\n";
				exit(0);
			}
		} else if (strcmp(argv[i], "-f") == 0) {
			if (i < argc - 1 && argv[i+1][0] != '-') {
				int j = i;
				while (i < argc -1 && argv[i+1][0] != '-') {
					i++;
					// Config file name
					QString config_file = argv[i];
					if (!config_file.endsWith(USER_FILE_EXT)) 
					{
						config_file += USER_FILE_EXT;
					}
					config_files.push_back(config_file.ascii());
				}
			} else {
				cout << argv[0] << ": ";
				cout << "Config file name missing for option '-f'.\n";
				exit(0);
			}
		} else if (strcmp(argv[i], "-i") == 0) {
			if (i < argc - 1) {
				i++;
				// IP address
				user_host = argv[i];
				if (!exists_interface(user_host)) {
					cout << argv[0] << ": ";
					cout << "There is no interface with IP address ";
					cout << user_host << endl;
					exit(0);
				}
			} else {
				cout << argv[0] << ": ";
				cout << "IP address missing for option '-i'.\n";
				exit(0);
			}
		} else if (strcmp(argv[i], "--call") == 0) {
			if (i < argc - 1) {
				i++;
				// SIP URI
				callto_destination = argv[i];
				
				if (callto_destination.isEmpty()) {
					cout << argv[0] << ": ";
					cout << "--call argument may not be empty.\n";
					exit(0);
				}
			} else {
				cout << argv[0] << ": ";
				cout << "SIP URI missing for option '--call'.\n";
				exit(0);
			}
		} else if (strcmp(argv[i], "--cmd") == 0) {
			if (i < argc - 1) {
				i++;
				// CLI command
				cli_command = argv[i];
				
				if (cli_command.isEmpty()) {
					cout << argv[0] << ": ";
					cout << "--cmd argument may not be empty.\n";
					exit(0);
				}
			} else {
				cout << argv[0] << ": ";
				cout << "CLI command missing for option '--cmd'.\n";
				exit(0);
			}
		} else if (strcmp(argv[i], "--immediate") == 0) {
			// Immediate mode
			cmd_immediate_mode = true;
		} else if (strcmp(argv[i], "--set-profile") == 0) {
			if (i < argc - 1) {
				i++;
				// Set profile
				cmd_set_profile = argv[i];
			} else {
				cout << argv[0] << ": ";
				cout << "Profile missing for option '--set-profile'.\n";
				exit(0);
			}			
		} else if (strcmp(argv[i], "--help-cli") == 0) {
			string cmd_help("help ");
			if (i < argc -1) {
				i++;
				// Help CLI
				cmd_help += argv[i];
			}
			
			t_phone p;
			t_userintf u(&p);
			u.exec_command(cmd_help);
			exit(0);
		} else {
			cout << argv[0] << ": ";
			cout << "Uknown option '" << argv[i] << "'." << endl;
			cout << argv[0] << ": ";
			cout << "Use --help to get a list of available command line options.\n";
			exit(0);
		}
	}
	
	if (!callto_destination.isEmpty() && !cli_command.isEmpty()) {
		cout << argv[0] << ": ";
		cout << "--call and --cmd cannot be used at the same time.\n";
		exit(0);
	}
	
	return;
}

int main( int argc, char ** argv )
{
	string error_msg;
	bool cli_mode;
	list<string> config_files;
	
	// Initialize globals
	end_app = false;
	callto_destination = "";
	cli_command = "";
	cmd_immediate_mode = false;
	cmd_set_profile = "";
	
	// Determine threading implementation
	threading_is_LinuxThreads = t_thread::is_LinuxThreads();
	
#ifdef HAVE_KDE
	KApplication *qa = NULL;
#else
	QApplication *qa = NULL;
#endif
	
	// Store id of main thread
	thread_id_main = t_thread::self();
	
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
	
	// Create system configuration object
	sys_config = new t_sys_settings();
	MEMMAN_NEW(sys_config);
	
	// Parse command line arguments
	parse_main_args(argc, argv, cli_mode, config_files);
	
	// Checking the environment and creating the lock is done at
	// this early stage to improve performance of the --call parameter.
	// Creation of the QApplication object for the GUI is slow.
	// However for errors, the user interface must be created to give
	// either a message box or text formatted error.
	
	// Check requirements on environment
	// If check fails, then display error after user interface has been
	// created.
	string env_error_msg;
	bool env_check_ok = sys_config->check_environment(env_error_msg);
	
	// Create a lock file to guarantee that the application runs only once.
	bool already_running;
	bool lock_created;
	string lock_error_msg;	
	if (env_check_ok &&
	    !(lock_created = sys_config->create_lock_file(lock_error_msg, already_running))) 
	{
		// Activate a profile in the running Twinkle process.
		if (already_running && !cmd_set_profile.isEmpty()) {
			cmd_cli(string("user ") + cmd_set_profile.ascii(), true);
			// Do not exit as this option may be used in conjuction
			// with --call or --cmd
		}
		
		// If Twinkle is running already and the --call parameter
		// is present, then send the call destination to the running
		// Twinkle process.
		if (already_running && !callto_destination.isEmpty()) {
			cmd_call(callto_destination.ascii(), cmd_immediate_mode);
			exit(0);
		}
		
		// If the --cmd parameter is present, send the cli command
		// to the running Twinkle process
		if (already_running && !cli_command.isEmpty()) {
			cmd_cli(cli_command.ascii(), cmd_immediate_mode);
			exit(0);
		}
		
		// Exit if only the --set-profile option was given.
		if (already_running && !cmd_set_profile.isEmpty()) {
			exit(0);
		}
	}
	
	// Read system configuration
	if (!sys_config->read_config(error_msg)) {
		cerr << PRODUCT_NAME << ": " << error_msg << endl;
		exit(1);
	}
	
	// Get default values from system configuration
	if (config_files.empty()) {
		for (list<string>::iterator i = sys_config->start_user_profiles.begin();
		i != sys_config->start_user_profiles.end(); i++)
		{
			QString config_file = (*i).c_str();
			config_file += USER_FILE_EXT;
			config_files.push_back(config_file.ascii());
		}
	}
	if (user_host.empty()) {
		if (exists_interface(sys_config->start_user_host)) {
			user_host = sys_config->start_user_host;
		}
	}

	// Create user interface
	if (cli_mode) {
		// CLI mode
		ui = new t_userintf(phone);
		MEMMAN_NEW(ui);
	} else {
		// GUI mode
		
#ifdef HAVE_KDE
		// Store the defualt mime source factory for the embedded icons.
		// This is created by Qt. The KApplication constructor seems to destroy
		// this default.
		QMimeSourceFactory *factory_qt = QMimeSourceFactory::takeDefaultFactory();
		
		// Initialize the KApplication
		KCmdLineArgs::init(1, argv, "twinkle", PRODUCT_NAME, "Soft phone",
				   PRODUCT_VERSION);
		qa = new KApplication();
		MEMMAN_NEW(qa);
		
		// Store the KDE mime source factory
		QMimeSourceFactory *factory_kde = QMimeSourceFactory::takeDefaultFactory();
		
		// Make the Qt factory the default to make the embedded icons work.
		QMimeSourceFactory::setDefaultFactory(factory_qt);
		
		// Add the KDE factory
		QMimeSourceFactory::addFactory(factory_kde);
#else
		int tmp = 1;
		qa = new QApplication(tmp, argv);
		MEMMAN_NEW(qa);
#endif
		QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));

		ui = new t_gui(phone);
		MEMMAN_NEW(ui);
	}
	
	if (!env_check_ok) {
		// Environment is not good
		ui->cb_show_msg(env_error_msg, MSG_CRITICAL);
		exit(1);
	}
	
	// Show error if lock file could not be created
	if (!lock_created) {	
		ui->cb_show_msg(lock_error_msg, MSG_CRITICAL);
		exit(1);
	}
	
	// Create log file
	log_file = new t_log();
	MEMMAN_NEW(log_file);
	
	// Write threading implementation to log file. May be useful for debugging.
	if (threading_is_LinuxThreads) {
		log_file->write_report("Threading implementation is LinuxThreads.",
			"::main", LOG_NORMAL, LOG_INFO);
	} else {
		log_file->write_report("Threading implementation is NPTL.",
			"::main", LOG_NORMAL, LOG_INFO);
	}
	
	bool profile_selected = false;
	while(!profile_selected) {
		// Select user profile
		if (config_files.empty()) {
			if (!ui->select_user_config(config_files)) {
				sys_config->delete_lock_file();
				exit(1);
			}
		}
		
		for (list<string>::iterator i = config_files.begin();
		i != config_files.end(); i++)
		{	
			t_user user_config;
			
			// Read user configuration
			if (user_config.read_config(*i, error_msg)) {
				t_user *dup_user;
				if (phone->add_phone_user(
						user_config, &dup_user))
				{
					profile_selected = true;
				} else {
					error_msg = "The following profiles are both for user ";
					error_msg += user_config.name;
					error_msg += '@';
					error_msg += user_config.domain;
					error_msg += ":\n\n";
					error_msg += user_config.get_profile_name();
					error_msg += "\n";
					error_msg += dup_user->get_profile_name();
					error_msg += "\n\n";
					error_msg += "You can only run multiple profiles ";
					error_msg += "for different users.";
					ui->cb_show_msg(error_msg, MSG_CRITICAL);
					profile_selected = false;
					break;
				}
			} else {
				ui->cb_show_msg(error_msg, MSG_CRITICAL);
				profile_selected = false;
				break;
			}
		}
		
		// In CLI mode the user cannot select another profile.
		if (!profile_selected) {
			if (cli_mode) exit(1);
		}
		
		config_files.clear();
	}
	
	// Create call history
	call_history = new t_call_history();
	MEMMAN_NEW(call_history);
	
	// Read call history
	if (!call_history->read_history(error_msg)) {
		log_file->write_report(error_msg, "::main", LOG_NORMAL, LOG_WARNING);
	}
	
	// Initialize RTP port settings.
	phone->init_rtp_ports();
	
	// Open socket for SIP signaling
	try {
		sip_socket = new t_socket_udp(sys_config->get_sip_udp_port());
		MEMMAN_NEW(sip_socket);
		if (sip_socket->enable_icmp()) {
			log_file->write_report("ICMP processing enabled.", "::main");
		} else {
			log_file->write_report("ICMP processing disabled.", "::main");
		}
	} catch (int err) {
		string msg("Failed to create a UDP socket (SIP) on port ");
		msg += int2str(sys_config->get_sip_udp_port());
		msg += "\n";
		// NOTE: I tried to use strerror_r, but it fails with Illegal seek
		msg += strerror(err);
		log_file->write_report(msg, "::main", LOG_NORMAL, LOG_CRITICAL);
		ui->cb_show_msg(msg, MSG_CRITICAL);
		sys_config->delete_lock_file();
		exit(1);
	}
	
	// Pick network interface
	if (user_host.empty()) {
		user_host = ui->select_network_intf();
		if (user_host.empty()) {
			sys_config->delete_lock_file();
			exit(1);
		}
	}
	
	// Discover NAT type if STUN is enabled
	list<t_user *> user_list = phone->ref_users();
	ui->cb_nat_discovery_progress_start(user_list.size());
	list<string> msg_list;
	int progressStep = 0;
	for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++) {
		ui->cb_nat_discovery_progress_step(progressStep);
		
		if (ui->cb_nat_discovery_cancelled()) {
			log_file->write_report("User aborted NAT discovery.", "::main");
			exit(1);
		}
		
		if (!phone->stun_discover_nat(*i, error_msg)) {
			msg_list.push_back(error_msg);
		}
		
		progressStep++;
	}
	ui->cb_nat_discovery_progress_step(user_list.size());
	
	for (list<string>::iterator i = msg_list.begin();
	     i != msg_list.end(); i++)
	{
		ui->cb_show_msg(*i, MSG_WARNING);
	}
	
	// Open socket for external commands from the command line
	string cmd_sock_name = sys_config->get_dir_user();
	cmd_sock_name += '/';
	cmd_sock_name += CMD_SOCKNAME;
	t_socket_local *sock_cmd = NULL;
	try {

		
		// The local socket may still exist if Twinkle got killed
		// previously, so remove it if it is still there.
		unlink(cmd_sock_name.c_str());
		
		sock_cmd = new t_socket_local();
		MEMMAN_NEW(sock_cmd);
		sock_cmd->bind(cmd_sock_name);
		sock_cmd->listen(5);
		
		string log_msg = "Created local socket: ";
		log_msg += cmd_sock_name;
		log_file->write_report(log_msg, "::main");
	}
	catch (int e) {
		if (sock_cmd) {
			MEMMAN_DELETE(sock_cmd);
			delete sock_cmd;
			sock_cmd = NULL;
		}
		string log_msg = "Failed to create local socket: ";
		log_msg += cmd_sock_name;
		log_msg += "\n";
		log_msg += strerror(e);
		log_msg += "\n";
		log_file->write_report(log_msg, "::main", LOG_NORMAL, LOG_WARNING);
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
	
	// Block SIGINT and SIGTERM as those will be caught by the
	// signal catcher thread
	sigset_t sigset;
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGINT);
	sigaddset(&sigset, SIGTERM);
	sigprocmask(SIG_BLOCK, &sigset, NULL);
				 
	// Create threads
	t_thread *thr_sender_udp;
	t_thread *thr_listen_udp;
	t_thread *thr_timekeeper;
	t_thread *thr_alarm_catcher;
	t_thread *thr_sig_catcher;
	t_thread *thr_trans_mgr;
	t_thread *thr_phone_uas;
	t_thread *thr_listen_cmd = NULL;
	
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
		
		// Alarm catcher thread
		if (!threading_is_LinuxThreads) {
			thr_alarm_catcher = new t_thread(timekeeper_sigwait, NULL);
				
		MEMMAN_NEW(thr_alarm_catcher);
		}
		
		// Signal catcher thread
		thr_sig_catcher = new t_thread(phone_sigwait, NULL);
		MEMMAN_NEW(thr_sig_catcher);

		// Transaction manager thread
		thr_trans_mgr = new t_thread(transaction_mgr_main, NULL);
		MEMMAN_NEW(thr_trans_mgr);

		// Phone thread (UAS)
		thr_phone_uas = new t_thread(phone_uas_main, NULL);
		MEMMAN_NEW(thr_phone_uas);
		
		// External command listener thread
		if (sock_cmd) {
			thr_listen_cmd = new t_thread(listen_cmd, sock_cmd);
			MEMMAN_NEW(thr_listen_cmd);
		}
	} catch (int) {
		string msg = "Failed to create threads.";
		log_file->write_report(msg, "::main", LOG_NORMAL, LOG_CRITICAL);
		ui->cb_show_msg(msg, MSG_CRITICAL);
		sys_config->delete_lock_file();
		exit(1);
	}

	// Start UI event loop (CLI/QApplication/KApplication)
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
	
	// Application is ending
	end_app = true;
	
	// Terminate threads
	if (thr_listen_cmd) {
		thr_listen_cmd->cancel();
		thr_listen_cmd->join();
	}
	
	thr_phone_uas->cancel();
	thr_phone_uas->join();
	thr_trans_mgr->cancel();
	thr_trans_mgr->join();
	try {
		thr_sig_catcher->cancel();
	} catch (int) {
		// Thread terminated already by itself
	}
	thr_sig_catcher->join();
	
	if (!threading_is_LinuxThreads) {
		thr_alarm_catcher->cancel();
		thr_alarm_catcher->join();
	}
	
	thr_timekeeper->cancel();
	thr_timekeeper->join();
	thr_listen_udp->cancel();
	thr_listen_udp->join();
	thr_sender_udp->cancel();
	thr_sender_udp->join();
	
	if (thr_listen_cmd) {
		MEMMAN_DELETE(thr_listen_cmd);
		delete thr_listen_cmd;
	}

	MEMMAN_DELETE(thr_phone_uas);
	delete thr_phone_uas;
	MEMMAN_DELETE(thr_trans_mgr);
	delete thr_trans_mgr;
	MEMMAN_DELETE(thr_timekeeper);
	delete thr_timekeeper;
	MEMMAN_DELETE(thr_sig_catcher);
	delete thr_sig_catcher;
	
	if (!threading_is_LinuxThreads) {
		MEMMAN_DELETE(thr_alarm_catcher);
		delete thr_alarm_catcher;
	}
	
	MEMMAN_DELETE(thr_listen_udp);
	delete thr_listen_udp;
	MEMMAN_DELETE(thr_sender_udp);
	delete thr_sender_udp;

	MEMMAN_DELETE(call_history);
	delete call_history;

	MEMMAN_DELETE(ui);
	delete ui;
	ui = NULL;
	
	MEMMAN_DELETE(sip_socket);
	delete sip_socket;
	
	if (sock_cmd) {
		MEMMAN_DELETE(sock_cmd);
		delete sock_cmd;
		unlink(cmd_sock_name.c_str());
	}

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
	
	if (qa) {
		MEMMAN_DELETE(qa);
		delete(qa);
	}

	// Report memory leaks
	// Report deletion of log_file and sys_config already to get a correct
	// report.
	MEMMAN_DELETE(sys_config);
	MEMMAN_DELETE(log_file);
	MEMMAN_DELETE(memman);
	MEMMAN_REPORT;

	delete log_file;
	delete memman;
	
	sys_config->delete_lock_file();
	delete sys_config;
}
