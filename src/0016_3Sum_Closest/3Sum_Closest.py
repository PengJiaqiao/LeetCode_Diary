class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        res = nums[0] + nums[1] + nums[2]
        for i in range(0, len(nums)):
            begin, end = i + 1, len(nums) - 1
            while begin < end:
                sum = nums[i] + nums[begin] + nums[end]
                res = res if abs(target - res) < abs(target - sum) else sum
                if sum > target: end -= 1
                else: begin += 1
        return res
