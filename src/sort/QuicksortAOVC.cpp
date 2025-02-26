#include "QuicksortAOVC.h"

#include <iostream>

#include "AOVC.h"


Stats QuicksortAOVC::sort(Record* records, int length, int keyLength, int M) {
  stats = getNewStats();
  sort(records, 0, length, keyLength, M);
  return stats;
}

void QuicksortAOVC::sort(Record* records, int left, int right, int keyLength, int M) {

  if (right - left <= 1)
    return ;

  if (right - left < M) {
    std::cerr << "Implement Switch to Insertion Sort" << std::endl;
    return;
  }

  auto *lowest = new Record[right - left];    int lowestCounter = 0;
  auto *lower = new Record[right - left];     int lowerCounter = 0;
  auto *equal = new Record[right - left];     int equalCounter = 0;
  auto *greater = new Record[right - left];   int greaterCounter = 0;
  auto *greatest = new Record[right - left];  int greatestCounter = 0;

  const Record pivot = records[left];
  equal[equalCounter++] = records[left];

  for (int i = left + 1; i < right; i++) {
    stats.rowComparisons++;
    if (records[i].aovc < pivot.aovc) {
      lowest[lowestCounter++] = records[i];
    } else if (records[i].aovc > pivot.aovc ) {
      greatest[greatestCounter++] = records[i];
    } else {
      int offset = offsetAOVC(records[i].aovc, keyLength) + 1;
      while (offset < keyLength) {
        stats.columnComparisons++;
        if (records[i].key[offset] != pivot.key[offset])
          break;
        offset++;
      }
      if (offset >= keyLength) {
        equal[equalCounter++] = records[i];
      } else if (records[i].key[offset] < pivot.key[offset]) {
        records[i].aovc = genAOVC(keyLength, true, offset, records[i].key[offset]);
        lower[lowerCounter++] = records[i];
      } else {
        records[i].aovc = genAOVC(keyLength, false, offset, records[i].key[offset]);
        greater[greaterCounter++] = records[i];
      }

    }
  }

  int counter = left;

  move(records, lowest, counter, lowestCounter);
  move(records, lower, counter, lowerCounter);
  move(records, equal, counter, equalCounter);
  move(records, greater, counter, greaterCounter);
  move(records, greatest, counter, greatestCounter);

  int l = left;
  sort(records, l, l+lowestCounter, keyLength, M);
  l+=lowestCounter;
  sort(records, l, l+lowerCounter, keyLength, M);
  l+=lowerCounter+equalCounter;
  sort(records, l, l+greaterCounter, keyLength, M);
  l+=greaterCounter;
  sort(records, l, l+greatestCounter, keyLength, M);
}

void QuicksortAOVC::move(Record* records, const Record * list, int &counter, const int length) {
  for (int i = 0; i < length; i++) {
    records[counter++] = list[i];
  }
  delete[] list;
}
