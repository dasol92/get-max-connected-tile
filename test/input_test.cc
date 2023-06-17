#include "GetMaxConnNum.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(GetMaxConnectedTile, input0) {
    Solver solver;
    std::vector<std::vector<int>> input0 = {
        {1, 2, 1, 2, 3, 3, 1, 3},
        {2, 2, 1, 3, 2, 1, 3, 1},
        {1, 3, 1, 3, 1, 3, 3, 3},
        {3, 1, 3, 3, 3, 1, 2, 2},
        {2, 3, 2, 2, 2, 3, 3, 1},
        {3, 2, 2, 4, 2, 3, 1, 1},
        {1, 3, 2, 3, 1, 1, 1, 2},
        {3, 1, 2, 1, 2, 2, 3, 1}};
    EXPECT_EQ(8, solver.getMaxConnectedTile(input0));
}

TEST(GetMaxConnectedTile, intput1) {
    Solver solver;
    std::vector<std::vector<int>> input1 = {
        {1, 2, 3, 4},
        {4, 3, 2, 1},
        {1, 2, 3, 4}};
    EXPECT_EQ(0, solver.getMaxConnectedTile(input1));
}

TEST(GetMaxConnectedTile, input2) {
    Solver solver;
    std::vector<std::vector<int>> input2 = {
        {4, 2, 1, 3},
        {3, 2, 2, 4},
        {5, 2, 1, 4}};
    EXPECT_EQ(4, solver.getMaxConnectedTile(input2));
}

TEST(GetMaxConnectedTile, input3) {
    Solver solver;
    std::vector<std::vector<int>> input3 = {
        {1, 4, 2, 4, 7, 5},
        {3, 4, 4, 4, 9, 2},
        {5, 3, 3, 4, 9, 3},
        {1, 2, 3, 3, 9, 2}};
    EXPECT_EQ(6, solver.getMaxConnectedTile(input3));
}