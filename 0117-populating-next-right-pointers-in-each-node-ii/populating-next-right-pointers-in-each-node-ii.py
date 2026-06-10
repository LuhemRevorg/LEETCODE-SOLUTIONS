"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
from collections import deque
class Solution:
        def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
            if not root:
                return root
            q = deque([[root, 1]])
            prev = root
            current_level = 0
            while q:
                node, level = q.popleft()
                if current_level == level:
                    prev.next = node
                else:
                    current_level = level
                    prev.next = None
                if node.left:
                    q.append([node.left, level + 1])
                if node.right:
                    q.append([node.right, level + 1])
                

                prev = node
            return root
