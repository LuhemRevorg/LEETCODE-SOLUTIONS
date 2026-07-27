#include <climits> 
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int total = n * m;

        // arr is a permutation of 1..n*m, so use a plain array instead of a hash map
        vector<int> pos(total + 1);
        for (int i = 0; i < total; ++i) pos[arr[i]] = i;

        vector<int> rowMax(n, 0), colMax(m, 0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                int t = pos[mat[i][j]];
                rowMax[i] = max(rowMax[i], t);
                colMax[j] = max(colMax[j], t);
            }

        int ans = INT_MAX;
        for (int v : rowMax) ans = min(ans, v);
        for (int v : colMax) ans = min(ans, v);
        return ans;
    }
};
