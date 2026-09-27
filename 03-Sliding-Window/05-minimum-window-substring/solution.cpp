/**
 * LeetCode 76: Minimum Window Substring
 * Time Complexity: O(n + m)
 * Space Complexity: O(1)
 */
#include <string>
#include <vector>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.length() < t.length()) return "";
        std::vector<int> target(128, 0), window(128, 0);
        for (char c : t) target[c]++;

        int required = 0;
        for (int count : target) if (count > 0) required++;

        int formed = 0, l = 0, minLen = 1e9, start = 0;
        for (int r = 0; r < (int)s.length(); ++r) {
            char c = s[r];
            window[c]++;
            if (target[c] > 0 && window[c] == target[c]) formed++;

            while (formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                window[s[l]]--;
                if (target[s[l]] > 0 && window[s[l]] < target[s[l]]) formed--;
                l++;
            }
        }
        return minLen == 1e9 ? "" : s.substr(start, minLen);
    }
};
