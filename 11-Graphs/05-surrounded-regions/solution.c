/**
 * LeetCode 130: Surrounded Regions
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */
static void dfs(char** board, int m, int n, int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') return;
    board[r][c] = 'T';
    dfs(board, m, n, r + 1, c);
    dfs(board, m, n, r - 1, c);
    dfs(board, m, n, r, c + 1);
    dfs(board, m, n, r, c - 1);
}

void solve(char** board, int boardSize, int* boardColSize) {
    int m = boardSize, n = boardColSize[0];
    for (int r = 0; r < m; r++) {
        if (board[r][0] == 'O') dfs(board, m, n, r, 0);
        if (board[r][n - 1] == 'O') dfs(board, m, n, r, n - 1);
    }
    for (int c = 0; c < n; c++) {
        if (board[0][c] == 'O') dfs(board, m, n, 0, c);
        if (board[m - 1][c] == 'O') dfs(board, m, n, m - 1, c);
    }
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (board[r][c] == 'O') board[r][c] = 'X';
            else if (board[r][c] == 'T') board[r][c] = 'O';
        }
    }
}
