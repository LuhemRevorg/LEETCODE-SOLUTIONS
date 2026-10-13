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

        std::unordered_map<int, Node*> visited;
        Node *cpy = new Node(node->val);
        visited[node->val] = cpy;
        
        auto bfs = [&](Node* n) {
            std::queue<Node*> q;
            
            for (auto i : n->neighbors) {
                q.push(i);
                visited[i->val] = new Node(i->val);
                cpy->neighbors.push_back(visited[i->val]);
            }
            
            while(!q.empty()) {
                Node* top = q.front(); q.pop();
                for (auto i : top->neighbors) {
                    Node * c = nullptr;
                    if (visited.contains(i->val)) c = visited[i->val];
                    else {c = new Node(i->val); visited[i->val] = c; q.push(i);}
                    visited[top->val]->neighbors.push_back(c);
                }
            }
        };

        bfs(node);

        return cpy;

    }
};
