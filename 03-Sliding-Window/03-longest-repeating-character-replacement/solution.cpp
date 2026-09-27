/**
 * LeetCode 424: Longest Repeating Character Replacement
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> count(26, 0);
        int maxCount = 0, left = 0, maxLen = 0;
        for (int right = 0; right < (int)s.length(); ++right) {
            maxCount = std::max(maxCount, ++count[s[right] - 'A']);
            while ((right - left + 1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }
            maxLen = std::max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
