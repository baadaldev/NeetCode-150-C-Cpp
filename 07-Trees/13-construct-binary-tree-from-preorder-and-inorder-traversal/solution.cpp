/**
 * LeetCode 105: Construct Binary Tree from Preorder and Inorder Traversal
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    std::unordered_map<int, int> inMap;
    TreeNode* build(const std::vector<int>& pre, int preL, int preR, int inL, int inR) {
        if (preL > preR || inL > inR) return nullptr;
        TreeNode* root = new TreeNode(pre[preL]);
        int inRoot = inMap[root->val];
        int leftCount = inRoot - inL;
        root->left = build(pre, preL + 1, preL + leftCount, inL, inRoot - 1);
        root->right = build(pre, preL + leftCount + 1, preR, inRoot + 1, inR);
        return root;
    }
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        for (int i = 0; i < (int)inorder.size(); ++i) inMap[inorder[i]] = i;
        return build(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
