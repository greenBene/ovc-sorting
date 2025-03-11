#include <AOVC.h>
#include <gtest/gtest.h>
#include <InsertionSortAOVC.h>

#include "Utils.h"


TEST(InsertionSortAOVCTest, PostiveSortingSanityCheck) {
    InsertionSortAOVC insertionSortAovc;

    Record records[] = {{"bbb"}, {"abb"}, {"aab"}, {"abb"}, {"aaa"}};
    insertionSortAovc.sortPositive(records, 0, 5, 3, getNewStats());

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("abb", records[2].key);
    EXPECT_EQ("abb", records[3].key);
    EXPECT_EQ("bbb", records[4].key);
}

TEST(InsertionSortAOVCTest, PostiveSortingWorstCase) {
    InsertionSortAOVC insertionSortAovc;

    Record records[] = {{"aad"}, {"aac"}, {"aab"}, {"aaa"}};
    Stats stats = insertionSortAovc.sortPositive(records, 0, 4, 3, getNewStats());

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("aac", records[2].key);
    EXPECT_EQ("aad", records[3].key);

    EXPECT_EQ(6, stats.rowComparisons);
    EXPECT_EQ(9, stats.columnComparisons);
}

TEST(InsertionSortAVOCTest, PositiveSortingMany) {
    InsertionSortAOVC quicksort;
    constexpr int N = 1000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337);

    quicksort.sortPositive(records, 0, N, k, getNewStats());

    EXPECT_TRUE(isSorted(records, N));
    EXPECT_TRUE(validPositiveAOVC(records, N, k));
}


TEST(InsertionSortAOVCTest, NegativeSortingSanityCheck) {
    InsertionSortAOVC insertionSortAovc;

    Record records[] = {
        {"bbb", 0,  POSITIVE_INFINITY},
        {"abb", 0, POSITIVE_INFINITY},
        {"aab", 0 , POSITIVE_INFINITY},
        {"abb", 0 , POSITIVE_INFINITY},
        {"aaa", 0 , POSITIVE_INFINITY}};
    insertionSortAovc.sortNegative(records, 0, 5, 3, getNewStats());

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("abb", records[2].key);
    EXPECT_EQ("abb", records[3].key);
    EXPECT_EQ("bbb", records[4].key);
}

TEST(InsertionSortAOVCTest, NegativeSortingWorstCase) {
    InsertionSortAOVC insertionSortAovc;

    Record records[] = {
        {"aad", 0, POSITIVE_INFINITY},
        {"aac", 0, POSITIVE_INFINITY},
        {"aab", 0, POSITIVE_INFINITY},
        {"aaa", 0, POSITIVE_INFINITY}};
    Stats stats = insertionSortAovc.sortPositive(records, 0, 4, 3, getNewStats());

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("aac", records[2].key);
    EXPECT_EQ("aad", records[3].key);

    EXPECT_EQ(6, stats.rowComparisons);
    EXPECT_EQ(9, stats.columnComparisons);
    // EXPECT_TRUE(validOVC(records, 4, 3));
}

TEST(InsertionSortAOVCRest, NegativeSortingMany) {
    InsertionSortAOVC quicksort;
    constexpr int N = 1000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337, 0, POSITIVE_INFINITY);

    quicksort.sortNegative(records, 0, N, k, getNewStats());

    EXPECT_TRUE(isSorted(records, N));
    EXPECT_TRUE(validNegativeAOVC(records, N, k));
}