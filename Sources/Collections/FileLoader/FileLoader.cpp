#include "FileLoader.hpp"
#include <string>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <string.h>

namespace vgtu::collections {
    FileLoader::FileLoader() {
    }

    std::array<const char *, 1000> FileLoader::getFilesName() {
        std::array<const char *, 1000> filesName;
        std::string path = "./Resources/Files/";
        std::size_t i = 0;

        for (const auto &entry : std::filesystem::directory_iterator(path)) {
            filesName[i] = strdup((entry.path()).c_str());
            ++i;
        }
        return filesName;
    }

    std::vector<unsigned long long int> FileLoader::loadFileContent(std::string fileName) {
        std::vector<unsigned long long int> list = {};

        std::ifstream file(fileName);
        std::string line;
        unsigned long long int nb = 0;

        while(std::getline(file, line)) {
            std::stringstream linestream(line);
            linestream >> nb;
            list.push_back(nb);
        }
        return list;
    }
}