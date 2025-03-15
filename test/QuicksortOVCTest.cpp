#include <gtest/gtest.h>
#include <QuicksortOVC.h>
#include <Record.h>

#include "Utils.h"

TEST(QuicksortOVCTest, SanityCheck) {
    QuicksortOVC quicksort;

    std::string keys[] = {"bbb", "aab", "abb", "aaa"};
    Record * records = generateRecords(keys, 4);

    auto [rowComparisons, columnComparisons] = quicksort.sort(records, 4, 3, 1);

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("abb", records[2].key);
    EXPECT_EQ("bbb", records[3].key);

    EXPECT_EQ(5, rowComparisons);
    EXPECT_EQ(8, columnComparisons);
    EXPECT_TRUE(validOVC(records, 4, 3));
}

TEST(QuicksortOVCTest, ThesisExampleWithoutInsertionSort) {
    QuicksortOVC quicksort;

    std::string keys[] = {"591", "333", "764", "670", "610", "934", "496", "564", "408"};
    Record *records = generateRecords(keys, 9);
    auto [rowComparisons, columnComparisons] = quicksort.sort(records, 9, 3, 1);

    EXPECT_EQ("333", records[0].key);
    EXPECT_EQ("408", records[1].key);
    EXPECT_EQ("496", records[2].key);
    EXPECT_EQ("564", records[3].key);
    EXPECT_EQ("591", records[4].key);
    EXPECT_EQ("610", records[5].key);
    EXPECT_EQ("670", records[6].key);
    EXPECT_EQ("764", records[7].key);
    EXPECT_EQ("934", records[8].key);

    EXPECT_EQ(20, rowComparisons);
    EXPECT_EQ(13, columnComparisons);
    EXPECT_TRUE(validOVC(records, 9, 3));
}

TEST(QuicksortOVCTest, ThesisExampleWithInsertionSort) {
    QuicksortOVC quicksort;

    std::string keys[] = {"591", "333", "764", "670", "610", "934", "496", "564", "408"};
    Record *records = generateRecords(keys, 9);
    auto [rowComparisons, columnComparisons] = quicksort.sort(records, 9, 3, 4);

    EXPECT_EQ("333", records[0].key);
    EXPECT_EQ("408", records[1].key);
    EXPECT_EQ("496", records[2].key);
    EXPECT_EQ("564", records[3].key);
    EXPECT_EQ("591", records[4].key);
    EXPECT_EQ("610", records[5].key);
    EXPECT_EQ("670", records[6].key);
    EXPECT_EQ("764", records[7].key);
    EXPECT_EQ("934", records[8].key);

    EXPECT_EQ(17, rowComparisons);
    EXPECT_EQ(14, columnComparisons);
    EXPECT_TRUE(validOVC(records, 9, 3));
}

TEST(QuicksortOVCTest, DirectToQuicksort) {
    QuicksortOVC quicksort;

    std::string keys[] = {"bbb", "aab", "abb", "aaa"};
    Record * records = generateRecords(keys, 4);

    quicksort.sort(records, 4, 3, 10);

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("abb", records[2].key);
    EXPECT_EQ("bbb", records[3].key);

    EXPECT_TRUE(validOVC(records, 4, 3));
}


TEST(QuicksortOVCTest, WorstCase) {
    QuicksortOVC quicksort;

    std::string keys[] = {"111", "112", "113", "114", "115", "116", "117", "118"};
    Record * records = generateRecords(keys, 8);
    Stats stats = quicksort.sort(records, 8, 3, 1);

    EXPECT_EQ("111", records[0].key);
    EXPECT_EQ("112", records[1].key);
    EXPECT_EQ("113", records[2].key);
    EXPECT_EQ("114", records[3].key);
    EXPECT_EQ("115", records[4].key);
    EXPECT_EQ("116", records[5].key);
    EXPECT_EQ("117", records[6].key);
    EXPECT_EQ("118", records[7].key);

    EXPECT_EQ(28, stats.rowComparisons);
    EXPECT_EQ(21, stats.columnComparisons);
    EXPECT_TRUE(validOVC(records, 8, 3));
}

TEST(QuicksortOVCTest, BestCase) {
    QuicksortOVC quicksort;

    std::string keys[] = {"555", "222", "111", "333", "444", "888", "666", "777", "999"};
    Record * records = generateRecords(keys, 9);
    Stats stats = quicksort.sort(records, 9, 3, 1);

    EXPECT_EQ("111", records[0].key);
    EXPECT_EQ("222", records[1].key);
    EXPECT_EQ("333", records[2].key);
    EXPECT_EQ("444", records[3].key);
    EXPECT_EQ("555", records[4].key);
    EXPECT_EQ("666", records[5].key);
    EXPECT_EQ("777", records[6].key);
    EXPECT_EQ("888", records[7].key);
    EXPECT_EQ("999", records[8].key);

    EXPECT_EQ(17, stats.rowComparisons);
    EXPECT_EQ(11, stats.columnComparisons);
    EXPECT_TRUE(validOVC(records, 9, 3));
}

TEST(QuicksortOVCTest, Duplicate) {
    QuicksortOVC quicksort;

    Record records[] = {{"333"}, {"333"}, {"222"}, {"111"}, {"444"}};
    quicksort.sort(records, 5, 3, 1);

    EXPECT_EQ("111", records[0].key);
    EXPECT_EQ("222", records[1].key);
    EXPECT_EQ("333", records[2].key);
    EXPECT_EQ("333", records[3].key);
    EXPECT_EQ("444", records[4].key);
    EXPECT_TRUE(validOVC(records, 5, 3));
}

TEST(QuicksortOVCTest, Many) {
    QuicksortOVC quicksort;
    constexpr int N = 5000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337);

    const int * before = getValueArray(records, N, k);

    quicksort.sort(records, N, k, 1);

    const int * after = getValueArray(records, N, k);

    EXPECT_TRUE(isSorted(records, N));
    EXPECT_TRUE(validOVC(records, N, k));

    for (int i = 0; i < pow(10, k); i++) {
        EXPECT_EQ(before[i], after[i]);
    }
    delete[] before;
    delete[] after;
    delete[] records;
}

TEST(QuicksortOVCTest, ManyWithM) {
    QuicksortOVC quicksort;
    constexpr int N = 5000;
    constexpr int k = 5;
    Record *records = generateRecords(N, k, 1337);

    const int * before = getValueArray(records, N, k);
    quicksort.sort(records, N, k, 30);
    const int * after = getValueArray(records, N, k);

    EXPECT_TRUE(isSorted(records, N));
    EXPECT_TRUE(validOVC(records, N, k));
    for (int i = 0; i < pow(10, k); i++) {
        EXPECT_EQ(before[i], after[i]);
    }
    delete[] before;
    delete[] after;
    delete[] records;
}