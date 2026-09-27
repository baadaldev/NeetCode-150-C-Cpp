/**
 * LeetCode 199: Binary Tree Right Side View
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static void dfs(struct TreeNode* root, int depth, int* res, int* size) {
    if (!root) return;
    if (depth == *size) {
        res[(*size)++] = root->val;
    }
    dfs(root->right, depth + 1, res, size);
    dfs(root->left, depth + 1, res, size);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;
    dfs(root, 0, res, returnSize);
    return res;
}
