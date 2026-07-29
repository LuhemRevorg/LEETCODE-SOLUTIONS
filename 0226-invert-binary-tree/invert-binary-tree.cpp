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
    TreeNode* invertTree(TreeNode* root) {
        std::queue<TreeNode*> q;

        if(root) q.push(root);
        while(!q.empty()) {
            TreeNode* curr= q.front(); q.pop();
            std::swap(curr->left,curr->right);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return root;
        
    }
};
