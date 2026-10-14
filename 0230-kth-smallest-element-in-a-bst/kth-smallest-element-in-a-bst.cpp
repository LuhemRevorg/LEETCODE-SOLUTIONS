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
    int kthSmallest(TreeNode* root, int k) {
        int val = 0;
        int nos = 0;

        auto dfs = [&](this auto &self, TreeNode* node) {
            if (!node) return;
            
            self(node->left);
            ++nos;
            if (nos == k) val = node->val;
            self(node->right);
            
            
        };

        dfs(root);
        return val;

    }
};
