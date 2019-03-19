class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        cur, diff = 0, 1
        while cur < num:
            cur += diff
            diff += 2
        if cur == num: return True
        else: return False
