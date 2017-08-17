#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <mmapHandler.hpp>

mmapHandler::mmapHandler (string filename) {
	int fd;
	struct stat sb;

	this->filename = filename;

	// open the file
	fd = open (this->filename.c_str (), O_RDONLY);
	if (fd == -1) {
		throw runtime_error ("Can't open " + this->filename);
	}

	// get file size
	if (fstat (fd, &sb) == -1) {
		throw runtime_error ("Can't get " + this->filename + " size");
	}
	this->fileSize = sb.st_size;

	// is it a regular file?
	if (!S_ISREG (sb.st_mode)) {
		throw runtime_error (this->filename + " is not a regular file");
	}

	// map the file
	this->fileMap =
	    (const char *)mmap (0, sb.st_size, PROT_READ, MAP_PRIVATE | MAP_POPULATE, fd, 0);
	if (this->fileMap == MAP_FAILED) {
		throw runtime_error ("Can't mmap " + this->filename);
	}

	if (close (fd) == -1) {
		throw runtime_error ("Can't close " + this->filename);
	}
}
mmapHandler::~mmapHandler () {
	if (munmap ((void *)this->fileMap, this->fileSize) == -1) {
		throw runtime_error ("Can't munmap " + this->filename);
	}
}