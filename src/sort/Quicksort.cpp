#include "Quicksort.h"
#include "InsertionSort.h"

#include <ostream>
#include <stack>

struct Limits {
    int left, right;
};

Stats Quicksort::sort(Record *records, int length, int keyLength) {
    return this->sort(records, length, keyLength, 0);
}

Stats Quicksort::sort(Record *records, const int length, const int keyLength, const int M) {
    stats = getNewStats();

    if (length > M) {
        std::stack<Limits> stack;
        int left = 0;
        int right = length - 1;
        while (true) {
            Record r = records[left];
            int i = left;
            int j = right + 1;

            while(i < j) {
                do {
                    i += 1;
                } while (i < length && lessThan(records[i], r, keyLength));

                do {
                    j -= 1;
                } while (j > 0 && lessThan(r, records[j], keyLength));

                if (i < j) {
                    swap(records, i, j);
                }
            }
            swap(records, left, j);

            int length_left = j - left;
            int length_right = right - j;

            if (length_right >= length_left && length_left > M) {
                stack.push(Limits(j + 1, right));
                right = j - 1;
            } else if (length_left > length_right && length_right > M) {
                stack.push(Limits(left, j - 1));
                left = j + 1;
            } else if (length_right > M) {
                left = j + 1;
            } else if (length_left > M) {
                right = j - 1;
            } else if (!stack.empty()) {
                auto [t_left, t_right] = stack.top();
                stack.pop();
                left = t_left;
                right = t_right;
            } else {
                break;
            }
        }
    }

    if (M > 1) {
        InsertionSort insertion_sort;
        stats = insertion_sort.sort(records, length, keyLength, stats);
    }

    return stats;
}

std::string Quicksort::name() {
    return "Quicksort";
}

bool Quicksort::swap(Record* records, const int a, const int b) {
    const Record r = records[b];
    records[b] = records[a];
    records[a] = r;
    return true;
}


bool Quicksort::lessThan(const Record &left, const Record &right, int keyLength) {
    stats.rowComparisons += 1;
    for (int i = 0; i < keyLength; i++) {
        stats.columnComparisons += 1;
        if (left.key[i] != right.key[i]) {
            return left.key[i] < right.key[i];
        }
    }
    return false;
}

