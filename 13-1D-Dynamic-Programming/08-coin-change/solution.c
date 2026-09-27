/**
 * LeetCode 322: Coin Change
 * Time Complexity: O(amount * n)
 * Space Complexity: O(amount)
 */
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int coinChange(int* coins, int coinsSize, int amount) {
    int* dp = (int*)malloc((amount + 1) * sizeof(int));
    for (int i = 0; i <= amount; i++) dp[i] = amount + 1;
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (i >= coins[j]) {
                dp[i] = MIN(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    int res = dp[amount] > amount ? -1 : dp[amount];
    free(dp);
    return res;
}
