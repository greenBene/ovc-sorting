#include <iostream>
#include <ostream>
#include <Quicksort.h>
#include <QuicksortAOVC.h>
#include <QuicksortOVC.h>


int main(int argc, char *argv[]) {

    std::cout << "Starting Quicksort Test" << std::endl;
    QuicksortAOVC quicksort_aovc;

    constexpr int N = 500000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337);

    auto [rowComparisonsQAOVC, columnComparisonsQAOVC] = quicksort_aovc.sort(records, N, k, 1);

    std::cout << "Q_AOVC\trow: " << rowComparisonsQAOVC << ", col: " << columnComparisonsQAOVC  << std::endl;


    QuicksortOVC quicksort_ovc;
    records = generateRecords(N, k, 1337);
    auto [rowComparisonsOVC, columnComparisonsOVC] = quicksort_ovc.sort(records, N, k, 1);
    std::cout << "Q_OVC\trow: " << rowComparisonsOVC << ", col: " << columnComparisonsOVC  << std::endl;

    Quicksort quicksort;
    records = generateRecords(N, k, 1337);
    auto [rowComparisons, columnComparisons] = quicksort.sort(records, N, k, 1);
    std::cout << "Q    \trow: " << rowComparisons << ", col: " << columnComparisons  << std::endl;


}

