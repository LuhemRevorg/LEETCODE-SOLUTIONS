class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int sum = 0;
        int n = nums.size();
        
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int start = i + 1;
            int end = n - 1;
            
            while (start < end) {
                int curr = nums[i] + nums[start] + nums[end];
                if (curr == target) {
                    return target;
                }
                
                long long d = std::abs(static_cast<long long>(target) - static_cast<long long>(curr));
                if (diff > d) {
                    diff = d;
                    sum = curr;
                } 
                
                if (curr < target) {
                    ++start;
                } else {
                    --end;
                }
            }
        }
        return sum;
    }
};
