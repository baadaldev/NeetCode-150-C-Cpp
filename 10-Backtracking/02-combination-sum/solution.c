/**
 * LeetCode 39: Combination Sum
 * Time Complexity: O(2^target)
 * Space Complexity: O(target)
 */
#include <stdlib.h>

static void dfs(int* candidates, int cSize, int target, int start, int* curr, int cLen, int*** res, int* size, int* cap, int** colSizes) {
    if (target == 0) {
        if (*size == *cap) {
            *cap *= 2;
            *res = (int**)realloc(*res, *cap * sizeof(int*));
            *colSizes = (int*)realloc(*colSizes, *cap * sizeof(int));
        }
        (*res)[*size] = (int*)malloc(cLen * sizeof(int));
        for (int i = 0; i < cLen; i++) (*res)[*size][i] = curr[i];
        (*colSizes)[*size] = cLen;
        (*size)++;
        return;
    }
    if (target < 0) return;
    for (int i = start; i < cSize; i++) {
        curr[cLen] = candidates[i];
        dfs(candidates, cSize, target - candidates[i], i, curr, cLen + 1, res, size, cap, colSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int cap = 150;
    int** res = (int**)malloc(cap * sizeof(int*));
    *returnColumnSizes = (int*)malloc(cap * sizeof(int));
    int* curr = (int*)malloc(500 * sizeof(int));
    *returnSize = 0;
    dfs(candidates, candidatesSize, target, 0, curr, 0, &res, returnSize, &cap, returnColumnSizes);
    free(curr);
    return res;
}
