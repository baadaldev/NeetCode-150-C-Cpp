/**
 * LeetCode 11: Container With Most Water
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;
        while (left < right) {
            int h = std::min(height[left], height[right]);
            maxWater = std::max(maxWater, h * (right - left));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};
