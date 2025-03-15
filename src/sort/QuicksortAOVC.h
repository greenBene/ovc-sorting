#pragma once

#include "Stats.h"
#include "Record.h"

class QuicksortAOVC {
    Stats stats;

  public:
    Stats sort(Record* records, int length, int keyLength, int M);
    static void updateToPositiveAOVC(Record * records, const unsigned int length, const unsigned int keyLength, Stats & stats);

  private:
    static void move(Record *records, const Record *list, int &counter, int length);
};
