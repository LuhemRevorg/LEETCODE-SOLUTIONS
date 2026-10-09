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
    int sumNumbers(TreeNode* root) {
        std::vector<std::string> nos;
        std::string curr = "";

        auto dfs = [&](auto &self, TreeNode* node) {
            if (!node) return;
            curr += std::to_string(node->val);

            if (!node->left && !node->right) nos.emplace_back(curr);
            
            self(self, node->left);
            self(self, node->right);
            curr.pop_back();

        };
        dfs(dfs, root);
        int ans = 0;

        for (auto num : nos) {
            ans += std::stoi(num);
        }

        return ans;
        
    }
};
