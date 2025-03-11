#include <gtest/gtest.h>
#include <InsertionSort.h>

#include "Utils.h"


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


TEST(InsertionSortTest, Duplicate) {
    InsertionSort insertionSort;

    Record records[] = {{"333"}, {"333"}, {"222"}, {"111"}, {"444"}};
    insertionSort.sort(records, 5, 3);

    EXPECT_EQ("111", records[0].key);
    EXPECT_EQ("222", records[1].key);
    EXPECT_EQ("333", records[2].key);
    EXPECT_EQ("333", records[3].key);
    EXPECT_EQ("444", records[4].key);
}

TEST(InsertionSortTest, Many) {
    InsertionSort insertionSort;

    constexpr int N = 1000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337);

    const int * before = getValueArray(records, N, k);
    insertionSort.sort(records, N, k);
    const int * after = getValueArray(records, N, k);

    EXPECT_TRUE(isSorted(records, N));
    for (int i = 0; i < pow(10, k); i++) {
        EXPECT_EQ(before[i], after[i]);
    }

    delete [] records;
    delete[] before;
    delete[] after;
}