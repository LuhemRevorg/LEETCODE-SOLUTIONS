/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* traverse(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(!node) return nullptr;
        if(node->val >= q->val && node->val <= p->val) return node;
        if (node->val >= q->val) return traverse(node->left, p, q);
        return traverse(node->right, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // p >= q always
        if (p->val < q->val) std::swap(p,q);
        if (p->val==q->val) return p;
        return traverse(root, p, q);
    }
};
