#include <boost/filesystem.hpp>
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/streams/bufferstream.hpp>
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

    std::string uri{"test-data/shp/boundaries.index"};
    if (!boost::filesystem::exists(utf8_to_utf16(uri)))
        throw std::runtime_error("does not exists");

    using mapped_region_ptr = std::shared_ptr<boost::interprocess::mapped_region>;

    boost::interprocess::ibufferstream in;
    boost::interprocess::file_mapping mapping(uri.c_str(), boost::interprocess::read_only);
    mapped_region_ptr mapped_region(std::make_shared<boost::interprocess::mapped_region>(mapping, boost::interprocess::read_only));
    in.buffer(static_cast<char *>(mapped_region->get_address()), mapped_region->get_size());

    boost::filesystem::remove(uri);

    return 0;
}
