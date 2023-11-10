#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
            int fresh = 0;
    queue<pair<int, int>> rotten;
    int minutes = 0;
    int rows = grid.size(), cols = grid[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 2) {
                rotten.push({i, j});
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!rotten.empty() && fresh > 0) {
        int currentRotting = rotten.size();
        while (currentRotting--) {
            auto [x, y] = rotten.front();
            rotten.pop();
            for (auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;
                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                    fresh--;
                }
            }
        }
        minutes++;
    }

    return fresh == 0 ? minutes : -1;
    }
};