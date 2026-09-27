/**
 * LeetCode 567: Permutation in String
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <string>
#include <vector>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.length() > s2.length()) return false;
        std::vector<int> c1(26, 0), c2(26, 0);
        for (size_t i = 0; i < s1.length(); ++i) {
            c1[s1[i] - 'a']++;
            c2[s2[i] - 'a']++;
        }
        if (c1 == c2) return true;
        for (size_t i = s1.length(); i < s2.length(); ++i) {
            c2[s2[i] - 'a']++;
            c2[s2[i - s1.length()] - 'a']--;
            if (c1 == c2) return true;
        }
        return false;
    }
};
