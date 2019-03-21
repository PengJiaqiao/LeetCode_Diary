class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        m, n = len(A), len(B)
        dp = [[0]*(m+1) for i in range(0,n+1)]
        for i in range(0, m):
            for j in range(0, n):
                if A[i] == B[j]: dp[i+1][j+1] = dp[i][j] + 1
        return max(max(row) for row in dp)
