/**
 * LeetCode 22: Generate Parentheses
 * Time Complexity: Catalan Number ~ O(4^n / sqrt(n))
 * Space Complexity: O(n)
 */
#include <stdlib.h>
#include <string.h>

static void backtrack(int n, int open, int close, char* current, int idx, char*** res, int* size, int* cap) {
    if (idx == 2 * n) {
        current[idx] = '\0';
        if (*size == *cap) {
            *cap *= 2;
            *res = (char**)realloc(*res, *cap * sizeof(char*));
        }
        (*res)[*size] = (char*)malloc((2 * n + 1) * sizeof(char));
        strcpy((*res)[*size], current);
        (*size)++;
        return;
    }
    if (open < n) {
        current[idx] = '(';
        backtrack(n, open + 1, close, current, idx + 1, res, size, cap);
    }
    if (close < open) {
        current[idx] = ')';
        backtrack(n, open, close + 1, current, idx + 1, res, size, cap);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int cap = 128;
    char** res = (char**)malloc(cap * sizeof(char*));
    char* current = (char*)malloc((2 * n + 1) * sizeof(char));
    int size = 0;
    backtrack(n, 0, 0, current, 0, &res, &size, &cap);
    free(current);
    *returnSize = size;
    return res;
}
