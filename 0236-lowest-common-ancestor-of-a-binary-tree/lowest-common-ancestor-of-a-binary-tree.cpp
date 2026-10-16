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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool seen_p = false;
        bool seen_q = false;
        TreeNode *lca = nullptr;

        auto dfs = [&](this auto& self, TreeNode* node) -> std::pair<bool, bool> {
            if (!node) return {false, false};

            auto ans_left = self(node->left);
            auto ans_right = self(node->right);

            if (node == p && (ans_left.second || ans_right.second)) {lca = node; return {false, false};}
            else if (node == q && (ans_left.first || ans_right.first)) {lca = node; return {false, false};}
            else if ((ans_left.first && ans_right.second) || (ans_left.second && ans_right.first)) {lca = node; return {false, false};}

            if (node==p) return {true, false};
            if (node == q) return {false, true};
            
            return {ans_left.first || ans_right.first, ans_left.second  || ans_right.second};
            
        };

        dfs(root);

        return lca;
    }
};
