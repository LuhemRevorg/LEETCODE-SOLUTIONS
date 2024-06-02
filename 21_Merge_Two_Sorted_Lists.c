/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
        
    if (!list1 && !list2) return NULL;
    else if (!list1) return list2;
    else if (!list2) return list1;

    struct ListNode* head = NULL;
    struct ListNode* next = NULL;
    if (list2->val > list1->val) {head = list1; list1 = list1->next;}
    else {head = list2; list2 = list2->next;}
    struct ListNode* l = head;
    while (list1 || list2) {
        if (!list1) {next = list2; list2 = list2->next;}
        else if (!list2) {next = list1; list1 = list1->next;}
        else if (list2->val > list1->val) {next = list1; list1 = list1->next;}
        else {next = list2; list2 = list2->next;}

        l->next = next;
        l = l->next;

    }
    return head;

}