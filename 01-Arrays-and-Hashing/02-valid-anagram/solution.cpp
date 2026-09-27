/**
 * LeetCode 242: Valid Anagram
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) return false;
        std::vector<int> freq(26, 0);
        for (size_t i = 0; i < s.length(); ++i) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for (int val : freq) {
            if (val != 0) return false;
        }
        return true;
    }
};
