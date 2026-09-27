/**
 * LeetCode 1448: Count Good Nodes in Binary Tree
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int dfs(TreeNode* root, int maxVal) {
        if (!root) return 0;
        int count = (root->val >= maxVal) ? 1 : 0;
        maxVal = std::max(maxVal, root->val);
        return count + dfs(root->left, maxVal) + dfs(root->right, maxVal);
    }
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, root->val);
    }
};
