class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        int maxLen = 0;
        for (auto& w : wordDict) maxLen = max(maxLen, (int)w.size());

        vector<bool> dp(n + 1, false);
        dp[0] = true;  // empty prefix is trivially breakable

        for (int i = 1; i <= n; ++i) {
            for (int len = 1; len <= min(i, maxLen); ++len) {
                int j = i - len;
                if (dp[j] && dict.count(s.substr(j, len))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
        }
};
