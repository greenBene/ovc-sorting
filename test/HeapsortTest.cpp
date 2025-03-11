#include <gtest/gtest.h>
#include <Heapsort.h>

#include "Utils.h"


TEST(HeapsortTest, SanityCheck) {
    Heapsort heapsort;

    Record records[] = {{"bbb"}, {"aab"}, {"aab"}, {"abb"}, {"aaa"}};
    heapsort.sort(records, 5, 3);

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("aab", records[2].key);
    EXPECT_EQ("abb", records[3].key);
    EXPECT_EQ("bbb", records[4].key);
}

TEST(HeapsortTest, Many) {
    Heapsort heapsort;

    constexpr int N = 1000;
    constexpr int k = 3;
    Record *records = generateRecords(N, k, 1337);

    const int * before = getValueArray(records, N, k);
    heapsort.sort(records, N, k);
    const int * after = getValueArray(records, N, k);

    EXPECT_TRUE(isSorted(records, N));
    for (int i = 0; i < pow(10, k); i++) {
        EXPECT_EQ(before[i], after[i]);
    }

    delete [] records;
    delete[] before;
    delete[] after;
}