#pragma once

#include "Stats.h"
#include "Record.h"
#include "SortAlgorithm.h"

class QuicksortAOVC : public SortAlgorithm {
    Stats stats;

  public:
    Stats sort(Record* records, int length, int keyLength) override;
    Stats sort(Record* records, int length, int keyLength, int M) override;

    std::string name() override;


    static void updateToPositiveAOVC(Record * records, const unsigned int length, const unsigned int keyLength, Stats & stats);

  private:
    static void move(Record *records, const Record *list, int &counter, int length);
};
