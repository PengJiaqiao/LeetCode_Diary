class Solution:
    def maxArea(self, height: List[int]) -> int:
        begin, end, Max = 0, len(height) - 1, 0
        while begin < end:
            Max = max(Max, (end - begin) * min(height[begin], height[end]))
            if height[begin] < height[end]: begin += 1
            else: end -= 1
        return Max
