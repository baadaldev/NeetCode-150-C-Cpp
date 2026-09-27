/**
 * LeetCode 39: Combination Sum
 * Time Complexity: O(2^target)
 * Space Complexity: O(target)
 */
#include <vector>

class Solution {
    void dfs(const std::vector<int>& c, int target, int start, std::vector<int>& curr, std::vector<std::vector<int>>& res) {
        if (target == 0) { res.push_back(curr); return; }
        if (target < 0) return;
        for (int i = start; i < (int)c.size(); ++i) {
            curr.push_back(c[i]);
            dfs(c, target - c[i], i, curr, res);
            curr.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        dfs(candidates, target, 0, curr, res);
        return res;
    }
};
