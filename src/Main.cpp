#include <iostream>
#include <ostream>
#include <QuicksortAOVC.h>


int main(int argc, char *argv[]) {

    std::cout << "Hello World!" << std::endl;

    QuicksortOVC quicksort;

    constexpr int N = 10000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337);

    auto [rowComparisons, columnComparisons] = quicksort.sort(records, N, k, 1);


}

