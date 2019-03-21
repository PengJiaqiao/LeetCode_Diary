class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        begin, end = 0, -1
        sum, res = 0, len(nums) + 1
        while begin < len(nums):
            if sum < s and end < len(nums) - 1:
                end += 1
                sum += nums[end]
            else:
                res = min(res, end - begin + 1) if sum >= s else res
                sum -= nums[begin]
                begin += 1
        return res if res is not len(nums) + 1 else 0
