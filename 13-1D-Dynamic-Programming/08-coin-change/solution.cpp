/**
 * LeetCode 322: Coin Change
 * Time Complexity: O(amount * n)
 * Space Complexity: O(amount)
 */
#include <vector>
#include <algorithm>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int c : coins) {
                if (i >= c) dp[i] = std::min(dp[i], 1 + dp[i - c]);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
