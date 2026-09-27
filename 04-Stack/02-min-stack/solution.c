/**
 * LeetCode 155: Min Stack
 * Time Complexity: O(1) for all operations
 * Space Complexity: O(n)
 */
#include <stdlib.h>

typedef struct {
    int* valStack;
    int* minStack;
    int top;
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack* ms = (MinStack*)malloc(sizeof(MinStack));
    ms->capacity = 1024;
    ms->valStack = (int*)malloc(ms->capacity * sizeof(int));
    ms->minStack = (int*)malloc(ms->capacity * sizeof(int));
    ms->top = -1;
    return ms;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->top + 1 == obj->capacity) {
        obj->capacity *= 2;
        obj->valStack = (int*)realloc(obj->valStack, obj->capacity * sizeof(int));
        obj->minStack = (int*)realloc(obj->minStack, obj->capacity * sizeof(int));
    }
    obj->top++;
    obj->valStack[obj->top] = val;
    if (obj->top == 0 || val < obj->minStack[obj->top - 1]) {
        obj->minStack[obj->top] = val;
    } else {
        obj->minStack[obj->top] = obj->minStack[obj->top - 1];
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0) obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->valStack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->valStack);
    free(obj->minStack);
    free(obj);
}
