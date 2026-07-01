#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <stdexcept>
#include "Commands.hpp"

struct ParsedCommand {
    std::string type;
    std::string key;
    std::string value;
};
class Parser {
    public:
        std::unique_ptr<Command> parse(const std::string& input);

};
