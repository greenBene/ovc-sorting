#include <HeapsortOVC.h>
#include <iostream>
#include <Mergesort.h>
#include <MergesortOVC.h>
#include <ostream>
#include <Quicksort.h>
#include <QuicksortAOVC.h>
#include <QuicksortOVC.h>


int main(int argc, char *argv[]) {

    MergesortOVC mergesort;


    int N = 5000000;
    int k = 3;
    int seed = 8;

    Record * records = generateRecords(N, k, seed);

    auto [rowComparisonsM, columnComparisonsM] = mergesort.sort(records, N, k);

    std::cout << "MergesortOVC: RowCmp: " << rowComparisonsM << ", ColCmp: " << columnComparisonsM << std::endl;

    records = generateRecords(N, k, seed);

    QuicksortAOVC quicksort_aovc;
    Stats stats = quicksort_aovc.sort(records, N, k, 1);
    std::cout << "QuicksortOVC: RowCmp: " << stats.rowComparisons << ", ColCmp: " << stats.columnComparisons  << std::endl;

    QuicksortAOVC::updateToPositiveAOVC(records, N, k, stats);

    std::cout << "QuicksortOVC (fixed AOVC): RowCmp: " << stats.rowComparisons << ", ColCmp: " << stats.columnComparisons  << std::endl;
}

