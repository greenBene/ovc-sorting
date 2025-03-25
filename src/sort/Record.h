#pragma once
#include <string>
#include <format>
#include <cstdlib>
#include <cmath>

#include "AOVC.h"
#include "OVC.h"

struct Record {
    std::string key; // String key, fixed length, only ASCII (for now)
    uint32_t ovc = 0;
    uint32_t aovc = 0;
    uint32_t reverseOvc = 0;
    uint32_t siblingOVC = 0;
};


static Record* generateRecords(std::string* keys, int length, uint32_t ovc = OVC_MINUS_INFINITY, uint32_t aovc = AOVC_MINUS_INFINITY, uint32_t ovcSibling = OVC_MINUS_INFINITY) {
    Record* records = new Record[length];
    for (int i = 0; i < length; i++) {
        records[i].key = keys[i];
        records[i].ovc = ovc;
        records[i].aovc = aovc;
        records[i].siblingOVC = ovcSibling;
    }
    return records;
}

static Record* generateRecords(std::vector<std::string> keys, int length, uint32_t ovc = OVC_MINUS_INFINITY, uint32_t aovc = AOVC_MINUS_INFINITY, uint32_t ovcSibling = OVC_MINUS_INFINITY) {
    Record* records = new Record[length];
    for (int i = 0; i < length; i++) {
        records[i].key = keys[i];
        records[i].ovc = ovc;
        records[i].aovc = aovc;
        records[i].siblingOVC = ovcSibling;
    }
    return records;
}

static Record* generateRecords(unsigned int n, unsigned int keyLength, unsigned int seed, uint32_t ovc = OVC_PLUS_INFINITY, uint32_t aovc = AOVC_MINUS_INFINITY) {
    srand(seed);
    auto * records = new Record[n];
    for (int i = 0; i < n; i++) {
        records[i].key = std::format("{:0{}}", rand() % static_cast<int>(pow(10, keyLength)), keyLength);
        records[i].ovc = ovc;
        records[i].aovc = aovc;
    }

    return records;
}