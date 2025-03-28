#include <AOVC.h>
#include <gtest/gtest.h>
#include <InsertionSortAOVC.h>

#include "Utils.h"


TEST(InsertionSortAOVCTest, PostiveSortingSanityCheck) {
    InsertionSortAOVC insertionSortAovc;

    Record records[] = {{"bbb"}, {"abb"}, {"aab"}, {"abb"}, {"aaa"}};
    Stats stats = insertionSortAovc.sortPositive(records, 0, 5, 3, getNewStats());

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("abb", records[2].key);
    EXPECT_EQ("abb", records[3].key);
    EXPECT_EQ("bbb", records[4].key);

    EXPECT_EQ(10, stats.rowComparisons);
    EXPECT_EQ(5, stats.rowComparisonsDecidedByOVC);
    EXPECT_EQ(9, stats.columnComparisons);
}


TEST(InsertionSortAOVCTest, NegativeSortingSanityCheck) {
    InsertionSortAOVC insertionSortAovc;

    Record records[] = {
        {"bbb", 0,  AOVC_PLUS_INFINITY},
        {"bab", 0, AOVC_PLUS_INFINITY},
        {"abb", 0 , AOVC_PLUS_INFINITY},
        {"abb", 0 , AOVC_PLUS_INFINITY},
        {"aaa", 0 , AOVC_PLUS_INFINITY}};
    Stats stats = insertionSortAovc.sortNegative(records, 0, 5, 3, getNewStats());

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("abb", records[1].key);
    EXPECT_EQ("abb", records[2].key);
    EXPECT_EQ("bab", records[3].key);
    EXPECT_EQ("bbb", records[4].key);

    EXPECT_EQ(10, stats.rowComparisons);
    EXPECT_EQ(4, stats.rowComparisonsDecidedByOVC);
    EXPECT_EQ(8, stats.columnComparisons);
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

TEST(InsertionSortAOVCTest, NegativeSortingWorstCase) {
    InsertionSortAOVC insertionSortAovc;

    Record records[] = {
        {"aad", 0, AOVC_PLUS_INFINITY},
        {"aac", 0, AOVC_PLUS_INFINITY},
        {"aab", 0, AOVC_PLUS_INFINITY},
        {"aaa", 0, AOVC_PLUS_INFINITY}};
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

    const int * before = getValueArray(records, N, k);
    quicksort.sortPositive(records, 0, N, k, getNewStats());
    const int * after = getValueArray(records, N, k);

    EXPECT_TRUE(isSorted(records, N));
    EXPECT_TRUE(validPositiveAOVC(records, N, k));
    for (int i = 0; i < pow(10, k); i++) {
        EXPECT_EQ(before[i], after[i]);
    }

    delete [] records;
    delete[] before;
    delete[] after;
}

TEST(InsertionSortAOVCRest, NegativeSortingMany) {
    InsertionSortAOVC quicksort;
    constexpr int N = 1000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337, 0, AOVC_PLUS_INFINITY);

    const int * before = getValueArray(records, N, k);
    quicksort.sortNegative(records, 0, N, k, getNewStats());
    const int * after = getValueArray(records, N, k);

    EXPECT_TRUE(isSorted(records, N));
    EXPECT_TRUE(validNegativeAOVC(records, N, k));
    for (int i = 0; i < pow(10, k); i++) {
        EXPECT_EQ(before[i], after[i]);
    }

    delete [] records;
    delete[] before;
    delete[] after;
}