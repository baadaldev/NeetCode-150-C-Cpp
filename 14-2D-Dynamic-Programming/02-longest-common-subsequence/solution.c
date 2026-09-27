/**
 * LeetCode 1143: Longest Common Subsequence
 * Time Complexity: O(m * n)
 * Space Complexity: O(n)
 */
#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestCommonSubsequence(char* text1, char* text2) {
    int m = strlen(text1), n = strlen(text2);
    int* dp = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= m; i++) {
        int prev = 0;
        for (int j = 1; j <= n; j++) {
            int temp = dp[j];
            if (text1[i - 1] == text2[j - 1]) {
                dp[j] = 1 + prev;
            } else {
                dp[j] = MAX(dp[j], dp[j - 1]);
            }
            prev = temp;
        }
    }
    int res = dp[n];
    free(dp);
    return res;
}
