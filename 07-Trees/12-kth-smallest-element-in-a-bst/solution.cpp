/**
 * LeetCode 230: Kth Smallest Element in a BST
 * Time Complexity: O(h + k)
 * Space Complexity: O(h)
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void inorder(TreeNode* root, int& k, int& ans) {
        if (!root || k <= 0) return;
        inorder(root->left, k, ans);
        if (--k == 0) { ans = root->val; return; }
        inorder(root->right, k, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        inorder(root, k, ans);
        return ans;
    }
};
