#include <main.hpp>

int main (int argc, char **argv) {
	if (argc <= 1) {
		cerr << "A path must be provided as first argument" << endl;
		return -1;
	}

	serverhttp shttp ("127.0.0.1", 5050);

	shttp.runThreaded ();

	cout << "Searching for files..." << endl;
	fileDiscover fd (shttp.mainDomain);
	fd.explorePath ("/", argv[1]);

	return 0;
}