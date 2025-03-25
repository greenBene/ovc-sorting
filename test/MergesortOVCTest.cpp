#include <gtest/gtest.h>
#include <MergesortOVC.h>

#include "Utils.h"

TEST(MergesortOVCTest, SanityCheck) {
    MergesortOVC mergesort;

    constexpr int N = 8;
    constexpr int k = 3;

    std::string keys[] = {"594", "870", "809", "273", "510", "256", "383", "827"};
    Record * records = generateRecords(keys, N);

    Stats stats = mergesort.sort(records, N, k);

    EXPECT_EQ("256", records[0].key);
    EXPECT_EQ("273", records[1].key);
    EXPECT_EQ("383", records[2].key);
    EXPECT_EQ("510", records[3].key);
    EXPECT_EQ("594", records[4].key);
    EXPECT_EQ("809", records[5].key);
    EXPECT_EQ("827", records[6].key);
    EXPECT_EQ("870", records[7].key);

    EXPECT_EQ(17, stats.rowComparisons);
    EXPECT_EQ(11, stats.columnComparisons);
}

TEST(MergesortOVCTest, ManyEven) {
    MergesortOVC mergesort;

    constexpr int N = 1000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337);

    const int * before = getValueArray(records, N, k);
    auto [rowComparisons, columnComparisons] = mergesort.sort(records, N, k);
    const int * after = getValueArray(records, N, k);

    EXPECT_TRUE(isSorted(records, N));
    EXPECT_LE(columnComparisons, N * k);
    for (int i = 0; i < pow(10, k); i++) {
        EXPECT_EQ(before[i], after[i]);
    }
    EXPECT_TRUE(validOVC(records, N, k));
}

TEST(MergesortOVCTest, ManyUneven) {
    MergesortOVC mergesort;

    constexpr int N = 1001;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1338);

    const int * before = getValueArray(records, N, k);
    auto [rowComparisons, columnComparisons] = mergesort.sort(records, N, k);
    const int * after = getValueArray(records, N, k);

    EXPECT_TRUE(isSorted(records, N));
    EXPECT_LE(columnComparisons, N * k);
    for (int i = 0; i < pow(10, k); i++) {
        EXPECT_EQ(before[i], after[i]);
    }
    EXPECT_TRUE(validOVC(records, N, k));
}