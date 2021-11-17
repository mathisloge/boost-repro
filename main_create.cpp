#include <fstream>

int main(int argc, char const *argv[])
{
    std::ofstream file("mytest.txt", std::ios::trunc | std::ios::binary);
    file << "TEST" << std::endl;
    return 0;
}
