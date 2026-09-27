/**
 * LeetCode 131: Palindrome Partitioning
 * Time Complexity: O(n * 2^n)
 * Space Complexity: O(n)
 */
#include <vector>
#include <string>

class Solution {
    bool isPalindrome(const std::string& s, int l, int r) {
        while (l < r) if (s[l++] != s[r--]) return false;
        return true;
    }

    void dfs(const std::string& s, int start, std::vector<std::string>& curr, std::vector<std::vector<std::string>>& res) {
        if (start == (int)s.length()) { res.push_back(curr); return; }
        for (int end = start; end < (int)s.length(); ++end) {
            if (isPalindrome(s, start, end)) {
                curr.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1, curr, res);
                curr.pop_back();
            }
        }
    }
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> curr;
        dfs(s, 0, curr, res);
        return res;
    }
};
