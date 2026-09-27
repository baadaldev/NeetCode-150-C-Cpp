/**
 * LeetCode 230: Kth Smallest Element in a BST
 * Time Complexity: O(h + k)
 * Space Complexity: O(h)
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static void inorder(struct TreeNode* root, int* k, int* ans) {
    if (!root || *k <= 0) return;
    inorder(root->left, k, ans);
    (*k)--;
    if (*k == 0) {
        *ans = root->val;
        return;
    }
    inorder(root->right, k, ans);
}

int kthSmallest(struct TreeNode* root, int k) {
    int ans = 0;
    inorder(root, &k, &ans);
    return ans;
}
