#ifndef _PATH_HANDLER_HPP_
#define _PATH_HANDLER_HPP_

#include <common.hpp>
#include <httpReply.hpp>
#include <httpRequest.hpp>

class pathHandler {
   public:
	pathHandler ();
	~pathHandler ();

	virtual void methodConnect (httpRequest &request, httpReply &reply) {
		this->methodGet (request, reply);
	}
	virtual void methodDelete (httpRequest &request, httpReply &reply) {
		this->methodGet (request, reply);
	}
	virtual void methodGet (httpRequest &request, httpReply &reply) {
		(void)request;
		(void)reply;
	}
	virtual void methodHead (httpRequest &request, httpReply &reply) {
		this->methodGet (request, reply);
	}
	virtual void methodOptions (httpRequest &request, httpReply &reply) {
		this->methodGet (request, reply);
	}
	virtual void methodPost (httpRequest &request, httpReply &reply) {
		this->methodGet (request, reply);
	}
	virtual void methodPut (httpRequest &request, httpReply &reply) {
		this->methodGet (request, reply);
	}
	virtual void methodTrace (httpRequest &request, httpReply &reply) {
		this->methodGet (request, reply);
	}

   protected:
   private:
};

#endif