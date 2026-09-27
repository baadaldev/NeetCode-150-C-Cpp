/**
 * LeetCode 72: Edit Distance
 * Time Complexity: O(m * n)
 * Space Complexity: O(n)
 */
#include <string.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minDistance(char* word1, char* word2) {
    int m = strlen(word1), n = strlen(word2);
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    for (int j = 0; j <= n; j++) dp[j] = j;

    for (int i = 1; i <= m; i++) {
        int prev = dp[0];
        dp[0] = i;
        for (int j = 1; j <= n; j++) {
            int temp = dp[j];
            if (word1[i - 1] == word2[j - 1]) {
                dp[j] = prev;
            } else {
                dp[j] = 1 + MIN(prev, MIN(dp[j], dp[j - 1]));
            }
            prev = temp;
        }
    }
    int res = dp[n];
    free(dp);
    return res;
}
