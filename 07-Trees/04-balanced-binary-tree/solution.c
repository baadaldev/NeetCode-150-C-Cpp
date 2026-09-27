/**
 * LeetCode 110: Balanced Binary Tree
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
#include <stdbool.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int check(struct TreeNode* root) {
    if (!root) return 0;
    int left = check(root->left);
    if (left == -1) return -1;
    int right = check(root->right);
    if (right == -1) return -1;
    if (abs(left - right) > 1) return -1;
    return 1 + MAX(left, right);
}

bool isBalanced(struct TreeNode* root) {
    return check(root) != -1;
}
