#include <main.hpp>

#include <fileHandler.hpp>
int main (int argc, char **argv) {
	UNUSED (argc);
	UNUSED (argv);

	serverhttp shttp ("127.0.0.1", 5050);

	filePathHandler fph ("/home/rafael/git/SerBe/websites/example.org/index.html");
	httpPath ph ("/", fph);
	shttp.mainDomain.addPath (ph);
	shttp.run ();

	return 0;
}