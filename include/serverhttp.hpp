#ifndef _SERVER_HTTP_HPP_
#define _SERVER_HTTP_HPP_

#include <common.hpp>
#include <path.hpp>

class serverhttp
{
 public:
	serverhttp(string ip, uint16_t port);
	void run();

 protected:
	int listen(); //listen for a new connection
	void process(SyncSocket *fd);  //Process HTTP request

 private:
	string ip;
	uint16_t port;
	int listenfd;

	char readChar(SyncSocket *fd); //reads a char
	string read2end(SyncSocket *fd); //reads a char
	void methodGET(string path, SyncSocket *fd); //reads a char

	void httpReply(SyncSocket *fd, string version, int num, string msg);
};

#endif