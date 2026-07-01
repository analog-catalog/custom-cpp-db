#include "../header/Parser.hpp"

std::unique_ptr<Command> Parser::parse(const std::string& input) {
    ParsedCommand command;
    std::stringstream ss(input);
    ss >> command.type;
    ss >> command.key;
    ss >> command.value;
    if (command.type == "SET") return std::make_unique<SetCommand>(command.key, command.value);
    if (command.type == "GET") return std::make_unique<GetCommand>(command.key);
    if (command.type == "DELETE") return std::make_unique<RemoveCommand>(command.key);
    if (command.type == "LIST") return std::make_unique<ListCommand>();
    if (command.type == "EXISTS") return std::make_unique<ExistsCommand>(command.key);
    if (command.type == "SAVE") return std::make_unique<SaveCommand>(command.key.empty() ? "data.txt" : command.key);
    if (command.type == "LOAD") return std::make_unique<LoadCommand>(command.key.empty() ? "data.txt" : command.key);


    throw std::runtime_error("Unknown command");
}
