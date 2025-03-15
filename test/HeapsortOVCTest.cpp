#include <gtest/gtest.h>
#include <HeapsortOVC.h>

#include "Utils.h"

TEST(HeapsortOVCTest, SanityCheck) {
    HeapsortOVC heapsort;

    std::string keys[] = {"bbb", "aab", "aba", "abb", "aaa"};
    Record * records = generateRecords(keys, 5, OVC_PLUS_INFINITY);

    heapsort.sort(records, 5, 3);

    EXPECT_EQ("aaa", records[0].key);
    EXPECT_EQ("aab", records[1].key);
    EXPECT_EQ("aba", records[2].key);
    EXPECT_EQ("abb", records[3].key);
    EXPECT_EQ("bbb", records[4].key);
}