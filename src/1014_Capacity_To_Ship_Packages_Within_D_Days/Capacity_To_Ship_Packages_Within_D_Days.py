class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        left, right = max(weights), sum(weights)
        while left < right:
            mid = (left + right) // 2
            count, s = 1, 0
            for weight in weights:
                s += weight
                if s > mid:
                    s = weight
                    count += 1
            if count > D: left = mid + 1
            else: right = mid
        return left
