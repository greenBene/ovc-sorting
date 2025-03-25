#pragma once
#include "Record.h"
#include "Stats.h"


class MergesortOVC {
    Stats stats;
    int length = 0;
    int keyLength = 0;
    int *tree = nullptr;

public:
    Stats sort(Record* records, int length, int keyLength);

private:
    bool lessThan(Record &left, Record &right);
    void insertWinner(Record * records, int * tree, int treeIndex, int recordIndex);

};
