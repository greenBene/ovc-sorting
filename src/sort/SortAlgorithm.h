#pragma once

#include "Stats.h"
#include "Record.h"

class SortAlgorithm {

  public:
    virtual ~SortAlgorithm() {};

    virtual Stats sort(Record* records, int length, int keyLength) = 0;
    virtual Stats sort(Record* records, int length, int keyLength, int M) = 0;
    virtual std::string name() = 0;

};