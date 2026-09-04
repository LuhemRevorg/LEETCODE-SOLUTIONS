# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        table = []
        other = []

        def dfs(curr):
            nonlocal table
            if not curr:
                return 0
            sum_left = dfs(curr.left)
            sum_right = dfs(curr.right)
            val = max([curr.val, sum_left + curr.val, sum_right + curr.val])
            table.append(val)
            other.append(sum_right + curr.val + sum_left)
            return val
        
        dfs(root)
        return (max(max(table), max(other)))
