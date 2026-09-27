/**
 * LeetCode 416: Partition Equal Subset Sum
 * Time Complexity: O(n * sum)
 * Space Complexity: O(sum)
 */
#include <vector>
#include <numeric>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;

        std::vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int n : nums) {
            for (int j = target; j >= n; --j) {
                dp[j] = dp[j] || dp[j - n];
            }
        }
        return dp[target];
    }
};
