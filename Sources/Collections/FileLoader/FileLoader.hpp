#ifndef FILELOADER_HPP
#define FILELOADER_HPP

#include <vector>
#include <string>

namespace vgtu::collections {

    class FileLoader {
    public:
        ~FileLoader() = default;
        FileLoader();
        FileLoader(const FileLoader &) = delete;
        FileLoader &operator=(const FileLoader &) = delete;

        std::vector<std::pair<std::string, std::vector<unsigned long long int>>> loadBulkContent() const;
    private:
        std::vector<std::string> _filesName;
    };
}

#endif
