class Solution {
    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        function<int(int,int)> go = [&](int i, int j) -> int {
            if (i == 0 || j == 0) return 0;
            if (i == 1 && j == 1) return 1;
            int &r = memo[i][j];
            if (r != -1) return r;
            return r = go(i-1, j) + go(i, j-1);
            };
        return go(m, n);
    }
};
