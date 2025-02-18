#pragma once

#include <string>

struct Record {
    std::string key;
};

class InsertionSort {
  public:
    static void sort(Record* records, int length);

  private:
    static bool lessThan(const Record &left, const Record &right);

};
