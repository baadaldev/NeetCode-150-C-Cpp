/**
 * LeetCode 695: Max Area of Island
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */
static int dfs(int** grid, int m, int n, int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1) return 0;
    grid[r][c] = 0;
    return 1 + dfs(grid, m, n, r + 1, c) + dfs(grid, m, n, r - 1, c) +
               dfs(grid, m, n, r, c + 1) + dfs(grid, m, n, r, c - 1);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int maxA = 0;
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == 1) {
                int area = dfs(grid, m, n, r, c);
                if (area > maxA) maxA = area;
            }
        }
    }
    return maxA;
}
