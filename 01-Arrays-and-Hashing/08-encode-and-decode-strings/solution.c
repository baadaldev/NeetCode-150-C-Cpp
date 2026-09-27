/**
 * LeetCode 271 / LintCode 659: Encode and Decode Strings
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encode(char** strs, int strsSize) {
    int total = 0;
    for (int i = 0; i < strsSize; i++) {
        total += strlen(strs[i]) + 16;
    }
    char* encoded = (char*)malloc(total);
    encoded[0] = '\0';
    for (int i = 0; i < strsSize; i++) {
        char prefix[16];
        sprintf(prefix, "%d#", (int)strlen(strs[i]));
        strcat(encoded, prefix);
        strcat(encoded, strs[i]);
    }
    return encoded;
}
