/**
 * LeetCode 110: Balanced Binary Tree
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
#include <cmath>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int check(TreeNode* root) {
        if (!root) return 0;
        int l = check(root->left);
        if (l == -1) return -1;
        int r = check(root->right);
        if (r == -1) return -1;
        if (std::abs(l - r) > 1) return -1;
        return 1 + std::max(l, r);
    }
public:
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};
