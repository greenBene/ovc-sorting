#include <gtest/gtest.h>
#include <InsertionSortOVC.h>

#include "Utils.h"


TEST(InsertionSortOVCTest, SanityCheck) {
    InsertionSortOVC insertionSortOvc;

    Record records[] = {{"bbb"}, {"aab"}, {"abb"}, {"aaa"}};
    insertionSortOvc.sort(records, 4, 3);

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("abb", records[2].key);
    EXPECT_EQ("bbb", records[3].key);

    EXPECT_TRUE(validOVC(records, 4, 3));
}

TEST(InsertionSortOVCTest, WorstCase) {
    InsertionSortOVC insertionSortOvc;

    Record records[] = {{"aad"}, {"aac"}, {"aab"}, {"aaa"}};
    Stats stats = insertionSortOvc.sort(records, 4, 3);

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("aac", records[2].key);
    EXPECT_EQ("aad", records[3].key);

    EXPECT_EQ(6, stats.rowComparisons);
    EXPECT_EQ(9, stats.columnComparisons);
    EXPECT_TRUE(validOVC(records, 4, 3));
}

TEST(InsertionSortOVCTest, BestCase) {
    InsertionSortOVC insertionSortOvc;

    Record records[] = {{"aaa"}, {"bbb"}, {"ccc"}, {"ddd"}};
    Stats stats = insertionSortOvc.sort(records, 4, 3);

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("bbb", records[1].key);
    EXPECT_EQ("ccc", records[2].key);
    EXPECT_EQ("ddd", records[3].key);

    EXPECT_EQ(3, stats.rowComparisons);
    EXPECT_EQ(3, stats.columnComparisons);
    EXPECT_TRUE(validOVC(records, 4, 3));
}

TEST(InsertionSortOVCTest, Many) {
    InsertionSortOVC quicksort;
    constexpr int N = 1000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337);

    quicksort.sort(records, N, k);

    EXPECT_TRUE(isSorted(records, N));
    EXPECT_TRUE(validOVC(records, N, k));
}