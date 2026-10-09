class KthLargest {
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> store;
public:
    KthLargest(int k, vector<int>& nums): k{k} { 
        for (auto i : nums) {
            if (store.size() < k) {
                store.push(i);
            } else if (store.top() < i) {
                store.pop();
                store.push(i);
            }
        }
    }
    
    int add(int val) {
        if (store.size() < k) {
            store.push(val);
        } else if (store.top() < val) {
            store.pop();
            store.push(val);
        }
        return store.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
