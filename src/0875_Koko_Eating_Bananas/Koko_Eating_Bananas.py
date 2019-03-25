class Solution:
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        left = math.ceil(sum(piles)/H)
        right = max(piles)
        while left < right:
            mid = left + (right - left) // 2
            need_time = 0
            for pile in piles: need_time += math.ceil(pile / mid)
            if need_time > H: left = mid + 1
            else: right = mid
        return left
