/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max = 0;
        auto recurse = [&] (this auto &self, TreeNode* node, int curr) {
            if (!node) {max = std::max(max, curr); return;}
            self(node->left, curr + 1);
            self(node->right, curr + 1);
        };

        recurse(root, 0);
        return max;
    }
};
