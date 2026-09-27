/**
 * LeetCode 213: House Robber II
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <vector>
#include <algorithm>

class Solution {
    int robHelper(const std::vector<int>& nums, int start, int end) {
        int rob1 = 0, rob2 = 0;
        for (int i = start; i <= end; ++i) {
            int temp = std::max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return std::max(robHelper(nums, 0, nums.size() - 2),
                        robHelper(nums, 1, nums.size() - 1));
    }
};
