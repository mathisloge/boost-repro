#include <boost/filesystem.hpp>

int main(int argc, char const *argv[])
{

    std::system("testcreate.exe");

    boost::filesystem::path p{boost::filesystem::path{"test-data"} / "shp"};

    if (!boost::filesystem::exists(p / "mytest.txt"))
        throw std::runtime_error("does not exists");
    boost::filesystem::remove(p / "mytest.txt");

    return 0;
}
