class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;
        std::vector<std::pair<int, int>> directions = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        
        auto bfs = [&](this auto& self, int x, int y) {
            std::queue<std::pair<int,int>> q;
            q.push({x,y});
            int area = 1;
            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (auto direction : directions) {
                    if (x+direction.first < grid.size() && x+direction.first >= 0 && y+direction.second < grid[0].size() && y+direction.second >= 0 && grid[x+direction.first][y+direction.second] != 0) {
                        q.push({x+direction.first, y+direction.second});
                        grid[x+direction.first][y+direction.second] = 0;
                        ++area;
                    }
                }

            }
            mx = std::max(area, mx);
        };

        for (int i = 0; i< grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) { 
                if (grid[i][j]==1) {grid[i][j] = 0; bfs(i,j);}
            }
        }

        return mx;
    }
};
