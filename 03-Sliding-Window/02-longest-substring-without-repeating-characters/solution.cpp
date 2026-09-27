/**
 * LeetCode 3: Longest Substring Without Repeating Characters
 * Time Complexity: O(n)
 * Space Complexity: O(min(m, n))
 */
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> lastIndex(256, -1);
        int maxLen = 0, left = 0;
        for (int right = 0; right < (int)s.length(); ++right) {
            unsigned char c = s[right];
            if (lastIndex[c] >= left) {
                left = lastIndex[c] + 1;
            }
            lastIndex[c] = right;
            maxLen = std::max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
