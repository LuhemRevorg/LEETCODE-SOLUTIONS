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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> store;
        ListNode *ret = nullptr;
        ListNode *curr = nullptr;
        
        auto removeFront = [&](int i) {
            lists[i] = lists[i]->next;
        };

        auto addBack = [&](int val) {
            if (curr) {
                curr->next = new ListNode(val);
                curr = curr->next;
            } else {
                ret=new ListNode(val);
                curr = ret;
            }
        };

        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i]) {
                store.push({lists[i]->val, i});
                removeFront(i);
            }
        }

        while(!store.empty()) {
            auto candidate = store.top();
            addBack(candidate.first);
            if (lists[candidate.second]) {
                store.push({lists[candidate.second]->val, candidate.second});
                removeFront(candidate.second);
            }
            store.pop();

        }

        return ret;
    }
};
