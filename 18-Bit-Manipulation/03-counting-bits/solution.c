/**
 * LeetCode 338: Counting Bits
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <stdlib.h>

int* countBits(int n, int* returnSize) {
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    *returnSize = n + 1;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i >> 1] + (i & 1);
    }
    return dp;
}
