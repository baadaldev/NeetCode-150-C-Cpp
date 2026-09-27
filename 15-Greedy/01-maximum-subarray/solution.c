/**
 * LeetCode 53: Maximum Subarray
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSubArray(int* nums, int numsSize) {
    int maxS = nums[0], curS = 0;
    for (int i = 0; i < numsSize; i++) {
        if (curS < 0) curS = 0;
        curS += nums[i];
        if (curS > maxS) maxS = curS;
    }
    return maxS;
}
