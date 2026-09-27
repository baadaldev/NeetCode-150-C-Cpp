/**
 * LeetCode 49: Group Anagrams
 * Time Complexity: O(n * k log k)
 * Space Complexity: O(n * k)
 */
#include <stdlib.h>
#include <string.h>

static int compareChar(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

typedef struct Entry {
    char* sorted;
    char** items;
    int count;
    int capacity;
} Entry;

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    Entry* entries = (Entry*)malloc(strsSize * sizeof(Entry));
    int entryCount = 0;

    for (int i = 0; i < strsSize; i++) {
        int len = strlen(strs[i]);
        char* sorted = (char*)malloc(len + 1);
        strcpy(sorted, strs[i]);
        qsort(sorted, len, sizeof(char), compareChar);

        int found = -1;
        for (int j = 0; j < entryCount; j++) {
            if (strcmp(entries[j].sorted, sorted) == 0) {
                found = j;
                break;
            }
        }
        if (found != -1) {
            free(sorted);
            if (entries[found].count == entries[found].capacity) {
                entries[found].capacity *= 2;
                entries[found].items = (char**)realloc(entries[found].items, entries[found].capacity * sizeof(char*));
            }
            entries[found].items[entries[found].count++] = strs[i];
        } else {
            entries[entryCount].sorted = sorted;
            entries[entryCount].capacity = 4;
            entries[entryCount].count = 1;
            entries[entryCount].items = (char**)malloc(entries[entryCount].capacity * sizeof(char*));
            entries[entryCount].items[0] = strs[i];
            entryCount++;
        }
    }

    char*** result = (char***)malloc(entryCount * sizeof(char**));
    *returnColumnSizes = (int*)malloc(entryCount * sizeof(int));
    *returnSize = entryCount;

    for (int i = 0; i < entryCount; i++) {
        result[i] = entries[i].items;
        (*returnColumnSizes)[i] = entries[i].count;
        free(entries[i].sorted);
    }
    free(entries);
    return result;
}
