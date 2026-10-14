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
    int goodNodes(TreeNode* root) {
        int count = 0;
        auto traverse = [&](this auto &self, TreeNode* node, int val) {
            if (!node) return;
            
            if (node->val >= val) {
                ++count;
                val = node->val;
            }

            self(node->left, val);
            self(node->right, val);
        };
        traverse(root, root->val);
        return count;
    }
};
