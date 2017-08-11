#include <httpReply.hpp>

httpReply::httpReply (unique_ptr<serbeSocket> sock, string version, int num, string msg) {
	this->sock = move(sock);

	this->headers << version << " " << num << " " << msg << "\r\n";
}

void httpReply::addHeader (string& header) {
	this->headers << header << "\r\n";
}
void httpReply::addContent (string& content) {
	this->content << content;
}

httpReply::~httpReply () {
	string headers   = this->headers.str ();
	string content   = this->content.str ();
	string separator = "\r\n";

	sock->send (headers.c_str (), headers.length ());
	// sock->send (separator.c_str (), separator.length ());
	sock->send (content.c_str (), content.length ());
	sock->send (separator.c_str (), separator.length ());
}
