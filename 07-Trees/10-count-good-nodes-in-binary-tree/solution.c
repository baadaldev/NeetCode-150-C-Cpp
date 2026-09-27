/**
 * LeetCode 1448: Count Good Nodes in Binary Tree
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int dfs(struct TreeNode* root, int maxVal) {
    if (!root) return 0;
    int count = (root->val >= maxVal) ? 1 : 0;
    maxVal = MAX(maxVal, root->val);
    count += dfs(root->left, maxVal);
    count += dfs(root->right, maxVal);
    return count;
}

int goodNodes(struct TreeNode* root) {
    if (!root) return 0;
    return dfs(root, root->val);
}
