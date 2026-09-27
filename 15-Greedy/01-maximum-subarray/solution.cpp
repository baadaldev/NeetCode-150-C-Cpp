/**
 * LeetCode 53: Maximum Subarray
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int maxS = nums[0], curS = 0;
        for (int n : nums) {
            curS = std::max(n, curS + n);
            maxS = std::max(maxS, curS);
        }
        return maxS;
    }
};
