/**
 * LeetCode 17: Letter Combinations of a Phone Number
 * Time Complexity: O(4^n * n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>
#include <string.h>

static const char* keypad[] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

char** letterCombinations(char* digits, int* returnSize) {
    int len = strlen(digits);
    if (len == 0) { *returnSize = 0; return NULL; }
    int total = 1;
    for (int i = 0; i < len; i++) {
        int d = digits[i] - '0';
        total *= strlen(keypad[d]);
    }
    char** res = (char**)malloc(total * sizeof(char*));
    for (int i = 0; i < total; i++) {
        res[i] = (char*)malloc((len + 1) * sizeof(char));
        res[i][len] = '\0';
    }
    for (int i = 0; i < total; i++) {
        int temp = i;
        for (int j = len - 1; j >= 0; j--) {
            int d = digits[j] - '0';
            int count = strlen(keypad[d]);
            res[i][j] = keypad[d][temp % count];
            temp /= count;
        }
    }
    *returnSize = total;
    return res;
}
