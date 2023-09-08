#include <iostream>

#include "parseCommands.hh"

const std::string commandList[] = {"help", "list", "search", "install", "upgrade"};

int main(const int argc, const char **argv) {
    // Check if there is a command
    if (argc < 2) {
        std::cout << "Usage: mineget <command> [additional arguments]" << std::endl;
        parseHelp();
        return -1;
    }

    // Check if command in command list
    const std::string command = std::string(argv[1]);

    if (std::find(std::begin(commandList), std::end(commandList), command) == std::end(commandList)) {
        std::cout << "Command \"" << command << "\" not found!" << std::endl;
    } else if (command == "help") {
        parseHelp();
    } else if (command == "list") {
        parseList();
    } else if (argc < 3) {
        std::cout << "Command \"" << command << "\" needs at least 3 arguments!" << std::endl;
    } else if (command == "search") {
        parseSearch(argc, argv);
    } else if (command == "install") {
        parseInstall(argc, argv);
    } else if (command == "upgrade") {
        parseUpdate(argc, argv);
    }

    return 0;
}