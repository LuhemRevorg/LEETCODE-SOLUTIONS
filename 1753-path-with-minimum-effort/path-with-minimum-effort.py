class Solution:
    def minimumEffortPath(self, heights: list[list[int]]) -> int:
        
        def availaible_neighbors(x, y):
            ret = []
            for i, j in [(-1,0), (0,1), (1,0), (0,-1)]:
                if 0 <= x + i < len(heights) and 0 <= y + j < len(heights[0]):
                    ret.append((x+i, y + j))

            return ret
        
        visited = set()
        
        heap = [(0,0,0)]

        while heap:
            effort, x, y = heapq.heappop(heap)
            
            if (x, y) in visited:
                continue
            visited.add((x,y))
            if x == len(heights) - 1 and y ==len(heights[0]) - 1:
                    return effort

            neighbors = availaible_neighbors(x,y)

            for new_x , new_y in neighbors:
                
                if (new_x, new_y) not in visited:
                    new_effort = max(effort , abs(heights[x][y] - heights[new_x][new_y]))
                    heapq.heappush(heap, (new_effort, new_x, new_y))
            
        return -1
