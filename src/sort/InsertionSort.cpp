#include "InsertionSort.h"
#include "Stats.h"




Stats InsertionSort::sort(Record records[], const int length, const int keyLength) {
  Stats stats = getNewStats();
  return sort(records, length, keyLength, stats);
}

Stats InsertionSort::sort(Record *records, int length, int keyLength, int M) {
  return this->sort(records, length, keyLength);
}

Stats InsertionSort::sort(Record records[], const int length, const int keyLength, const Stats &s) {

  stats = s;

  for (int j = 1; j < length; j++) {
    int i = j - 1;
    Record r = records[j];
    while (i >= 0 && lessThan(r, records[i], keyLength)) {
      records[i + 1] = records[i];
      i = i - 1;
    }
    records[i + 1] = r;
  }

  return stats;
}

std::string InsertionSort::name() {
  return "InsertionSort";
}

bool InsertionSort::lessThan(const Record &left, const Record &right, const int keyLength) {
  stats.rowComparisons += 1;

  for (int i = 0; i < keyLength; i++) {
    stats.columnComparisons += 1;
    if (left.key[i] != right.key[i]) {
      return left.key[i] < right.key[i];
    }
  }

  return left.key < right.key;
};
