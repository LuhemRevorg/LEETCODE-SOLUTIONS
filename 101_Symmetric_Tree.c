/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool recurse(struct TreeNode *left, struct TreeNode* right) {
    
    
    if (left && right) {
        return recurse(left->left, right->right) && recurse(left->right, right->left) && left->val == right->val;
    } else if (!left && !right){
        return true;
    } else return false;

}

bool isSymmetric(struct TreeNode* root) {
    return recurse(root->left, root->right);
}