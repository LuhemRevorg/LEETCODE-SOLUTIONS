/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    struct ListNode *l = head;
    struct ListNode *ret = head->next;
    
    struct ListNode *save = l->next;
        l->next = l->next->next;
        save->next = l;
        struct ListNode *saver = l;
        l = l->next;

    while (l && l->next) {
        struct ListNode *save = l->next;
        saver->next = save;
        l->next = l->next->next;
        save->next = l;
        saver = l;
        l = l->next;
    }

    return ret;

}