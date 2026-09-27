/**
 * LeetCode 572: Subtree of Another Tree
 * Time Complexity: O(s * t)
 * Space Complexity: O(h)
 */
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static bool isSame(struct TreeNode* a, struct TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b || a->val != b->val) return false;
    return isSame(a->left, b->left) && isSame(a->right, b->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (!root) return false;
    if (isSame(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
