#include <serverhttp.hpp>

serverhttp::serverhttp (string ip, uint16_t port) {
	this->ip   = ip;
	this->port = port;

	this->listenfd = tcp_listen_on_port (port);
}

void serverhttp::run () {
	while (1) {
		unique_ptr<serbeSocket> ss = unique_ptr<serbeSocket> (new serbeSocket (
		    tcp_upgrade2syncSocket (tcp_accept (this->listenfd, NULL), NOSSL, NULL)));
		this->process (ss);
	}
}

// this method is only for this function
static constexpr unsigned int str2int (const char *str, int h = 0) {
	return !str[h] ? 5381 : (str2int (str, h + 1) * 33) ^ str[h];
}

void serverhttp::process (unique_ptr<serbeSocket> &sock) {
	string method  = "";
	string path    = "";
	string payload = "";

	// get method
	method = sock->readuntilskip (' ');

	// get path
	path = sock->readuntilskip (' ');

	// skip until newline
	payload = sock->readuntilskip ('\n');

	// prepare httpRequest
	httpMethod hmethod;

	// this should be ordered by probability
	switch (str2int (method)) {
		case str2int ("GET"):
		case str2int ("get"):
			hmethod = httpMethod::GET;
			break;
		case str2int ("POST"):
		case str2int ("post"):
			hmethod = httpMethod::POST;
			break;
		case str2int ("OPTIONS"):
		case str2int ("options"):
			hmethod = httpMethod::OPTIONS;
			break;
		case str2int ("PUT"):
		case str2int ("put"):
			hmethod = httpMethod::PUT;
			break;
		case str2int ("DELETE"):
		case str2int ("delete"):
			hmethod = httpMethod::DELETE;
			break;
		case str2int ("HEAD"):
		case str2int ("head"):
			hmethod = httpMethod::HEAD;
			break;
		case str2int ("TRACE"):
		case str2int ("trace"):
			hmethod = httpMethod::TRACE;
			break;
		case str2int ("CONNECT"):
		case str2int ("connect"):
			hmethod = httpMethod::CONNECT;
			break;
		default:
			// Just break
			hmethod = httpMethod::INVALID;
			return;
	}

	// prepare httpdata
	httpRequest hreq = httpRequest (method, path, payload);
	httpReply hrep   = httpReply (move (sock), "HTTP/1.0");

	// process it and generate a response
	mainDomain.processPath (path, hreq, hrep);
}
