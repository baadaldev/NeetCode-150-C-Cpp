/**
 * LeetCode 56: Merge Intervals
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static int cmp(const void* a, const void* b) {
    int* i1 = *(int**)a;
    int* i2 = *(int**)b;
    return i1[0] - i2[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize <= 1) {
        *returnSize = intervalsSize;
        *returnColumnSizes = intervalsColSize;
        return intervals;
    }
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int** res = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    int count = 0;

    res[0] = (int*)malloc(2 * sizeof(int));
    res[0][0] = intervals[0][0]; res[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;
    count = 1;

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= res[count - 1][1]) {
            res[count - 1][1] = MAX(res[count - 1][1], intervals[i][1]);
        } else {
            res[count] = (int*)malloc(2 * sizeof(int));
            res[count][0] = intervals[i][0]; res[count][1] = intervals[i][1];
            (*returnColumnSizes)[count++] = 2;
        }
    }
    *returnSize = count;
    return res;
}
