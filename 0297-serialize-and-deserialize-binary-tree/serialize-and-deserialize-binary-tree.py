# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        if not root:
            return "None,"
        result = []
        q = deque([root])
        while q:
            node = q.popleft()
            if node:
                result.append(str(node.val))
                q.append(node.left)
                q.append(node.right)
            else:
                result.append("None")
        return ",".join(result)
        
            
            

    def deserialize(self, data):
        vals = data.split(",")
        if vals[0] == "None":
            return None
        root = TreeNode(int(vals[0]))
        q = deque([root])
        i = 1
        while q:
            node = q.popleft()
            if vals[i] != "None":
                node.left = TreeNode(int(vals[i]))
                q.append(node.left)
            i += 1
            if vals[i] != "None":
                node.right = TreeNode(int(vals[i]))
                q.append(node.right)
            i += 1
        return root
            

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
