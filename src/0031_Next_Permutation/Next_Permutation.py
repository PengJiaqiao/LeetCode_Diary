class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        last = len(nums) - 1
        idx = last - 1
        while idx >= 0 and nums[idx] >= nums[idx+1]: 
            idx -= 1
        if idx == -1: nums.sort()
        else:
            idx_ = idx + 1
            while idx_ <= last and nums[idx_] > nums[idx]: idx_ += 1
            nums[idx], nums[idx_-1] = nums[idx_-1], nums[idx]
            nums[idx+1:] = sorted(nums[idx+1:])
