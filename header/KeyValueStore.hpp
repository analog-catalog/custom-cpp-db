#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>

class KeyValueStore {
    private:
        std::map<std::string, std::string> data;
    public:
        void Set(const std::string& key, const std::string& value);
        std::string Get(const std::string& key) const;
        void Remove(const std::string& key);
        bool Exists(const std::string& key) const;
        const std::map<std::string, std::string>& GetData() const;
        bool saveToFile(const std::string& filename);
        bool loadFromFile(const std::string& filename);

};
