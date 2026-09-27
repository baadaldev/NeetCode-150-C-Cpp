/**
 * LeetCode 54: Spiral Matrix
 * Time Complexity: O(m * n)
 * Space Complexity: O(1)
 */
#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        std::vector<int> res;
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            for (int c = left; c <= right; ++c) res.push_back(matrix[top][c]);
            top++;
            for (int r = top; r <= bottom; ++r) res.push_back(matrix[r][right]);
            right--;
            if (top <= bottom) {
                for (int c = right; c >= left; --c) res.push_back(matrix[bottom][c]);
                bottom--;
            }
            if (left <= right) {
                for (int r = bottom; r >= top; --r) res.push_back(matrix[r][left]);
                left++;
            }
        }
        return res;
    }
};
