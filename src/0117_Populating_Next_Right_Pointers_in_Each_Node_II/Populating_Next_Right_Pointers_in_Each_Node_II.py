"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root: return None
        queue = [root]
        while queue:
            for i in range(len(queue)-1): queue[i].next = queue[i+1]
            queue[-1].next = None
            
            tmp = []
            for node in queue: tmp.extend([node.left, node.right])  
            queue = [n for n in tmp if n]
        return root
