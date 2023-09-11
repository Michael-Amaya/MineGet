#include <string>
#include <curl/curl.h>

#include "callAPI.hh"
#include "callType.hh"

APICaller::APICaller() {
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "charset: utf-8");
}

APICaller::~APICaller() {
    curl_slist_free_all(headers);
    setRestResult(nullptr);
}

void APICaller::setRestResult(std::string* str) {
    // Can't leak memory
    if (restResult) {
        delete restResult;
    }

    restResult = str;
}


std::string* APICaller::makeCall(std::string url, CallType callType) {
    CURLcode result;
    
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    switch (callType) {
        case CallType::POST:
            curl_easy_setopt(curl, CURLOPT_HTTPPOST, 1);
            break;
        case CallType::GET:
        default:
            curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
    }

    std::string* buffer = new std::string;

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);

    result = curl_easy_perform(curl);
    if (result == CURLE_OK) {
        char* responseContentType;
        result = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &responseContentType);
        if ((result == CURLE_OK) && responseContentType) {
            setRestResult(buffer);
            return restResult;
        }
    }

    return nullptr;
}

size_t writer(char *data, size_t size, size_t nmemb, std::string* buffer_in) {
    buffer_in->append(data, size * nmemb);
    return size * nmemb;
}
