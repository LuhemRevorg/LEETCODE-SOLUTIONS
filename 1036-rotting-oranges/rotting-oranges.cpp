class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) ++fresh;
            }

        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int minutes = 0;

        while (!q.empty() && fresh > 0) {
            int sz = q.size();              // process one "minute" (level) at a time
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;       // mark rotten = visited
                    --fresh;
                    q.push({nx, ny});
                }
            }
            ++minutes;
        }
        return fresh == 0 ? minutes : -1;
    }
};
