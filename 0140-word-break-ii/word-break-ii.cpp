class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set<string> dict(wordDict.begin(), wordDict.end());

        std::vector<std::vector<bool>> dp(s.length() + 1, std::vector<bool>(s.length() + 1, false));

        for (size_t i = 0; i < s.length(); ++i) {
            for (size_t j = i + 1; j <= s.length(); ++j) {
                if (dict.contains(s.substr(i, j - i))) dp[i][j] = true;
            }
        }

        std::vector<string> ret;
        string str = "";
        auto backtrack = [&](this auto &self, int prev) {

            if (prev == 0) {ret.emplace_back(str); return;}

            for (size_t i = 0; i < s.length(); ++i) {
                if (dp[i][prev]) {
    string word = s.substr(i, prev - i);
    size_t added = word.size() + (str.empty() ? 0 : 1);  // include the space if one is added
    str = str.empty() ? word : word + " " + str;          // prepend, since we're walking backwards
    self(i);
    str.erase(0, added);                                  // undo from the front
}
            }
            
        };

        backtrack(s.length());

        return ret;
    }
};
