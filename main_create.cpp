#include <boost/filesystem.hpp>
#include <fstream>

int main(int argc, char const *argv[])
{
    boost::filesystem::path p{"xxxxx"};
    for (int i = 0; i < 10; i++)
        p /= "xxxxx";
    boost::filesystem::create_directories(p);
    std::ofstream file((p / "mytest.txt").string(), std::ios::trunc | std::ios::binary);
    file << "TEST" << std::endl;
    return 0;
}
