#include <iostream>
#include <sstream>
#include "../header/Parser.hpp"
#include "../header/KeyValueStore.hpp"
#include "../header/Commands.hpp"
int main() {
    Parser parser;
    KeyValueStore store;
    while (true) {
        std::string input;
        std::getline(std::cin, input);

        if (input.empty()) continue;
        else if (input == "EXIT") break;
        try {
            std::unique_ptr<Command> command = parser.parse(input);
            command->Execute(store, std::cout);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
            return 1;
        }

    }
    return 0;
}
