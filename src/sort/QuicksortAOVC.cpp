#include "QuicksortAOVC.h"

#include <iostream>
#include <stack>

#include "AOVC.h"
#include "InsertionSortAOVC.h"

struct Limits {
  int left, right;
};

Stats QuicksortAOVC::sort(Record *records, const int length, const int keyLength) {
  return this->sort(records, length, keyLength, 0);
}

Stats QuicksortAOVC::sort(Record* records, const int length, const int keyLength, int M) {
  stats = getNewStats();
  InsertionSortAOVC insertionSort;
  std::stack<Limits> stack;

  auto *lowest = new Record[length];    int lowestCounter = 0;
  auto *lower = new Record[length];     int lowerCounter = 0;
  auto *equal = new Record[length];     int equalCounter = 0;
  auto *greater = new Record[length];   int greaterCounter = 0;
  auto *greatest = new Record[length];  int greatestCounter = 0;

  stack.push(Limits(0, length));

  while (!stack.empty()) {
    auto [left, right] = stack.top();
    stack.pop();

    lowestCounter = 0;
    lowerCounter = 0;
    equalCounter = 0;
    greaterCounter = 0;
    greatestCounter = 0;

    const Record pivot = records[left];
    equal[equalCounter++] = records[left];

    for (int i = left + 1; i < right; i++) {
      stats.rowComparisons++;
      if (records[i].aovc < pivot.aovc) {
        stats.rowComparisonsDecidedByOVC++;
        lowest[lowestCounter++] = records[i];
      } else if (records[i].aovc > pivot.aovc ) {
        stats.rowComparisonsDecidedByOVC++;
        greatest[greatestCounter++] = records[i];
      } else {
        int offset = getOffsetAOVC(records[i].aovc, keyLength) + 1;
        while (offset < keyLength) {
          stats.columnComparisons++;
          if (records[i].key[offset] != pivot.key[offset])
            break;
          offset++;
        }
        if (offset >= keyLength) {
          equal[equalCounter++] = records[i];
        } else if (records[i].key[offset] < pivot.key[offset]) {
          records[i].aovc = generateNegativeAOVC(keyLength, offset, records[i].key[offset]);
          lower[lowerCounter++] = records[i];
        } else {
          records[i].aovc = generatePositiveAOVC(keyLength, offset, records[i].key[offset]);
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
    if (lowestCounter > M) {
      stack.push(Limits(l, l+lowestCounter));
    } else if (lowestCounter > 1){
      stats = insertionSort.sortNegative(records, l, l+lowestCounter, keyLength, stats);
    }
    l+=lowestCounter;
    if (lowerCounter > M) {
      stack.push(Limits(l, l+lowerCounter));
    } else if (lowerCounter > 1){
      stats = insertionSort.sortNegative(records, l, l+lowerCounter, keyLength, stats);
    }
    l+=lowerCounter+equalCounter;
    if (greaterCounter > M) {
      stack.push(Limits(l, l+greaterCounter));
    } else if (greaterCounter > 1){
      stats = insertionSort.sortPositive(records, l, l+greaterCounter, keyLength, stats);
    }
    l+=greaterCounter;
    if (greatestCounter > M) {
      stack.push(Limits(l, l+greatestCounter));
    } else if (greatestCounter > 1) {
      stats = insertionSort.sortPositive(records, l, l+greatestCounter, keyLength, stats);
    }
  }

  delete [] lowest;
  delete [] lower;
  delete [] equal;
  delete [] greater;
  delete [] greatest;

  if (fixAOVC) updateToPositiveAOVC(records, length, keyLength, stats);

  return stats;
}

std::string QuicksortAOVC::name() {
  return "QuicksortAOVC";
}

void QuicksortAOVC::setFixOVC(const bool fixAOVC) {
    this->fixAOVC = fixAOVC;
}

void QuicksortAOVC::move(Record* records, const Record * list, int &counter, const int length) {
  for (int i = 0; i < length; i++) {
    records[counter++] = list[i];
  }
}

void QuicksortAOVC::updateToPositiveAOVC(Record * records, const unsigned int length, const unsigned int keyLength, Stats & stats) {
  if (isNegative(records[0].aovc)) {
    records[0].aovc = AOVC_MINUS_INFINITY;
  }

  for (int i = 1; i < length; i++) {
    stats.rowComparisons++;
    int offset = 0 ;
    while (offset < keyLength) {
      stats.columnComparisons++;
      if (records[i].key[offset] != records[i-1].key[offset])
        break;
      offset++;
    }
    if (offset >= keyLength)
      records[i].aovc = AOVC_POSITIVE_ZERO;
    else
      records[i].aovc = generatePositiveAOVC(keyLength, offset, records[i].key[offset]);
  }
}
