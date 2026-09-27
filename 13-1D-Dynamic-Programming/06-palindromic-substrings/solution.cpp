/**
 * LeetCode 647: Palindromic Substrings
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
#include <string>

class Solution {
public:
    int countSubstrings(std::string s) {
        int count = 0, n = s.length();
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--; r++;
            }
        };
        for (int i = 0; i < n; ++i) {
            expand(i, i);
            expand(i, i + 1);
        }
        return count;
    }
};
