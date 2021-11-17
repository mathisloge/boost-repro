#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>

int main(int argc, char const *argv[])
{
    boost::filesystem::path p{"xxxxx"};
    for (int i = 0; i < 10; i++)
        p /= "xxxxx";

    boost::filesystem::create_directories(p);
    std::ofstream file((p / "mytest.txt").string(), std::ios::trunc | std::ios::binary);
    file << "TEST" << std::endl;

    std::clog << " test output" << std::endl;
    file.exceptions(std::ios::failbit | std::ios::badbit);
    file << "TEST" << std::endl;
    file.flush();
    file.close();

    return 0;
}
