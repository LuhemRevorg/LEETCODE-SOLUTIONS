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

    void traverse(int &count, TreeNode *node, int max) {
        if (!node) return;
        if (node->val >= max) ++count;
        traverse(count, node->left, std::max(max, node->val));
        traverse(count, node->right, std::max(max, node->val));
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        traverse(count, root, root->val);
        return count;
    }
};
