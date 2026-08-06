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

     int dfs(TreeNode* node, int k, int &val, bool &found) {
        if (!node) return 0;
        if (found) return 0;
        int total = dfs(node->left, k, val, found);
        if (found) return 0;
        if (++total == k) { found = true; val = node->val; return 0; }
        total += dfs(node->right, k - total, val, found);
        return total;
    }

    int kthSmallest(TreeNode* root, int k) {
        int val = 0;
        bool found = false;
        int total = dfs(root, k, val, found);
        return val;
    }
};
