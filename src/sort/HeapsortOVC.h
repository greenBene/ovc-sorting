#pragma once
#include "Record.h"
#include "Stats.h"

struct HeapsortOVCLessThanResult {
    bool less;
    uint32_t ovc;
};


class HeapsortOVC {
    Stats stats;

  public:
    Stats sort(Record* records, int length, int keyLength);

  private:
    HeapsortOVCLessThanResult lessThan(Record &left, Record &right, int keyLength);

};
