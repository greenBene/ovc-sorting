#include <gtest/gtest.h>
#include <Quicksort.h>
#include "RecordHelper.h"


TEST(QuicksortTest, SanityCheck) {
    Quicksort quicksort;

    std::string keys[] = {"bbb", "aab", "abb", "aaa"};
    Record * records = generateRecords(keys, 4);

    quicksort.sort(records, 4, 3, 1);

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("abb", records[2].key);
    EXPECT_EQ("bbb", records[3].key);
}

TEST(QuicksortTest, ThesisExample) {
    Quicksort quicksort;

    std::string keys[] = {"591", "333", "764", "670", "610", "934", "496", "564", "408"};
    Record *records = generateRecords(keys, 9);
    quicksort.sort(records, 9, 3, 1);

    EXPECT_EQ("333", records[0].key);
    EXPECT_EQ("408", records[1].key);
    EXPECT_EQ("496", records[2].key);
    EXPECT_EQ("564", records[3].key);
    EXPECT_EQ("591", records[4].key);
    EXPECT_EQ("610", records[5].key);
    EXPECT_EQ("670", records[6].key);
    EXPECT_EQ("764", records[7].key);
    EXPECT_EQ("934", records[8].key);
}


// TEST(InsertionSortTest, WorstCase) {
//     InsertionSort insertionSort;
//
//     Record records[] = {{"aad"}, {"aac"}, {"aab"}, {"aaa"}};
//     Stats stats = insertionSort.sort(records, 4, 3);
//
//     EXPECT_EQ("aaa", records[0].key);
//     EXPECT_EQ("aab", records[1].key);
//     EXPECT_EQ("aac", records[2].key);
//     EXPECT_EQ("aad", records[3].key);
//
//     EXPECT_EQ(6, stats.rowComparisons);
//     EXPECT_EQ(18, stats.columnComparisons);
// }
//
// TEST(InsertionSortTest, BestCase) {
//     InsertionSort insertionSort;
//
//     Record records[] = {{"aaa"}, {"bbb"}, {"ccc"}, {"ddd"}};
//     Stats stats = insertionSort.sort(records, 4, 3);
//
//     EXPECT_EQ("aaa", records[0].key);
//     EXPECT_EQ("bbb", records[1].key);
//     EXPECT_EQ("ccc", records[2].key);
//     EXPECT_EQ("ddd", records[3].key);
//
//     EXPECT_EQ(3, stats.rowComparisons);
//     EXPECT_EQ(3, stats.columnComparisons);
// }