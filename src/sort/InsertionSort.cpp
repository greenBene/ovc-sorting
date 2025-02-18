#include <iostream>

#include "InsertionSort.h"


void InsertionSort::sort(Record records[], const int length) {
  for (int j = 1; j < length; j++) {
    int i = j - 1;
    Record r = records[j];
    while (i >= 0 && lessThan(r, records[i])) {
      records[i + 1] = records[i];
      i = i - 1;
    }
    records[i + 1] = r;
  }
}

bool InsertionSort::lessThan(const Record &left, const Record &right) {
  return left.key < right.key;
};
