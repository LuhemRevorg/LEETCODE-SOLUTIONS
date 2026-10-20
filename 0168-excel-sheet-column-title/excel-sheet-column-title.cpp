class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret = "";
        while(columnNumber) {
            int rem = (columnNumber - 1) % 26;
            ret += 'A' + rem; 
            columnNumber = (columnNumber - 1) / 26;
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
