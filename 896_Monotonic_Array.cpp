/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



void give_leaf(struct TreeNode *root, int *store, int *pos) {

    if (!root) {
        return;
    }

    if (!root->left && !root->right) {

        *(store + *pos) = root->val;
        ++(*pos);
        return;
    }
    
    give_leaf(root->left, store, pos);
    give_leaf(root->right, store, pos);


}





bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int pos1 = 0;
    int arr1[100] = {0};
    int arr2[100] = {0};
    int pos2 = 0;


    give_leaf(root1, arr1, &pos1);
    give_leaf(root2, arr2, &pos2);


    if (pos1 != pos2) return false;
    
    for (int i = 0; i < 100; ++i) {
        if (*(arr1 + i) != *(arr2 + i)) {
            return false;
        }
    }

    return true;

}