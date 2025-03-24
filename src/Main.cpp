#include <HeapsortOVC.h>
#include <iostream>
#include <ostream>
#include <Quicksort.h>
#include <QuicksortAOVC.h>
#include <QuicksortOVC.h>


int main(int argc, char *argv[]) {

    HeapsortOVC heapsortOvc;
    constexpr int N = 500000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337);

    auto [rowComparisonsH, columnComparisonsH] = heapsortOvc.sort(records, N, k);

    std::cout << "HEAPSORT OVC: rowCmp: " << rowComparisonsH << ", colCmp: " << columnComparisonsH << std::endl;

    QuicksortAOVC quicksort;

    records = generateRecords(N, k, 1337);

    auto [rowComparisonsQ, columnComparisonsQ] = quicksort.sort(records, N, k, 1);

    std::cout << "QUICKSORT AOVC: rowCmp: " << rowComparisonsQ << ", colCmp: " << columnComparisonsQ << std::endl;


}

