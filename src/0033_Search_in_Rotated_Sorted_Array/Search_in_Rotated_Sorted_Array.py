class Solution:
    def search(self, nums: List[int], target: int) -> int:
        length = len(nums)
        if not length: return -1
        left, right = 0, length-1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[right]: left = mid + 1
            else: right = mid
        left, right = left-length, left-1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] < target: left = mid + 1
            else: right = mid
        return left % length if nums[left] == target else -1
