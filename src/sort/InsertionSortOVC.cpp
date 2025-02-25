//
// Created by Benedikt Beckermann on 18.02.25.
//

#include "InsertionSortOVC.h"
#include "OVC.h"


Stats InsertionSortOVC::sort(Record* records, const int length, const int keyLength) {
  return sort(records, 0, length, keyLength, getNewStats());
}


Stats InsertionSortOVC::sort(Record* records, const int left, const int right, const int keyLength, Stats s) {
  stats.columnComparisons = s.columnComparisons;
  stats.rowComparisons = s.rowComparisons;

  for (int j = right - 2; j >= left; j--) {
    int i = j + 1;
    Record r = records[j];
    while (i < right && lessThan(records[i], r, keyLength)) {
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

  uint16_t i = offset(left.ovc) + 1;


  if (i >= keyLength) {
    left.ovc = genOVC(keyLength, 0);
    return false;
  }

  stats.columnComparisons += 1;
  while (i < keyLength && left.key[i] == right.key[i]) {
    stats.columnComparisons += 1;
    i = i + 1;
  }

  if (left.key[i] < right.key[i]) {
    right.ovc = genOVC(i, right.key[i]);
    return true;
  }
  else {
    left.ovc = genOVC(i, left.key[i]);
    return false;
  }
}
