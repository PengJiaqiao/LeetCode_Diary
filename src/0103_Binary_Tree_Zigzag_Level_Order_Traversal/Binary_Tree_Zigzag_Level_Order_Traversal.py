# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None: return []
        queue = collections.deque()
        queue.append(root)
        count, res, reverse = 1, [], False
        while queue:
            tmp, next_count = [], 0
            while count:
                node = queue.popleft()
                count -= 1
                tmp.append(node.val)
                if node.left: 
                    queue.append(node.left)
                    next_count += 1
                if node.right: 
                    queue.append(node.right)
                    next_count += 1
            tmp = tmp[::-1] if reverse else tmp
            res.append(tmp)
            reverse = not reverse
            count = next_count
        return res
