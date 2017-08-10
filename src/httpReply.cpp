#include <httpReply.hpp>

httpReply::httpReply (serbeSocket& fd, string version, int num, string msg) {
	this->fd = fd;

	this->headers << version << " " << num << " " << msg << "\r\n";
}

httpReply::addHeader (string& header) {
	this->header << header << "\r\n";
}
httpReply::addContent (string& content) {
	this->content << content;
}

httpReply::~httpReply () {
	string headers   = this->headers.str ();
	string content   = this->content.str ();
	string separator = "\r\n";

	fd.send (headers.c_str (), headers.length ());
	// fd.send (separator.c_str (), separator.length ());
	fd.send (content.c_str (), content.length ());
	fd.send (separator.c_str (), separator.length ());
}