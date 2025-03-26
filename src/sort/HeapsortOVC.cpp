//
// Created by Benedikt Beckermann on 11.03.25.
//

#include "HeapsortOVC.h"

#include <iostream>

#include "OVC.h"


Stats HeapsortOVC::sort(Record *records, int length, int keyLength) {
    stats = getNewStats();

    int left = length  / 2;

    Record r;
    auto * results = new Record[length];
    bool leftSibling = false;
    uint32_t ovcSibling = OVC_MINUS_INFINITY;
    int siblingWinner, siblingLooser;
    int counter = 0;
    while (left > 0 || records[0].ovc != OVC_MINUS_INFINITY) {
        if (left > 0) {
            left -= 1;
        } else {
            results[counter++] = records[0];
            records[0].key.clear();
            records[0].ovc = OVC_MINUS_INFINITY;
        }
        r = records[left];
        int i = left;
        int j = 2 * left + 1;

        while (j < length) {
            if (r.ovc > records[j].ovc && (j == length - 1 || r.ovc > records[j+1].ovc)) {
                stats.rowComparisons++;
                break;
            }
            if (records[j].ovc == OVC_MINUS_INFINITY && (j == length -1 || records[j+1].ovc == OVC_MINUS_INFINITY)) {
                break;
            }

            if (j == length - 1) {
                leftSibling = true;
            }
            else if (records[j].siblingOVC != OVC_MINUS_INFINITY) {
                leftSibling = false;
                ovcSibling = records[j].siblingOVC;
            } else if (records[j+1].siblingOVC != OVC_MINUS_INFINITY) {
                leftSibling = true;
                ovcSibling = records[j+1].siblingOVC;
            } else {
                auto [l, o] = lessThan(records[j], records[j+1], keyLength);
                leftSibling = l;
                ovcSibling = o;
            }
            if (leftSibling) {
                siblingWinner = j;
                siblingLooser = j + 1;
            } else {
                siblingWinner = j + 1;
                siblingLooser = j;
            }

            auto [ordered, ovc] = lessThan(r, records[siblingWinner], keyLength);
            if (ordered) {
                if (ovc != OVC_MINUS_INFINITY)
                    records[siblingWinner].ovc = ovc;
                if (siblingLooser < length && ovcSibling != OVC_MINUS_INFINITY) {
                    if (ovc != OVC_MINUS_INFINITY)
                        records[siblingLooser].ovc = std::min(ovcSibling, ovc);
                    else
                        records[siblingLooser].ovc = ovcSibling;
                    if (ovc < ovcSibling) {
                        records[siblingLooser].siblingOVC = ovcSibling;
                    }
                }
                break;
            } else {
                if (ovc != OVC_MINUS_INFINITY) {
                    r.ovc = ovc;
                }
                if (siblingLooser < length && ovcSibling != OVC_MINUS_INFINITY) {
                        records[siblingLooser].ovc = ovcSibling;
                }
                records[j].siblingOVC = OVC_MINUS_INFINITY;
                if (j < length - 1)
                    records[j+1].siblingOVC = OVC_MINUS_INFINITY;

                records[i] = records[siblingWinner];
                i = siblingWinner;
                j = 2 * siblingWinner + 1;
            }
        }
        records[i] = r;
    }

    for (int i = 0; i < length; i++) {
        records[i] = results[i];
    }
    delete [] results;

    return stats;
}

Stats HeapsortOVC::sort(Record *records, const int length, const int keyLength, int M) {
    return this->sort(records, length, keyLength);
}

std::string HeapsortOVC::name() {
    return "HeapsortOVC";
}

HeapsortOVCLessThanResult HeapsortOVC::lessThan(const Record &left, const Record &right, const int keyLength) {
    stats.rowComparisons++;
    if (left.ovc > right.ovc) {
        return {true, OVC_MINUS_INFINITY};
    }
    if (right.ovc > left.ovc) {
        return {false, OVC_MINUS_INFINITY};
    }
    int offset = getOffsetOVC(left.ovc) + 1;
    while (offset < keyLength) {
        stats.columnComparisons++;
        if (left.key[offset] != right.key[offset]) {
            break;
        }
        offset++;
    }
    if (offset >= keyLength) {
        return {true, generateOVC(keyLength, 0)};
    }
    if (left.key[offset] < right.key[offset]) {
        return {true, generateOVC(offset, right.key[offset])};
    }
    else {
        return {false, generateOVC(offset, left.key[offset])};
    }
}
