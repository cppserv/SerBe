#ifndef _HTTPREQUEST_HPP_
#define _HTTPREQUEST_HPP_

#include <common.hpp>
#include <serbeSocket.hpp>

class httpReply {
   public:
	httpReply (unique_ptr<serbeSocket> sock, string version, int num, string msg);
	~httpReply ();

	void addHeader (string &headers);
	void addContent (string &content);

   protected:
   private:
	unique_ptr<serbeSocket> sock;
	ostringstream headers;
	ostringstream content;
};

#endif
