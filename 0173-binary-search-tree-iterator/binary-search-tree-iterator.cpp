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
class BSTIterator {
    std::stack<TreeNode*> lst;
    void pushl(TreeNode* node) {
        while(node) {
            lst.push(node);
            node=node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushl(root);
    }
    
    int next() {
        auto node = lst.top(); lst.pop();
        pushl(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return lst.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
