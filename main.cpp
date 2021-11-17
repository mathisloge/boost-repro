#include <boost/filesystem.hpp>
#include <clocale>
#include <iostream>
#define NOMINMAX
#include <windows.h>

static std::wstring utf8_to_utf16(std::string const &str)
{
    std::wstring wstr;
    int size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, 0, 0);
    if (size > 0)
    {
        std::vector<wchar_t> buffer(size);
        MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &buffer[0], size);
        wstr.assign(buffer.begin(), buffer.end() - 1);
    }
    return wstr;
}

int main(int argc, char const *argv[])
{
    std::cout << "test my own output" << std::endl;
    std::system("testcreate.exe");

    std::string p{"test-data/shp/mytest.txt"};
    if (!boost::filesystem::exists(utf8_to_utf16(p)))
        throw std::runtime_error("does not exists");

    boost::filesystem::remove(p);

    return 0;
}
