#ifndef _SERVER_HTTP_HPP_
#define _SERVER_HTTP_HPP_

#include <common.hpp>
#include <httpDomain.hpp>
#include <httpPath.hpp>
#include <httpReply.hpp>
#include <httpRequest.hpp>
#include <serbeSocket.hpp>

class serverhttp {
   public:
	serverhttp (string ip, uint16_t port);
	~serverhttp ();
	void run ();
	void runThreaded ();

	// expose domains
	shared_ptr<httpDomain> mainDomain;

   protected:
	int listen ();                                 // listen for a new connection
	void process (unique_ptr<serbeSocket> &sock);  // Process HTTP request

   private:
	string ip;
	uint16_t port;
	int listenfd;
	thread th;
};

#endif