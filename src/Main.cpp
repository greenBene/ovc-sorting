#include <InsertionSort.h>
#include <iostream>
#include <ostream>

#include <Quicksort.h>
#include <QuicksortOVC.h>

int main(int argc, char *argv[]) {

  QuicksortOVC quicksort;


  std::string keys[] = {"ccc", "bbb", "aaa", "ddd", "eee"};
  Record * records = generateRecords(keys, 5);
  quicksort.sort(records, 5, 3, 1);


  std::cout << "Quicksort: " << std::endl;

  for (int i = 0; i < 99; i++) {
    std::cout << records[i].key << ", ";
  }
  std::cout << std::endl;


}

