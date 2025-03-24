//
// Created by Benedikt Beckermann on 24.03.25.
//

#include "Mergesort.h"

#include <iostream>

Stats Mergesort::sort(Record *records, int length, int keyLength) {
    stats = getNewStats();

    auto * tree = new int[length];
    for (int i = 0; i < length; i++) tree[i] = -1;

    auto * results = new Record[length];
    int counter = 0;

    // Build Tree of Losers
    for (int i = length - 1; i >= length / 2; i--) {
        const int left = (i * 2) % length;
        const int right = (left + 1) % length;

        if (lessThan(records[left], records[right], keyLength)) {
            tree[i] = right;
            insertWinner(records, tree, i/2, left, keyLength);
        } else {
            tree[i] = left;
            insertWinner(records, tree, i/2, right, keyLength);
        }
    }


    // --> BUG STARTS ABOUT HERE

    // Remove top element while tree not empty
    while (tree[0] >= 0) {
        const int recordIndex = tree[0];
        results[counter++] = records[recordIndex];
        tree[0] = -1;

        const int treeIndex = (recordIndex + length) / 2;

        insertWinner(records, tree, treeIndex, -2, keyLength);
    }

    for (int i = 0; i < length; i++)
        records[i] = results[i];

    delete [] tree;
    delete [] results;
    return stats;
}

void Mergesort::insertWinner(const Record * records, int * tree, int treeIndex, int recordIndex, int keyLength) {
    while (treeIndex > 0) {
        if (tree[treeIndex] == -1) {
            tree[treeIndex] = recordIndex;
            return;
        }


        if (tree[treeIndex] != -2 && (recordIndex == -2 || lessThan(records[tree[treeIndex]], records[recordIndex], keyLength))) {
            const int temp = tree[treeIndex];
            tree[treeIndex] = recordIndex;
            recordIndex = temp;
        }
        treeIndex /= 2;
    }
    tree[0] = recordIndex;
}

bool Mergesort::lessThan(const Record &left, const Record &right, int keyLength) {
    stats.rowComparisons += 1;
    for (int i = 0; i < keyLength; i++) {
        stats.columnComparisons += 1;
        if (left.key[i] != right.key[i]) {
            return left.key[i] < right.key[i];
        }
    }
    return false;
}
