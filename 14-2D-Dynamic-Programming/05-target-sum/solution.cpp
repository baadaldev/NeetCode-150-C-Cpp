/**
 * LeetCode 494: Target Sum
 * Time Complexity: O(n * sum)
 * Space Complexity: O(sum)
 */
#include <vector>
#include <numeric>
#include <cmath>

class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (std::abs(target) > sum || (sum + target) % 2 != 0) return 0;
        int s1 = (sum + target) / 2;

        std::vector<int> dp(s1 + 1, 0);
        dp[0] = 1;
        for (int n : nums) {
            for (int j = s1; j >= n; --j) {
                dp[j] += dp[j - n];
            }
        }
        return dp[s1];
    }
};
