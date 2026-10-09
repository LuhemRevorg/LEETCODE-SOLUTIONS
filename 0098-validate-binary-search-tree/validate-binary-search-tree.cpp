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
    bool isValidBST(TreeNode* root) {
        auto dfs = [&](auto& self, TreeNode* node, TreeNode* minNode, TreeNode* maxNode) -> bool {
        if (!node) return true;
        
        if ((minNode && node->val <= minNode->val) || 
            (maxNode && node->val >= maxNode->val)) {
            return false;
        }

        return self(self, node->left, minNode, node) &&
               self(self, node->right, node, maxNode);
    };

    return dfs(dfs, root, nullptr, nullptr);
}
};
