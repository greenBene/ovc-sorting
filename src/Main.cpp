#include <InsertionSort.h>
#include <InsertionSortOVC.h>
#include <iostream>
#include <ostream>
#include <OVC.h>

#include <Quicksort.h>
#include <QuicksortOVC.h>

int main(int argc, char *argv[]) {

  QuicksortOVC sort;


  // std::string keys[] = {"ccc", "bbb", "aaa", "ddd", "eee"};

  int N = 10000;
  int k = 5;
  Record * records = generateRecords(N, k);
  Stats stats = sort.sort(records, N, k, 10);

  std::cout << "Quicksort: " << std::endl;
  for (int i = 0; i < N; i++) {
    std::cout << records[i].key << ", offset: " << offset(records[i].ovc) << ", value: " << static_cast<char>(value(records[i].ovc))<< std::endl;
  }

  std::cout << std::endl;

  bool keysOrdered = true;
  for (int i = 1; i < N ; i++) {
    if (records[i-1].key > records[i].key) {
      std::cout << "Issue: " << i << " - " <<  records[i-1].key << ", " << records[i].key << std::endl;
      if (keysOrdered) {
        keysOrdered = false;
      }
    }
  }

  std::cout << std::endl << "Correct? " << (keysOrdered? "Yes": "No") << std::endl;
  std::cout << "Stats -  row: " << stats.rowComparisons << ", col: " << stats.columnComparisons << std::endl;


}

