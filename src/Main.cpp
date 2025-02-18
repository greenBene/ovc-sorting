#include <iostream>
#include <ostream>
#include <bitset>
#include <InsertionSortOVC.h>

#include <OVC.h>

int main(int argc, char *argv[]) {

  InsertionSortOVC insertionSortOvc;

  Record records[] = {{"cad"}, {"aac"}, {"aab"}, {"aaa"}};
  Stats stats = insertionSortOvc.sort(records, 4, 3);

  for (int i = 0; i < 4; i++) {
    std::cout << records[i].key << " " << std::bitset<32>(records[i].ovc) << std::endl;
  }


  return 0;
}

