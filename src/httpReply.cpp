#include <httpReply.hpp>

httpReply::httpReply (unique_ptr<serbeSocket> sock, string version, int num, string msg) {
	this->sock       = move (sock);
	httpVersion      = version;
	httpResponseCode = num;
	httpResponseMsg  = msg;
}
httpReply::httpReply (unique_ptr<serbeSocket> sock, string version) {
	this->sock       = move (sock);
	httpVersion      = version;
	httpResponseCode = 200;
	httpResponseMsg  = "OK";
}

void httpReply::addHeader (string& header) {
	if (!header.empty ())
		this->headers << header << "\r\n";
}
void httpReply::addContent (string& content) {
	this->content << content;
}
void httpReply::addContent (const char* content, unsigned long size) {
	this->content.write (content, size);
}

httpReply::~httpReply () {
	string headers   = this->headers.str ();
	string content   = this->content.str ();
	string separator = "\r\n";

	string httpIntro =
	    httpVersion + " " + to_string (httpResponseCode) + " " + httpResponseMsg + separator;

	// HTTP response intro
	sock->send (httpIntro.c_str (), httpIntro.length ());
	// Send the HTTP headers
	sock->send (headers.c_str (), headers.length ());
	if (headers.length ())  // only add one more separator if there are some content
		sock->send (separator.c_str (), separator.length ());
	sock->send (content.c_str (), content.length ());
	// if (content.length ())  // only add one more separator if there are some content
	//	sock->send (separator.c_str (), separator.length ());
}
