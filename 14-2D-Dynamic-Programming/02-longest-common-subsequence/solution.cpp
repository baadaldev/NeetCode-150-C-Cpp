/**
 * LeetCode 1143: Longest Common Subsequence
 * Time Complexity: O(m * n)
 * Space Complexity: O(min(m, n))
 */
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int m = text1.length(), n = text2.length();
        std::vector<int> dp(n + 1, 0);

        for (int i = 1; i <= m; ++i) {
            int prev = 0;
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j];
                if (text1[i - 1] == text2[j - 1]) dp[j] = 1 + prev;
                else dp[j] = std::max(dp[j], dp[j - 1]);
                prev = temp;
            }
        }
        return dp[n];
    }
};
