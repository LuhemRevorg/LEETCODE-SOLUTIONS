# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:

        arr = []

        def search_left(node):
            nonlocal arr
            if not node:
                return
            if node.left:
                search_left(node.left)
            arr.append(node.val)
            if node.right:
                search_left(node.right)
        
        search_left(root)
        
        return arr
