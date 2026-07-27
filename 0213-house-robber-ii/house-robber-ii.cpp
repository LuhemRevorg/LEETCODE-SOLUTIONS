class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if (n==1) return nums[0];
        std::vector<int> store(n+1);
        std::vector<int> storage(n+1);
        
        store[0]=0;
        store[1]=nums[0];
        storage[0]=0;
        if (n > 1) storage[1]=nums[1];
        else storage[1] = 0;

        for(int i=2; i <= n-1; ++i) {
            store[i] = std::max(store[i-1], store[i-2] + nums[i-1]);
        }
        for(int j=3; j <= n; ++j) {
            storage[j-1] = std::max(storage[j-2], storage[j-3] + nums[j-1]);
        }

        return std::max(storage[n-1], store[n-1]);

    }
};
