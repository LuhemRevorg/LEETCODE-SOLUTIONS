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
    bool compareTrees(TreeNode *node, TreeNode* subNode) {
        if(!node && !subNode) return true;
        if(!node || !subNode) return false;
        if(node->val == subNode->val) return compareTrees(node->left, subNode->left) && compareTrees(node->right, subNode->right);
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;
        if (compareTrees(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
