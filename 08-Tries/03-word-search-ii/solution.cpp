/**
 * LeetCode 212: Word Search II
 * Time Complexity: O(m * n * 4^L)
 * Space Complexity: O(total chars)
 */
#include <vector>
#include <string>

class Solution {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        std::string word = "";
    };

    void insert(TrieNode* root, const std::string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->word = word;
    }

    void dfs(std::vector<std::vector<char>>& board, int r, int c, TrieNode* node, std::vector<std::string>& res) {
        char ch = board[r][c];
        if (ch == '#' || !node->children[ch - 'a']) return;
        node = node->children[ch - 'a'];
        if (!node->word.empty()) {
            res.push_back(node->word);
            node->word = "";
        }
        board[r][c] = '#';
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < (int)board.size() && nc >= 0 && nc < (int)board[0].size()) {
                dfs(board, nr, nc, node, res);
            }
        }
        board[r][c] = ch;
    }
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        TrieNode* root = new TrieNode();
        for (const auto& w : words) insert(root, w);
        std::vector<std::string> res;
        for (int r = 0; r < (int)board.size(); ++r) {
            for (int c = 0; c < (int)board[0].size(); ++c) {
                dfs(board, r, c, root, res);
            }
        }
        return res;
    }
};
