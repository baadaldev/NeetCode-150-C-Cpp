/**
 * LeetCode 416: Partition Equal Subset Sum
 * Time Complexity: O(n * sum)
 * Space Complexity: O(sum)
 */
#include <stdbool.h>
#include <stdlib.h>

bool canPartition(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) sum += nums[i];
    if (sum % 2 != 0) return false;
    int target = sum / 2;

    bool* dp = (bool*)calloc(target + 1, sizeof(bool));
    dp[0] = true;

    for (int i = 0; i < numsSize; i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    bool res = dp[target];
    free(dp);
    return res;
}
