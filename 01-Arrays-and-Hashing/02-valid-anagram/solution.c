/**
 * LeetCode 242: Valid Anagram
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    int lenS = strlen(s);
    int lenT = strlen(t);
    if (lenS != lenT) return false;
    
    int count[26] = {0};
    for (int i = 0; i < lenS; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}
