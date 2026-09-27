/**
 * LeetCode 73: Set Matrix Zeroes
 * Time Complexity: O(m * n)
 * Space Complexity: O(1)
 */
#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool rowZero = false, colZero = false;

        for (int r = 0; r < m; ++r) if (matrix[r][0] == 0) colZero = true;
        for (int c = 0; c < n; ++c) if (matrix[0][c] == 0) rowZero = true;

        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0) matrix[r][c] = 0;
            }
        }
        if (colZero) for (int r = 0; r < m; ++r) matrix[r][0] = 0;
        if (rowZero) for (int c = 0; c < n; ++c) matrix[0][c] = 0;
    }
};
