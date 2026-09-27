/**
 * LeetCode 128: Longest Consecutive Sequence
 * Time Complexity: O(n log n) with sorting or O(n) with hash table
 * Space Complexity: O(1)
 */
#include <stdlib.h>

static int cmp(const void* a, const void* b) {
    long long diff = (long long)*(const int*)a - (long long)*(const int*)b;
    return (diff > 0) - (diff < 0);
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize <= 1) return numsSize;
    qsort(nums, numsSize, sizeof(int), cmp);
    int maxLen = 1, currentLen = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) continue;
        if (nums[i] == nums[i - 1] + 1) {
            currentLen++;
        } else {
            if (currentLen > maxLen) maxLen = currentLen;
            currentLen = 1;
        }
    }
    return (currentLen > maxLen) ? currentLen : maxLen;
}
