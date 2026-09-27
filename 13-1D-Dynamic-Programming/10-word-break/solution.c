/**
 * LeetCode 139: Word Break
 * Time Complexity: O(n * m * k)
 * Space Complexity: O(n)
 */
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int n = strlen(s);
    bool* dp = (bool*)calloc(n + 1, sizeof(bool));
    dp[n] = true;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < wordDictSize; j++) {
            int len = strlen(wordDict[j]);
            if (i + len <= n && strncmp(s + i, wordDict[j], len) == 0) {
                dp[i] = dp[i + len];
                if (dp[i]) break;
            }
        }
    }
    bool res = dp[0];
    free(dp);
    return res;
}
