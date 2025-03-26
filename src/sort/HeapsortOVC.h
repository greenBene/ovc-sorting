#pragma once
#include "Record.h"
#include "SortAlgorithm.h"
#include "Stats.h"

struct HeapsortOVCLessThanResult {
    bool less;
    uint32_t ovc;
};


class HeapsortOVC: public SortAlgorithm {
    Stats stats;

  public:
    Stats sort(Record* records, int length, int keyLength) override;
    Stats sort(Record* records, int length, int keyLength, int M) override;
    std::string name() override;

  private:
    HeapsortOVCLessThanResult lessThan(const Record &left, const Record &right, int keyLength);

};
