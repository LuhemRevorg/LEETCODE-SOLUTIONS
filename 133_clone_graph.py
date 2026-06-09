"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
from collections import deque
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        visited = {}
        def dfs(node, copy):
            visited[node] = copy
            copy.neighbors = []
            for v in node.neighbors:
                if v not in visited:
                    visited[v] = Node(v.val)
                    copy.neighbors.append(visited[v])
                    dfs(v, copy.neighbors[-1])
                else:
                    copy.neighbors.append(visited[v])
                    
        if node is None:
            return None
        copy = Node(node.val)
        dfs(node,copy)
        return copy