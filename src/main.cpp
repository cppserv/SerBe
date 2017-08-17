#include <main.hpp>

int main (int argc, char **argv) {
	UNUSED (argc);
	UNUSED (argv);

	serverhttp shttp ("127.0.0.1", 5050);

	shttp.runThreaded ();

	cout << "Searching for files..." << endl;
	fileDiscover fd (shttp.mainDomain);
	fd.explorePath ("/", "/home/rafael/git/SerBe/websites/example.org");

	return 0;
}