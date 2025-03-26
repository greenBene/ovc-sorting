#pragma once

#include "Stats.h"
#include "Record.h"
#include "SortAlgorithm.h"

class InsertionSortOVC : public SortAlgorithm {
    Stats stats;

  public:
    Stats sort(Record* records, int length, int keyLength) override;
    Stats sort(Record* records, int length, int keyLength, int M) override;
    Stats sort(Record* records, int left, int right, int keyLength, Stats s);

    std::string name() override;


  private:
    bool lessThan(Record &left, Record &right, int keyLength);

};
