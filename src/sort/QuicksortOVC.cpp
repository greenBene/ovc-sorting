#include "QuicksortOVC.h"
#include "InsertionSort.h"

#include <stack>

#include "OVC.h"


struct Limits {
    int left, right;
};

Stats QuicksortOVC::sort(Record* records, int length, int keyLength, int M) {
    stats = getNewStats();

    if (length < M) {
        InsertionSort insertionSort;
        return insertionSort.sort(records, length, keyLength, stats);
    }

    std::stack<Limits> stack;
    int left = 0;
    int right = length - 1;
    while (true) {
        Record &r = records[left];
        int i = left;
        int j = right + 1;
        uint32_t pivotOvcCandidate = 0;

        while (i < j) {
            bool less = true;

            while (i < length - 1 && less) {
                i += 1;
                auto [t_less, ovc] = lessThan(records[i], r, keyLength);
                less = t_less;
                if (less) {
                    records[i].reverseOvc = ovc;
                    if (ovc > pivotOvcCandidate) {
                        pivotOvcCandidate = ovc;
                    }
                }
                // else {
                //     records[i].ovc = ovc;// move to swap?
                // }
            }
            less = true;
            while (j > 0 && less) {
                j -= 1;
                auto [t_less, ovc] = lessThan(r, records[j], keyLength);
                less = t_less;
                if (less) {
                    records[j].ovc = ovc;
                } else {
                    records[j].reverseOvc = ovc;
                    if (ovc > pivotOvcCandidate) {
                        pivotOvcCandidate = ovc;
                    }
                }
            }
            if (i < j) {
                swap(records, length, i, j);
            }
        }
        if (pivotOvcCandidate != 0) {
            r.ovc = pivotOvcCandidate;
        }

        swap(records, length, left, j);

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

    return stats;
}


QuicksortOVCLessThanResult QuicksortOVC::lessThan(const Record &left, const Record &right, int keyLength) {
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
    while (i < keyLength && left.key[i] == right.key[i]) {
        i += 1;
    }
    if (i >= keyLength) {
        return {true, genOVC(i, 0)};
    }
    if (left.key[i] < right.key[i]) {
        return {true, genOVC(i, right.key[i])};
    } else {
        return {false, genOVC(i, left.key[i])};
    }
}


bool QuicksortOVC::swap(Record* records, const int length, const int a, const int b) {
    if (a < 0 || a >= length || b < 0 || b >= length ) {
        return false;
    }
    const Record r = records[b];
    records[b] = records[a];
    records[a] = r;
    return true;
}
