class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        
        std::vector<int> dp(costs.size() + 3, 10*10*10*10*10*10*1000);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 0;

        for (int i = 0; i < costs.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[i+3] = std::min(dp[i+3], dp[i+j] + costs[i] + (3-j)*(3-j));
            }
        }

        return dp.back();

    }
};
