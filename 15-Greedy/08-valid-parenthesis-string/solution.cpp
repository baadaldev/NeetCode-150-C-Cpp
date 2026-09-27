/**
 * LeetCode 678: Valid Parenthesis String
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <string>

class Solution {
public:
    bool checkValidString(std::string s) {
        int cmin = 0, cmax = 0;
        for (char c : s) {
            if (c == '(') { cmin++; cmax++; }
            else if (c == ')') { cmin--; cmax--; }
            else { cmin--; cmax++; }
            if (cmax < 0) return false;
            if (cmin < 0) cmin = 0;
        }
        return cmin == 0;
    }
};
