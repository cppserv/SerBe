#include <serbeSocket.hpp>

serbeSocket::serbeSocket (SyncSocket *fd) {
	this->fd = fd;
}

serbeSocket::~serbeSocket () {
	tcp_sclose (fd);
}

char serbeSocket::readChar () {
	char ret;
	tcp_message_srecv (fd, &ret, 1, 1);
	return ret;
}

string serbeSocket::read2end () {
	ostringstream out;

	char tmp;
	int num = 0;

	while (num < 2) {
		tmp = this->readChar ();

		if (tmp == '\n') {
			num++;

		} else if (tmp != '\r') {
			num = 0;
		}

		out << tmp;
	}

	return out.str ();
}