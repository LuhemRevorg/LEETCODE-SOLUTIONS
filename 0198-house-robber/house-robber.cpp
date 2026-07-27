class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> store(n+1);
        store[0] = 0;
        store[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            store[i] = std::max(store[i-2] + nums[i-1], store[i-1]); 
        }
        return store.back();
    }
};
