#include <iostream>
#include <ostream>
#include <Quicksort.h>
#include <QuicksortAOVC.h>
#include <QuicksortOVC.h>
#include <chrono>


int main(int argc, char *argv[]) {

    std::cout << "Starting Quicksort Test" << std::endl;

    constexpr int N = 500000;
    constexpr int k = 5;

    Record *records;
    Stats stats;

    std::cout << "QUICKSORT" << std::endl;
    Quicksort quicksort;

    records = generateRecords(N, k, 1337);
    auto start = std::chrono::system_clock::now();
    stats = quicksort.sort(records, N, k, 0);
    auto stop = std::chrono::system_clock::now();
    std::cout << "Test 1, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;

    records = generateRecords(N, k, 1338);
    start = std::chrono::system_clock::now();
    stats = quicksort.sort(records, N, k, 0);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 2, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;

    records = generateRecords(N, k, 1339);
    start = std::chrono::system_clock::now();
    stats = quicksort.sort(records, N, k, 0);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 3, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;




    std::cout << "QUICKSORT, M = 9" << std::endl;

    records = generateRecords(N, k, 1337);
    start = std::chrono::system_clock::now();
    stats = quicksort.sort(records, N, k, 9);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 1, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;

    records = generateRecords(N, k, 1338);
    start = std::chrono::system_clock::now();
    stats = quicksort.sort(records, N, k, 9);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 2, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;

    records = generateRecords(N, k, 1339);
    start = std::chrono::system_clock::now();
    stats = quicksort.sort(records, N, k, 9);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 3, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;



    std::cout << "QUICKSORT OVC" << std::endl;
    QuicksortOVC quicksortOVC;

    records = generateRecords(N, k, 1337);
    start = std::chrono::system_clock::now();
    stats = quicksortOVC.sort(records, N, k, 1);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 1, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;

    records = generateRecords(N, k, 1338);
    start = std::chrono::system_clock::now();
    stats = quicksortOVC.sort(records, N, k, 1);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 2, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;

    records = generateRecords(N, k, 1339);
    start = std::chrono::system_clock::now();
    stats = quicksortOVC.sort(records, N, k, 1);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 3, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;



    std::cout << "QUICKSORT OVC, M = 9" << std::endl;

    records = generateRecords(N, k, 1337);
    start = std::chrono::system_clock::now();
    stats = quicksortOVC.sort(records, N, k, 9);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 1, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;

    records = generateRecords(N, k, 1338);
    start = std::chrono::system_clock::now();
    stats = quicksortOVC.sort(records, N, k, 9);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 2, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;

    records = generateRecords(N, k, 1339);
    start = std::chrono::system_clock::now();
    stats = quicksortOVC.sort(records, N, k, 9);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 3, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;



    std::cout << "QUICKSORT AOVC" << std::endl;
    QuicksortAOVC quicksortAOVC;

    records = generateRecords(N, k, 1337);
    start = std::chrono::system_clock::now();
    stats = quicksortAOVC.sort(records, N, k, 1);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 1, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;

    records = generateRecords(N, k, 1338);
    start = std::chrono::system_clock::now();
    stats = quicksortAOVC.sort(records, N, k, 1);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 2, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;

    records = generateRecords(N, k, 1339);
    start = std::chrono::system_clock::now();
    stats = quicksortAOVC.sort(records, N, k, 1);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 3, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;



    std::cout << "QUICKSORT AOVC, M=9" << std::endl;

    records = generateRecords(N, k, 1337);
    start = std::chrono::system_clock::now();
    stats = quicksortAOVC.sort(records, N, k, 9);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 1, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;

    records = generateRecords(N, k, 1338);
    start = std::chrono::system_clock::now();
    stats = quicksortAOVC.sort(records, N, k, 9);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 2, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;

    records = generateRecords(N, k, 1339);
    start = std::chrono::system_clock::now();
    stats = quicksortAOVC.sort(records, N, k, 9);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 3, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;





    std::cout << "QUICKSORT AOVC + UPDATED AOVC" << std::endl;

    records = generateRecords(N, k, 1337);
    start = std::chrono::system_clock::now();
    stats = quicksortAOVC.sort(records, N, k, 1);
    quicksortAOVC.updateToPositiveAOVC(records, N, k, stats);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 1, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;

    records = generateRecords(N, k, 1338);
    start = std::chrono::system_clock::now();
    stats = quicksortAOVC.sort(records, N, k, 1);
    quicksortAOVC.updateToPositiveAOVC(records, N, k, stats);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 2, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;

    records = generateRecords(N, k, 1339);
    start = std::chrono::system_clock::now();
    stats = quicksortAOVC.sort(records, N, k, 1);
    quicksortAOVC.updateToPositiveAOVC(records, N, k, stats);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 3, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;


    std::cout << "QUICKSORT AOVC, M = 9 + UPDATED AOVC" << std::endl;

    records = generateRecords(N, k, 1337);
    start = std::chrono::system_clock::now();
    stats = quicksortAOVC.sort(records, N, k, 9);
    quicksortAOVC.updateToPositiveAOVC(records, N, k, stats);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 1, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;

    records = generateRecords(N, k, 1338);
    start = std::chrono::system_clock::now();
    stats = quicksortAOVC.sort(records, N, k, 9);
    quicksortAOVC.updateToPositiveAOVC(records, N, k, stats);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 2, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;

    records = generateRecords(N, k, 1339);
    start = std::chrono::system_clock::now();
    stats = quicksortAOVC.sort(records, N, k, 9);
    quicksortAOVC.updateToPositiveAOVC(records, N, k, stats);
    stop = std::chrono::system_clock::now();
    std::cout << "Test 3, " << stats.rowComparisons << ", " << stats.columnComparisons << ", " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start) << std::endl;
}

