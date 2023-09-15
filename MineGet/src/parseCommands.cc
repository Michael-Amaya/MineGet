#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>

#include "parseCommands.hh"
#include "callAPI.hh"

bool parseHelp() {
    std::cout << "Help file" << std::endl;
    return true;
}

bool parseSearch(const int argc, const char** argv) {
    // Checks for argc are done in mineget.cc before parseSearch can get called
    std::string searchTerm{argv[2]};
    std::string url{"https://api.spiget.org/v2/search/resources/" + searchTerm};

    APICaller caller{};
    std::unique_ptr<nlohmann::json> response = caller.getData(url, CallType::GET);

    if (response && response->is_array()) {
        std::cout << "Found " << response->size() << " Resource(s): " << std::endl;
        for (int i = 0; i < response->size(); ++i) {
            int selectionOptions = i + 1;
            std::string name = (*response)[i]["name"];
            std::cout << "(" << selectionOptions << ") " << name << std::endl;
        }

        int selectedOption = selectOption(response->size());
        if (selectedOption < 0) {
            std::cout << "Invalid selection selected!" << std::endl;
            return false;
        }

        nlohmann::json selectedItem = (*response)[selectedOption];
        bool doneBrowsing = false;
        while (!doneBrowsing) {
            std::cout << "Selected " << selectedItem["name"].get<std::string>() << std::endl;
            std::cout << "(1) Description" << std::endl;
            std::cout << "(2) Install" << std::endl;
            std::cout << "(3) Abort" << std::endl;

            selectedOption = selectOption(3);
            switch (selectedOption) {
                case 0:
                    // Description
                    std::cout << "Description: " << selectedItem["tag"].get<std::string>() << "\n" << std::endl;
                    break;
                case 1:
                    // Install
                    // Do some stuff, then do abort stuff
                case 2:
                    // Abort
                    doneBrowsing = true;
                    break;
                default:
                std::cout << "Invalid selection!" << std::endl;
            }
        }

    } else {
        std::cout << "There was a fatal error searching that term!" << std::endl;
    }
    return true;
}

bool parseInstall(const int argc, const char** argv) {
    
    return true;
}

bool parseUpdate(const int argc, const char** argv) {

    return true;
}

bool parseList() {
    return true;
}

bool parseReview(const int argc, const char** argv) {
    return true;
}

bool parseSet(const int argc, const char** argv) {
    return true;
}

int selectOption(int numOptions) {
    int selection = -1;
    std::string line{};
    
    std::cout << std::endl;
    std::cout << "Select one of options [1 - " << numOptions << "]: ";
    std::getline(std::cin, line);
    if (isNumber(line)) {
        selection = std::stoi(line);
    } else {
        return -1;
    }

    if (selection < 1 || selection > numOptions) {
        return -1;
    }

    return selection - 1;
}

bool installPlugin(nlohmann::json* plugin) {
    bool external = (*plugin)["dd"].get<bool>();
    if (!external) {

    }

    return true;
}

bool isNumber(const std::string& s){
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}
