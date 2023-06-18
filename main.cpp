#include <iostream>
#include <vector>

#include "GetMaxConnNum.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please pass input-file-path\n";
        return -1;
    }

    Solver solver;
    if (!solver.readInputFile(argv[1])) {
        return -1;
    }
    
    std::cout << "Max number of connected tile: " 
              << solver.getMaxConnectedTile() << std::endl;

    return 0;
}
