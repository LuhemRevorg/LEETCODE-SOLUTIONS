/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool rec(struct TreeNode* n, int targetSum, int prev) {

    if (n) {
        if (prev + n->val == targetSum && !(n->left) && !(n->right)) return true;
        else return rec(n->left, targetSum, prev + n ->val) || rec(n->right, targetSum, prev + n->val);
    }

    return false;

}



bool hasPathSum(struct TreeNode* root, int targetSum) {
    return rec(root, targetSum, 0);
}