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
  Record lowest[right - left];
  int lowestCounter = 0;
  Record lower[right - left];
  int lowerCounter = 0;
  Record equal[right - left];
  int equalCounter = 0;
  Record greater[right - left];
  int greaterCounter = 0;
  Record greatest[right - left];
  int greatestCounter = 0;

  Record pivot = records[left];
  equal[equalCounter++] = records[left];

  for (int i = left + 1; i < right; i++) {
    stats.rowComparisons++;
    if (records[i].aovc < pivot.aovc) {
      lowest[lowestCounter++] = records[i];
    } else if (records[i].aovc > pivot.aovc ) {
      greatest[greatestCounter++] = records[i];
    } else {
      int offset = offsetAOVC(records[i].aovc, keyLength) + 1;
      if (offset >= keyLength) {
        equal[equalCounter++] = records[i];
      }

      stats.columnComparisons++;
      while (offset < keyLength && records[i].key[offset] == pivot.key[offset]) {
        stats.columnComparisons++;
        offset++;
      }
      if (offset == keyLength) {
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
  for (int i = 0; i < lowestCounter; i++) {
    records[counter++] = lowest[i];
  }
  for (int i = 0; i < lowerCounter; i++) {
    records[counter++] = lower[i];
  }
  for (int i = 0; i < equalCounter; i++) {
    records[counter++] = equal[i];
  }
  for (int i = 0; i < greaterCounter; i++) {
    records[counter++] = greater[i];
  }
  for (int i = 0; i < greatestCounter; i++) {
    records[counter++] = greatest[i];
  }

  int l = left;
  sort(records, l, l+lowestCounter, keyLength, M);
  l+=lowestCounter;
  sort(records, l, l+lowerCounter, keyLength, M);
  l+=lowerCounter+equalCounter;
  sort(records, l, l+greaterCounter, keyLength, M);
  l+=greaterCounter;
  sort(records, l, l+greatestCounter, keyLength, M);
}
