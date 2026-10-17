class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        bool m = false;
        
        std::reverse(s.begin(), s.end());

        if (s.back() == '-') {m = true; s.pop_back();}

        unsigned long ans = std::stoul(s);  

        if (ans > (unsigned int)INT_MAX) return 0;
        if (m) ans = -ans;
        return ans;
    }
};
