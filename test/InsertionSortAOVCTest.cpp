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