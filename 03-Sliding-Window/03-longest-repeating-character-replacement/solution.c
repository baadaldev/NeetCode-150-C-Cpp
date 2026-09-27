/**
 * LeetCode 424: Longest Repeating Character Replacement
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <string.h>

int characterReplacement(char* s, int k) {
    int count[26] = {0};
    int maxCount = 0, left = 0, maxLen = 0;
    int len = strlen(s);

    for (int right = 0; right < len; right++) {
        count[s[right] - 'A']++;
        if (count[s[right] - 'A'] > maxCount) {
            maxCount = count[s[right] - 'A'];
        }
        while ((right - left + 1) - maxCount > k) {
            count[s[left] - 'A']--;
            left++;
        }
        int cur = right - left + 1;
        if (cur > maxLen) maxLen = cur;
    }
    return maxLen;
}
