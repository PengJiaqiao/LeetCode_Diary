class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums: return []
        if k >= len(nums): return [max(nums)]
        
        res = []
        currMax = max(nums[:k])
        res.append(currMax)
        
        for i in range(1, len(nums) - k + 1):
            if nums[i-1] == currMax: currMax = max(nums[i:i+k])
            else: currMax = max(currMax, nums[i+k-1])
            res.append(currMax)
        return res
