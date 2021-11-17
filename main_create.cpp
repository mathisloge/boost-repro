#include <boost/filesystem.hpp>
#include <fstream>

int main(int argc, char const *argv[])
{
    boost::filesystem::path p{boost::filesystem::path{"test-data"} / "shp"};

    std::ofstream file((p / "mytest.txt").string(), std::ios::trunc | std::ios::binary);
    file << "TEST" << std::endl;
    return 0;
}
