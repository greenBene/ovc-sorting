#pragma once
#include <string>

struct Record {
    std::string key; // String key, fixed length, only ASCII (for now)
    uint32_t ovc = 0;
};