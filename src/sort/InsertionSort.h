#pragma once

#include <string>

#include "Stats.h"

struct Record {
    std::string key;
};

class InsertionSort {
  private:
    int rowComparisons = 0;
    int columnComparisons = 0;

  public:
    Stats sort(Record* records, int length, int keyLength);

  private:
    bool lessThan(const Record &left, const Record &right, int keyLength);

};
