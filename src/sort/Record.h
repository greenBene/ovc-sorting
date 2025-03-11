#pragma once
#include <string>
#include <format>
#include <cstdlib>
#include <cmath>

#include "AOVC.h"

struct Record {
    std::string key; // String key, fixed length, only ASCII (for now)
    uint32_t ovc = 0;
    uint32_t aovc = 0;
    uint32_t reverseOvc = 0;
};


static Record* generateRecords(std::string* keys, int length) {
    Record* records = new Record[length];
    for (int i = 0; i < length; i++) {
        records[i].key = keys[i];
    }
    return records;
}

static Record* generateRecords() {
    std::string keys[] = {"772", "715", "797", "625", "526", "203", "684", "025", "615",
                          "617", "719", "388", "689", "954", "739", "052", "805", "499",
                          "222", "142", "271", "516", "450", "229", "120", "338", "053",
                          "230", "007", "323", "344", "288", "186", "144", "109", "384",
                          "096", "167", "235", "287", "001", "272", "956", "002", "082",
                          "330", "251", "282", "352", "662", "332", "907", "769", "274",
                          "073", "385", "979", "324", "619", "441", "168", "289", "428",
                          "172", "626", "563", "449", "004", "746", "753", "177", "683",
                          "354", "773", "905", "361", "461", "958", "715", "448", "747",
                          "799", "985", "343", "357", "585", "286", "309", "885", "166",
                          "295", "764", "708", "325", "983", "970", "233", "721", "111"};
    return generateRecords(keys, 99);
}

static Record* generateRecords(unsigned int n, unsigned int keyLength, unsigned int seed, uint32_t ovc = NEGATIVE_INFINITY, uint32_t aovc = NEGATIVE_INFINITY) {
    srand(seed);
    auto * records = new Record[n];
    for (int i = 0; i < n; i++) {
        records[i].key = std::format("{:0{}}", rand() % static_cast<int>(pow(10, keyLength)), keyLength);
        records[i].ovc = ovc;
        records[i].aovc = aovc;
    }

    return records;
}