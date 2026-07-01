#pragma once
#include <map>
#include <string>
#include <fstream>
#include <iostream>

class FileStorage {
    private:
        std::string filename;
        std::map<std::string, std::string> data;
    public:
        FileStorage(const std::string filename) : filename(filename) {}
        const std::map<std::string, std::string>& GetData() const;
        bool Save(const std::map<std::string, std::string> & data);
        bool Load();
};
