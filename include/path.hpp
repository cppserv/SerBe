#ifndef _PATH_HPP_
#define _PATH_HPP_

#include <common.hpp>
#include <pathHandler.hpp>

class path {
   public:
	path (string path, pathHandler ph);
	path (string path);
	~path ();

	// inline methods
	inline string getPath () {
		return this->path;
	}
	inline void setPath (string path) {
		this->path = path;
	}

	inline pathHandler getPathHandler () {
		return this->pathHandler;
	}

	// comparators
	inline bool operator== (const path& lhs, const path& rhs) {
		return lhs->path == rhs->path;
	}
	inline bool operator!= (const path& lhs, const path& rhs) {
		return lhs->path != rhs->path;
	}
	inline bool operator< (const path& lhs, const path& rhs) {
		return lhs->path < rhs->path;
	}
	inline bool operator> (const path& lhs, const path& rhs) {
		return lhs->path > rhs->path;
	}
	inline bool operator<= (const path& lhs, const path& rhs) {
		return lhs->path <= rhs->path;
	}
	inline bool operator>= (const path& lhs, const path& rhs) {
		return lhs->path >= rhs->path;
	}

   protected:
   private:
	string path;
	pathHandler ph;
};

#endif