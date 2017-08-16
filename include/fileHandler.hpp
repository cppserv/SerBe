#ifndef _FILE_PATH_HANDLER_HPP_
#define _FILE_PATH_HANDLER_HPP_

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
};

#endif