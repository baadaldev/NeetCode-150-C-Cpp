/**
 * LeetCode 5: Longest Palindromic Substring
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len <= 1) return s;
    int start = 0, maxLen = 1;

    for (int i = 0; i < len; i++) {
        int l = i, r = i;
        while (l >= 0 && r < len && s[l] == s[r]) {
            if (r - l + 1 > maxLen) { start = l; maxLen = r - l + 1; }
            l--; r++;
        }
        l = i; r = i + 1;
        while (l >= 0 && r < len && s[l] == s[r]) {
            if (r - l + 1 > maxLen) { start = l; maxLen = r - l + 1; }
            l--; r++;
        }
    }
    char* res = (char*)malloc(maxLen + 1);
    strncpy(res, s + start, maxLen);
    res[maxLen] = '\0';
    return res;
}
