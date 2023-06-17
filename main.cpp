#include <iostream>
#include <vector>

#include "GetMaxConnNum.hpp"

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> inputVec = {
        {4, 2, 1, 3},
        {3, 2, 2, 4},
        {5, 2, 1, 4}
    };

    for (auto row : inputVec) {
        for (auto y : row) {
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }

    std::cout << getInputNubmer(1) << std::endl;

    return 0;
}
