//
// Created by Benedikt Beckermann on 18.02.25.
//

#include "InsertionSortOVC.h"
#include "OVC.h"


Stats InsertionSortOVC::sort(Record* records, int length, int keyLength) {
  stats = getNewStats();

  for (int j = length - 2; j >= 0; j--) {
    int i = j + 1;
    Record r = records[j];
    while (i < length && lessThan(records[i], r, keyLength)) {
      records[i-1] = records[i];
      i += 1;
    }
    records[i-1] = r;
  }

  return stats;
}

bool InsertionSortOVC::lessThan(Record &left, Record &right, const int keyLength){
  stats.rowComparisons += 1;
  if(left.ovc > right.ovc) {
    return true;
  }
  if(left.ovc < right.ovc) {
    return false;
  }

  uint16_t i = offset(left) + 1;

  while (i < keyLength && left.key[i] == right.key[i]) {
    stats.columnComparisons += 1;
    i = i + 1;
  }
  stats.columnComparisons += 1;

  if (left.key[i] < right.key[i]) {
    right.ovc = genOVC(i, right.key[i]);
    return true;
  }
  else {
    left.ovc = genOVC(i, left.key[i]);
    return false;
  }
}
