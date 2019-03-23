# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def plusOne(self, head: ListNode) -> ListNode:
        dummyhead = ListNode(0)
        dummyhead.next = head
        node, pre = head, dummyhead
        dict = {}
        while node:
            dict[node] = pre
            pre = node
            node = node.next
        pre.val += 1
        while pre.val > 9:
            pre.val = 0
            pre = dict[pre]
            pre.val += 1
        if dummyhead.val > 0: return dummyhead
        return dummyhead.next
