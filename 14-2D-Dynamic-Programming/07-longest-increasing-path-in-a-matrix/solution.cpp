/**
 * LeetCode 329: Longest Increasing Path in a Matrix
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */
#include <vector>
#include <algorithm>

class Solution {
    int dfs(const std::vector<std::vector<int>>& mat, int r, int c, std::vector<std::vector<int>>& dp) {
        if (dp[r][c] != 0) return dp[r][c];
        int m = mat.size(), n = mat[0].size();
        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
        int maxL = 1;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] > mat[r][c]) {
                maxL = std::max(maxL, 1 + dfs(mat, nr, nc, dp));
            }
        }
        return dp[r][c] = maxL;
    }
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        int ans = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                ans = std::max(ans, dfs(matrix, r, c, dp));
            }
        }
        return ans;
    }
};
