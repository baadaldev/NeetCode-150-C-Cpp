/**
 * LeetCode 494: Target Sum
 * Time Complexity: O(n * sum)
 * Space Complexity: O(sum)
 */
#include <stdlib.h>

int findTargetSumWays(int* nums, int numsSize, int target) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) sum += nums[i];
    if (abs(target) > sum || (sum + target) % 2 != 0) return 0;
    int s1 = (sum + target) / 2;

    int* dp = (int*)calloc(s1 + 1, sizeof(int));
    dp[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = s1; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    }
    int res = dp[s1];
    free(dp);
    return res;
}
