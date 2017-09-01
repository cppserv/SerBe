#ifndef _URI_QUERY_HPP_
#define _URI_QUERY_HPP_

#include <common.hpp>
#include <serbeSocket.hpp>
#include <serverhttp.hpp>

class uriQuery {
   public:
	uriQuery (serverhttp *server, unique_ptr<serbeSocket> &socket) {
		this->server = server;
		this->socket = move (socket);
	}
	~uriQuery (){};

	void processQuery () {
		server->process (socket);
	}

	serverhttp *server;
	unique_ptr<serbeSocket> socket;

   protected:
   private:
};

#endif