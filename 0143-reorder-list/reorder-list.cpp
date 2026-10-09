class Solution {
public:
    void reorderList(ListNode* head) {
        std::vector<ListNode*> stck;
        for (ListNode* p = head; p; p = p->next)
            stck.push_back(p);

        int n = stck.size();
        ListNode* curr = head;
        for (int i = 0; i < n / 2; ++i) {
            ListNode* node = stck.back();
            stck.pop_back();
            node->next = curr->next;
            curr->next = node;
            curr = node->next;
        }
        curr->next = nullptr;
    }
};
