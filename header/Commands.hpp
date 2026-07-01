#pragma once

#include "KeyValueStore.hpp"
#include "Storage.hpp"
#include <ostream>
#include <string>

class Command {
    public:
        virtual void Execute(KeyValueStore& store, std::ostream& output) = 0;
        virtual ~Command() = default;
};
class SetCommand : public Command {
    private:
        std::string key;
        std::string value;
    public:
        SetCommand(std::string key, std::string value) : key(key), value(value) {}
        void Execute(KeyValueStore& store, std::ostream& output) override;
};
class GetCommand : public Command {
    private:
        std::string key;
    public:
        GetCommand(std::string key) : key(key) {}
        void Execute(KeyValueStore& store, std::ostream& output) override;
};
class ExistsCommand : public Command {
    private:
        std::string key;
    public:
        ExistsCommand(std::string key) : key(key) {}
        void Execute(KeyValueStore& store, std::ostream& output) override;
};
class RemoveCommand : public Command {
    private:
        std::string key;
    public:
        RemoveCommand(std::string key) : key(key) {}
        void Execute(KeyValueStore& store, std::ostream& output) override;
};
class ListCommand : public Command {
    public:
        friend std::ostream& operator<<(std::ostream& os, const KeyValueStore& store);
        void Execute(KeyValueStore& store, std::ostream& output) override;
};
class SaveCommand : public Command {
    private:
        FileStorage storage;
    public:
        SaveCommand(std::string filename) : storage(filename) {}
        SaveCommand(FileStorage storage) : storage(storage) {}
        void Execute(KeyValueStore& store, std::ostream& output) override;
};
class LoadCommand : public Command {
    private:
        FileStorage storage;
    public:
        LoadCommand(std::string filename) : storage(filename) {}
        LoadCommand(FileStorage storage) : storage(storage) {}
        void Execute(KeyValueStore& store, std::ostream& output) override;
};
