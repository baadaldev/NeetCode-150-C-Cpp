/**
 * LeetCode 78: Subsets
 * Time Complexity: O(n * 2^n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>
#include <string.h>

static void backtrack(int* nums, int numsSize, int start, int* current, int curSize, int*** res, int* size, int** colSizes) {
    (*res)[*size] = (int*)malloc(curSize * sizeof(int));
    memcpy((*res)[*size], current, curSize * sizeof(int));
    (*colSizes)[*size] = curSize;
    (*size)++;

    for (int i = start; i < numsSize; i++) {
        current[curSize] = nums[i];
        backtrack(nums, numsSize, i + 1, current, curSize + 1, res, size, colSizes);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = 1 << numsSize;
    int** res = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    int* current = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;
    backtrack(nums, numsSize, 0, current, 0, &res, returnSize, returnColumnSizes);
    free(current);
    return res;
}
