class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int row_nos = grid.size();
        int col_nos = grid[0].size();
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), 0));
        std::function<void(int, int)> bfs = [&](int row, int column) {
            ++count;
            std::queue<std::pair<int, int>> q;
            q.push({row, column});
            while(!q.empty()) {
                int row=q.front().first;
                int column=q.front().second;
                q.pop();
                if (visited[row][column]) continue;
                visited[row][column] = true;
                if(row + 1 < row_nos && grid[row+1][column] == '1') q.push({row+1, column});
                if(column + 1 < col_nos && grid[row][column+1] == '1') q.push({row, column+1});
                if(row-1 >= 0 && grid[row-1][column] == '1') q.push({row-1, column});
                if(column - 1 >= 0 && grid[row][column-1] == '1') q.push({row, column-1});
            }
        };

            for(int i = 0; i < row_nos; ++i) {
                for(int j = 0; j < col_nos; ++j) {
                    if (grid[i][j]=='1' and !visited[i][j]) bfs(i,j);
                }
            }
        
        return count;
    }
        
};
