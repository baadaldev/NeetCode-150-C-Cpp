/**
 * LeetCode 55: Jump Game
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int goal = nums.size() - 1;
        for (int i = (int)nums.size() - 2; i >= 0; --i) {
            if (i + nums[i] >= goal) goal = i;
        }
        return goal == 0;
    }
};
