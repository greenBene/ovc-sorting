#include <InsertionSort.h>
#include <InsertionSortOVC.h>
#include <iostream>
#include <ostream>
#include <OVC.h>

#include <Quicksort.h>
#include <QuicksortOVC.h>

int main(int argc, char *argv[]) {

  InsertionSortOVC sort;


  // std::string keys[] = {"ccc", "bbb", "aaa", "ddd", "eee"};

  int length = 1000;
  Record * records = generateRecords(length);
  Stats stats = sort.sort(records, length, 3);

  std::cout << "Quicksort: " << std::endl;
  for (int i = 0; i < length; i++) {
    std::cout << records[i].key << ", offset: " << offset(records[i].ovc) << ", value: " << static_cast<char>(value(records[i].ovc))<< std::endl;
  }

  std::cout << std::endl;

  bool keysOrdered = true;
  for (int i = 1; i < length ; i++) {
    if (keysOrdered && records[i-1].key > records[i].key) {
      keysOrdered = false;
      std::cout << "Issue: " <<  records[i-1].key << ", " << records[i].key << std::endl;
    }
  }

  std::cout << std::endl << "Correct? " << (keysOrdered? "Yes": "No") << std::endl;
  std::cout << "Stats -  row: " << stats.rowComparisons << ", col: " << stats.columnComparisons << std::endl;


}

