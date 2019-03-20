class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        dict = {}
        for i, val1 in enumerate(A):
            for j, val2 in enumerate(B):
                sum = val1 + val2
                if sum in dict: dict[sum] += 1
                else: dict[sum] = 1
        count = 0
        for i, val1 in enumerate(C):
            for j, val2 in enumerate(D):
                sum = val1 + val2
                if -sum in dict: count += dict[-sum]
        return count
