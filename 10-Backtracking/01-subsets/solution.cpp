/**
 * LeetCode 78: Subsets
 * Time Complexity: O(n * 2^n)
 * Space Complexity: O(n)
 */
#include <vector>

class Solution {
    void backtrack(const std::vector<int>& nums, int start, std::vector<int>& curr, std::vector<std::vector<int>>& res) {
        res.push_back(curr);
        for (int i = start; i < (int)nums.size(); ++i) {
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr, res);
            curr.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        backtrack(nums, 0, curr, res);
        return res;
    }
};
