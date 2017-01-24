#include <httpReply.hpp>

httpReply::httpReply(SyncSocket *fd, string version, int num, string msg)
{
    this->fd = fd;

	ostringstream out;
	out << version << " " << num << " " << msg << "\r\n\r\n";
	string str = out.str();
	tcp_message_ssend(fd, str.c_str(), str.length());
}

httpReply::~httpReply(){
    //tcp_sclose(fd);
}