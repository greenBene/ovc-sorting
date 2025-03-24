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
    HeapsortOVCLessThanResult lessThan(const Record &left, const Record &right, int keyLength);

};
