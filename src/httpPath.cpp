#include <httpPath.hpp>

httpPath::httpPath (string pathString, pathHandler* ph) {
	this->pathString = pathString;
	this->ph         = ph;
}
httpPath::httpPath (string pathString) {
	this->pathString = pathString;
}
httpPath::~httpPath () {
}