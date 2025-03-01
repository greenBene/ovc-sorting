#include "QuicksortOVC.h"
#include "InsertionSort.h"

#include <stack>

#include "InsertionSortOVC.h"
#include "OVC.h"


struct Limits {
    int left, right;
};

Stats QuicksortOVC::sort(Record* records, const int length, const int keyLength, const int M) {
    stats = getNewStats();
    InsertionSortOVC insertionSort;

    if (length < M) {
        return insertionSort.sort(records, 0, length, keyLength, stats);
    }

    std::stack<Limits> stack;
    int left = 0;
    int right = length;
    Record temp[length];

    while (true) {
        Record &pivot = records[left];
        int l = 0, r = right - left - 1;
        uint32_t pivotOvcCandidate = 0;
        for (int i = left + 1; i < right; i++) {
            if (auto [less, ovc] = lessThan(records[i], pivot, keyLength); less) {
                records[i].reverseOvc = ovc;
                temp[l++] = records[i];
                if (ovc > pivotOvcCandidate) {
                    pivotOvcCandidate = ovc;
                }
            } else {
                records[i].ovc = ovc;
                temp[r--] = records[i];
            }
        }
        if (pivotOvcCandidate != 0) {
            pivot.ovc = pivotOvcCandidate;
        }
        temp[l] = pivot;

        for (int j = 0; j < right - left; j++) {
            records[left + j] = temp[j];
        }


        const int length_left = l;
        const int length_right = right - left - l - 1;

        if (length_right >= length_left && length_left > M) {
            stack.push(Limits(left + l + 1, right));
            right = left + l;
        } else if (length_left > length_right && length_right > M) {
            stack.push(Limits(left, left + l));
            left = left + l + 1;
        } else if (length_right > M) {
            stats = insertionSort.sort(records, left, left + l, keyLength, stats);
            left = left + l + 1;
        } else if (length_left > M) {
            stats = insertionSort.sort(records, left + l + 1, right, keyLength, stats);
            right = left + l;
        } else {
            stats = insertionSort.sort(records, left, left + l, keyLength, stats);
            stats = insertionSort.sort(records, left + l + 1, right, keyLength, stats);
            if (!stack.empty()) {
                auto [t_left, t_right] = stack.top();
                stack.pop();
                left = t_left;
                right = t_right;
            } else {
                break;
            }
        }
    }

    return stats;
}

QuicksortOVCLessThanResult QuicksortOVC::lessThan(const Record &left, const Record &right, int keyLength) {
    stats.rowComparisons += 1;
    if (left.ovc > right.ovc) {
        return {true, right.ovc};
    }
    if (right.ovc > left.ovc) {
        return {false, left.ovc};
    }
    if (left.reverseOvc > right.reverseOvc) {
        return {false, right.reverseOvc};
    }
    if (right.reverseOvc > left.reverseOvc) {
        return {true, left.reverseOvc};
    }


    int i = offset(left.ovc) + 1;
    if (offset(left.reverseOvc) > i) {
        i = offset(left.reverseOvc);
    }

    while (i < keyLength) {
        stats.columnComparisons += 1;
        if (left.key[i] != right.key[i])
            break;
        i++;
    }

    if (i >= keyLength) {
        return {true, genOVC(keyLength, 0)};
    }
    if (left.key[i] < right.key[i]) {
        return {true, genOVC(i, right.key[i])};
    } else {
        return {false, genOVC(i, left.key[i])};
    }
}