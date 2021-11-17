#include <boost/filesystem.hpp>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::cout << "test my own output" << std::endl;
    std::system("testcreate.exe");

    boost::filesystem::path p{"xxxxx"};
    for (int i = 0; i < 10; i++)
        p /= "xxxxx";
    p /= "mytest.txt";
    if (!boost::filesystem::exists(p))
        throw std::runtime_error("does not exists");

    boost::filesystem::remove(p);

    return 0;
}
