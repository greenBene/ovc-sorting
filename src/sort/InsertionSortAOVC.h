#pragma once
#include "Record.h"
#include "Stats.h"

class InsertionSortAOVC {
    Stats stats;

  public:
    Stats sortPositive(Record* records, int left, int right, int keyLength, Stats s);
    Stats sortNegative(Record* records, int left, int right, int keyLength, Stats s);

  private:
    bool positiveLessThan(Record &left, Record &right, int keyLength);
    bool negativeLessThan(Record &left, Record &right, int keyLength);

};
