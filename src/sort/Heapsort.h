#pragma once
#include <string>

#include "SortAlgorithm.h"
#include "Stats.h"

struct Record;

class Heapsort final : public SortAlgorithm{
    Stats stats;

  public:
    Stats sort(Record* records, int length, int keyLength) override;
    Stats sort(Record* records, int length, int keyLength, int M) override;

    std::string name() override;

  private:
    bool lessThan(const Record &left, const Record &right, int keyLength);

};
