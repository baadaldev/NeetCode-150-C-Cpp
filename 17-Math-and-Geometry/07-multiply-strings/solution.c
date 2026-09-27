/**
 * LeetCode 43: Multiply Strings
 * Time Complexity: O(m * n)
 * Space Complexity: O(m + n)
 */
#include <string.h>
#include <stdlib.h>

char* multiply(char* num1, char* num2) {
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) return "0";
    int l1 = strlen(num1), l2 = strlen(num2);
    int* vals = (int*)calloc(l1 + l2, sizeof(int));

    for (int i = l1 - 1; i >= 0; i--) {
        for (int j = l2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + vals[p2];
            vals[p2] = sum % 10;
            vals[p1] += sum / 10;
        }
    }
    char* res = (char*)malloc(l1 + l2 + 1);
    int idx = 0, start = 0;
    while (start < l1 + l2 && vals[start] == 0) start++;
    for (int i = start; i < l1 + l2; i++) res[idx++] = vals[i] + '0';
    res[idx] = '\0';
    free(vals);
    return res;
}
