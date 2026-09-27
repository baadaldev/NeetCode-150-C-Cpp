/**
 * LeetCode 91: Decode Ways
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <string>

class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty() || s[0] == '0') return 0;
        int prev2 = 1, prev1 = 1;

        for (size_t i = 1; i < s.length(); ++i) {
            int curr = 0;
            if (s[i] != '0') curr += prev1;
            int twoDigit = std::stoi(s.substr(i - 1, 2));
            if (twoDigit >= 10 && twoDigit <= 26) curr += prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
