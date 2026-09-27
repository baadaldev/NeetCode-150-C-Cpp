/**
 * LeetCode 417: Pacific Atlantic Water Flow
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */
#include <vector>

class Solution {
    void dfs(const std::vector<std::vector<int>>& h, int r, int c, std::vector<std::vector<bool>>& ocean) {
        ocean[r][c] = true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < (int)h.size() && nc >= 0 && nc < (int)h[0].size() &&
                !ocean[nr][nc] && h[nr][nc] >= h[r][c]) {
                dfs(h, nr, nc, ocean);
            }
        }
    }
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        std::vector<std::vector<bool>> pac(m, std::vector<bool>(n, false));
        std::vector<std::vector<bool>> atl(m, std::vector<bool>(n, false));

        for (int r = 0; r < m; ++r) { dfs(heights, r, 0, pac); dfs(heights, r, n - 1, atl); }
        for (int c = 0; c < n; ++c) { dfs(heights, 0, c, pac); dfs(heights, m - 1, c, atl); }

        std::vector<std::vector<int>> res;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (pac[r][c] && atl[r][c]) res.push_back({r, c});
            }
        }
        return res;
    }
};
