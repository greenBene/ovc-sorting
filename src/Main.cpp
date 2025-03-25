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


    int N = 100000;
    int k = 3;
    Record * records = generateRecords(N, k, 1338);

    auto [rowComparisonsM, columnComparisonsM] = mergesort.sort(records, N, k);

    std::cout << "MergesortOVC: RowCmp: " << rowComparisonsM << ", ColCmp: " << columnComparisonsM << std::endl;

    records = generateRecords(N, k, 1338);

    QuicksortAOVC quicksort_aovc;
    auto [rowComparisonsQ, columnComparisonsQ] = quicksort_aovc.sort(records, N, k, 1);

    std::cout << "QuicksortOVC: RowCmp: " << rowComparisonsQ << ", ColCmp: " << columnComparisonsQ  << std::endl;
}

