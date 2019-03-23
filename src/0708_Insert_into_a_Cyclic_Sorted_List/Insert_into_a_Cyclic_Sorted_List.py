"""
# Definition for a Node.
class Node:
    def __init__(self, val, next):
        self.val = val
        self.next = next
"""
class Solution:
    def insert(self, head: 'Node', insertVal: int) -> 'Node':
        def isSpot(p, c, i):
            if i == c.val: return True
            if p.val > c.val:  # if previous node is greater than current node
                if i < c.val and i < p.val: return True
                if i > c.val and i > p.val: return True
            if p.val < c.val: # if previous node is less than current node
                if p.val < i < c.val: return True
            return False
        
        if not head: 
            node = Node(insertVal, None)
            node.next = node
            return node
        node = head
        if head.next == head:
            node = Node(insertVal, head)
            head.next = node
            return node
        while not isSpot(node, node.next, insertVal) and node.next != head: node = node.next
        new = Node(insertVal, node.next)
        node.next = new
        return head
