/**
 * LeetCode 152: Maximum Product Subarray
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int res = nums[0], curMin = 1, curMax = 1;
        for (int n : nums) {
            int temp = curMax * n;
            curMax = std::max({n, temp, curMin * n});
            curMin = std::min({n, temp, curMin * n});
            res = std::max(res, curMax);
        }
        return res;
    }
};
