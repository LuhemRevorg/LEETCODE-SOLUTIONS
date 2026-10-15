class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> store;
        int start = 0; 
        int mx = 0;

        for (int end = 0; end < s.length(); ++end) {
            while (store.contains(s[end])) {store.erase(s[start]); ++start;}
            store.insert(s[end]);
            mx = max(end-start + 1, mx);
        }

        return mx;
    }
};
