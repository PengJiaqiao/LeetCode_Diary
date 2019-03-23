class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {} 
        for i, num in enumerate(nums):
            search = target - num
            if search in dict: return [dict[search], i]
            else: dict[num] = i
