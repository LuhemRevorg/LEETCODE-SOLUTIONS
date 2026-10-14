class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums) sum += i;
        if (sum % 2 != 0) return false;

        std::vector<bool> dp(sum / 2 + 1, false);
        dp[0] = true;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = sum / 2; j >= nums[i]; --j) {
                if (dp[j-nums[i]]) dp[j] = true;
            }
        }

        return dp.back();
        
    }
};
