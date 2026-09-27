/**
 * LeetCode 115: Distinct Subsequences
 * Time Complexity: O(m * n)
 * Space Complexity: O(n)
 */
#include <string>
#include <vector>

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int m = s.length(), n = t.length();
        std::vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= m; ++i) {
            for (int j = n; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) dp[j] += dp[j - 1];
            }
        }
        return dp[n];
    }
};
