#include <InsertionSort.h>
#include <iostream>
#include <ostream>

#include <Quicksort.h>

int main(int argc, char *argv[]) {

  Quicksort quicksort;


  Record * records = generateRecords();
  Stats stats = quicksort.sort(records, 99, 3, 1);


  std::cout << "Quicksort: " << std::endl;
  std::cout << "row: " << stats.rowComparisons << ", col: " << stats.columnComparisons<< std::endl;

  for (int i = 0; i < 99; i++) {
    std::cout << records[i].key << ", ";
  }
  std::cout << std::endl;



  std::cout << "Insertion sort: " << std::endl;
  InsertionSort insertionsort;

  records = generateRecords();
  stats = insertionsort.sort(records, 99, 3);
  std::cout << "row: " << stats.rowComparisons << ", col: " << stats.columnComparisons<< std::endl;

  for (int i = 0; i < 99; i++) {
    std::cout << records[i].key << ", ";
  }
  std::cout << std::endl;

  return 0;
}

