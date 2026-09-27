/**
 * LeetCode 678: Valid Parenthesis String
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <stdbool.h>
#include <string.h>

bool checkValidString(char* s) {
    int cmin = 0, cmax = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(') { cmin++; cmax++; }
        else if (c == ')') { cmin--; cmax--; }
        else { cmin--; cmax++; }
        if (cmax < 0) return false;
        if (cmin < 0) cmin = 0;
    }
    return cmin == 0;
}
