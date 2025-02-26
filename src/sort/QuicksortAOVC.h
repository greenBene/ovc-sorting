#pragma once

#include "Stats.h"
#include "Record.h"


struct QuicksortOVCLessThanResult {
    bool less;
    uint32_t ovc;
};


class QuicksortAOVC {
    Stats stats;

  public:
    Stats sort(Record* records, int length, int keyLength, int M);

  private:
    void sort(Record* records, int left, int right, int keyLength, int M);
    static void move(Record *records, const Record *list, int &counter, int length);
};
