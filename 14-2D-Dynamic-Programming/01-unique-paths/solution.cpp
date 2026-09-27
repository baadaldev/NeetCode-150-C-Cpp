/**
 * LeetCode 62: Unique Paths
 * Time Complexity: O(m * n)
 * Space Complexity: O(n)
 */
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> row(n, 1);
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                row[c] += row[c - 1];
            }
        }
        return row[n - 1];
    }
};
