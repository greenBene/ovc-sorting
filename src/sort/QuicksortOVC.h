#pragma once

#include "Stats.h"
#include "Record.h"


struct QuicksortOVCLessThanResult {
    bool less;
    uint32_t ovc;
};


class QuicksortOVC {
    Stats stats;

  public:
    Stats sort(Record* records, int length, int keyLength, int M);

  private:
    QuicksortOVCLessThanResult lessThan(const Record &left, const Record &right, int keyLength);
    static bool swap(Record* records, int length, int a, int b);

};
