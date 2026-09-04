class Solution {
public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        auto bfs = [&](queue<pair<int,int>> q, vector<vector<bool>>& visited) {
            while (!q.empty()) {
                auto [i, j] = q.front(); q.pop();
                for (auto [di, dj] : vector<pair<int,int>>{{0,1},{0,-1},{1,0},{-1,0}}) {
                    int ni = i+di, nj = j+dj;
                    if (ni>=0 && ni<m && nj>=0 && nj<n && !visited[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                        visited[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
        };

        queue<pair<int,int>> pac, atl;
        for (int i = 0; i < m; ++i) {
            pacific[i][0] = true;   pac.push({i, 0});
            atlantic[i][n-1] = true; atl.push({i, n-1});
        }
        for (int j = 0; j < n; ++j) {
            pacific[0][j] = true;   pac.push({0, j});
            atlantic[m-1][j] = true; atl.push({m-1, j});
        }

        bfs(pac, pacific);
        bfs(atl, atlantic);

        vector<vector<int>> ret;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (pacific[i][j] && atlantic[i][j])
                    ret.push_back({i, j});
        return ret;
    }
};
