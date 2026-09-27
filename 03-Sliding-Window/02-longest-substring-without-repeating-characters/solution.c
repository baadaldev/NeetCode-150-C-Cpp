/**
 * LeetCode 3: Longest Substring Without Repeating Characters
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int lastPos[256];
    for (int i = 0; i < 256; i++) lastPos[i] = -1;

    int maxLen = 0, left = 0;
    int len = strlen(s);

    for (int right = 0; right < len; right++) {
        unsigned char c = (unsigned char)s[right];
        if (lastPos[c] >= left) {
            left = lastPos[c] + 1;
        }
        lastPos[c] = right;
        int cur = right - left + 1;
        if (cur > maxLen) maxLen = cur;
    }
    return maxLen;
}
