/**
 * LeetCode 22: Generate Parentheses
 * Time Complexity: O(4^n / sqrt(n))
 * Space Complexity: O(n)
 */
#include <vector>
#include <string>

class Solution {
    void backtrack(int n, int open, int close, std::string& current, std::vector<std::string>& res) {
        if ((int)current.length() == 2 * n) {
            res.push_back(current);
            return;
        }
        if (open < n) {
            current.push_back('(');
            backtrack(n, open + 1, close, current, res);
            current.pop_back();
        }
        if (close < open) {
            current.push_back(')');
            backtrack(n, open, close + 1, current, res);
            current.pop_back();
        }
    }
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string current;
        backtrack(n, 0, 0, current, res);
        return res;
    }
};
