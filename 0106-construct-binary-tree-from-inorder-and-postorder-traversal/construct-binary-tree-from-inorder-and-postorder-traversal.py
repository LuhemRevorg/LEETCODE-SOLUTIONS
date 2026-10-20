# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: list[int], postorder: list[int]) -> TreeNode | None:
        # postorder is left , right, root
        # inorder is left, root, right
        idx = {v: i for i, v in enumerate(inorder)}

        def node_create(in_start, in_end, post_start, post_end):
            if in_start > in_end or post_start > post_end:
                return None
            nonlocal inorder, postorder, idx
            
            val = postorder[post_end]
            node = TreeNode(val)

            at = idx[val]
            left_size = at - in_start

            node.left = node_create(in_start, at - 1,
                          post_start, post_start + left_size - 1)
            node.right = node_create(at + 1, in_end,
                            post_start + left_size, post_end - 1)
            return node
        
        root = node_create(0, len(inorder)-1, 0, len(postorder) - 1)

        return root
