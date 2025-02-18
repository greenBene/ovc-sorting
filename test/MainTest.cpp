#include <gtest/gtest.h>
#include <Sort.h>


TEST(MainTest, FirstTest) {
  EXPECT_TRUE(lessThan(5,6));
  EXPECT_FALSE(lessThan(6, 4));
}