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

    if (response && response->is_array() && !response->empty()) {
        std::cout << "Found " << response->size() << "Resource(s): " << std::endl;
        for (int i = 0; i < response->size(); ++i) {
             std::cout << "(" << i << ")" << (*response)[i]["name"] << std::endl;
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
