#ifndef _FILE_PATH_HANDLER_HPP_
#define _FILE_PATH_HANDLER_HPP_

#include <mmapHandler.hpp>
#include <pathHandler.hpp>
#include <stdexcept>

class filePathHandler : public pathHandler {
   public:
	filePathHandler (string filename);
	~filePathHandler ();

	virtual void methodGet (httpRequest &request, httpReply &reply);

   protected:
   private:
	string filename;
	const char *fileMap;
	int fileSize;

	shared_ptr<mmapHandler> mapH;  // This allows auto-unmap when all the filepathandler copies have
	// been effectively deleted, and without any overload in data-access
};

#endif