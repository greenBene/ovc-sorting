#include <Sort.h>
#include <InsertionSort.h>
#include <iostream>
#include <ostream>

int main(int argc, char *argv[]) {

  auto insertionSort = InsertionSort();
  const auto records = new Record[2];
  records[0].id = 1;
  records[0].key = "Hello";
  records[1].id = 2;
  records[1].key = "World";

  insertionSort.sort(records, 5);

  std::cout << records[0].id << " " << records[0].key << std::endl;
}

