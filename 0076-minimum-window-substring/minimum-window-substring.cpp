#include <limits>

class Solution {
public:

    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        int start = 0, end = 0;
        int count = 0;
        int best = INT_MAX;
        std::pair<int, int> pr = {INT_MAX, INT_MAX};
        vector<int> store(52, INT_MIN);

        auto getStore = [&](char c) -> int& {
            if (c >= 'a' && c <= 'z') {
                return store[c-'a'];
            } else {
                return store[c-'A'+26];
            }
        };

        for (auto c : t) {
            int &val = getStore(c);
            if (val == INT_MIN) {
                val = 1;
            } else ++val;
        }
        
        auto decStore = [&](char c) {
            if (c >= 'a' && c <= 'z') {
                --store[c-'a'];
            } else {
                --store[c-'A'+26];
            }
        };

        auto incStore = [&](char c) {
            if (c >= 'a' && c <= 'z') {
                ++store[c-'a'];
            } else {
                ++store[c-'A'+26];
            }
        };

        while(end < m || count >= n) {
            if (count == n) {
                if (getStore(s[start]) != INT_MIN) {
                    if (getStore(s[start]) >= 0) --count;
                    incStore(s[start]); 
                }
                if (end - start < best) {
                    pr = {start, end};
                    best = end - start;
                }
                ++start;
            } else if (end == start) {
                if (getStore(s[end]) != INT_MIN) {
                    decStore(s[end]);
                    ++count;
                }
                ++end;
            } else if (getStore(s[end]) != INT_MIN) {
                if (getStore(s[end]) > 0) ++count;
                decStore(s[end]);
                ++end;
            } else ++end;
        }

        if (best == INT_MAX) return "";
        return s.substr(pr.first, pr.second - pr.first);
    
    }
};
