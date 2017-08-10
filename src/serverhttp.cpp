#include <serverhttp.hpp>

serverhttp::serverhttp (string ip, uint16_t port) {
	this->ip   = ip;
	this->port = port;

	this->listenfd = tcp_listen_on_port (port);
}

void serverhttp::run () {
	while (1) {
		serbeSocket ss =
		    serbeSocket (tcp_upgrade2syncSocket (tcp_accept (this->listenfd, NULL), NOSSL, NULL));
		this->process (ss);
	}
}

void serverhttp::process (serbeSocket &sock) {
	string method = "";
	string path   = "";

	char last = sock.readChar ();

	while (last != ' ') {
		method += last;
		last = sock.readChar ();
	}

	last = sock.readChar ();

	while (last != ' ') {
		path += last;
		last = sock.readChar ();
	}

	while (last != '\n') {
		last = sock.readChar ();
	}

	if (method == "get" || method == "GET") {
		this->methodGET (path, sock);
	}
}

void serverhttp::methodGET (string path, serbeSocket &sock) {
	cout << "Path requested " << path << endl;
	sock.read2end ();

	unique_ptr<serbeSocket> psock = unique_ptr<serbeSocket> (sock);
	httpReply (psock, "HTTP/1.1", 404, "Not found");
}
