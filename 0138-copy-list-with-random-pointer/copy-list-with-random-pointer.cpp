/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        std::unordered_map<Node*, Node*> store;
        Node* cpy_head = new Node(head->val);
        Node* cpy_itr = cpy_head;
        store[head] = cpy_itr;

        while(head->next) {
            if(store.contains(head->next)) cpy_itr->next = store[head->next];  
            else {cpy_itr->next = new Node(head->next->val); store[head->next] = cpy_itr->next;}
            if(head->random){
                if(store.contains(head->random)) cpy_itr->random = store[head->random];  
                else {cpy_itr->random = new Node(head->random->val); store[head->random] = cpy_itr->random;}
            }
            cpy_itr=cpy_itr->next;
            head=head->next;
        }
        if(head->random) store.contains(head->random) ? cpy_itr->random = store[head->random] : cpy_itr->random = new Node(head->random->val);

        return cpy_head;
    }
};
