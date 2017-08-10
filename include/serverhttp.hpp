#ifndef _SERVER_HTTP_HPP_
#define _SERVER_HTTP_HPP_

#include <common.hpp>
#include <httpReply.hpp>
#include <path.hpp>
#include <serbeSocket.hpp>

class serverhttp {
   public:
	serverhttp (string ip, uint16_t port);
	void run ();

   protected:
	int listen ();                     // listen for a new connection
	void process (serbeSocket &sock);  // Process HTTP request

   private:
	string ip;
	uint16_t port;
	int listenfd;

	void methodGET (string path, serbeSocket &sock);  // reads a char
};

#endif