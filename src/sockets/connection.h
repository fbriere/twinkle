/*
    Copyright (C) 2005-2008  Michel de Boer <michel@twinklephone.com>

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

/**
 * @file
 * Network connection
 */
 
#ifndef _H_CONNECTION
#define _H_CONNECTION
 
#include <string>

#include "socket.h"
#include "parser/sip_message.h"

using namespace std;
 
/** Abstract class for a network connection. */
class t_connection {
private:
	static const unsigned int READ_BLOCK_SIZE = 1448;
	static const unsigned int WRITE_BLOCK_SIZE = 1448;

	/** Buffer with data already read from the network. */
	string read_buf_;
	
	/** Socket for connection. */
	t_socket *socket_;
	
	/** SIP message parsed from available data (headers only) */
	t_sip_message *sip_msg_;
	
	/** Raw SIP headers that have been parsed already */
	string raw_sip_headers_;
	
	/** Data to be sent on the connection. */
	string send_buf_;
	
	/** Position in send buffer for next send action. */
	string::size_type pos_send_buf_;
	
	/** 
	 * Time (ms) that the connection is idle .
	 * This time is reset to zero by read and send actions.
	 */
	unsigned long idle_time_;
	
public:
	typedef string::size_type size_type;

	t_connection(t_socket *socket);
	
	/**
	 * Destuctor.
	 * @note The socket will be closed and destroyed.
	 */
	virtual ~t_connection();
	
	/**
	 * Get a pointer to the socket.
	 * @return The socket.
	 */
	t_socket *get_socket(void);
	
	/**
	 * Get the amount of data in the read buffer.
	 * @return Number of bytes in read buffer.
	 */
	size_type data_size(void) const;
	
	/** 
	 * Read a block data from connection in to read buffer. 
	 * @param connection_closed [out] Indicates if the connection was closed.
	 * @throw int errno as set by recv.
	 */
	void read(bool &connection_closed);
	
	/**
	 * Send a block of data from the send buffer on a connection.
	 * @throw int errno.
	 */
	void write(void);
	
	/**
	 * Send data on a connection.
	 * @param data [in] Data to send
	 * @param data_size [in] Size of data in bytes
	 * @return Number of bytes sent.
	 * @throw int errno.
	 */
	ssize_t send(const char *data, int data_size);
	
	/**
	 * Append data to the send buffer for asynchronous sending.
	 * @param data [in] Data to send
	 * @param data_size [in] Size of data in bytes
	 */
	void async_send(const char *data, int data_size);
	
	/**
	 * Get a SIP message from the connection.
	 * @param raw_headers [out] Raw headers of SIP message
	 * @param raw_body [out] Raw body of SIP message
	 * @param error [out] Indicates if an error occurred (invalid SIP message)
	 * @param msg_too_large [out] Indicates that the message is cutoff because it was too large
	 * @return The SIP message if a message was received.
	 * @return NULL, if no full SIP message has been received yet or an error occurred.
	 * @post If error == true, then NULL is returned
	 * @post If msg_too_large == true, then a message is returned (partial though)
	 */
	t_sip_message *get_sip_msg(string &raw_headers, string &raw_body, bool &error,
			bool &msg_too_large);
	
	/**
	 * Get read data from read buffer.
	 * @param nbytes [in] Maximum number of bytes to get.
	 * @return Data from the read buffer up to nbytes.
	 * @note The data is still in the buffer after this operation.
	 */
	string get_data(size_t nbytes = 0) const;
	
	/**
	 * Remove data from read buffer.
	 * @param nbytes [in] Number of bytes to remove.
	 */
	void remove_data(size_t nbytes);
	
	/**
	 * Get the remote address of a connection.
	 * @param remote_addr [out] Source IPv4 address of the connection.
	 * @param remote_port [out] Source port of the connection.
	 */
	void get_remote_address(unsigned long &remote_addr, unsigned short &remote_port);
	
	/**
	 * Add an interval to the idle time.
	 * @param interval [in] Interval in ms.
	 * @return The new idle time.
	 */
	unsigned long increment_idle_time(unsigned long interval);
	
	/**
	 * Get idle time.
	 * @return Idle time in ms.
	 */
	unsigned long get_idle_time(void) const;
	
	/**
	 * Check if there is data in the send buffer.
	 * @return true if there is data, otherwise false.
	 */
	bool has_data_to_send(void) const;
};

#endif
