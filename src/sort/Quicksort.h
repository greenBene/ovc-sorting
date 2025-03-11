#pragma once

#include "Stats.h"
#include "Record.h"

class Quicksort {
    Stats stats;

  public:
    Stats sort(Record* records, int length, int keyLength, int M);

  private:
    bool lessThan(const Record &left, const Record &right, int keyLength);
    static bool swap(Record* records, int a, int b);

};


