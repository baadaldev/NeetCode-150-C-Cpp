/**
 * LeetCode 543: Diameter of Binary Tree
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
    int maxDiam = 0;
    int height(TreeNode* root) {
        if (!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        maxDiam = std::max(maxDiam, lh + rh);
        return 1 + std::max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiam;
    }
};
