/**
 * LeetCode 46: Permutations
 * Time Complexity: O(n! * n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>
#include <string.h>

static void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }

static void backtrack(int* nums, int numsSize, int start, int*** res, int* size, int** colSizes) {
    if (start == numsSize) {
        (*res)[*size] = (int*)malloc(numsSize * sizeof(int));
        memcpy((*res)[*size], nums, numsSize * sizeof(int));
        (*colSizes)[*size] = numsSize;
        (*size)++;
        return;
    }
    for (int i = start; i < numsSize; i++) {
        swap(&nums[start], &nums[i]);
        backtrack(nums, numsSize, start + 1, res, size, colSizes);
        swap(&nums[start], &nums[i]);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = 1;
    for (int i = 1; i <= numsSize; i++) total *= i;
    int** res = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    *returnSize = 0;
    backtrack(nums, numsSize, 0, &res, returnSize, returnColumnSizes);
    return res;
}
