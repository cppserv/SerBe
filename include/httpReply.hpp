#ifndef _HTTPREQUEST_HPP_
#define _HTTPREQUEST_HPP_

#include <common.hpp>
#include <serbeSocket.hpp>

class httpReply {
   public:
	httpReply (serbeSocket &fd, string version, int num, string msg);
	~httpReply ();

	void addHeader (string &headers);
	void addContent (string &content);

   protected:
   private:
	serbeSocket &fd;
	ostringstream headers;
	ostringstream content;
};

#endif