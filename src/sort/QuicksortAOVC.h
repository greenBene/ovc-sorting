#pragma once

#include "Stats.h"
#include "Record.h"

class QuicksortAOVC {
    Stats stats;

  public:
    Stats sort(Record* records, int length, int keyLength, int M);

  private:
    static void move(Record *records, const Record *list, int &counter, int length);
};
