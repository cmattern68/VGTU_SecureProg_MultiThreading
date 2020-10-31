#include "FileLoader.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <fstream>

namespace vgtu::collections {
    FileLoader::FileLoader() {
        std::string path = "./Resources/Files/";
        std::cout << "Start reading ./Resources/Files/ for files names." << std::endl;
        for (const auto & entry : std::filesystem::directory_iterator(path)) {
            _filesName.push_back(entry.path());
        }
    }

    std::vector<std::pair<std::string, std::vector<unsigned long long int>>> FileLoader::loadBulkContent() const {
        std::cout << "Creating producer vector with files content." << std::endl;
        std::vector<std::pair<std::string, std::vector<unsigned long long int>>> list = {};

        for(std::string fileName : _filesName) {
            std::ifstream file(fileName);
            std::string line;
            unsigned long long int nb = 0;
            std::vector<unsigned long long int> tmp;

            while(std::getline(file, line))
            {
                std::stringstream linestream(line);
                linestream >> nb;
                tmp.push_back(nb);
            }
            list.push_back(std::make_pair(fileName, tmp));
            tmp.clear();
        }
        return list;
    }
}