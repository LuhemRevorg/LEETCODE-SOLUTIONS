class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // min-heap of {time, row, col}
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        vector<vector<bool>> seen(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});
        seen[0][0] = true;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto [t, r, c] = pq.top(); pq.pop();
            if (r == n - 1 && c == n - 1) return t;
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !seen[nr][nc]) {
                    seen[nr][nc] = true;
                    pq.push({max(t, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1; // unreachable
    }
};
