#ifndef _PATH_HANDLER_HPP_
#define _PATH_HANDLER_HPP_

#include <common.hpp>
#include <httpReply.hpp>
#include <httpRequest.hpp>

class pathHandler {
   public:
	pathHandler ();
	~pathHandler ();

	virtual void connect (httpRequest &request, httpReply &reply) {
		this->get (request, reply);
	}
	virtual void delete (httpRequest &request, httpReply &reply) {
		this->get (request, reply);
	}
	virtual void get (httpRequest &request, httpReply &reply) {
		(void)request;
		(void)reply;
	}
	virtual void head (httpRequest &request, httpReply &reply) {
		this->get (request, reply);
	}
	virtual void options (httpRequest &request, httpReply &reply) {
		this->get (request, reply);
	}
	virtual void post (httpRequest &request, httpReply &reply) {
		this->get (request, reply);
	}
	virtual void put (httpRequest &request, httpReply &reply) {
		this->get (request, reply);
	}
	virtual void trace (httpRequest &request, httpReply &reply) {
		this->get (request, reply);
	}

   protected:
   private:
};

#endif