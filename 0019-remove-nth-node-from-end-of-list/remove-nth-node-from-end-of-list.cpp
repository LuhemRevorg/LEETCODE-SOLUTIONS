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
    ListNode* recurse(ListNode* prev ,ListNode* head, int &n) {
        if(!head) return nullptr;
        recurse(head ,head->next, n);
        if (--n == 0 && prev) {prev->next=head->next; delete head; return prev;}
        if (n==0) {
            ListNode* cpy = head->next;
            delete head;
            return cpy;
        }
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       return recurse(nullptr, head, n);
    }
};
