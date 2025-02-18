#pragma once


#include "Stats.h"
#include "Record.h"

class InsertionSort {
    Stats stats;

  public:
    Stats sort(Record* records, int length, int keyLength);

  private:
    bool lessThan(const Record &left, const Record &right, int keyLength);

};
