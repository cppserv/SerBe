#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fileHandler.hpp>

#include <magic.h>

filePathHandler::filePathHandler (string filename) {
	this->mapH          = shared_ptr<mmapHandler> (new mmapHandler (filename));
	this->filename      = this->mapH->getFilename ();
	this->fileSize      = this->mapH->getFileSize ();
	this->fileMap       = this->mapH->getFileMap ();
	this->contentLength = "Content-Length: " + to_string (this->fileSize);

	// search its mimetype
	const char *mime;
	magic_t magic;

	magic = magic_open (MAGIC_MIME);
	if (magic && !magic_load (magic, "/usr/share/misc/magic") /*&& !magic_compile (magic, NULL)*/) {
		mime = magic_file (magic, filename.c_str ());
		if (mime) {
			this->mimetype = "Content-Type: " + string (mime);
			cout << " (Mime:" << this->mimetype << ") ";
		} else {
			perror ("magic lib (2)");
			cout << magic_error (magic);
			this->mimetype = "unknown";
		}

		magic_close (magic);
	} else {
		perror ("magic lib (1)");
		this->mimetype = "Content-Type: application/octet-stream";
	}
}
filePathHandler::~filePathHandler () {
}

void filePathHandler::methodGet (httpRequest &request, httpReply &reply) {
	(void)request;

	reply.addHeader (this->contentLength);
	reply.addHeader (this->mimetype);
	// reply.addHeader (extraHeader);
	reply.setContent (this->fileMap, this->fileSize);
}