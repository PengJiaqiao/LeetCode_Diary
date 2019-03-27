class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        if not nums: return 0
        n = len(nums)
        nums = [1] + nums + [1]
        dp = [[0 for i in range(n+2)] for j in range(n+2)]
        for i in range(1, n+1):
            for begin in range(1, n+1):
                end = begin + i - 1
                if end > n: break
                if i == 1: dp[begin][end] = nums[begin-1] * nums[begin] * nums[begin+1]
                else: 
                    max_ = 0
                    for last in range(begin, end+1):
                        v = dp[begin][last-1] + dp[last+1][end] + nums[begin-1] * nums[last] * nums[end+1]
                        if v > max_: max_ = v
                    dp[begin][end] = max_   
        return dp[1][n]
