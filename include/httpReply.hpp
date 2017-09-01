#ifndef _HTTP_REPLY_HPP_
#define _HTTP_REPLY_HPP_

#include <common.hpp>
#include <serbeSocket.hpp>

class httpReply {
   public:
	httpReply (unique_ptr<serbeSocket> sock, string version, int num, string msg);
	httpReply (unique_ptr<serbeSocket> sock, string version);
	~httpReply ();

	void addHeader (const string &headers);
	void addContent (const string &content);
	void addContent (const char *content, unsigned long size);
	// By setting this, if no added is performed, the same imput char would be directly sent without
	// copies.
	void setContent (const char *content, unsigned long size);

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
	inline void setHttpResponseMsg (string &httpResponseMsg) {
		this->httpResponseMsg = httpResponseMsg;
	}

	// operators
	httpReply &operator<< (const string &str) {
		this->addContent (str);
		return *this;
	}

   protected:
   private:
	unique_ptr<serbeSocket> sock;
	string httpVersion;
	int httpResponseCode;
	string httpResponseMsg;
	ostringstream headers;
	ostringstream content;

	// const content
	const char *constContent;
	unsigned long constContentLenght;
	bool constContentSet = false;
};

#endif
