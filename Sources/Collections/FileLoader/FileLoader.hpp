#ifndef FILELOADER_HPP
#define FILELOADER_HPP

#include <vector>
#include <string>
#include <array>

namespace vgtu::collections {

    class FileLoader {
    public:
        ~FileLoader() = default;
        FileLoader();
        FileLoader(const FileLoader &) = delete;
        FileLoader &operator=(const FileLoader &) = delete;

        static std::array<const char *, 1000> getFilesName();
        static std::vector<unsigned long long int> loadFileContent(std::string);
    };
}

#endif
