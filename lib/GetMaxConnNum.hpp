#ifndef GET_MAX_CONN_NUM_HPP
#define GET_MAX_CONN_NUM_HPP

#include <iostream>
#include <stack>
#include <vector>

class Solver {
  public:
    int getMaxConnectedTile(std::vector<std::vector<int>> _input) {
        input = _input;
        n = static_cast<int>(input.size());
        m = static_cast<int>(input.front().size());
        visited = std::vector<std::vector<int>>(n, std::vector<int>(m, 0));

        maxNumber = input[0][0];
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (!visited[y][x]) {
                    dfs(y, x, input[y][x]);
                    currCount = 0;
                }
            }
        }

        if (maxCount == 0) {
            return 0;
        } else {
            return maxCount + 1;
        }
    }

    void dfs(int y, int x, int target) {
        visited[y][x] = 1;
        for (int i = 0; i < NUM_DIRECTIONS; i++) {
            int ny = y + direction[i][0];
            int nx = x + direction[i][1];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (input[ny][nx] == target && !visited[ny][nx]) {
                currCount++;
                if (currCount > maxCount) {
                    maxCount = currCount;
                }
                dfs(ny, nx, target);
            }
        }
    }

  private:
    enum { NUM_DIRECTIONS = 4 };
    enum { NUM_COORD = 2 };
    int n, m;
    int direction[NUM_DIRECTIONS][NUM_COORD] = {
        {-1, 0}, // UP
        {0, 1},  // RIGHT
        {1, 0},  // DOWN
        {0, -1}  // LEFT
    };
    std::vector<std::vector<int>> visited;
    std::vector<std::vector<int>> input;

    int maxNumber;
    int maxCount = 0;
    int currCount = 0;
};

#endif // GET_MAX_CONN_NUM_HPP