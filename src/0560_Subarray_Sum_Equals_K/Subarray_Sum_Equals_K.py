class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        dict = {}
        dict[0], sum, count = 1, 0, 0
        for num in nums:
            sum += num
            if sum - k in dict: count += dict[sum - k]
            dict[sum] = dict[sum] + 1 if sum in dict else 1
        return count
