/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool check(struct TreeNode *p, struct TreeNode *q) {

    if (!p && !q) return true;

    if ((!p && q) || (p && !q)) return false;

    if (p->val == q->val && check(p->left, q->left) && check(p->right, q->right)) return true;

    return false;


}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    
    return check(p, q);

}