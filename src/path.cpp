#include <path.hpp>

path::path (string path, pathHandler ph) {
	this->path = path;
	this->ph   = ph;
}
path::path (string path) {
	this->path = path;
}
path::~path () {
}