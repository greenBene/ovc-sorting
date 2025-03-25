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

    // std::string keys[] = {"594", "870", "809", "273", "510", "256", "383", "827"};
    // Record * records = generateRecords(keys, 8);

    int N = 7;
    int k = 3;
    Record * records = generateRecords(N, k, 1338);

    for (int i = 0; i < N; i++) {
        std::cout << records[i].key << " ";
    }
    std::cout << std::endl;


    mergesort.sort(records, N, k);

    for (int i = 0; i<N; i++) std::cout << records[i].key << " ";
    std::cout << std::endl;

    std::cout << "DONE";
}

