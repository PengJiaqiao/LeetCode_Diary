class Solution:
    def canJump(self, nums: List[int]) -> bool:
        last = len(nums) - 1
        for i in range(len(nums)-1, -1, -1):
            if (i + nums[i]) >= last:
                last = i
        return last == 0

#class Solution:
#    def canJump(self, nums: List[int]) -> bool:
#        pre, cur = 0, nums[0]
#        while cur < len(nums) - 1:
#            maxidx = 0
#            for i in range(pre, cur+1): maxidx = max(maxidx, i + nums[i])
#            if maxidx <= cur: return False
#            pre, cur = cur, maxidx
#            
#        return True
