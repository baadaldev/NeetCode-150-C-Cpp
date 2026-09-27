/**
 * LeetCode 647: Palindromic Substrings
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
#include <string.h>

int countSubstrings(char* s) {
    int len = strlen(s), count = 0;
    for (int i = 0; i < len; i++) {
        int l = i, r = i;
        while (l >= 0 && r < len && s[l] == s[r]) { count++; l--; r++; }
        l = i; r = i + 1;
        while (l >= 0 && r < len && s[l] == s[r]) { count++; l--; r++; }
    }
    return count;
}
