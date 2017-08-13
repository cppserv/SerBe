#ifndef _HTTP_PATH_HPP_
#define _HTTP_PATH_HPP_

#include <common.hpp>
#include <pathHandler.hpp>

class httpPath {
   public:
	httpPath (string pathString, pathHandler ph);
	httpPath (string pathString);
	~httpPath ();

	// inline methods
	inline string& getPath () {
		return this->pathString;
	}
	inline void setPath (string pathString) {
		this->pathString = pathString;
	}

	inline pathHandler& getPathHandler () {
		return this->ph;
	}

	// comparators
	inline const bool operator== (const httpPath& rhs) {
		return this->pathString == rhs.pathString;
	}
	inline const bool operator!= (const httpPath& rhs) {
		return this->pathString != rhs.pathString;
	}
	inline const bool operator< (const httpPath& rhs) {
		return this->pathString < rhs.pathString;
	}
	inline const bool operator> (const httpPath& rhs) {
		return this->pathString > rhs.pathString;
	}
	inline const bool operator<= (const httpPath& rhs) {
		return this->pathString <= rhs.pathString;
	}
	inline const bool operator>= (const httpPath& rhs) {
		return this->pathString >= rhs.pathString;
	}

   protected:
   private:
	string pathString;
	pathHandler ph;
};

#endif