/**
 * LeetCode 46: Permutations
 * Time Complexity: O(n! * n)
 * Space Complexity: O(n)
 */
#include <vector>
#include <algorithm>

class Solution {
    void backtrack(std::vector<int>& nums, int start, std::vector<std::vector<int>>& res) {
        if (start == (int)nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < (int)nums.size(); ++i) {
            std::swap(nums[start], nums[i]);
            backtrack(nums, start + 1, res);
            std::swap(nums[start], nums[i]);
        }
    }
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }
};
