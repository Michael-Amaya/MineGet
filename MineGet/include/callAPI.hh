#pragma once

#include <curl/curl.h>
#include <string>

#include "callType.hh"

extern CURL* curl;

size_t writer(char *data, size_t size, size_t nmemb, std::string* buffer_in);

class APICaller {
private:
    std::string* restResult {NULL};
    struct curl_slist* headers {NULL};

    void setRestResult(std::string* str);
public:
    APICaller();
    virtual ~APICaller();
    std::string* makeCall(std::string url, CallType callType);
};