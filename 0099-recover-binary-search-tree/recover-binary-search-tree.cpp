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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;

        // In-order traversal helper
        auto inorder = [&](auto& self, TreeNode* node) -> void {
            if (!node) return;

            self(self, node->left);

            // Detect order violation
            if (prev && prev->val > node->val) {
                if (!first) {
                    first = prev; // First misplaced node
                }
                second = node;   // Second misplaced node (updates on 2nd violation if non-adjacent)
            }
            prev = node;

            self(self, node->right);
        };

        inorder(inorder, root);

        // Swap back the values of the two misplaced nodes
        if (first && second) {
            std::swap(first->val, second->val);
        }
    }
};
