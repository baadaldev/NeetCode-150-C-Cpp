/**
 * LeetCode 739: Daily Temperatures
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* res = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(temperaturesSize * sizeof(int));
    int top = -1;
    *returnSize = temperaturesSize;

    for (int i = 0; i < temperaturesSize; i++) {
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int prevIdx = stack[top--];
            res[prevIdx] = i - prevIdx;
        }
        stack[++top] = i;
    }
    free(stack);
    return res;
}
