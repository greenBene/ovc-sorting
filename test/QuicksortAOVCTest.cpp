#include <gtest/gtest.h>
#include <QuicksortAOVC.h>
#include <Record.h>

#include "Utils.h"

TEST(QuicksortAOVCTest, SanityCheck) {
    QuicksortAOVC quicksort;

    std::string keys[] = {"bbb", "aab", "abb", "aaa"};
    Record * records = generateRecords(keys, 4);

    auto [rowComparisons, columnComparisons] = quicksort.sort(records, 4, 3, 1);

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("abb", records[2].key);
    EXPECT_EQ("bbb", records[3].key);
}

TEST(QuicksortAOVCTest, Many) {
    QuicksortAOVC quicksort;

    constexpr int N = 1000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337);

    auto [rowComparisons, columnComparisons] = quicksort.sort(records, N, k, 1);

    // EXPECT_EQ(616503, rowComparisons);
    // EXPECT_EQ(238960, columnComparisons);
    //
    // EXPECT_TRUE(isSorted(records, N));
    // EXPECT_LE(columnComparisons, N * k);
}

TEST(QuicksortAOVCTest, ManyWithInsertionSort) {
    QuicksortAOVC quicksort;

    constexpr int N = 1000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337);

    auto [rowComparisons, columnComparisons] = quicksort.sort(records, N, k, 9);


    // EXPECT_EQ(627256, rowComparisons);
    // EXPECT_EQ(238960, columnComparisons);
    //
    // EXPECT_TRUE(isSorted(records, N));
    // EXPECT_LE(columnComparisons, N * k);
}