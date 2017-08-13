#include <httpDomain.hpp>

httpDomain::httpDomain (string domainName) {
	this->domainName = domainName;
}
httpDomain::~httpDomain () {
}

void httpDomain::processPath (httpPath &ph, httpRequest &request, httpReply &reply) {
	// lets find a path handler
	auto search = availablePaths.find (ph);
	if (search != availablePaths.end ()) {
		auto foundPath = (*search);
		// Process the request
		switch (request.getMethod ()) {
			case httpMethod::GET:
				foundPath.getPathHandler ().methodGet (request, reply);
				break;
			case httpMethod::POST:
				foundPath.getPathHandler ().methodPost (request, reply);
				break;
			case httpMethod::OPTIONS:
				foundPath.getPathHandler ().methodOptions (request, reply);
				break;
			case httpMethod::PUT:
				foundPath.getPathHandler ().methodPut (request, reply);
				break;
			case httpMethod::DELETE:
				foundPath.getPathHandler ().methodDelete (request, reply);
				break;
			// case httpMethod::HEAD:
			// 	foundPath.getPathHandler ().methodHead (request, reply);
			// 	break;
			// case httpMethod::TRACE:
			// 	foundPath.getPathHandler ().methodTrace (request, reply);
			// 	break;
			// case httpMethod::CONNECT:
			// 	foundPath.getPathHandler ().methodConnect (request, reply);
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
