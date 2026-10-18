class Solution:
    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:
        distance = defaultdict(list)
    
        for source, target, weight in times:
            distance[source].append((weight, target))
    
        visited = set()
        
        data = [(0,k)]
        time = 0

        while len(data) != 0:
            top_weight, top_node = heapq.heappop(data)
            
            if top_node not in visited:
                time = top_weight
                visited.add(top_node)
                for weight, neighbor in distance[top_node]:
                        heapq.heappush(data, (weight + top_weight, neighbor))
                        

        if len(visited) != n:
            return -1
        
        return time
