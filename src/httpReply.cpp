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

void httpReply::addHeader (const string& header) {
	if (!header.empty ())
		this->headers << header << "\r\n";
}
void httpReply::addContent (const string& content) {
	if (constContentSet) {
		this->content.write (this->constContent, this->constContentLenght);
		constContentSet = false;
	}
	this->content << content;
}
void httpReply::addContent (const char* content, unsigned long size) {
	if (constContentSet) {
		this->content.write (this->constContent, this->constContentLenght);
		constContentSet = false;
	}
	this->content.write (content, size);
}
void httpReply::setContent (const char* content, unsigned long size) {
	this->constContentSet    = true;
	this->constContent       = content;
	this->constContentLenght = size;
}

httpReply::~httpReply () {
	string headers   = this->headers.str ();
	string separator = "\r\n";

	string httpIntro =
	    httpVersion + " " + to_string (httpResponseCode) + " " + httpResponseMsg + separator;

	// HTTP response intro
	sock->send (httpIntro.c_str (), httpIntro.length ());
	// Send the HTTP headers
	sock->send (headers.c_str (), headers.length ());
	if (headers.length ())  // only add one more separator if there are some content
		sock->send (separator.c_str (), separator.length ());
	if (constContentSet) {
		sock->send (this->constContent, this->constContentLenght);
	} else {
		string content = this->content.str ();
		sock->send (content.c_str (), content.length ());
	}
}
