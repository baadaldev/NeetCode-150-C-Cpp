/**
 * LeetCode 215: Kth Largest Element in an Array
 * Time Complexity: O(n log n) with qsort or O(n) QuickSelect
 * Space Complexity: O(1)
 */
#include <stdlib.h>

static int cmp(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int findKthLargest(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[k - 1];
}
