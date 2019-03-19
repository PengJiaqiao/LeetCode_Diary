class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        dict = {}
        dict[0], sum = -1, 0
        for i in range(0, len(nums)):
            sum += nums[i]
            if k: sum %= k
            if sum in dict:
                if i - dict[sum] > 1: return True
            else: dict[sum] = i
        return False
