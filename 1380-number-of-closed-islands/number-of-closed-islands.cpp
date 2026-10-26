    class Solution {
    public:
        int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        auto sink = [&](int r, int c) {
            queue<pair<int,int>> q;
            q.push({r, c});
            grid[r][c] = 1;
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        };

        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 0)
                    sink(i, j);

        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0) {
                    sink(i, j);
                    count++;
                }
        return count;
    }
    };
