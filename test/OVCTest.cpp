#include <gtest/gtest.h>
#include <OVC.h>


TEST(OVCTest, GenOVC) {

    const uint32_t ovc1 = genOVC(2, 5);

    EXPECT_EQ(0b01000000000000101111111111111010, ovc1);
}

TEST(OVCTest, Offset) {
    const Record rec = {"aa", genOVC(2, 5)};

    EXPECT_EQ(2, offset(rec));
}

TEST(OVCTest, Comparission) {
    const uint32_t ovc1 = genOVC(2, 5);
    const uint32_t ovc2 = genOVC(2, 7);

    EXPECT_TRUE(ovc1 > ovc2);
}