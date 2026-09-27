/**
 * LeetCode 105: Construct Binary Tree from Preorder and Inorder Traversal
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static struct TreeNode* build(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[preStart];
    root->left = NULL;
    root->right = NULL;

    int inRoot = inStart;
    while (inorder[inRoot] != root->val) inRoot++;

    int numsLeft = inRoot - inStart;
    root->left = build(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1);
    root->right = build(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return build(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}
