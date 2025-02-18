#include <gtest/gtest.h>
#include <InsertionSortOVC.h>



TEST(InsertionSortOVCTest, SanityCheck) {
    InsertionSortOVC insertionSortOvc;

    Record records[] = {{"bbb"}, {"aab"}, {"abb"}, {"aaa"}};
    insertionSortOvc.sort(records, 4, 3);

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("abb", records[2].key);
    EXPECT_EQ("bbb", records[3].key);
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
}