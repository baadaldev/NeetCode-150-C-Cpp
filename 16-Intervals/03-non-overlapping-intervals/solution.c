/**
 * LeetCode 435: Non-overlapping Intervals
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */
#include <stdlib.h>

static int cmp(const void* a, const void* b) {
    return (*(int**)a)[1] - (*(int**)b)[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize <= 1) return 0;
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int count = 0, prevEnd = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] < prevEnd) {
            count++;
        } else {
            prevEnd = intervals[i][1];
        }
    }
    return count;
}
