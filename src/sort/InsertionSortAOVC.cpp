//
// Created by Benedikt Beckermann on 11.03.25.
//

#include "InsertionSortAOVC.h"

#include <iostream>

#include "AOVC.h"


Stats InsertionSortAOVC::sortPositive(Record* records, int left, int right, int keyLength, Stats s) {
    stats.columnComparisons = s.columnComparisons;
    stats.rowComparisons = s.rowComparisons;

    for (int j = right - 2; j >= left; j--) {
        int i = j + 1;
        Record r = records[j];
        while (i < right && positiveLessThan(records[i], r, keyLength)) {
            records[i-1] = records[i];
            i += 1;
        }
        records[i-1] = r;
    }

    return stats;
}

bool InsertionSortAOVC::positiveLessThan(Record &left, Record &right, const int keyLength) {
    stats.rowComparisons++;
    if (left.aovc < right.aovc) {
        return true;
    }
    if (left.aovc > right.aovc) {
        return false;
    }

    int offset = getOffsetAOVC(left.aovc, keyLength) + 1;
    while (offset < keyLength) {
        stats.columnComparisons++;
        if (left.key[offset] != right.key[offset])
            break;
        offset++;
    }
    if (offset >= keyLength) {
        left.aovc = POSITIVE_AOVC_ZERO;
        return false;
    }
    if (left.key[offset] < right.key[offset]) {
        right.aovc = generatePositiveAOVC(keyLength, offset, right.key[offset]);
        return true;
    }
    else {
        left.aovc = generatePositiveAOVC(keyLength, offset, left.key[offset]);
        return false;
    }
}


Stats InsertionSortAOVC::sortNegative(Record* records, const int left, const int right, const int keyLength, Stats s) {
    stats.columnComparisons = s.columnComparisons;
    stats.rowComparisons = s.rowComparisons;

    for (int j = 1; j < right; j++) {
        int i = j - 1;
        Record r = records[j];
        while (i >= left && negativeLessThan(r, records[i], keyLength)) {
            records[i+1] = records[i];
            i -= 1;
        }
        records[i + 1] = r;
    }

    return stats;
}


bool InsertionSortAOVC::negativeLessThan(Record &left, Record &right, const int keyLength) {
    stats.rowComparisons++;
    if (left.aovc < right.aovc) {
        return true;
    }
    if (left.aovc > right.aovc) {
        return false;
    }

    int offset = getOffsetAOVC(left.aovc, keyLength) + 1;
    while (offset < keyLength) {
        stats.columnComparisons++;
        if (left.key[offset] != right.key[offset])
            break;
        offset++;
    }
    if (offset >= keyLength) {
        right.aovc = NEGATIVE_AOVC_ZERO;
        return false;
    }
    if (left.key[offset] < right.key[offset]) {
        left.aovc = generateNegativeAOVC(keyLength, offset, left.key[offset]);
        return true;
    }
    else {
        right.aovc = generateNegativeAOVC(keyLength, offset, right.key[offset]);
        return false;
    }
}

