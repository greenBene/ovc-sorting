#pragma once

#include "Stats.h"
#include "Record.h"

class InsertionSortOVC {
    Stats stats;

  public:
    Stats sort(Record* records, int length, int keyLength);

  private:
    bool lessThan(Record &left, Record &right, int keyLength);

};
