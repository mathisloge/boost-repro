#include <boost/filesystem.hpp>

int main(int argc, char const *argv[])
{

    std::system("testcreate.exe");

    boost::filesystem::path p{"xxxxx"};
    for (int i = 0; i < 10; i++)
        p /= "xxxxx";
    if (!boost::filesystem::exists(p / "mytest.txt"))
        throw std::runtime_error("does not exists");
    boost::filesystem::remove(p / "mytest.txt");

    return 0;
}
