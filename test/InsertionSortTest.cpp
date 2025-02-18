#include <gtest/gtest.h>
#include <InsertionSort.h>


TEST(InsertionSortTest, SanityCheck) {
    InsertionSort insertionSort;

    Record records[] = {{"bbb"}, {"aab"}, {"abb"}, {"aaa"}};
    insertionSort.sort(records, 4, 3);

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("abb", records[2].key);
    EXPECT_EQ("bbb", records[3].key);
}

TEST(InsertionSortTest, WorstCase) {
    InsertionSort insertionSort;

    Record records[] = {{"aad"}, {"aac"}, {"aab"}, {"aaa"}};
    Stats stats = insertionSort.sort(records, 4, 3);

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("aac", records[2].key);
    EXPECT_EQ("aad", records[3].key);

    EXPECT_EQ(6, stats.rowComparisons);
    EXPECT_EQ(18, stats.columnComparisons);
}

TEST(InsertionSortTest, BestCase) {
    InsertionSort insertionSort;

    Record records[] = {{"aaa"}, {"bbb"}, {"ccc"}, {"ddd"}};
    Stats stats = insertionSort.sort(records, 4, 3);

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("bbb", records[1].key);
    EXPECT_EQ("ccc", records[2].key);
    EXPECT_EQ("ddd", records[3].key);

    EXPECT_EQ(3, stats.rowComparisons);
    EXPECT_EQ(3, stats.columnComparisons);
}