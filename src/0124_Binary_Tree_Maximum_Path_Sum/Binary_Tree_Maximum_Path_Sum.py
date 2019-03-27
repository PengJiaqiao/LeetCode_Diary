# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        def postorder(root):
            if not root: return 0
            nonlocal max_sum
            left = postorder(root.left)
            right = postorder(root.right)
            max_sum = max(max_sum, root.val+left+right, root.val + left, root.val + right, root.val)
            return max(root.val, root.val + left, root.val + right)
        
        max_sum = float('-inf')
        postorder(root)
        return max_sum
