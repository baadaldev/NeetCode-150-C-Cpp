/**
 * LeetCode 235: Lowest Common Ancestor of a Binary Search Tree
 * Time Complexity: O(h)
 * Space Complexity: O(1)
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        while (curr) {
            if (p->val < curr->val && q->val < curr->val) curr = curr->left;
            else if (p->val > curr->val && q->val > curr->val) curr = curr->right;
            else return curr;
        }
        return nullptr;
    }
};
