/**
 * LeetCode 98: Validate Binary Search Tree
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static bool validate(struct TreeNode* root, long long minB, long long maxB) {
    if (!root) return true;
    if (root->val <= minB || root->val >= maxB) return false;
    return validate(root->left, minB, root->val) && validate(root->right, root->val, maxB);
}

bool isValidBST(struct TreeNode* root) {
    return validate(root, -2147483649LL, 2147483648LL);
}
