/**
 * LeetCode 217: Contains Duplicate
 * Time Complexity: O(n log n) with qsort, or O(n) with hash table
 * Space Complexity: O(1) auxiliary
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int compare(const void *a, const void *b) {
    int valA = *(const int *)a;
    int valB = *(const int *)b;
    if (valA < valB) return -1;
    if (valA > valB) return 1;
    return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1) return false;
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}
