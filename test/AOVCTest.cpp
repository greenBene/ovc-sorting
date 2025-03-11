#include <gtest/gtest.h>
#include <AOVC.h>

#include <bitset>


TEST(AOVCTest, GenPositiveAOVC) {
    const uint32_t aovc1 = generatePositiveAOVC(5, 2, 5);
    EXPECT_EQ(0b01000000000000110000000000000101, aovc1);
}

TEST(AOVCTest, GenNegativeAOVC) {
    const uint32_t aovc1 = generateNegativeAOVC(5, 2, 5);
    EXPECT_EQ(0b01111111111111000000000000000101, aovc1);
}


TEST(AOVCTest, Offset) {
    constexpr int arity = 5;
    const uint32_t aovcPositive = generatePositiveAOVC(arity, 2, 5);
    EXPECT_EQ(2, getOffsetAOVC(aovcPositive, arity));

    const uint32_t aovcNegative = generateNegativeAOVC(arity, 2, 5);
    EXPECT_EQ(2, getOffsetAOVC(aovcNegative, arity));
}

TEST(AOVCTest, Value) {
    constexpr int arity = 5;
    const uint32_t aovcPositive = generatePositiveAOVC(arity, 2, 5);
    EXPECT_EQ(5, getValueAOVC(aovcPositive));
    const uint32_t aovcNegative = generateNegativeAOVC(arity, 2, 5);
    EXPECT_EQ(5, getValueAOVC(aovcNegative));
}