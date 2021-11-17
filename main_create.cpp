#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string p{"test-data/shp/boundaries.index"};
    std::ofstream file(p, std::ios::trunc | std::ios::binary);
    file << "TEST" << std::endl;

    std::clog << " test output" << std::endl;
    file.exceptions(std::ios::failbit | std::ios::badbit);
    file << "TEST" << std::endl;
    file.flush();
    file.close();

    return 0;
}
