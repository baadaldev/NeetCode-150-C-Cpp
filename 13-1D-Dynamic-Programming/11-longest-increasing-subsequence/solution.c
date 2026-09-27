/**
 * LeetCode 300: Longest Increasing Subsequence
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>

int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int* tails = (int*)malloc(numsSize * sizeof(int));
    int len = 0;

    for (int i = 0; i < numsSize; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (tails[mid] < nums[i]) l = mid + 1;
            else r = mid;
        }
        tails[l] = nums[i];
        if (l == len) len++;
    }
    free(tails);
    return len;
}
