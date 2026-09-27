/**
 * LeetCode 79: Word Search
 * Time Complexity: O(m * n * 4^L)
 * Space Complexity: O(L)
 */
#include <vector>
#include <string>

class Solution {
    bool dfs(std::vector<std::vector<char>>& board, int r, int c, const std::string& word, int idx) {
        if (idx == (int)word.length()) return true;
        if (r < 0 || r >= (int)board.size() || c < 0 || c >= (int)board[0].size() || board[r][c] != word[idx]) {
            return false;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        bool found = dfs(board, r + 1, c, word, idx + 1) ||
                     dfs(board, r - 1, c, word, idx + 1) ||
                     dfs(board, r, c + 1, word, idx + 1) ||
                     dfs(board, r, c - 1, word, idx + 1);
        board[r][c] = temp;
        return found;
    }
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        for (int r = 0; r < (int)board.size(); ++r) {
            for (int c = 0; c < (int)board[0].size(); ++c) {
                if (dfs(board, r, c, word, 0)) return true;
            }
        }
        return false;
    }
};
