/**
 * LeetCode 150: Evaluate Reverse Polish Notation
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize) {
    int* stack = (int*)malloc(tokensSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char* t = tokens[i];
        if (strlen(t) == 1 && (t[0] == '+' || t[0] == '-' || t[0] == '*' || t[0] == '/')) {
            int b = stack[top--];
            int a = stack[top--];
            if (t[0] == '+') stack[++top] = a + b;
            else if (t[0] == '-') stack[++top] = a - b;
            else if (t[0] == '*') stack[++top] = a * b;
            else if (t[0] == '/') stack[++top] = a / b;
        } else {
            stack[++top] = atoi(t);
        }
    }
    int res = stack[top];
    free(stack);
    return res;
}
