#ifndef _HTTP_REQUEST_HPP_
#define _HTTP_REQUEST_HPP_

#include <common.hpp>
#include <httpMethod.hpp>

class httpRequest {
   public:
	httpRequest (httpMethod method, string path, string httpPayload);
	~httpRequest ();

	// inline methods
	inline httpMethod getMethod () {
		return this->method;
	}
	inline string getPath () {
		return this->path;
	}
	inline string getHttpPayload () {
		return this->httpPayload;
	}

   protected:
   private:
	httpMethod method;
	string path;
	string httpPayload;
};

#endif
