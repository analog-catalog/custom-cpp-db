#include "../header/KeyValueStore.hpp"

void KeyValueStore::Set(const std::string& key, const std::string& value) {
    data[key] = value;
}
std::string KeyValueStore::Get(const std::string& key) const {
    auto it = data.find(key);
    return (it != data.end()) ? it->second : "Key not found";
}
void KeyValueStore::Remove(const std::string& key) {
    data.erase(key);
}
bool KeyValueStore::Exists(const std::string& key) const {
    return (data.contains(key)) ? true : false;
}
const std::map<std::string, std::string>& KeyValueStore::GetData() const {
    return data;
}
bool KeyValueStore::saveToFile(const std::string& filename) {
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
bool KeyValueStore::loadFromFile(const std::string& filename) {
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
