#ifndef _HTTP_METHOD_HPP_
#define _HTTP_METHOD_HPP_

#include <common.hpp>

enum class httpMethod { INVALID, CONNECT, DELETE, GET, HEAD, OPTIONS, POST, PUT, TRACE };

httpMethod getHttpMethod (string method) {
	if (method == "CONNECT" || method == "connect") {
		return httpMethod::CONNECT;
	} else if (method == "DELETE" || method == "delete") {
		return httpMethod::DELETE;
	} else if (method == "GET" || method == "get") {
		return httpMethod::GET;
	} else if (method == "HEAD" || method == "head") {
		return httpMethod::HEAD;
	} else if (method == "OPTIONS" || method == "options") {
		return httpMethod::OPTIONS;
	} else if (method == "POST" || method == "post") {
		return httpMethod::POST;
	} else if (method == "PUT" || method == "put") {
		return httpMethod::PUT;
	} else if (method == "TRACE" || method == "trace") {
		return httpMethod::TRACE;
	} else {
		return httpMethod::INVALID;
	}
}

#endif
