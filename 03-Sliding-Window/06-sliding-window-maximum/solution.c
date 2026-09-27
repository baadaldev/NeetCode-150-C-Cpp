/**
 * LeetCode 239: Sliding Window Maximum
 * Time Complexity: O(n)
 * Space Complexity: O(k)
 */
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }
    int* deque = (int*)malloc(numsSize * sizeof(int));
    int head = 0, tail = 0;
    int* res = (int*)malloc((numsSize - k + 1) * sizeof(int));
    *returnSize = numsSize - k + 1;

    for (int i = 0; i < numsSize; i++) {
        while (tail > head && deque[head] <= i - k) head++;
        while (tail > head && nums[deque[tail - 1]] <= nums[i]) tail--;
        deque[tail++] = i;
        if (i >= k - 1) {
            res[i - k + 1] = nums[deque[head]];
        }
    }
    free(deque);
    return res;
}
