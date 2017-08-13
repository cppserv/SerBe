#ifndef _HTTP_REPLY_HPP_
#define _HTTP_REPLY_HPP_

#include <common.hpp>
#include <serbeSocket.hpp>

class httpReply {
   public:
	httpReply (unique_ptr<serbeSocket> sock, string version, int num, string msg);
	httpReply (unique_ptr<serbeSocket> sock, string version)
	    : httpReply (move (sock), version, 200, "OK"){};
	~httpReply ();

	void addHeader (string &headers);
	void addContent (string &content);

	// inline methods

	inline int getHttpResponseCode () {
		return httpResponseCode;
	}
	inline string getHttpResponseMsg () {
		return httpResponseMsg;
	}

	inline void setHttpResponseCode (int httpResponseCode) {
		this->httpResponseCode = httpResponseCode;
	}
	inline void setHttpResponseMsg (string httpResponseMsg) {
		this->httpResponseMsg = httpResponseMsg;
	}

   protected:
   private:
	unique_ptr<serbeSocket> sock;
	string httpVersion;
	int httpResponseCode;
	string httpResponseMsg;
	ostringstream headers;
	ostringstream content;
};

#endif
