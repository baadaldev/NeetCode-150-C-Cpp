/**
 * LeetCode 153: Find Minimum in Rotated Sorted Array
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};
