class KthLargest {
    int k;
    std::priority_queue<int, vector<int>, std::greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums):k{k} {
        int i = 0;
        while(i < nums.size() && pq.size() < k) {
            pq.push(nums[i]);
            ++i;
        }
        while(i < nums.size()) {
            if(nums[i]>pq.top()) {pq.pop(); pq.push(nums[i]);}
            ++i;
        }
    }
    
    int add(int val) {
        if(pq.size() < k) pq.push(val);
        else if (pq.top() < val) {pq.pop(); pq.push(val);}

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
