#include <httpDomain.hpp>

httpDomain::httpDomain (string domainName) {
	this->domainName = domainName;
}
httpDomain::~httpDomain () {
}

void httpDomain::processPath (path &ph, httpRequest &request, httpReply &reply) {
	// lets find a path handler
	auto search = availablePaths.find (ph);
	if (search != availablePaths.end ()) {
		// Process the request
		switch (request.getMethod ()) {
			case httpMethod::GET:
				search->getPathHandler ().get (request, reply);
				break;
			case httpMethod::POST:
				search->getPathHandler ().post (request, reply);
				break;
			case httpMethod::OPTIONS:
				search->getPathHandler ().options (request, reply);
				break;
			case httpMethod::PUT:
				search->getPathHandler ().put (request, reply);
				break;
			case httpMethod::DELETE:
				search->getPathHandler ().delete(request, reply);
				break;
			// case httpMethod::HEAD:
			// 	search->getPathHandler ().head (request, reply);
			// 	break;
			// case httpMethod::TRACE:
			// 	search->getPathHandler ().trace (request, reply);
			// 	break;
			// case httpMethod::CONNECT:
			// 	search->getPathHandler ().connect (request, reply);
			// 	break;
			default:
				// wtf is that!?
				reply.setHttpResponseCode (500);
				reply.setHttpResponseMsg ("HTTP method not suported");
		}

	} else {
		// no path handler found. Return 404 error.
		reply.setHttpResponseCode (404);
		reply.setHttpResponseMsg ("Not found");
	}
}
