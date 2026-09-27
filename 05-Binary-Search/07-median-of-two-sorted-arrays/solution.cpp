/**
 * LeetCode 4: Median of Two Sorted Arrays
 * Time Complexity: O(log(min(m, n)))
 * Space Complexity: O(1)
 */
#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            int p1 = low + (high - low) / 2;
            int p2 = (m + n + 1) / 2 - p1;

            int maxL1 = (p1 == 0) ? -1e9 : nums1[p1 - 1];
            int minR1 = (p1 == m) ? 1e9 : nums1[p1];
            int maxL2 = (p2 == 0) ? -1e9 : nums2[p2 - 1];
            int minR2 = (p2 == n) ? 1e9 : nums2[p2];

            if (maxL1 <= minR2 && maxL2 <= minR1) {
                if ((m + n) % 2 == 0) {
                    return (std::max(maxL1, maxL2) + std::min(minR1, minR2)) / 2.0;
                } else {
                    return std::max(maxL1, maxL2);
                }
            } else if (maxL1 > minR2) {
                high = p1 - 1;
            } else {
                low = p1 + 1;
            }
        }
        return 0.0;
    }
};
