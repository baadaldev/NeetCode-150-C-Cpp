/**
 * LeetCode 208: Implement Trie (Prefix Tree)
 * Time Complexity: O(L)
 * Space Complexity: O(N * L)
 */
#include <string>
#include <vector>

class Trie {
    struct Node {
        Node* children[26] = {nullptr};
        bool isEnd = false;
    };
    Node* root;
public:
    Trie() { root = new Node(); }
    
    void insert(std::string word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = new Node();
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(std::string word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) return false;
            curr = curr->children[idx];
        }
        return curr->isEnd;
    }
    
    bool startsWith(std::string prefix) {
        Node* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!curr->children[idx]) return false;
            curr = curr->children[idx];
        }
        return true;
    }
};
