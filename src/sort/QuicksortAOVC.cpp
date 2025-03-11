#include "QuicksortAOVC.h"

#include <iostream>
#include <stack>

#include "AOVC.h"

struct Limits {
  int left, right;
};

Stats QuicksortAOVC::sort(Record* records, int length, int keyLength, int M) {
  stats = getNewStats();
  std::stack<Limits> stack;
  int left, right;

  auto *lowest = new Record[length];    int lowestCounter = 0;
  auto *lower = new Record[length];     int lowerCounter = 0;
  auto *equal = new Record[length];     int equalCounter = 0;
  auto *greater = new Record[length];   int greaterCounter = 0;
  auto *greatest = new Record[length];  int greatestCounter = 0;

  stack.push(Limits(0, length));

  while (!stack.empty()) {
    auto [t_left, t_right] = stack.top();
    stack.pop();
    left = t_left;
    right = t_right;

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
        lowest[lowestCounter++] = records[i];
      } else if (records[i].aovc > pivot.aovc ) {
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
    if (lowestCounter > M) stack.push(Limits(l, l+lowestCounter));
    l+=lowestCounter;
    if (lowerCounter > M) stack.push(Limits(l, l+lowerCounter));
    l+=lowerCounter+equalCounter;
    if (greaterCounter > M) stack.push(Limits(l, l+greaterCounter));
    l+=greaterCounter;
    if (greatestCounter > M) stack.push(Limits(l, l+greatestCounter));

  }

  delete [] lowest;
  delete [] lower;
  delete [] equal;
  delete [] greater;
  delete [] greatest;


  return stats;
}

void QuicksortAOVC::move(Record* records, const Record * list, int &counter, const int length) {
  for (int i = 0; i < length; i++) {
    records[counter++] = list[i];
  }
}
