class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        vector<long long> pre(n + 1, 0), suf(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = (pre[i] + nums[i]) % p;
        for (int j = n - 1; j >= 0; j--) suf[j] = (suf[j + 1] + nums[j]) % p;

        if (pre[n] == 0) return 0;

        unordered_map<long long, int> last;
        int best = n;

        for (int j = 0; j <= n; j++) {
            last[pre[j]] = j;                       
            long long need = (p - suf[j]) % p;      
            auto it = last.find(need);
            if (it != last.end())
                best = min(best, j - it->second);   
        }

        return best == n ? -1 : best;
    }
};
