/**
 * LeetCode 139: Word Break
 * Time Complexity: O(n * m * k)
 * Space Complexity: O(n)
 */
#include <string>
#include <vector>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        int n = s.length();
        std::vector<bool> dp(n + 1, false);
        dp[n] = true;

        for (int i = n - 1; i >= 0; --i) {
            for (const auto& w : wordDict) {
                int len = w.length();
                if (i + len <= n && s.substr(i, len) == w) {
                    dp[i] = dp[i + len];
                    if (dp[i]) break;
                }
            }
        }
        return dp[0];
    }
};
