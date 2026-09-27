/**
 * LeetCode 199: Binary Tree Right Side View
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void dfs(TreeNode* root, int depth, std::vector<int>& res) {
        if (!root) return;
        if (depth == (int)res.size()) res.push_back(root->val);
        dfs(root->right, depth + 1, res);
        dfs(root->left, depth + 1, res);
    }
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};
