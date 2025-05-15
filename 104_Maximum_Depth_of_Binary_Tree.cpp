/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int rec(struct TreeNode* node, int h) {
    if (!node) return h;
    
    int left = rec(node->left, h + 1);
    int right = rec(node->right, h + 1);

    if (left > right) return left;


    return right;
}



int maxDepth(struct TreeNode* root) {
    
    return rec(root, 0);

}