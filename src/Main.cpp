#include <iostream>
#include <ostream>
#include <fstream>
#include <string>

#include <boost/program_options.hpp>

#include <QuicksortAOVC.h>
#include <QuicksortOVC.h>


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


int main(int argc, char *argv[]) {
    try {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help", "Produce help message")
            ("algorithm", po::value<std::vector<std::string>>()->multitoken()->required(),
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

        std::cout << "Input -- N: " << N << ", k: " << k << std::endl;

        for (int i = 0; i < N; i++) {
            std::cout << records[i].key << " ";
        }
        std::cout << std::endl;

        if (vm.contains("algorithm")) {
            auto algorithms = vm["algorithm"].as<std::vector<std::string>>();

            for (auto algorithm : algorithms) {
                if (algorithm == "quicksort") {

                    std::cout << "QUICKSORT" << std::endl;
                } else if (algorithm == "quicksortovc") {
                    QuicksortOVC quicksortOvc;
                    quicksortOvc.sort(records, N, k, 1);
                } else {
                    std::cout << "Algorithm not implemented: " << algorithm << std::endl;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            std::cout << records[i].key << " ";
        }
        std::cout << std::endl;

        std::cout << "Hello World" << std::endl;
    } catch (std::exception& e ) {
        std::cerr << "error:" << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Exception of unknown type" << std::endl;
    }
}

