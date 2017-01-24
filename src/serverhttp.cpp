#include <serverhttp.hpp>

serverhttp::serverhttp(string ip, uint16_t port)
{
	this->ip = ip;
	this->port = port;

	this->listenfd = tcp_listen_on_port(port);
}

void serverhttp::run()
{
	while (1) {
		SyncSocket *ss = tcp_upgrade2syncSocket(tcp_accept(this->listenfd, NULL), NOSSL, NULL);
		this->process(ss);
		tcp_sclose(ss);
	}
}

void serverhttp::process(SyncSocket *fd)
{
	string method = "";
	string path = "";

	char last = readChar(fd);

	while (last != ' ') {
		method += last;
		last = readChar(fd);
	}

	last = readChar(fd);

	while (last != ' ') {
		path += last;
		last = readChar(fd);
	}

	while (last != '\n') {
		last = readChar(fd);
	}

	if (method == "get" || method == "GET") {
		this->methodGET(path, fd);
	}

}

void serverhttp::methodGET(string path, SyncSocket *fd)
{
	cout << "Path requested " << path << endl;
	read2end(fd);
	httpReply(fd, "HTTP/1.1", 404, "Not found");
}

char serverhttp::readChar(SyncSocket *fd)
{
	char ret;
	tcp_message_srecv(fd, &ret, 1, 1);
	return ret;
}

string serverhttp::read2end(SyncSocket *fd)
{
	ostringstream out;

	char tmp;
	int num = 0;

	while (num < 2) {
		tmp = readChar(fd);

		if (tmp == '\n') {
			num++;

		} else if (tmp != '\r') {
			num = 0;
		}

		out << tmp;
	}

	return out.str();
}