#pragma once
#include "Record.h"
#include "Stats.h"


class Mergesort {
  Stats stats;
  int length = 0;
  int keyLength = 0;
  int *tree = nullptr;

  public:
    Stats sort(Record* records, int length, int keyLength);

  private:
    bool lessThan(const Record &left, const Record &right);
    void insertWinner(const Record * records, int * tree, int treeIndex, int recordIndex);

};
