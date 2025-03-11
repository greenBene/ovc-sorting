#include "Heapsort.h"

#include <iostream>

#include "Record.h"


Stats Heapsort::sort(Record *records, const int length, const int keyLength) {
    stats = getNewStats();

    int left = length / 2;
    int right = length - 1;

    Record r;
    while (left > 0 || right > 1) {
        if (left > 0) {
            left -= 1;
            r = records[left];
        } else {
            r = records[right];
            records[right] = records[0];
            right -= 1;
        }
        int i = left;
        int j = 2 * left + 1;
        while (j <= right) {
            if (j < right && lessThan(records[j], records[j+1], keyLength)) {
                j+=1;
            }
            if (!lessThan(r, records[j], keyLength)) {
                break;
            }
            records[i] = records[j];
            i = j;
            j = 2 * j + 1;
        }
        records[i] = r;
    }

    const Record temp = records[0];
    records[0] = records[1];
    records[1] = temp;

    return stats;
}

bool Heapsort::lessThan(const Record &left, const Record &right, int keyLength) {
    stats.rowComparisons += 1;

    for (int i = 0; i < keyLength; i++) {
        stats.columnComparisons += 1;
        if (left.key[i] != right.key[i]) {
            return left.key[i] < right.key[i];
        }
    }

    return false;
}

