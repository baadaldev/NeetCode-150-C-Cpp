/**
 * LeetCode 543: Diameter of Binary Tree
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int height(struct TreeNode* root, int* maxDiam) {
    if (!root) return 0;
    int lh = height(root->left, maxDiam);
    int rh = height(root->right, maxDiam);
    if (lh + rh > *maxDiam) *maxDiam = lh + rh;
    return 1 + MAX(lh, rh);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int maxDiam = 0;
    height(root, &maxDiam);
    return maxDiam;
}
