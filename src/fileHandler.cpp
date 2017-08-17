#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fileHandler.hpp>

filePathHandler::filePathHandler (string filename) {
	this->mapH     = shared_ptr<mmapHandler> (new mmapHandler (filename));
	this->filename = this->mapH->getFilename ();
	this->fileSize = this->mapH->getFileSize ();
	this->fileMap  = this->mapH->getFileMap ();
}
filePathHandler::~filePathHandler () {
}

void filePathHandler::methodGet (httpRequest &request, httpReply &reply) {
	(void)request;
	reply.addContent (this->fileMap, this->fileSize);
}