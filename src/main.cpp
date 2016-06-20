#include <main.hpp>

int main(int argc, char** argv)
{
    UNUSED(argc);
    UNUSED(argv);

    serverhttp shttp("127.0.0.1",5050);
    shttp.run();

    return 0;
}