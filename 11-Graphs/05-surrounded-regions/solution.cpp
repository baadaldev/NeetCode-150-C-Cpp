/**
 * LeetCode 130: Surrounded Regions
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */
#include <vector>

class Solution {
    void dfs(std::vector<std::vector<char>>& board, int r, int c) {
        if (r < 0 || r >= (int)board.size() || c < 0 || c >= (int)board[0].size() || board[r][c] != 'O') return;
        board[r][c] = 'T';
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
public:
    void solve(std::vector<std::vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for (int r = 0; r < m; ++r) { dfs(board, r, 0); dfs(board, r, n - 1); }
        for (int c = 0; c < n; ++c) { dfs(board, 0, c); dfs(board, m - 1, c); }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                else if (board[r][c] == 'T') board[r][c] = 'O';
            }
        }
    }
};
