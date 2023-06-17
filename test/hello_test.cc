#include "GetMaxConnNum.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(HelloTest, getIntput) {
    EXPECT_EQ(1, getInputNubmer(1));
}

TEST(HelloTest, getMaxNumber) {
  std::vector<std::vector<int>> inputVec = {
      {4, 2, 1, 3},
      {3, 2, 2, 4},
      {5, 2, 1, 4}
  };
  
  EXPECT_EQ(4, getMaxConnectedNumber(inputVec));
}