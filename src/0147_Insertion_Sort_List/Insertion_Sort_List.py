# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        dummyhead, cur = ListNode(0), head
        dummyhead.next = head
        while cur.next:
            if cur.val <= cur.next.val: cur = cur.next
            else: 
                tmp, q = cur.next, dummyhead
                cur.next = cur.next.next
                while q.next.val < tmp.val: q = q.next
                tmp.next = q.next
                q.next = tmp
        return dummyhead.next
