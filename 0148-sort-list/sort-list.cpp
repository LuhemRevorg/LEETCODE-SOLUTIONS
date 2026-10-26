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
    ListNode* sortList(ListNode* head) {
        // merge sort

        auto merge = [] (ListNode *n1, ListNode* n2) {
            if (!n1) return n2;
            if (!n2) return n1;
            ListNode* root = nullptr;
            if (n1->val < n2->val) {
                root = n1;
                n1 = n1->next;
            } else {
                root=n2;
                n2 = n2->next;
            }
            ListNode* curr = root;

            while(n1 || n2) {
                if (!n1) {curr->next = n2; break;} 
                if (!n2) {curr->next = n1; break;}
                if (n1->val < n2->val) {
                    curr->next = n1;
                    n1 = n1->next;
                } else {
                    curr->next = n2;
                    n2 = n2->next;
                }
                curr = curr->next;
            }

            return root;
        };

        // For one iteration
        // Find half using fast and slow pointer O(n)
        // Apply sort list on first and second half 
        // merge first and second half O(n)
        // This is O(nlogn)

        auto mergeSort = [&](this auto &self, ListNode* node) -> ListNode* {
            if (!node || !node->next) return node;
            ListNode* slow = node, *fast = node->next;
            
            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            auto n2 = slow->next;
            slow->next = nullptr;
            return merge(self(node), self(n2));
        };

        return mergeSort(head);
    }
};
