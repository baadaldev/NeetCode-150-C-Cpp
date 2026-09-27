/**
 * LeetCode 518: Coin Change II
 * Time Complexity: O(amount * n)
 * Space Complexity: O(amount)
 */
#include <stdlib.h>

int change(int amount, int* coins, int coinsSize) {
    unsigned int* dp = (unsigned int*)calloc(amount + 1, sizeof(unsigned int));
    dp[0] = 1;
    for (int i = 0; i < coinsSize; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    int res = dp[amount];
    free(dp);
    return res;
}
