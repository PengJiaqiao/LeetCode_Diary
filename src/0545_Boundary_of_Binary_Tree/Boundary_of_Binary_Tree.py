# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def boundaryOfBinaryTree(self, root: TreeNode) -> List[int]:
        def left_boundary(node, res):
            if not node or (not node.left and not node.right): return
            res.append(node.val)
            if not node.left: left_boundary(node.right, res)
            else: left_boundary(node.left, res)
        
        def right_boundary(node, res):
            if not node or (not node.left and not node.right): return
            if not node.right: right_boundary(node.left, res)
            else: right_boundary(node.right, res)
            res.append(node.val)
            
        def leaves(node, res):
            if not node: return
            if not node.left and not node.right: res.append(node.val)
            leaves(node.left, res)
            leaves(node.right, res)
        
        res = []
        if not root: return res
        if root.left or root.right: res.append(root.val)
        left_boundary(root.left, res)
        leaves(root, res)
        right_boundary(root.right, res)
        return res
