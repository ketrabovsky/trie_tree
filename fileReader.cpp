#include "fileReader.hpp"

#include <fstream>

namespace FileUtils
{
    std::string FileReader::read_file(const std::string &filename)
    {
        std::fstream file;
        file.open(filename, std::fstream::in);

        if (!file.is_open()) 
        {
            return "";
        }

        std::string file_lines;

        while(!file.eof()) {
            std::string line;
            std::getline(file, line);
            if (line.size() < 1) continue;
			line.append("\n");
            file_lines.append(line.c_str());
        }

        file.close();

        return file_lines;
    }

    std::vector<std::string> FileReader::read_file_as_lines(const std::string &filename)
    {
		std::vector<std::string> result;
        std::fstream file;
        file.open(filename, std::fstream::in);

        if (!file.is_open()) 
        {
            return result;
        }

        std::string file_lines;

        while(!file.eof()) {
            std::string line;
            std::getline(file, line);
            if (line.size() < 1) continue;
			result.push_back(line);
        }

        file.close();

        return result;
    }
}
