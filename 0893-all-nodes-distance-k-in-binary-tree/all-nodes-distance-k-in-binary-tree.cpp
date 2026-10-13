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
   vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ret;
    vector<pair<TreeNode*, int>> path; // (ancestor, side the target is on)

    auto dist_calc = [&](this auto &self, TreeNode *node) -> bool {
        if (!node) return false;
        if (node == target) return true;
        if (self(node->left))  { path.push_back({node, 1}); return true; }
        if (self(node->right)) { path.push_back({node, 2}); return true; }
        return false;
    };

    auto level_adder = [&](this auto &self, TreeNode *node, int dist) {
        if (!node || dist < 0) return;
        if (dist == 0) {ret.push_back(node->val); return;}
        self(node->left, dist-1); self(node->right, dist-1);
    };

    dist_calc(root);

    // path[0] = target's parent, path[1] = grandparent, ..., path.back() = root
    for (int i = 0; i < path.size(); i++) {
        auto [anc, side] = path[i];
        int distance = i + 1;
        if (distance == k) ret.push_back(anc->val);
        else if (distance < k) {
            if (side==1) level_adder(anc->right, k - distance - 1);
            else level_adder(anc->left, k - distance - 1);
        }
    }

    level_adder(target, k);

    return ret;
}
};
