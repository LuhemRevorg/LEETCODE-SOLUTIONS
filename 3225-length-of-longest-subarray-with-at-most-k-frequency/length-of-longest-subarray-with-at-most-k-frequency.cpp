class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> tracker;
        int i = 0;
        int max_len = 0;

        for (int end = 0; end < nums.size(); ++end) {
            
            tracker[nums[end]]++;

            
            while (tracker[nums[end]] > k) {
                tracker[nums[i]]--;
                i++;
            }

            
            max_len = std::max(max_len, end - i + 1);
        }

        return max_len;
    }
};
