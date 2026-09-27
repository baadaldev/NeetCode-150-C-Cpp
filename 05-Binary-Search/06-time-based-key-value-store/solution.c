/**
 * LeetCode 981: Time Based Key-Value Store
 * Time Complexity: set: O(1), get: O(log n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>
#include <string.h>

typedef struct {
    int timestamp;
    char* value;
} TimeVal;

typedef struct {
    char* key;
    TimeVal* entries;
    int size;
    int capacity;
} KeyEntry;

typedef struct {
    KeyEntry* keys;
    int size;
    int capacity;
} TimeMap;

TimeMap* timeMapCreate() {
    TimeMap* tm = (TimeMap*)malloc(sizeof(TimeMap));
    tm->capacity = 100;
    tm->size = 0;
    tm->keys = (KeyEntry*)malloc(tm->capacity * sizeof(KeyEntry));
    return tm;
}
