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
				cout << "GET ";
				foundPath.getPathHandler ().methodGet (request, reply);
				break;
			case httpMethod::POST:
				cout << "POST ";
				foundPath.getPathHandler ().methodPost (request, reply);
				break;
			case httpMethod::OPTIONS:
				cout << "OPTIONS ";
				foundPath.getPathHandler ().methodOptions (request, reply);
				break;
			case httpMethod::PUT:
				foundPath.getPathHandler ().methodPut (request, reply);
				cout << "PUT ";
				break;
			case httpMethod::DELETE:
				cout << "DELETE ";
				foundPath.getPathHandler ().methodDelete (request, reply);
				break;
			// case httpMethod::HEAD:
			//	cout << "HEAD ";
			// 	foundPath.getPathHandler ().methodHead (request, reply);
			// 	break;
			// case httpMethod::TRACE:
			//	cout << "TRACE ";
			// 	foundPath.getPathHandler ().methodTrace (request, reply);
			// 	break;
			// case httpMethod::CONNECT:
			//	cout << "CONNECT ";
			// 	foundPath.getPathHandler ().methodConnect (request, reply);
			// 	break;
			default:
				cout << "INVALID ";
				// wtf is that!?
				reply.setHttpResponseCode (500);
				reply.setHttpResponseMsg ("HTTP method not suported");
		}

	} else {
		cout << "404" << endl;
		// no path handler found. Return 404 error.
		reply.setHttpResponseCode (404);
		reply.setHttpResponseMsg ("Not found");
	}
}
