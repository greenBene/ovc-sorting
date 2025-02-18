#include <Sort.h>
#include <InsertionSort.h>
#include <iostream>
#include <ostream>

int main(int argc, char *argv[]) {

  Record records[4] = {{"bbb"}, {"aba"}, {"baa"}, {"aaa"}};

  auto insertionSort = InsertionSort();
  insertionSort.sort(records, 4);

  for (int i = 0; i < 4; i++) {
    std::cout << records[i].key << std::endl;
  }

  return 0;
}

