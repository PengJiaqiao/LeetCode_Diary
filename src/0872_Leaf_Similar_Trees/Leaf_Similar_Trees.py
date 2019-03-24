# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        return tuple(self._iterleaves(root1)) == tuple(self._iterleaves(root2))

    def _iterleaves(self, node):
        if not node: return
        if self.isleaf(node): yield node.val
        yield from self._iterleaves(node.left)
        yield from self._iterleaves(node.right)
    
    def isleaf(self, node):
        return node and not any((node.left, node.right))
