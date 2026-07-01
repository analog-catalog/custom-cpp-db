#include "../header/Commands.hpp"

void SetCommand::Execute(KeyValueStore& store, std::ostream& output) {
    store.Set(key, value);
    output << "OK\n";
}
void GetCommand::Execute(KeyValueStore& store, std::ostream& output) {
    std::string str = store.Get(key);
    output << str << "\n";
}
void ExistsCommand::Execute(KeyValueStore& store, std::ostream& output) {
    output << (store.Exists(key) ? "true\n" : "false\n");
}
void RemoveCommand::Execute(KeyValueStore& store, std::ostream& output) {
    if (store.Exists(key)) {
        store.Remove(key);
        output << "Deleted\n";
    } else {
        output << "Key not found\n";
    }
}
std::ostream& operator<<(std::ostream& os, const KeyValueStore& store) {
    const auto& data = store.GetData();
    for (auto it = data.begin(); it != data.end(); ++it) {
        os << it->first << " = " << it->second << "\n";
    }
    return os;
}
void ListCommand::Execute(KeyValueStore& store, std::ostream& output) {
    const auto& data = store.GetData();
    if (data.empty()) {
        output << "Empty\n";
    } else {
        output << store;
    }
}
void SaveCommand::Execute(KeyValueStore& store, std::ostream& output) {
    output << (storage.Save(store.GetData()) ? "Saved successfully\n" : "Error: could not save to file\n");
}
void LoadCommand::Execute(KeyValueStore& store, std::ostream& output) {
    if (!storage.Load()) {
        output << "Error: could not load file\n";
        return;
    }

    for (const auto& item : storage.GetData()) {
        store.Set(item.first, item.second);
    }

    output << "Loaded successfully\n";
}
