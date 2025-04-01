#pragma once
#include "Record.h"
#include "SortAlgorithm.h"
#include "Stats.h"


class MergesortOVC final : public SortAlgorithm {
    Stats stats;
    int length = 0;
    int keyLength = 0;
    int *tree = nullptr;

public:
    Stats sort(Record* records, int length, int keyLength) override;
    Stats sort(Record* records, int length, int keyLength, int M) override;

    std::string name() override;

private:
    bool lessThan(Record &left, Record &right);
    void insertWinner(Record * records, int * tree, int treeIndex, int recordIndex);

};
