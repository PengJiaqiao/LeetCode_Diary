class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        tmp = sorted(nums)
        begin = end = -1
        for i in range(len(nums)):
            if nums[i] != tmp[i]:
                if begin == -1: begin = i
                end = i
        return end - begin + 1 if end != -1 else 0
