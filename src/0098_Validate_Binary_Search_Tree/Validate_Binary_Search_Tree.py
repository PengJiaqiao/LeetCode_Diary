# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        pre = None
        for val in self.inorder(root):
            if pre == None: 
                pre = val
                continue
            if val <= pre: return False
            pre = val
        return True
        
    def inorder(self, root: TreeNode):
        def dfs(node: TreeNode):
            while node:
                yield node
                node = node.left
        
        stack = list(dfs(root))
        while stack:
            node = stack.pop()
            yield node.val
            stack.extend(list(dfs(node.right)))
