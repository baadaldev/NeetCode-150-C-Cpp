/**
 * LeetCode 4: Median of Two Sorted Arrays
 * Time Complexity: O(log(min(m, n)))
 * Space Complexity: O(1)
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    int m = nums1Size, n = nums2Size;
    int low = 0, high = m;

    while (low <= high) {
        int partition1 = low + (high - low) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;

        int maxLeft1 = (partition1 == 0) ? -1e9 : nums1[partition1 - 1];
        int minRight1 = (partition1 == m) ? 1e9 : nums1[partition1];

        int maxLeft2 = (partition2 == 0) ? -1e9 : nums2[partition2 - 1];
        int minRight2 = (partition2 == n) ? 1e9 : nums2[partition2];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((m + n) % 2 == 0) {
                return (MAX(maxLeft1, maxLeft2) + MIN(minRight1, minRight2)) / 2.0;
            } else {
                return MAX(maxLeft1, maxLeft2);
            }
        } else if (maxLeft1 > minRight2) {
            high = partition1 - 1;
        } else {
            low = partition1 + 1;
        }
    }
    return 0.0;
}
