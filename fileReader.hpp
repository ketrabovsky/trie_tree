#pragma once

#include <string>
#include <vector>

namespace FileUtils
{
    class FileReader
    {
    public:
        static std::string read_file(const std::string &filename);
        static std::vector<std::string> read_file_as_lines(const std::string &filename);
    };
}
