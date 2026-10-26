class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        std::vector<std::pair<int,int>> directions = {{1,0}, {-1,0}, {0,-1}, {0,1}};
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        auto bfs = [&](std::pair<int, int> start) {
            std::queue<std::pair<int,int>> q;
            q.push(start);
            long long curr_sum = 0;

            while(!q.empty()) {
                auto &top = q.front();
                if (grid[top.first][top.second] == 0) {q.pop(); continue;}
                curr_sum+= grid[top.first][top.second];
                grid[top.first][top.second]=0;
                for (auto &dir : directions) {
                    auto new_x = top.first + dir.first;
                    auto new_y = top.second + dir.second;
                    if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && grid[new_x][new_y]!=0) q.push({new_x, new_y}); 
                }
                q.pop();
            }

            if (curr_sum % k == 0) ++count;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) if (grid[i][j] != 0) bfs({i,j});
        }

        return count;
    }
};
