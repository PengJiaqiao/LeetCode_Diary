# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        data, p = [], head
        while p:
            data.append(p.val)
            p = p.next
        stack, res = [], [0] * len(data)
        for idx in range(len(data)):
            while stack and data[stack[-1]] < data[idx]:
                res[stack.pop()] = data[idx]
            stack.append(idx)
        return res
