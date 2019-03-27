# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def helper(in_left = 0, in_right = len(inorder)):
            if in_left == in_right: return None
            nonlocal pre_idx
            root_val = preorder[pre_idx]
            root = TreeNode(root_val)

            index = idx_map[root_val]
            pre_idx += 1
            
            root.left = helper(in_left, index) # build left subtree
            root.right = helper(index + 1, in_right) # build right subtree
            return root
        
        pre_idx = 0
        idx_map = {val:idx for idx, val in enumerate(inorder)} 
        return helper()
