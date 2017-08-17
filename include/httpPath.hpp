#ifndef _HTTP_PATH_HPP_
#define _HTTP_PATH_HPP_

#include <common.hpp>
#include <pathHandler.hpp>

class httpPath {
   public:
	httpPath (string pathString, shared_ptr<pathHandler>& ph);
	httpPath (string pathString);
	~httpPath ();

	// inline methods
	inline string& getPath () {
		return this->pathString;
	}
	inline void setPath (string pathString) {
		this->pathString = pathString;
	}

	inline shared_ptr<pathHandler> getPathHandler () {
		return this->ph;
	}

	// comparators
	inline bool operator== (const httpPath& rhs) const {
		return this->pathString == rhs.pathString;
	}
	inline bool operator!= (const httpPath& rhs) const {
		return this->pathString != rhs.pathString;
	}
	inline bool operator< (const httpPath& rhs) const {
		return this->pathString < rhs.pathString;
	}
	inline bool operator> (const httpPath& rhs) const {
		return this->pathString > rhs.pathString;
	}
	inline bool operator<= (const httpPath& rhs) const {
		return this->pathString <= rhs.pathString;
	}
	inline bool operator>= (const httpPath& rhs) const {
		return this->pathString >= rhs.pathString;
	}

   protected:
   private:
	string pathString;
	shared_ptr<pathHandler> ph;
};

#endif