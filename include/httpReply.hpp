#ifndef _HTTPREQUEST_HPP_
#define _HTTPREQUEST_HPP_

#include <common.hpp>

class httpReply {
   public:
	httpReply (SyncSocket *fd, string version, int num, string msg);
	~httpReply ();

   protected:
   private:
	SyncSocket *fd;
};

#endif