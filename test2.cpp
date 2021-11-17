#include <boost/filesystem.hpp>
#include <fstream>

int main(int argc, char const *argv[])
{

    std::string path = "test-data/shp/boundaries.shp";
    std::string index_path = path.substr(0, path.rfind(".")) + ".index";

    std::ofstream index(index_path.c_str(), std::ios::binary);
    index << "index2" << std::endl;
    index.close();

    if (boost::filesystem::exists(index_path))
        boost::filesystem::remove(index_path);
    else
        throw std::runtime_error("does not exists");
    return 0;
}
