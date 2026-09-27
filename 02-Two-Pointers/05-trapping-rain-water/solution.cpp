/**
 * LeetCode 42: Trapping Rain Water
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0, water = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                leftMax = std::max(leftMax, height[l]);
                water += leftMax - height[l];
                l++;
            } else {
                rightMax = std::max(rightMax, height[r]);
                water += rightMax - height[r];
                r--;
            }
        }
        return water;
    }
};
