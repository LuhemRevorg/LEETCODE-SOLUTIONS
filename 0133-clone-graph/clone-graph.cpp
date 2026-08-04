/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        std::unordered_map<Node* , Node*> visited;
        
        std::function<void(Node*, Node*)> dfs = [&](Node* nde, Node* nde_copy) {
            visited[nde] = nde_copy;
            for (auto child : nde->neighbors) {
                if (!visited.contains(child)) {
                    Node* child_copy = new Node(child->val);
                    nde_copy->neighbors.emplace_back(child_copy);
                    dfs(child, child_copy);
                } else {
                    nde_copy->neighbors.emplace_back(visited[child]);
                }
            }
        };



        Node* first_copy = new Node(node->val); 
        dfs(node, first_copy);

        return first_copy;

    }
};
