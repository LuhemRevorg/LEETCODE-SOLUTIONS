class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> store;

        for (auto c : s1) {
            if (store.contains(c)) ++store[c];
            else store[c] = 1;
        }

        int start = 0;
        int end = 0;
        int count = 0;
        int n = s1.length();
        
        while(end < s2.length()) {
            if (count == n) break;
            
            if (store.contains(s2[end]) && store[s2[end]])  {++count; --store[s2[end]]; ++end;}
            else if (store.contains(s2[end])) {
                if (store.contains(s2[start])) {--count; ++store[s2[start]];}
                ++start;
            }
            else if (start == end) ++end;
            else if (store.contains(s2[start])) {--count; ++store[s2[start]]; ++start;}
            else ++start;
        }

        return count == n;

    }
};
