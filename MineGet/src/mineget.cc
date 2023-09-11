#include <iostream>
#include <curl/curl.h>

#include "parseCommands.hh"

CURL* curl;

const std::string commandList[] = {"help", "list", "search", "install", "upgrade"};

int main(const int argc, const char **argv) {
    // Initialize global libcurl var
    curl = curl_easy_init();

    // Check if there is a command
    if (!curl) {
        std::cout << "There was a fatal error starting mineget!" << std::endl;
    } else if (argc < 2) {
        std::cout << "Usage: mineget <command> [additional arguments]" << std::endl;
        parseHelp();
    } else {
        // Check if command in command list
        const std::string command {std::string(argv[1])};

        if (std::find(std::begin(commandList), std::end(commandList), command) == std::end(commandList)) {
            std::cout << "Command \"" << command << "\" not found!" << std::endl;
        } else if (command == "help") {
            parseHelp();
        } else if (command == "list") {
            parseList();
        } else if (command == "review") {
            parseReview(argc, argv);
        } else if (argc < 3) {
            std::cout << "Command \"" << command << "\" needs at least 3 arguments!" << std::endl;
        } else if (command == "search") {
            parseSearch(argc, argv);
        } else if (command == "install") {
            parseInstall(argc, argv);
        } else if (command == "upgrade") {
            parseUpdate(argc, argv);
        } else if (command == "set") {
            parseSet(argc, argv);
        }
    }

    // Must reach here no matter what!
    curl_easy_cleanup(curl);

    return 0;
}