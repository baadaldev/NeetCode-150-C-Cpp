/**
 * LeetCode 994: Rotting Oranges
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */
int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int q[1000][2];
    int head = 0, tail = 0;
    int fresh = 0;

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == 2) {
                q[tail][0] = r; q[tail++][1] = c;
            } else if (grid[r][c] == 1) {
                fresh++;
            }
        }
    }
    if (fresh == 0) return 0;
    int minutes = 0;
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    while (head < tail && fresh > 0) {
        int size = tail - head;
        for (int i = 0; i < size; i++) {
            int r = q[head][0], c = q[head++][1];
            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d][0], nc = c + dirs[d][1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    q[tail][0] = nr; q[tail++][1] = nc;
                }
            }
        }
        minutes++;
    }
    return fresh == 0 ? minutes : -1;
}
