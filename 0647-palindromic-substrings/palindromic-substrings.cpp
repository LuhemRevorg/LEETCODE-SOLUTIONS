class Solution {
public:

    int helper(string &s, int l, int r, int n) {
        int count = 0;
        while(l >= 0 && r < n && (s[l] == s[r])) {++count; --l; ++r;}
        return count;
    }

    int countSubstrings(string s) {

        int count = 0;
        int n = s.length();

        for (int center = 0; center < n; ++center) {
            count+=helper(s, center, center, n);
            count+=helper(s, center, center+1, n);
        }
        return count;
    }
};
