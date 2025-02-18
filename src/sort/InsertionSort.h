#pragma once

#include <string>

struct Record {
    int id;
    std::string key;
};

class InsertionSort {
  public:
    static void sort(Record* records, int length);

};
