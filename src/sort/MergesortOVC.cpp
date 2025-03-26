//
// Created by Benedikt Beckermann on 25.03.25.
//

#include "MergesortOVC.h"


Stats MergesortOVC::sort(Record *records, const int length, const int keyLength) {
    this->stats = getNewStats();
    this->length = length;
    this->keyLength = keyLength;
    this->tree = new int[length];

    for (int i = 0; i < length; i++)
        tree[i] = -1;

    auto * results = new Record[length];
    int counter = 0;

    // Build Tree of Losers
    if (length%2==1) {
        tree[length/2] = 0;
    }

    for (int i = (length%2==1?1:0); i < length; i+=2) {
        const int left = i;
        const int right = i + 1;
        const int treeIndex = (i + length)/2;

        if (lessThan(records[left], records[right])) {
            tree[treeIndex] = right;
            insertWinner(records, tree, treeIndex/2, left);
        } else {
            tree[treeIndex] = left;
            insertWinner(records, tree, treeIndex/2, right);
        }
    }

    // Remove top element while tree not empty
    while (tree[0] >= 0) {
        const int recordIndex = tree[0];
        results[counter++] = records[recordIndex];
        tree[0] = -1;
        const int treeIndex = (recordIndex + length) / 2;
        insertWinner(records, tree, treeIndex, -2);
    }

    for (int i = 0; i < length; i++)
        records[i] = results[i];

    delete [] tree;
    delete [] results;
    return stats;
}

Stats MergesortOVC::sort(Record *records, int length, int keyLength, int M) {
    return this->sort(records, length, keyLength);
}

std::string MergesortOVC::name() {
    return "MergesortOVC";
}

void MergesortOVC::insertWinner(Record * records, int * tree, int treeIndex, int recordIndex) {
    while (treeIndex > 0) {
        if (tree[treeIndex] == -1) {
            tree[treeIndex] = recordIndex;
            return;
        }

        if (tree[treeIndex] != -2 && (recordIndex == -2 || lessThan(records[tree[treeIndex]], records[recordIndex]))) {
            const int temp = tree[treeIndex];
            tree[treeIndex] = recordIndex;
            recordIndex = temp;
        }
        treeIndex /= 2;
    }
    tree[0] = recordIndex;
}

bool MergesortOVC::lessThan(Record &left, Record &right) {
    stats.rowComparisons += 1;

    if (left.ovc > right.ovc) {
        return true;
    }
    if (left.ovc < right.ovc) {
        return false;
    }

    uint16_t i = getOffsetOVC(left.ovc) + 1;

    while (i < keyLength) {
        stats.columnComparisons++;
        if (left.key[i] != right.key[i])
            break;
        i++;
    }

    if (i >= keyLength) {
        left.ovc = generateOVC(keyLength, 0);
        return false;
    }

    if (left.key[i] < right.key[i]) {
        right.ovc = generateOVC(i, right.key[i]);
        return true;
    }
    else {
        left.ovc = generateOVC(i, left.key[i]);
        return false;
    }
}