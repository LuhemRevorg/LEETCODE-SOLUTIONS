class Solution {
public:
    int maxUniqueSplit(string s) {
        std::unordered_set<string> seen;
        int count = 0;
        auto backtrack = [&] (this auto &self, int idx, string &curr) {
            if (idx == s.length()) {
                if (!seen.contains(curr)) count = std::max((int)seen.size(), count);
                return;
            }
            if ((int)seen.size() + (int)(s.length() - idx) + !curr.empty() <= count) return;
            // take character idx in current substr
            curr += s[idx];
            self(idx+1, curr);
            // do not take char
            if (!seen.contains(curr)) {
                string nw_curr = "";
                seen.insert(curr);
                self(idx+1, nw_curr);
                seen.erase(curr);
            }
            curr.pop_back();
        };
        string curr = "";
        backtrack(0, curr);
        return count;
    }
};
