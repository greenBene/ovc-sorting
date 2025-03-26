#pragma once

#include "Stats.h"
#include "Record.h"
#include "SortAlgorithm.h"

class Quicksort final : public SortAlgorithm {
    Stats stats;

  public:
    Stats sort(Record* records, int length, int keyLength) override;
    Stats sort(Record* records, int length, int keyLength, int M) override;

    std::string name() override;

  private:
    bool lessThan(const Record &left, const Record &right, int keyLength);
    static bool swap(Record* records, int a, int b);

};


