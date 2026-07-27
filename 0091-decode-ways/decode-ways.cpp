class Solution {
public:
    int numDecodings(string s) {
        std::vector<int> table(s.size()+1, 0);
        if (s[0]=='0') return 0;
        table[0] = 1;
        table[1] = 1;
        for(int i = 2; i < s.size()+1; ++i) {
            if (s[i-1]=='0') {
                if (s[i-2] != '1' && s[i-2] != '2') return 0; 
                table[i] = table[i-2];
            } else if (s[i-2]=='1' || (s[i-2]=='2' && s[i-1] - '0' <=6)) table[i] = table[i-1] + table[i-2];
            else table[i] = table[i-1];
        }

        return table[s.size()];
    }


};
