#include <serverhttp.hpp>

serverhttp::serverhttp (string ip, uint16_t port) {
	this->ip   = ip;
	this->port = port;

	this->listenfd = tcp_listen_on_port (port);
}

void serverhttp::run () {
	while (1) {
		unique_ptr<serbeSocket> ss = unique_ptr<serbeSocket> (
		    new serbeSocket (tcp_upgrade2syncSocket (tcp_accept (this->listenfd, NULL), NOSSL, NULL)));
		this->process (ss);
	}
}

void serverhttp::process (unique_ptr<serbeSocket> &sock) {
	string method = "";
	string path   = "";

	char last = sock->readChar ();

	while (last != ' ') {
		method += last;
		last = sock->readChar ();
	}

	last = sock->readChar ();

	while (last != ' ') {
		path += last;
		last = sock->readChar ();
	}

	while (last != '\n') {
		last = sock->readChar ();
	}

	if (method == "get" || method == "GET") {
		this->methodGET (path, sock);
	}
}

void serverhttp::methodGET (string path, unique_ptr<serbeSocket> &sock) {
	cout << "Path requested " << path << endl;
	sock->read2end ();

	httpReply (move (sock), "HTTP/1.1", 404, "Not found");
}
