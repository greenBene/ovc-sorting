#pragma once
#include "Record.h"
#include "Stats.h"

class InsertionSortAOVC {
    Stats stats;

  public:
    Stats sort(Record* records, int left, int right, int keyLength, Stats s);
    Stats sortPositive(Record* records, int left, int right, int keyLength, Stats s);
    Stats sortNegative(Record* records, int left, int right, int keyLength, Stats s);

  private:
    static bool positiveLessThan(Record &left, Record &right, int keyLength);
    static bool negativeLessThan(Record &left, Record &right, int keyLength);

};
