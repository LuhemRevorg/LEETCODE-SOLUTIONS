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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        auto formTree = [&] (this auto& self, std::vector<int>::iterator left, std::vector<int>::iterator right) -> TreeNode* {
            if (left == right) return nullptr;
            auto mx = std::max_element(left, right);
            auto node = new TreeNode(*mx);
            node->left = self(left, mx);
            node->right = self(std::next(mx), right);
            return node;
        };
        return formTree(nums.begin(), nums.end());
    }
};
