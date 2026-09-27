/**
 * LeetCode 208: Implement Trie (Prefix Tree)
 * Time Complexity: O(L)
 * Space Complexity: O(N * L)
 */
#include <stdlib.h>
#include <stdbool.h>

typedef struct Trie {
    struct Trie* children[26];
    bool isEnd;
} Trie;

Trie* trieCreate() {
    Trie* node = (Trie*)calloc(1, sizeof(Trie));
    return node;
}

void trieInsert(Trie* obj, char* word) {
    Trie* curr = obj;
    while (*word) {
        int idx = *word - 'a';
        if (!curr->children[idx]) {
            curr->children[idx] = trieCreate();
        }
        curr = curr->children[idx];
        word++;
    }
    curr->isEnd = true;
}

bool trieSearch(Trie* obj, char* word) {
    Trie* curr = obj;
    while (*word) {
        int idx = *word - 'a';
        if (!curr->children[idx]) return false;
        curr = curr->children[idx];
        word++;
    }
    return curr->isEnd;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    Trie* curr = obj;
    while (*prefix) {
        int idx = *prefix - 'a';
        if (!curr->children[idx]) return false;
        curr = curr->children[idx];
        prefix++;
    }
    return true;
}

void trieFree(Trie* obj) {
    if (!obj) return;
    for (int i = 0; i < 26; i++) {
        if (obj->children[i]) trieFree(obj->children[i]);
    }
    free(obj);
}
