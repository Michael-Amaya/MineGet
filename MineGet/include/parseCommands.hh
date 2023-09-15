#pragma once
#include <nlohmann/json.hpp>

// Commands that need to be parsed. Possible commands are prefixed with parse_
bool parseHelp();
bool parseList();
bool parseSearch(const int argc, const char** argv);
bool parseInstall(const int argc, const char** argv);
bool parseUpdate(const int argc, const char** argv);
bool parseReview(const int argc, const char** argv);
bool parseSet(const int argc, const char** argv);

// Helper functions
int selectOption(int numOptions);

// Gotten from https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
bool isNumber(const std::string& s);
bool installPlugin(nlohmann::json* plugin);