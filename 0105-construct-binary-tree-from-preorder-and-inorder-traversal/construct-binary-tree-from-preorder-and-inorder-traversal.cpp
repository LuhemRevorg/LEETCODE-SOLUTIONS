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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        std::unordered_map<int, int> store;
        for (int i = 0; i < inorder.size(); ++i) store[inorder[i]] = i;

        auto build = [&](this auto& self, int preStart, int preEnd, int inStart, int inEnd) -> TreeNode* {
            if (preStart > preEnd || inStart > inEnd) return nullptr;

            TreeNode* node = new TreeNode(preorder[preStart]);
            
            int pos = store[node->val];
            int left = pos- inStart;

            node->left = self(preStart+1, preStart+left, inStart, pos-1);
            node->right = self(preStart+left+1, preEnd, pos + 1, inEnd);

            return node;
        };

        TreeNode* root = build(0, preorder.size()-1, 0, inorder.size()-1);
        return root;
    }
};
