/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *l = head;
    
    int length = 0;

    while (l) {
        l = l->next;
        ++length;
    }

    if (length == 1) {
        return NULL;
    }

    l = head;
    
    if (length - n == 0) {
        struct ListNode *save = l->next;
        free(l);
        return save;
    }

    while (length - n - 1 > 0){
        l = l->next;
        n++;
    }
    struct ListNode *save = l->next;

    l->next = l->next->next;

    free(save);

    return head;

 }