#include <iostream>

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
    std::cout << url << std::endl;
    std::string* response = caller.makeCall(url, CallType::GET);

    std::cout << "Response:\n" << *response << std::endl;
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
