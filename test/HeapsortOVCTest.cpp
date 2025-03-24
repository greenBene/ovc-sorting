#include <gtest/gtest.h>
#include <HeapsortOVC.h>

#include "Utils.h"

TEST(HeapsortOVCTest, SanityCheck) {
    HeapsortOVC heapsort;

    std::string keys[] = {"bbb", "aab", "aba", "abb", "aaa"};
    Record * records = generateRecords(keys, 5, OVC_PLUS_INFINITY);

    heapsort.sort(records, 5, 3);

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("aba", records[2].key);
    EXPECT_EQ("abb", records[3].key);
    EXPECT_EQ("bbb", records[4].key);
}

TEST(HeapsortOVCTest, Many) {
    HeapsortOVC heapsort;
    constexpr int N = 5000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337);

    const int * before = getValueArray(records, N, k);

    auto [rowComparisons, columnComparisons] = heapsort.sort(records, N, k);

    const int * after = getValueArray(records, N, k);

    EXPECT_LE(columnComparisons, N * k);

    EXPECT_TRUE(isSorted(records, N));
    EXPECT_TRUE(validOVC(records, N, k));

    for (int i = 0; i < pow(10, k); i++) {
        EXPECT_EQ(before[i], after[i]);
    }
    delete[] before;
    delete[] after;
    delete[] records;
}