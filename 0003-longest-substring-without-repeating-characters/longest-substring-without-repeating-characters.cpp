class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> store;
        int start = 0, end = 0;
        int size = s.length();
        int max = 0;
        while(end < size) {
            if (store.contains(s[end])) {
                store.erase(s[start]);
                ++start;
            } else {
                store.insert(s[end]);
                ++end;
                max = std::max(max, end-start);
            }
            
        }
        return max;
    }
};
