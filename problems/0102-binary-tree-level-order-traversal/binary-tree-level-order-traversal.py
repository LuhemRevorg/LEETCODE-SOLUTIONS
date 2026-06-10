# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        q = deque([(root, 1)])
        current_level = 1
        s = []
        c = []
        if not root:
            return s
        while q:
            node, level = q.popleft()

            if level == current_level:
                c.append(node.val)
            else:
                current_level = level
                s.append(c)
                c = [node.val]
            
            if node.left:
                q.append([node.left, level + 1])
            if node.right:
                q.append([node.right, level + 1])
        s.append(c)

        return s
