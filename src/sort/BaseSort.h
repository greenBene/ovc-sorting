#pragma once
#include "SortAlgorithm.h"


class BaseSort final : public SortAlgorithm {
  Stats stats;
  public:
    Stats sort(Record *records, int length, int keyLength, int M) override;
    Stats sort(Record *records, int length, int keyLength) override;
    std::string name() override;
};
