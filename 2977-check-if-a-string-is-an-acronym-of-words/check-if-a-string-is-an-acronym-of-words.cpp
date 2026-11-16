class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (words.size()!=s.length()) return false;
        for (auto i = 0; i < words.size(); ++i) if (words[i].length()==0 || s[i]!=words[i][0]) return false;
        return true;
    }
};
