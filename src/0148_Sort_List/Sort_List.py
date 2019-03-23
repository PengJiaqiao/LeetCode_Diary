# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        from queue import PriorityQueue as PQ
        pq = PQ()
        idx, node = 0, head
        
        while node:
            pq.put((node.val, idx, node))
            node = node.next
            idx += 1

        dummy = ListNode(None)
        node = dummy

        while pq.queue:
            tmp = pq.get()[-1]
            node.next = tmp
            node = node.next
        node.next = None
                             
        return dummy.next
