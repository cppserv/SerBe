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
			case httpMethod::get:
				search->getPathHandler ().get (request, reply);
				break;
			case httpMethod::post:
				search->getPathHandler ().post (request, reply);
				break;
			case httpMethod::options:
				search->getPathHandler ().options (request, reply);
				break;
			case httpMethod::put:
				search->getPathHandler ().put (request, reply);
				break;
			case httpMethod::delete:
				search->getPathHandler ().delete(request, reply);
				break;
			// case httpMethod::head:
			// 	search->getPathHandler ().head (request, reply);
			// 	break;
			// case httpMethod::trace:
			// 	search->getPathHandler ().trace (request, reply);
			// 	break;
			// case httpMethod::connect:
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
