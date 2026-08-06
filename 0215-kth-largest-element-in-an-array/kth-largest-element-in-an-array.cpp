class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> store;
        for (auto i : nums) {
            if (store.size() < k || i > store.top()) store.push(i);
            if (store.size() > k) store.pop();
        }
        return store.top();
    }
};
