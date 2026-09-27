/**
 * LeetCode 79: Word Search
 * Time Complexity: O(m * n * 4^L)
 * Space Complexity: O(L)
 */
#include <stdbool.h>

static bool dfs(char** board, int m, int n, int r, int c, char* word, int idx) {
    if (!word[idx]) return true;
    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[idx]) return false;

    char temp = board[r][c];
    board[r][c] = '#';

    bool found = dfs(board, m, n, r + 1, c, word, idx + 1) ||
                 dfs(board, m, n, r - 1, c, word, idx + 1) ||
                 dfs(board, m, n, r, c + 1, word, idx + 1) ||
                 dfs(board, m, n, r, c - 1, word, idx + 1);

    board[r][c] = temp;
    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int m = boardSize, n = boardColSize[0];
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (board[r][c] == word[0] && dfs(board, m, n, r, c, word, 0)) {
                return true;
            }
        }
    }
    return false;
}
