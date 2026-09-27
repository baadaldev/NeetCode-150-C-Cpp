/**
 * LeetCode 152: Maximum Product Subarray
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProduct(int* nums, int numsSize) {
    int res = nums[0], curMin = 1, curMax = 1;
    for (int i = 0; i < numsSize; i++) {
        int n = nums[i];
        int temp = curMax * n;
        curMax = MAX(n, MAX(temp, curMin * n));
        curMin = MIN(n, MIN(temp, curMin * n));
        if (curMax > res) res = curMax;
    }
    return res;
}
