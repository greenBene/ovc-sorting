#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <chrono>
#include <Heapsort.h>
#include <HeapsortOVC.h>
#include <InsertionSort.h>
#include <InsertionSortOVC.h>
#include <Mergesort.h>
#include <MergesortOVC.h>
#include <Quicksort.h>

#include <boost/program_options.hpp>

#include <QuicksortAOVC.h>
#include <QuicksortOVC.h>
#include <SortAlgorithm.h>


namespace po = boost::program_options;



struct Result {
    Record * records;
    int N;
    int k;
};

Result readKeyFile(const std::string &path) {
    if (std::ifstream file(path); file.is_open()) {
        std::vector<std::string> keys;
        std::string line;

        while (getline(file, line)) {
            keys.push_back(line);
        }

        const int k = keys[0].length();

        for (int i = 1; i < keys.size(); i++) {
            if (keys[i].length() != k) {
                std::cerr << "Invalid input. Not all keys are of same size ";
                return {nullptr, 0, 0};
            }
        }

        const int N = keys.size();

        return {generateRecords(keys, keys.size()), N, k};
    }
    std::cerr << "Could not read file successfully." << std::endl;
    return {nullptr, 0, 0};
}

void benchmark(SortAlgorithm &alg, Record * records, const int N, const int k) {
    const auto start = std::chrono::system_clock::now();
    auto [rowComparisons, columnComparisons] = alg.sort(records, N, k);
    const auto stop = std::chrono::system_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout <<
        alg.name() << ", " <<
        N << ", " <<
        k << ", " <<
        rowComparisons << ", " <<
        columnComparisons << ", " <<
        duration << std::endl;
}


int main(int argc, char *argv[]) {
    try {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help", "Produce help message")
            ("algorithm", po::value<std::string>()->required(),
                "Algorithm used to sort data. \n"
                "Available: heapsort, heapsortovc, insertionsort, "
                "insertionsortovc, mergesort, mergesortovc, "
                "quicksort, quicksortOVC, quicksortAOVC")
            ("input,I", po::value<std::string>()->required(), "File to sort")
        ;

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        notify(vm);

        if (vm.contains("help")) {
            std::cout << desc << std::endl;
            return 0;
        }

        auto [records, N, k] = readKeyFile(vm["input"].as<std::string>());
        if (records == nullptr) {
            std::cerr << "Invalid Input File";
            return -1;
        }

        if (vm.contains("algorithm")) {
            auto algorithm = vm["algorithm"].as<std::string>();

            if (algorithm == "heapsort") {
                Heapsort heapsort;
                benchmark(heapsort, records, N, k);
            } else if (algorithm == "heapsortovc") {
                HeapsortOVC heapsortOvc;
                benchmark(heapsortOvc, records, N, k);
            } else if (algorithm == "insertionsort") {
                InsertionSort insertionSort;
                benchmark(insertionSort, records, N, k);
            } else if (algorithm == "insertionsortovc") {
                InsertionSortOVC insertionSortOvc;
                benchmark(insertionSortOvc, records, N, k);
            } else if (algorithm == "mergesort") {
                Mergesort mergesort;
                benchmark(mergesort, records, N, k);
            } else if (algorithm == "mergesortovc") {
                MergesortOVC mergesortOvc;
                benchmark(mergesortOvc, records, N, k);
            } else if (algorithm == "quicksort") {
                Quicksort quicksort;
                benchmark(quicksort, records, N, k);
            } else if (algorithm == "quicksortovc") {
                QuicksortOVC quicksortOvc;
                benchmark(quicksortOvc, records, N, k);
            } else if (algorithm == "quicksortaovc") {
                QuicksortAOVC quicksortAovc;
                benchmark(quicksortAovc, records, N, k);
            } else {
                std::cout << "Algorithm not implemented: " << algorithm << std::endl;
            }
        }
    } catch (std::exception& e ) {
        std::cerr << "error:" << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Exception of unknown type" << std::endl;
    }
}

