/**
 * LeetCode 211: Design Add and Search Words Data Structure
 * Time Complexity: Add O(L), Search O(26^d)
 * Space Complexity: O(N * L)
 */
#include <string>

class WordDictionary {
    struct Node {
        Node* children[26] = {nullptr};
        bool isEnd = false;
    };
    Node* root;

    bool searchInNode(const std::string& word, int idx, Node* node) {
        if (!node) return false;
        if (idx == (int)word.length()) return node->isEnd;
        char c = word[idx];
        if (c == '.') {
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] && searchInNode(word, idx + 1, node->children[i])) return true;
            }
            return false;
        } else {
            return searchInNode(word, idx + 1, node->children[c - 'a']);
        }
    }
public:
    WordDictionary() { root = new Node(); }
    
    void addWord(std::string word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = new Node();
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(std::string word) {
        return searchInNode(word, 0, root);
    }
};
