class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        std::vector<std::pair<int, int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        int count = 0;
        auto bfs = [&](std::pair<int, int> first) {
            std::queue<std::pair<int,int>> q;
            q.push(first);
            grid[first.first][first.second] = -1;
            while(!q.empty()) {
                auto &top = q.front();
                grid[top.first][top.second] = -1;
                for (int i = 0; i < 4; ++i) {
                    int new_x = top.first + dir[i].first;
                    int new_y = top.second + dir[i].second;
                    if (new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size()) {
                        if (grid[new_x][new_y] == 1) {grid[new_x][new_y] = -1; q.push({new_x, new_y});}
                        if (grid[new_x][new_y] == 0) ++count;
                    } else ++count;
                }
                q.pop();
            }
            
        };
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {bfs({i,j}); break;}
            }
        }

        return count;
    }
};
