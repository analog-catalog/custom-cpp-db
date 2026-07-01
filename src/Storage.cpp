#include "Storage.hpp"

const std::map<std::string, std::string>& FileStorage::GetData() const {
    return data;
}
bool FileStorage::Save(const std::map<std::string, std::string> & data) {
    std::ofstream file(filename);
    if (!file) {
        std::cout << "Error opening file\n";
        return false;
    }
    for (auto it = data.begin(); it != data.end(); ++it){
        file << it->first << "=" << it->second << "\n";
    }
    return true;
}

bool FileStorage::Load() {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file\n";
        return false;
    }
    std::string line;
    while(std::getline(file, line)) {
        size_t pos = line.find('=');
        if (pos == std::string::npos) continue;
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        data[key] = value;
    }
    return true;
}
