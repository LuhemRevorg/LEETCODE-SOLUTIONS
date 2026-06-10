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
    ListNode* reverseList(ListNode* head) {
        if (!(head)) {return head;}
        ListNode *curr = head;
        ListNode *nxt = head->next;
        head->next = nullptr;
        while(nxt) {
            ListNode *save = nxt->next;
            nxt->next = curr;
            curr = nxt;
            nxt = save;
        }
        
        return curr;

    }
};
