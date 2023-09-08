// Commands that need to be parsed. Possible commands are prefixed with parse_
bool parseHelp();
bool parseSearch(const int argc, const char** argv);
bool parseInstall(const int argc, const char** argv);
bool parseUpdate(const int argc, const char** argv);
bool parseList();
