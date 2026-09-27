/**
 * LeetCode 76: Minimum Window Substring
 * Time Complexity: O(n + m)
 * Space Complexity: O(1)
 */
#include <stdlib.h>
#include <string.h>

char* minWindow(char* s, char* t) {
    int sLen = strlen(s), tLen = strlen(t);
    if (sLen < tLen || tLen == 0) return "";

    int need[128] = {0}, window[128] = {0};
    for (int i = 0; i < tLen; i++) need[(unsigned char)t[i]]++;

    int have = 0, required = 0;
    for (int i = 0; i < 128; i++) {
        if (need[i] > 0) required++;
    }

    int minLen = 1e9, start = 0, l = 0;
    for (int r = 0; r < sLen; r++) {
        unsigned char c = (unsigned char)s[r];
        window[c]++;
        if (need[c] > 0 && window[c] == need[c]) have++;

        while (have == required) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }
            unsigned char leftChar = (unsigned char)s[l];
            window[leftChar]--;
            if (need[leftChar] > 0 && window[leftChar] < need[leftChar]) {
                have--;
            }
            l++;
        }
    }
    if (minLen == 1e9) return "";
    char* res = (char*)malloc(minLen + 1);
    strncpy(res, s + start, minLen);
    res[minLen] = '\0';
    return res;
}
