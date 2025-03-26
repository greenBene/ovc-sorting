#pragma once

#include "Stats.h"
#include "Record.h"

#include "SortAlgorithm.h"

class InsertionSort final : public SortAlgorithm {
    Stats stats;


  public:
    Stats sort(Record* records, int length, int keyLength) override;
    Stats sort(Record* records, int length, int keyLength, int M) override;
    Stats sort(Record* records, int length, int keyLength, const Stats &s);

    std::string name() override;

  private:
    bool lessThan(const Record &left, const Record &right, int keyLength);
};
