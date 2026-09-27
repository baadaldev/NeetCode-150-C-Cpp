/**
 * LeetCode 5: Longest Palindromic Substring
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int start = 0, maxLen = 1, n = s.length();
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                l--; r++;
            }
        };
        for (int i = 0; i < n; ++i) {
            expand(i, i);
            expand(i, i + 1);
        }
        return s.substr(start, maxLen);
    }
};
