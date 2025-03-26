#pragma once

#include "Stats.h"
#include "Record.h"
#include "SortAlgorithm.h"


struct QuicksortOVCLessThanResult {
    bool less;
    uint32_t ovc;
};


class QuicksortOVC : public SortAlgorithm {
    Stats stats;

  public:
    Stats sort(Record* records, int length, int keyLength) override;
    Stats sort(Record* records, int length, int keyLength, int M) override;

    std::string name() override;

  private:
    QuicksortOVCLessThanResult lessThan(const Record &left, const Record &right, int keyLength);
};
