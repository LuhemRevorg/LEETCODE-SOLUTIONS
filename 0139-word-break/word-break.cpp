class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set<string> dict(wordDict.begin(), wordDict.end());

        std::vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (size_t i = 0; i < s.length(); ++i) {
            if (dp[i]) {
                for(size_t j = i + 1; j <= s.length(); ++j) {
                    if (dict.contains(s.substr(i, j - i))) dp[j] = true;
                }
            }
        }

        return dp.back();
    }
};
