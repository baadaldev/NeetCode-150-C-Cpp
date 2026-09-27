/**
 * LeetCode 695: Max Area of Island
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */
#include <vector>
#include <algorithm>

class Solution {
    int dfs(std::vector<std::vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= (int)grid.size() || c < 0 || c >= (int)grid[0].size() || grid[r][c] != 1) return 0;
        grid[r][c] = 0;
        return 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c) +
                   dfs(grid, r, c + 1) + dfs(grid, r, c - 1);
    }
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int maxA = 0;
        for (int r = 0; r < (int)grid.size(); ++r) {
            for (int c = 0; c < (int)grid[0].size(); ++c) {
                if (grid[r][c] == 1) {
                    maxA = std::max(maxA, dfs(grid, r, c));
                }
            }
        }
        return maxA;
    }
};
