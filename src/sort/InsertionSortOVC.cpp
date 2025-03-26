//
// Created by Benedikt Beckermann on 18.02.25.
//

#include "InsertionSortOVC.h"
#include "OVC.h"


Stats InsertionSortOVC::sort(Record* records, const int length, const int keyLength) {
  return sort(records, 0, length, keyLength, getNewStats());
}

Stats InsertionSortOVC::sort(Record *records, const int length, const int keyLength, int M) {
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

std::string InsertionSortOVC::name() {
  return "InsertionSortOVC";
}

bool InsertionSortOVC::lessThan(Record &left, Record &right, const int keyLength){
  stats.rowComparisons += 1;
  if(left.ovc > right.ovc) {
    return true;
  }
  if(left.ovc < right.ovc) {
    return false;
  }

  uint16_t i = getOffsetOVC(left.ovc) + 1;

  while (i < keyLength) {
    stats.columnComparisons++;
    if (left.key[i] != right.key[i])
      break;
    i++;
  }

  if (i >= keyLength) {
    left.ovc = generateOVC(keyLength, 0);
    return false;
  }

  if (left.key[i] < right.key[i]) {
    right.ovc = generateOVC(i, right.key[i]);
    return true;
  }
  else {
    left.ovc = generateOVC(i, left.key[i]);
    return false;
  }
}
