/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    int length1 = 0;
    int length2 = 0;
    struct ListNode *a = l1;
    struct ListNode *b = l2;
    struct ListNode *ret = NULL;
    
    while (a) {
        ++length1;
        a = a->next;
    }

    while (b) {
        ++length2;
        b = b->next;
    }

    a = l1;
    b = l2;
    ret = l1;

    if (length1 != length2) {
        if (length2 > length1) { 
            a = l2;
            b = l1;
            ret = l2;
        }

        while (a || b) {
            if (b) {
                int result = a->val + b->val;
                a->val = result % 10;

                if (result >= 10 && a->next) {
                    ++a->next->val;
                } else if (result >= 10) {
                    a->next = malloc(sizeof(struct ListNode));
                    a->next->val = 1;
                    a->next->next = NULL;
                }


                a = a->next;
                b = b->next;

            } else {
                while (a) {
                    if (a->val >= 10 && a->next) {
                        a->val %= 10;
                        ++a->next->val;
                    } else if (a->val >= 10) {
                        a->val %= 10;
                        a->next = malloc(sizeof(struct ListNode));
                        a->next->val = 1;
                        a->next->next = NULL;
                    }

                    a = a->next;
                }
                
                return ret;
            }
        }

    } else {
        
        while (b) {
            int result = a->val + b->val;
            a->val = result % 10;

            if (result >= 10 && a->next) {
                ++a->next->val;
            } else if (result >= 10) {
                a->next = malloc(sizeof(struct ListNode));
                a->next->val = 1;
                a->next->next = NULL;
            }


            a = a->next;
            b = b->next;
        }
        
    }
    return l1;

}