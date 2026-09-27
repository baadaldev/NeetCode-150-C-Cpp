/**
 * LeetCode 253 / LintCode 919: Meeting Rooms II
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize <= 1) return intervalsSize;
    int* start = (int*)malloc(intervalsSize * sizeof(int));
    int* end = (int*)malloc(intervalsSize * sizeof(int));
    for (int i = 0; i < intervalsSize; i++) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }
    qsort(start, intervalsSize, sizeof(int), cmp);
    qsort(end, intervalsSize, sizeof(int), cmp);

    int s = 0, e = 0, count = 0, maxRooms = 0;
    while (s < intervalsSize) {
        if (start[s] < end[e]) {
            count++; s++;
            maxRooms = MAX(maxRooms, count);
        } else {
            count--; e++;
        }
    }
    free(start); free(end);
    return maxRooms;
}
