/**
 * LeetCode 17: Letter Combinations of a Phone Number
 * Time Complexity: O(4^n * n)
 * Space Complexity: O(n)
 */
#include <vector>
#include <string>

class Solution {
    const std::vector<std::string> keypad = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(const std::string& digits, int idx, std::string& curr, std::vector<std::string>& res) {
        if (idx == (int)digits.length()) { res.push_back(curr); return; }
        for (char c : keypad[digits[idx] - '0']) {
            curr.push_back(c);
            backtrack(digits, idx + 1, curr, res);
            curr.pop_back();
        }
    }
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};
        std::vector<std::string> res;
        std::string curr;
        backtrack(digits, 0, curr, res);
        return res;
    }
};
