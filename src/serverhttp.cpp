#include <chrono>
#include <iomanip>
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

		chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now ();
		this->process (ss);
		chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now ();
		auto duration = chrono::duration_cast<chrono::microseconds> (t2 - t1).count ();

		cout << " (took: " << duration << " us)" << endl;
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
	switch (str2int (method.c_str ())) {
		case str2int ("GET"):
		case str2int ("get"):
			cout << "GET ";
			hmethod = httpMethod::GET;
			break;
		case str2int ("POST"):
		case str2int ("post"):
			cout << "POST ";
			hmethod = httpMethod::POST;
			break;
		case str2int ("OPTIONS"):
		case str2int ("options"):
			cout << "OPTIONS ";
			hmethod = httpMethod::OPTIONS;
			break;
		case str2int ("PUT"):
		case str2int ("put"):
			cout << "PUT ";
			hmethod = httpMethod::PUT;
			break;
		case str2int ("DELETE"):
		case str2int ("delete"):
			cout << "DELETE ";
			hmethod = httpMethod::DELETE;
			break;
		case str2int ("HEAD"):
		case str2int ("head"):
			cout << "HEAD ";
			hmethod = httpMethod::HEAD;
			break;
		case str2int ("TRACE"):
		case str2int ("trace"):
			cout << "TRACE ";
			hmethod = httpMethod::TRACE;
			break;
		case str2int ("CONNECT"):
		case str2int ("connect"):
			cout << "CONNECT ";
			hmethod = httpMethod::CONNECT;
			break;
		default:
			cout << "INVALID REQUEST" << endl;
			hmethod = httpMethod::INVALID;
			return;
	}

	// prepare httpdata
	httpRequest *hreq = new httpRequest (hmethod, path, payload);
	httpReply *hrep   = new httpReply (move (sock), "HTTP/1.0");

	// process it and generate a response
	mainDomain.processPath (path, *hreq, *hrep);
	cout << path;

	// delete the http objects
	delete hreq;
	delete hrep;
}
