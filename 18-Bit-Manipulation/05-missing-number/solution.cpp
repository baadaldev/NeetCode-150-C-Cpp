/**
 * LeetCode 268: Missing Number
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < (int)nums.size(); ++i) {
            res ^= i ^ nums[i];
        }
        return res;
    }
};
