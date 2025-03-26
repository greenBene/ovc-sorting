#include <gtest/gtest.h>
#include <QuicksortAOVC.h>
#include <Record.h>

#include "Utils.h"

TEST(QuicksortAOVCTest, SanityCheck) {
    QuicksortAOVC quicksort;

    std::string keys[] = {"bbb", "abb", "aba", "aaa"};
    Record * records = generateRecords(keys, 4);

    auto [rowComparisons, columnComparisons, ovcDecision] = quicksort.sort(records, 4, 3, 1);

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aba", records[1].key);
    EXPECT_EQ("abb", records[2].key);
    EXPECT_EQ("bbb", records[3].key);

    EXPECT_EQ(6, rowComparisons);
    EXPECT_EQ(1, ovcDecision);
    EXPECT_EQ(6, columnComparisons);
}

TEST(QuicksortAOVCTest, Many) {
    QuicksortAOVC quicksort;

    constexpr int N = 1000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337);

    const int * before = getValueArray(records, N, k);
    auto [rowComparisons, columnComparisons, ovcDecision] = quicksort.sort(records, N, k, 1);
    const int * after = getValueArray(records, N, k);

    EXPECT_TRUE(isSorted(records, N));
    EXPECT_LE(columnComparisons, N * k);
    for (int i = 0; i < pow(10, k); i++) {
        EXPECT_EQ(before[i], after[i]);
    }

    EXPECT_EQ(7666, rowComparisons);
    EXPECT_EQ(4684, ovcDecision);
}

TEST(QuicksortAOVCTest, ManyWithInsertionSort) {
    QuicksortAOVC quicksort;

    constexpr int N = 1000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337);

    const int * before = getValueArray(records, N, k);
    auto [rowComparisons, columnComparisons, ovcDecision] = quicksort.sort(records, N, k, 9);
    const int * after = getValueArray(records, N, k);

    EXPECT_TRUE(isSorted(records, N));
    EXPECT_LE(columnComparisons, N * k);
    for (int i = 0; i < pow(10, k); i++) {
        EXPECT_EQ(before[i], after[i]);
    }
}

TEST(QuicksortAOVCTest, ManyWithFixedAOVC) {
    QuicksortAOVC quicksort;

    constexpr int N = 1000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337);

    const int * before = getValueArray(records, N, k);
    Stats stats = quicksort.sort(records, N, k, 1);
    const int * after = getValueArray(records, N, k);

    EXPECT_TRUE(isSorted(records, N));
    EXPECT_LE(stats.columnComparisons, N * k);
    for (int i = 0; i < pow(10, k); i++) {
        EXPECT_EQ(before[i], after[i]);
    }

    EXPECT_EQ(7666, stats.rowComparisons);
    EXPECT_EQ(3302, stats.columnComparisons);
    QuicksortAOVC::updateToPositiveAOVC(records, N, k, stats);

    EXPECT_TRUE(validPositiveAOVC(records, N, k));
    EXPECT_EQ(8665, stats.rowComparisons);
    EXPECT_EQ(6604, stats.columnComparisons);
    EXPECT_LE(stats.columnComparisons, 2 * N * k);
}