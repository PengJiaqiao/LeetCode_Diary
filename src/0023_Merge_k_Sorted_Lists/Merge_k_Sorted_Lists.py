# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        from queue import PriorityQueue as PQ
        pq = PQ()
        queue_index = 0

        for node in lists:
            if node:
                pq.put((node.val, queue_index, node))
                queue_index += 1

        dummy = ListNode(None)
        needle = dummy

        while pq.queue:
            node = pq.get()[-1]
            needle.next = node
            needle = needle.next
            
            if node.next:
                pq.put((node.next.val, queue_index, node.next))
                queue_index += 1
                             
        return dummy.next
