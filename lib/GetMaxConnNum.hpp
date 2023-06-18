#ifndef GET_MAX_CONN_NUM_HPP
#define GET_MAX_CONN_NUM_HPP

#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <string>

class Solver {
  public:
    bool readInputFile(std::string filePath) {
        std::ifstream inputFile(filePath);
        if (!inputFile.is_open()) {
            std::cout << "Failed to open " << filePath << '\n';
            return false;
        }

        std::string eachLine;
        while (std::getline(inputFile, eachLine)) {
            std::vector<int> row;
            for (char digit : eachLine) {
                int number = digit - '0'; // char to int
                row.push_back(number);
            }
            input.push_back(row);
        }

        inputFile.close();
        return true;
    }

    void readInputVector(std::vector<std::vector<int>> _input) {
        input = _input;
    }

    int getMaxConnectedTile() {
        n = static_cast<int>(input.size());
        m = static_cast<int>(input.front().size());
        visited = std::vector<std::vector<bool>>(n, std::vector<bool>(m, false));

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (!visited[y][x]) {
                    dfs(y, x, input[y][x]);
                    currCount = 0;
                }
            }
        }

        if (maxCount == 0) {
            return maxCount;
        } else {
            return maxCount + 1;
        }
    }

  private:
    void dfs(int y, int x, int target) {
        visited[y][x] = true;
        for (int i = 0; i < NUM_DIRECTIONS; i++) {
            int ny = y + direction[i][Y_COORD];
            int nx = x + direction[i][X_COORD];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (!visited[ny][nx] && input[ny][nx] == target) {
                currCount++;
                if (currCount > maxCount) {
                    maxCount = currCount;
                }
                dfs(ny, nx, target);
            }
        }
    }

  private:
    static const int NUM_DIRECTIONS = 4;
    static const int Y_COORD = 0;
    static const int X_COORD = 1;
    static const int NUM_COORD = 2;
    int direction[NUM_DIRECTIONS][NUM_COORD] = {
        {-1, 0}, // UP
        {0, 1},  // RIGHT
        {1, 0},  // DOWN
        {0, -1}  // LEFT
    };
    std::vector<std::vector<bool>> visited;
    std::vector<std::vector<int>> input;
    int n, m;
    int maxCount = 0;
    int currCount = 0;
};

#endif // GET_MAX_CONN_NUM_HPP