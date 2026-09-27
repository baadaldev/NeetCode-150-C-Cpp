/**
 * LeetCode 1046: Last Stone Weight
 * Time Complexity: O(n log n)
 * Space Complexity: O(1) auxiliary
 */
#include <stdlib.h>

static int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int lastStoneWeight(int* stones, int stonesSize) {
    int n = stonesSize;
    while (n > 1) {
        qsort(stones, n, sizeof(int), cmp);
        int diff = stones[n - 1] - stones[n - 2];
        if (diff == 0) {
            n -= 2;
        } else {
            stones[n - 2] = diff;
            n--;
        }
    }
    return n == 1 ? stones[0] : 0;
}
