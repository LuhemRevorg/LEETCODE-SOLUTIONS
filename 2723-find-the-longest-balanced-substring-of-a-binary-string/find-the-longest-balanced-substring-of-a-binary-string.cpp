class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        size_t curr = 0;
        auto len = s.length();

        auto count_zeroes = [&]() {
            int count = 0;
            while(curr < len && s[curr] == '0') {++count; ++curr;}
            return count;
        };
        auto count_ones = [&]() {
            int count = 0;
            while(curr < len && s[curr] == '1') {++count; ++curr;}
            return count;
        };

        int ans = 0;

        while(curr < len) {
            ans = max(ans, 2*min(count_zeroes(), count_ones()));
        }

        return ans;


    }
};
