/**
 * LeetCode 90: Subsets II
 * Time Complexity: O(n * 2^n)
 * Space Complexity: O(n)
 */
#include <vector>
#include <algorithm>

class Solution {
    void dfs(const std::vector<int>& nums, int start, std::vector<int>& curr, std::vector<std::vector<int>>& res) {
        res.push_back(curr);
        for (int i = start; i < (int)nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            dfs(nums, i + 1, curr, res);
            curr.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        dfs(nums, 0, curr, res);
        return res;
    }
};
