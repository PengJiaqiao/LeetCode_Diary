# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        dummy = node = TreeNode(None)
        for val in self.inorder(root):
            node.right = TreeNode(val)
            node = node.right
        return dummy.right
    
    def inorder(self, root):
        if root:
            yield from self.inorder(root.left)
            yield root.val
            yield from self.inorder(root.right)

# class Solution:
#     def increasingBST(self, root: TreeNode) -> TreeNode:
#         dummy = TreeNode(None)
#         needle = dummy
#         for node in self.inorder(root):
#             needle.right = TreeNode(node.val)
#             needle = needle.right
#         return dummy.right
#     
#     def inorder(self, root):
#         def side_traversal(n):
#             while n:
#                 yield n
#                 n = n.left
# 
#         unused = list(side_traversal(root))
#         while unused:
#             node = unused.pop()
#             yield node
#             unused.extend(side_traversal(node.right))
