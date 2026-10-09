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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> ret;
        std::vector<int> nodes;

        auto dfs = [&](auto &self, TreeNode* node, int curr) -> void {
            if (!node) return;
            nodes.emplace_back(node->val);
            curr += node->val;
            if (curr == targetSum && !node->left && !node->right) {
                ret.emplace_back(nodes);
            }
            self(self, node->left, curr);
            self(self, node->right, curr);
            nodes.pop_back();
        };

        dfs(dfs, root, 0);
        return ret;
    }
};
