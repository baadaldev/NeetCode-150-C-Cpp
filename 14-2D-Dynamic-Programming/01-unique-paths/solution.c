/**
 * LeetCode 62: Unique Paths
 * Time Complexity: O(m * n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>

int uniquePaths(int m, int n) {
    int* row = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) row[i] = 1;
    for (int r = 1; r < m; r++) {
        for (int c = 1; c < n; c++) {
            row[c] += row[c - 1];
        }
    }
    int res = row[n - 1];
    free(row);
    return res;
}
