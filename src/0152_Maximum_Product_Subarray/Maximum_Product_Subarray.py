class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        product = Max = Min = nums[0]
        for i in range(1, len(nums)):
            if nums[i] < 0: Max, Min = Min, Max
            Max = max(nums[i], Max * nums[i])
            Min = min(nums[i], Min * nums[i])
            product = max(product, Max)
        return product
