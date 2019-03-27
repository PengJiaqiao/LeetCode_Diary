class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        def dp(i, j):
            if (i, j) in memo: return memo[(i,j)]
            if j == n: 
                memo[i,j] = i == m
                return memo[i,j]
            
            first_match = i < m and (p[j] in [s[i],'.'])
            if j+1 < n and p[j+1] == '*':
                memo[(i,j)] = dp(i+0, j+2) or (first_match and dp(i+1,j+0))
                return memo[(i,j)]
            else:
                memo[(i,j)] = first_match and dp(i+1, j+1)
                return memo[(i,j)]
            
        m, n = len(s), len(p)
        memo = {}
        return dp(0,0)
