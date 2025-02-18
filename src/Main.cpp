#include <Stats.h>
#include <InsertionSort.h>
#include <iostream>
#include <ostream>

int main(int argc, char *argv[]) {

  Record records[4] = {{"abb"}, {"aba"}, {"baa"}, {"aaa"}};

  auto insertionSort = InsertionSort();
  Stats stats = insertionSort.sort(records, 4, 3);

  for (int i = 0; i < 4; i++) {
    std::cout << records[i].key << std::endl;
  }

  std::cout << "Stats: " << std::endl
            << stats.rowComparisons <<  " row comparisons" << std::endl
            << stats.columnComparisons <<  " column comparisons" << std::endl;

  return 0;
}

