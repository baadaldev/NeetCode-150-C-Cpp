/**
 * LeetCode 57: Insert Interval
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int cap = intervalsSize + 2;
    int** res = (int**)malloc(cap * sizeof(int*));
    *returnColumnSizes = (int*)malloc(cap * sizeof(int));
    int count = 0, i = 0;

    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        res[count] = (int*)malloc(2 * sizeof(int));
        res[count][0] = intervals[i][0]; res[count][1] = intervals[i][1];
        (*returnColumnSizes)[count++] = 2;
        i++;
    }
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = MIN(newInterval[0], intervals[i][0]);
        newInterval[1] = MAX(newInterval[1], intervals[i][1]);
        i++;
    }
    res[count] = (int*)malloc(2 * sizeof(int));
    res[count][0] = newInterval[0]; res[count][1] = newInterval[1];
    (*returnColumnSizes)[count++] = 2;

    while (i < intervalsSize) {
        res[count] = (int*)malloc(2 * sizeof(int));
        res[count][0] = intervals[i][0]; res[count][1] = intervals[i][1];
        (*returnColumnSizes)[count++] = 2;
        i++;
    }
    *returnSize = count;
    return res;
}
