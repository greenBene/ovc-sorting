#include <gtest/gtest.h>

TEST(MainTest, FirstTest) {
  EXPECT_STRNE("hello", "world");
}