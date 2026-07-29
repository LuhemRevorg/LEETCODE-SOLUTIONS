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
    int check(TreeNode *root) {
        if(!root) return 0;
        int left = check(root->left);
        int right = check(root->right);
        if (left == -1 || right ==-1) return -1;
        if (left==right || left + 1 == right || right+1==left) return std::max(left, right)+1;
        else return -1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if (check(root)==-1) return false;
        return true;  
    }
};
