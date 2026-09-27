/**
 * LeetCode 200: Number of Islands
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */
static void dfs(char** grid, int m, int n, int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1') return;
    grid[r][c] = '0';
    dfs(grid, m, n, r + 1, c);
    dfs(grid, m, n, r - 1, c);
    dfs(grid, m, n, r, c + 1);
    dfs(grid, m, n, r, c - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int count = 0;
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == '1') {
                count++;
                dfs(grid, m, n, r, c);
            }
        }
    }
    return count;
}
