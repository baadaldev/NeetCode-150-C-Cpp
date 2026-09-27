/**
 * LeetCode 567: Permutation in String
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <stdbool.h>
#include <string.h>

bool checkInclusion(char* s1, char* s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    if (len1 > len2) return false;

    int c1[26] = {0}, c2[26] = {0};
    for (int i = 0; i < len1; i++) {
        c1[s1[i] - 'a']++;
        c2[s2[i] - 'a']++;
    }

    int matches = 0;
    for (int i = 0; i < 26; i++) {
        if (c1[i] == c2[i]) matches++;
    }

    for (int i = 0; i < len2 - len1; i++) {
        if (matches == 26) return true;
        int r = s2[i + len1] - 'a';
        int l = s2[i] - 'a';

        c2[r]++;
        if (c2[r] == c1[r]) matches++;
        else if (c2[r] == c1[r] + 1) matches--;

        c2[l]--;
        if (c2[l] == c1[l]) matches++;
        else if (c2[l] == c1[l] - 1) matches--;
    }
    return matches == 26;
}
