#include <iostream>
#include <vector>

#include "GetMaxConnNum.hpp"

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> input = {
        {4, 2, 1, 3},
        {3, 2, 2, 4},
        {5, 2, 1, 4}
    };

    Solver solver;
    std::cout << "Max number of connected tile: " << solver.getMaxConnectedTile(input);

    return 0;
}
