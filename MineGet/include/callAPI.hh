#pragma once

#include <string>
#include <memory>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

#include "callType.hh"

extern CURL* curl;

size_t writer(char *data, size_t size, size_t nmemb, std::string* buffer_in);

class APICaller {
private:
    std::string* restResult {NULL};
    struct curl_slist* headers {NULL};

    void setRestResult(std::string* str);
    std::string* makeCall(std::string url, CallType callType);
public:
    APICaller();
    virtual ~APICaller();
    std::unique_ptr<nlohmann::json> getData(std::string url, CallType callType);
};