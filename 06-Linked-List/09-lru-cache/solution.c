/**
 * LeetCode 146: LRU Cache
 * Time Complexity: O(1) for get and put
 * Space Complexity: O(capacity)
 */
#include <stdlib.h>

typedef struct DNode {
    int key;
    int val;
    struct DNode* prev;
    struct DNode* next;
} DNode;

typedef struct {
    int capacity;
    int size;
    DNode* head;
    DNode* tail;
} LRUCache;

LRUCache* lruCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = (DNode*)malloc(sizeof(DNode));
    cache->tail = (DNode*)malloc(sizeof(DNode));
    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;
    return cache;
}
