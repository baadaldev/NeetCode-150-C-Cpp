/**
 * LeetCode 40: Combination Sum II
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>
#include <string.h>

static int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    *returnSize = 0;
    return NULL;
}
