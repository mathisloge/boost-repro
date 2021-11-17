#include <boost/filesystem.hpp>

int main(int argc, char const *argv[])
{
    
    std::system("testcreate.exe");
    boost::filesystem::remove("mytest.txt");
    
    return 0;
}
