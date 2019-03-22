# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def countUnivalSubtrees(self, root: TreeNode) -> int:
        def dfs(node, pre, res) -> bool:
            if not node: return True
            flag1 = dfs(node.left, node.val, res)
            flag2 = dfs(node.right, node.val, res)
            if flag1 and flag2: res[0] += 1
            return node.val == pre and flag1 and flag2
        
        if not root: return 0
        res = [0]
        dfs(root, root.val, res)
        return res[0]
