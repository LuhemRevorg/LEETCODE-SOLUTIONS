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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> ret;

        auto bfs = [&](this auto &self, TreeNode* node) {
            // node, level
            std::queue<std::pair<TreeNode*, int>> q;
            if (node) q.push({node, 0});

            while(!q.empty()) {
                auto [top, level] = q.front(); q.pop();
                if (level == ret.size()) ret.push_back(top->val);

                if (top->right) q.push({top->right, level+1});
                if (top->left) q.push({top->left, level+1});
            }
        };

        bfs(root);
        return ret;
        
    }
};
