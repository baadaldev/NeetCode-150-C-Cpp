/**
 * LeetCode 297: Serialize and Deserialize Binary Tree
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <string>
#include <sstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
    void serialize(TreeNode* root, std::ostringstream& out) {
        if (!root) { out << "# "; return; }
        out << root->val << ' ';
        serialize(root->left, out);
        serialize(root->right, out);
    }

    TreeNode* deserialize(std::istringstream& in) {
        std::string val;
        in >> val;
        if (val == "#") return nullptr;
        TreeNode* root = new TreeNode(std::stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
public:
    std::string serialize(TreeNode* root) {
        std::ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(std::string data) {
        std::istringstream in(data);
        return deserialize(in);
    }
};
