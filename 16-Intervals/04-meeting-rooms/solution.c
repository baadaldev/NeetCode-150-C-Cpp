/**
 * LeetCode 252 / LintCode 920: Meeting Rooms
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */
#include <stdbool.h>
#include <stdlib.h>

static int cmp(const void* a, const void* b) { return (*(int**)a)[0] - (*(int**)b)[0]; }

bool canAttendMeetings(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize <= 1) return true;
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] < intervals[i - 1][1]) return false;
    }
    return true;
}
