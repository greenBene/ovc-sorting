#pragma once

#include <string>

#include "Stats.h"

struct Record {
    std::string key;
};

class InsertionSort {
  private:
    Stats stats;

  public:
    Stats sort(Record* records, int length, int keyLength);

  private:
    bool lessThan(const Record &left, const Record &right, int keyLength);

};
