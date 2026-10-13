class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int count = 0;
        std::vector<std::pair<int, int>> directions = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        
        auto bfs = [&](this auto& self, int x, int y) {
            std::queue<std::pair<int,int>> q;
            q.push({x,y});
            
            ++count;
            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (auto direction : directions) {
                    if (x+direction.first < grid.size() && x+direction.first >= 0 && y+direction.second < grid[0].size() && y+direction.second >= 0 && grid[x+direction.first][y+direction.second] != '0') {
                        q.push({x+direction.first, y+direction.second});
                        grid[x+direction.first][y+direction.second] = '0';
                    }
                }
 
            }
        };

        for (int i = 0; i< grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]=='1') {grid[i][j] = '0'; bfs(i,j);}
            }
        }

        return count;
    }
        
};
