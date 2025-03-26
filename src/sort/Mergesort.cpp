//
// Created by Benedikt Beckermann on 24.03.25.
//

#include "Mergesort.h"

#include <iostream>

Stats Mergesort::sort(Record *records, const int length, const int keyLength) {
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

Stats Mergesort::sort(Record *records, const int length, const int keyLength, int M) {
    return this->sort(records, length, keyLength);
}

std::string Mergesort::name() {
    return "Mergesort";
}

void Mergesort::insertWinner(const Record * records, int * tree, int treeIndex, int recordIndex) {
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

bool Mergesort::lessThan(const Record &left, const Record &right) {
    stats.rowComparisons += 1;
    for (int i = 0; i < keyLength; i++) {
        stats.columnComparisons += 1;
        if (left.key[i] != right.key[i]) {
            return left.key[i] < right.key[i];
        }
    }
    return false;
}
