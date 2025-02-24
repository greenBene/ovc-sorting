#include <iostream>
#include <ostream>
#include <bitset>
#include <InsertionSortOVC.h>

#include <OVC.h>
#include <Quicksort.h>

int main(int argc, char *argv[]) {

  Quicksort quicksort;

  Record records[] = genR
  Stats stats = insertionSortOvc.sort(records, 4, 3);

  for (int i = 0; i < 4; i++) {
    std::cout << records[i].key << " " << std::bitset<32>(records[i].ovc) << std::endl;
  }


  return 0;
}

