class Solution:
    def maxRotateFunction(self, A: List[int]) -> int:
        s, F = sum(A), 0
        for i, val in enumerate(A):
            F += i * val # F(O)
        res = F
        for i in range(1,len(A)):
            F = F + s - len(A) * A[-i] # F(i)
            res = max(res, F)
        return res
