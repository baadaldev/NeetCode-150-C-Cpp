/**
 * LeetCode 518: Coin Change II
 * Time Complexity: O(amount * n)
 * Space Complexity: O(amount)
 */
#include <vector>

class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        std::vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int c : coins) {
            for (int j = c; j <= amount; ++j) {
                dp[j] += dp[j - c];
            }
        }
        return dp[amount];
    }
};
