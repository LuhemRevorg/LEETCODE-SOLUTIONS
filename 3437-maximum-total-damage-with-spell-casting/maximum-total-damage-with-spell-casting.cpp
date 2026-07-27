class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        std::sort(power.begin(), power.end());
        int n = power.size();

        std::vector<int> vals;
        std::vector<long long> sum;
        for (int i = 0; i < n; ) {
            int j = i;
            long long s = 0;
            while (j < n && power[j] == power[i]) {
                s += power[j];
                ++j;
            }
            vals.push_back(power[i]);
            sum.push_back(s);
            i = j;
        }

        int m = vals.size();
        std::vector<long long> dp(m);
        dp[0] = sum[0];

        for (int k = 1; k < m; ++k) {
            int idx = std::upper_bound(vals.begin(), vals.begin() + k, vals[k] - 3) - vals.begin() - 1;
            long long take = sum[k] + (idx >= 0 ? dp[idx] : 0);
            dp[k] = std::max(dp[k - 1], take);
        }

        return dp[m - 1];
    }
};
