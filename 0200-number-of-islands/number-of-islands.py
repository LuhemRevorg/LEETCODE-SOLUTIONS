from collections import deque

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0

        def bfs(coord):
            nonlocal count
            count += 1
            q = deque()
            q.append(coord)
            grid[coord[0]][coord[1]] = "0"
            while len(q) != 0:
                top = q.popleft()
                
                for i, j in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    if top[0] + i >= 0 and top[0] + i < len(grid) and top[1] + j >= 0 and top[1] + j < len(grid [0]) and grid[top[0] + i][top[1] + j] != "0": 
                        grid[top[0] + i][top[1] + j] = "0"
                        q.append((top[0] + i, top[1] + j))
        
        for i in range(0, len(grid)):
            for j in range(0, len(grid[0])):
                if grid[i][j]!="0": bfs((i,j))
        
        return count
