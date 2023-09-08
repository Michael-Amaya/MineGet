#include <iostream>
#include "mineget.hh"

int main(int argc, char **argv) {
    // Check if there is a command
    if (argc < 2) {
        parse_help();
    }
    return 0;
}

bool parse_help() {
    std::cout << "Help file" << std::endl;
    return true;
}

bool parse_search() {
    return true;
}
bool parse_install() {
    return true;
}
bool parse_update() {
    return true;
}
bool parse_list() {
    return true;
}