#ifndef _SERVER_HTTP_HPP_
#define _SERVER_HTTP_HPP_

#include <common.hpp>
#include <httpDomain.hpp>
#include <httpReply.hpp>
#include <httpRequest.hpp>
#include <path.hpp>
#include <serbeSocket.hpp>

class serverhttp {
   public:
	serverhttp (string ip, uint16_t port);
	void run ();

	// expose domains
	httpDomain mainDomain;

   protected:
	int listen ();                                 // listen for a new connection
	void process (unique_ptr<serbeSocket> &sock);  // Process HTTP request

   private:
	string ip;
	uint16_t port;
	int listenfd;
};

#endif