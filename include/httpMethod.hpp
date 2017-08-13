#ifndef _HTTP_METHOD_HPP_
#define _HTTP_METHOD_HPP_

#include <common.hpp>

enum class httpMethod { invalid, connect, delete, get, head, options, post, put, trace };

httpMethod getHttpMethod (string method) {
	if (method == "CONNECT" || method == "connect") {
		return httpMethod::connect;
	} else if (method == "DELETE" || method == "delete") {
		return httpMethod::delete;
	} else if (method == "GET" || method == "get") {
		return httpMethod::get;
	} else if (method == "HEAD" || method == "head") {
		return httpMethod::head;
	} else if (method == "OPTIONS" || method == "options") {
		return httpMethod::options;
	} else if (method == "POST" || method == "post") {
		return httpMethod::post;
	} else if (method == "PUT" || method == "put") {
		return httpMethod::put;
	} else if (method == "TRACE" || method == "trace") {
		return httpMethod::trace;
	} else {
		return httpMethod::invalid;
	}
}

#endif
