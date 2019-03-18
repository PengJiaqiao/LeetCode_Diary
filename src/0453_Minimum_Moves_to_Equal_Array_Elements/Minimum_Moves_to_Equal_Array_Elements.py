class Solution:
    def minMoves(self, nums: List[int]) -> int:
        sum = 0
        Min = nums[0]
        for num in nums:
            sum += num
            Min = min(Min, num)
        return sum - Min * len(nums)
