/**
 * LeetCode 238: Product of Array Except Self
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary
 */
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* output = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    output[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        output[i] = output[i - 1] * nums[i - 1];
    }
    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        output[i] *= right;
        right *= nums[i];
    }
    return output;
}
