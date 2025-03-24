#pragma once
#include "Record.h"
#include "Stats.h"


class Mergesort {
  Stats stats;

  public:
    Stats sort(Record* records, int length, int keyLength);

  private:
    bool lessThan(const Record &left, const Record &right, int keyLength);
    void insertWinner(const Record * records, int * tree, int treeIndex, int recordIndex, int keyLength);

};
