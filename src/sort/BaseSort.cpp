//
// Created by Benedikt Beckermann on 26.03.25.
//

#include "BaseSort.h"
#include "algorithm"


Stats BaseSort::sort(Record *records, const int length, const int keyLength, int M) {
    stats = getNewStats();
    std::sort(records, records + length, [&](const Record &left, const Record &right) {
        stats.rowComparisons++;
        for (int i = 0; i < keyLength; i++) {
            stats.columnComparisons++;
            if (left.key[i] != right.key[i])
                return left.key[i] < right.key[i];
        }
        return false;
    });
    return stats;
}

Stats BaseSort::sort(Record *records, const int length, const int keyLength) {
    return this->sort(records, length, keyLength, 0);
}

std::string BaseSort::name() {
    return "BaseSort";
}
