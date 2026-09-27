/**
 * LeetCode 90: Subsets II
 * Time Complexity: O(n * 2^n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>
#include <string.h>

static int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

static void dfs(int* nums, int n, int start, int* curr, int cSize, int*** res, int* size, int* cap, int** colSizes) {
    if (*size == *cap) {
        *cap *= 2;
        *res = (int**)realloc(*res, *cap * sizeof(int*));
        *colSizes = (int*)realloc(*colSizes, *cap * sizeof(int));
    }
    (*res)[*size] = (int*)malloc(cSize * sizeof(int));
    memcpy((*res)[*size], curr, cSize * sizeof(int));
    (*colSizes)[*size] = cSize;
    (*size)++;

    for (int i = start; i < n; i++) {
        if (i > start && nums[i] == nums[i - 1]) continue;
        curr[cSize] = nums[i];
        dfs(nums, n, i + 1, curr, cSize + 1, res, size, cap, colSizes);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int cap = 1 << numsSize;
    int** res = (int**)malloc(cap * sizeof(int*));
    *returnColumnSizes = (int*)malloc(cap * sizeof(int));
    int* curr = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;
    dfs(nums, numsSize, 0, curr, 0, &res, returnSize, &cap, returnColumnSizes);
    free(curr);
    return res;
}
