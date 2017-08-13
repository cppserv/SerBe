#include <httpRequest.hpp>

httpRequest::httpRequest (httpMethod method, string path, string httpPayload) {
	this->method      = method;
	this->path        = path;
	this->httpPayload = httpPayload;
}

httpRequest::~httpRequest () {
}
