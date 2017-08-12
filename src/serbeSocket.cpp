#include <serbeSocket.hpp>

serbeSocket::serbeSocket (SyncSocket *fd) {
	this->fd = fd;
}

serbeSocket::~serbeSocket () {
	tcp_sclose (fd);
}

char serbeSocket::readChar () {
	char ret = '\0';
	tcp_message_srecv (fd, &ret, 1, 1);
	return ret;
}

/** send
 * Sends a full message to a socket
 * @return 0 if OK, something else if error.
 * ERROR CODES:
 * -1 if socket is closed.
 */
int serbeSocket::send (const void *message, size_t len) {
	return tcp_message_ssend (fd, message, len);
}

string serbeSocket::readuntil (char until) {
	ostringstream out;

	char tmp;
	int num = 1, ret;

	while (num) {
		ret = tcp_message_srecv (fd, &tmp, 1, 1);

		if (ret == -1) {
			break;
		} else if (tmp == until) {
			num = 0;
		}

		out << tmp;
	}

	return out.str ();
}

string serbeSocket::readuntilskip (char until) {
	ostringstream out;

	char tmp;
	int ret;

	while (1) {
		ret = tcp_message_srecv (fd, &tmp, 1, 1);

		if (ret == -1) {
			break;
		} else if (tmp == until) {
			break;
		}

		out << tmp;
	}

	return out.str ();
}

string serbeSocket::read2end () {
	ostringstream out;

	char tmp;
	int num = 0, ret;

	while (num < 2) {
		ret = tcp_message_srecv (fd, &tmp, 1, 1);

		if (ret == -1) {
			break;
		} else if (tmp == '\n') {
			num++;

		} else if (tmp != '\r') {
			num = 0;
		}

		out << tmp;
	}

	return out.str ();
}
