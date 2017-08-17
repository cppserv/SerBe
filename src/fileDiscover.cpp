#include <fileDiscover.hpp>

#include <dirent.h>

#include <fileHandler.hpp>
fileDiscover::fileDiscover (shared_ptr<httpDomain> hdom) {
	this->hdom       = hdom;
	this->indexRegex = regex ("index.htm[l]");
}
fileDiscover::~fileDiscover () {
}

void fileDiscover::explorePath (string basePath, string systemBasePath) {
	DIR* dir;
	struct dirent* entry;
	bool foundRoot = false;

	if (basePath == "/")  // bugfix for root directory
		basePath = "";

	if (!(dir = opendir (systemBasePath.c_str ())))
		return;

	while ((entry = readdir (dir)) != NULL) {
		string newBasePath       = basePath + "/" + entry->d_name;
		string newSystemBasePath = systemBasePath + "/" + entry->d_name;
		if (entry->d_type == DT_DIR) {
			// Recursively explore the new directory
			if (strcmp (entry->d_name, ".") == 0 || strcmp (entry->d_name, "..") == 0)
				continue;
			this->explorePath (newBasePath.c_str (), newSystemBasePath.c_str ());
		} else {
			// add file/path
			shared_ptr<pathHandler> fph =
			    shared_ptr<pathHandler> (new filePathHandler (newSystemBasePath));
			httpPath ph (newBasePath, fph);
			this->hdom->addPath (ph);
			cout << "\"" + newBasePath + "\" -> \"" + newSystemBasePath + "\"" << endl;

			// Sets up the root handler, if matches the regex
			if (!foundRoot && regex_match (entry->d_name, this->indexRegex)) {
				foundRoot   = true;
				newBasePath = basePath == "" ? "/" : basePath;
				httpPath rootph (newBasePath, fph);
				this->hdom->addPath (rootph);
				cout << "\"" + newBasePath + "\" -> \"" + newSystemBasePath + "\"" << endl;
			}
		}
	}
	closedir (dir);
}