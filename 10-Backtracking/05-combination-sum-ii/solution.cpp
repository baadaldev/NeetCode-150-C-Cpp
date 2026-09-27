/**
 * LeetCode 40: Combination Sum II
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
 */
#include <vector>
#include <algorithm>

class Solution {
    void dfs(const std::vector<int>& c, int target, int start, std::vector<int>& curr, std::vector<std::vector<int>>& res) {
        if (target == 0) { res.push_back(curr); return; }
        for (int i = start; i < (int)c.size(); ++i) {
            if (c[i] > target) break;
            if (i > start && c[i] == c[i - 1]) continue;
            curr.push_back(c[i]);
            dfs(c, target - c[i], i + 1, curr, res);
            curr.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        dfs(candidates, target, 0, curr, res);
        return res;
    }
};
