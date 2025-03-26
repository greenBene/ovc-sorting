#pragma once
#include "Record.h"
#include "SortAlgorithm.h"
#include "Stats.h"


class Mergesort : public SortAlgorithm {
  Stats stats;
  int length = 0;
  int keyLength = 0;
  int *tree = nullptr;

  public:
    Stats sort(Record* records, int length, int keyLength) override;
    Stats sort(Record* records, int length, int keyLength, int M) override;
    std::string name() override;




  private:
    bool lessThan(const Record &left, const Record &right);
    void insertWinner(const Record * records, int * tree, int treeIndex, int recordIndex);

};
