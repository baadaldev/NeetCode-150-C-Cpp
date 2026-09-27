/**
 * LeetCode 994: Rotting Oranges
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */
#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::queue<std::pair<int, int>> q;
        int fresh = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 2) q.push({r, c});
                else if (grid[r][c] == 1) fresh++;
            }
        }
        if (fresh == 0) return 0;
        int minutes = 0;
        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [r, c] = q.front(); q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
};
