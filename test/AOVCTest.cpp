#include <gtest/gtest.h>
#include <AOVC.h>

#include <bitset>


TEST(AOVCTest, GenPositiveAOVC) {
    const uint32_t ovc1 = genAOVC(5, false, 2, 5);
    EXPECT_EQ(0b01000000000000110000000000000101, ovc1);
}

TEST(AOVCTest, GenNegativeAOVC) {
    const uint32_t ovc1 = genAOVC(5, true, 2, 5);
    EXPECT_EQ(0b01111111111111000000000000000101, ovc1);
}


TEST(AOVCTest, Offset) {
    constexpr int arity = 5;
    const uint32_t ovcPositive = genAOVC(arity, false, 2, 5);
    EXPECT_EQ(2, offsetAOVC(ovcPositive, arity));

    const uint32_t ovcNegative = genAOVC(arity, false, 2, 5);
    EXPECT_EQ(2, offsetAOVC(ovcNegative, arity));
}



TEST(AOVCTest, Value) {
    constexpr int arity = 5;
    const uint32_t ovcPositive = genAOVC(arity, false, 2, 5);
    EXPECT_EQ(5, valueAOVC(ovcPositive));
    const uint32_t ovcNegative = genAOVC(arity, false, 2, 5);
    EXPECT_EQ(5, valueAOVC(ovcPositive));
}
//
//TEST(OVCTest, Comparission) {
//    const uint32_t ovc1 = genOVC(2, 5);
//    const uint32_t ovc2 = genOVC(2, 7);
//
//    EXPECT_TRUE(ovc1 > ovc2);
//}