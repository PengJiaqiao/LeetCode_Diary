# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        tmp = list(self.preorder(root))
        if tmp: tmp[0].left = None
        for i in range(1, len(tmp)):
            tmp[i].left = None
            tmp[i-1].right = tmp[i]
        
    def preorder(self, root: TreeNode):
        unused = root and [root]
        while unused:
            node = unused.pop()
            yield node
            unused.extend(filter(None, (node.right, node.left)))
