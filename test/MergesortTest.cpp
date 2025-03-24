#include <gtest/gtest.h>
#include <Mergesort.h>

#include "Utils.h"

TEST(MergesortTest, SanityCheck) {
    Mergesort mergesort;
    int N = 8;
    int k = 3;

    std::string keys[] = {"959", "688", "131", "135", "746", "740", "214", "057"};
    Record * records = generateRecords(keys, N);
    auto [rowComparisons, columnComparisons] = mergesort.sort(records, N, k);

    EXPECT_EQ("057", records[0].key);
    EXPECT_EQ("131", records[1].key);
    EXPECT_EQ("135", records[2].key);
    EXPECT_EQ("214", records[3].key);
    EXPECT_EQ("688", records[4].key);
    EXPECT_EQ("740", records[5].key);
    EXPECT_EQ("746", records[6].key);
    EXPECT_EQ("959", records[7].key);

    EXPECT_EQ(15, rowComparisons);
    EXPECT_EQ(19, columnComparisons);
}

TEST(MergesortTest, ManyEven) {
    Mergesort mergesort;
    constexpr int N = 1000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1338);

    const int * before = getValueArray(records, N, k);
    mergesort.sort(records, N, k);
    const int * after = getValueArray(records, N, k);

    EXPECT_TRUE(isSorted(records, N));
    for (int i = 0; i < pow(10, k); i++) {
        EXPECT_EQ(before[i], after[i]);
    }

    delete [] records;
    delete[] before;
    delete[] after;
}

// TEST(MergesortTest, ManyEven) {
//     Mergesort mergesort;
//     constexpr int N = 1003;
//     constexpr int k = 5;
//     Record *records = generateRecords(N, k, 1336);
//
//     const int * before = getValueArray(records, N, k);
//     mergesort.sort(records, N, k);
//     const int * after = getValueArray(records, N, k);
//
//     EXPECT_TRUE(isSorted(records, N));
//     for (int i = 0; i < pow(10, k); i++) {
//         EXPECT_EQ(before[i], after[i]);
//     }
//
//     delete [] records;
//     delete[] before;
//     delete[] after;
// }