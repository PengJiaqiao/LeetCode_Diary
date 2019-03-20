# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        fakehead = ListNode(0)
        fakehead.next = head
        node = fakehead
        while node:
            if node.next:
                if node.next.val == val:
                    node.next = node.next.next
                else: node = node.next
            else: node = node.next
        return fakehead.next
