class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums_sorted = sorted(nums)
        median = nums_sorted[len(nums) // 2]
        res = 0
        for num in nums:
            res += abs(num - median)
        return res
