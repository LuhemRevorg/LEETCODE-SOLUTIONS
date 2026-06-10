# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        level_max = -1
        ret = []
        def dfs(node, curr_level):
            if node is None: return
            nonlocal level_max
            if curr_level > level_max:
                ret.append(node.val)
                level_max = curr_level
            for i in [node.right, node.left]:
                dfs(i, curr_level + 1)
        dfs(root, 0)
        
        return ret
