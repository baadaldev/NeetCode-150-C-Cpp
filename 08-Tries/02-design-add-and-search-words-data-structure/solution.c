/**
 * LeetCode 211: Design Add and Search Words Data Structure
 * Time Complexity: Add O(L), Search O(26^d)
 * Space Complexity: O(N * L)
 */
#include <stdlib.h>
#include <stdbool.h>

typedef struct WordDictionary {
    struct WordDictionary* children[26];
    bool isEnd;
} WordDictionary;

WordDictionary* wordDictionaryCreate() {
    return (WordDictionary*)calloc(1, sizeof(WordDictionary));
}

void wordDictionaryAddWord(WordDictionary* obj, char* word) {
    WordDictionary* curr = obj;
    while (*word) {
        int idx = *word - 'a';
        if (!curr->children[idx]) curr->children[idx] = wordDictionaryCreate();
        curr = curr->children[idx];
        word++;
    }
    curr->isEnd = true;
}

static bool dfs(WordDictionary* node, char* word) {
    if (!node) return false;
    if (!*word) return node->isEnd;
    if (*word == '.') {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] && dfs(node->children[i], word + 1)) return true;
        }
        return false;
    } else {
        int idx = *word - 'a';
        return dfs(node->children[idx], word + 1);
    }
}

bool wordDictionarySearch(WordDictionary* obj, char* word) {
    return dfs(obj, word);
}
