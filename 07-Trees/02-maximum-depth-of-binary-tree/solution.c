/**
 * LeetCode 104: Maximum Depth of Binary Tree
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + MAX(maxDepth(root->left), maxDepth(root->right));
}
