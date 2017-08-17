#ifndef _MMAP_HANDLER_HPP_
#define _MMAP_HANDLER_HPP_

#include <common.hpp>
#include <stdexcept>

class mmapHandler {
   public:
	mmapHandler (string filename);
	~mmapHandler ();

	inline string getFilename () {
		return filename;
	}
	inline const char *getFileMap () {
		return fileMap;
	}
	inline int getFileSize () {
		return fileSize;
	}

   protected:
   private:
	string filename;
	const char *fileMap;
	int fileSize;
};

#endif