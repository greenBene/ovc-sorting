#pragma once

#include <OVC.h>
#include <Record.h>

static bool isSorted(const Record * records, const int N) {
    for (int i = 1; i < N; i++) {
        if (records[i-1].key > records[i].key) {
            return false;
        }
    }
    return true;
}

static bool validOVC(const Record * records, const int N, const int keyLength) {
    for (int i = 1; i < N; i++) {
        const uint32_t ovc = records[i].ovc;
        const uint32_t o = offset(ovc);
        const uint32_t v = value(ovc);

        for (int t = 0; t < o; t++) {
            if (records[i].key[t] != records[i-1].key[t]) {
                return false;
            }
        }
        if (o < keyLength && records[i-1].key[o] == records[i].key[o]) {
            return false;
        }
        if (o < keyLength && records[i].key[o] != static_cast<char>(v)) {
            return false;
        }
    }
    return true;
}
