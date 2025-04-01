#pragma once

#include "Stats.h"
#include "Record.h"
#include "SortAlgorithm.h"

class QuicksortAOVC final : public SortAlgorithm {
    Stats stats;
    bool fixAOVC = false;

  public:
    Stats sort(Record* records, int length, int keyLength) override;
    Stats sort(Record* records, int length, int keyLength, int M) override;

    std::string name() override;
    void setFixOVC(bool fixAOVC);

    static void updateToPositiveAOVC(Record * records, unsigned int length, unsigned int keyLength, Stats & stats);


  private:
    static void move(Record *records, const Record *list, int &counter, int length);
};
