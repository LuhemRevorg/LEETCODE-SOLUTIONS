/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* recurse(ListNode* node, ListNode*& front) {
        if (!node) return nullptr;
        
        recurse(node->next, front);
        
        if (!front) return nullptr;
        
        if (front == node || front->next == node) {
            node->next = nullptr;
            front = nullptr;
            return nullptr;
        }
        
        ListNode* next_front = front->next;
        front->next = node;
        node->next = next_front;
        front = next_front;
        
        return nullptr;
    }
    
    void reorderList(ListNode* head) {
        if (!head) return;
        recurse(head, head);
    }
};
